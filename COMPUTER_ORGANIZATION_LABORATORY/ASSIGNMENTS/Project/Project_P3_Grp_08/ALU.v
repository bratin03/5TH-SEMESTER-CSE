`timescale 1ns/1ps

// Module for a 32-bit NOT operation
module NOT32(input [31:0] in1, output [31:0] out);
    assign out = ~in1; // Bitwise NOT operation on in1 and assign to out.
endmodule

// Module for a 32-bit AND operation
module AND32(input [31:0] in1, input [31:0] in2, output [31:0] out);
    assign out = in1 & in2; // Bitwise AND operation between in1 and in2, result assigned to out.
endmodule

// Module for a 32-bit arithmetic right shift operation
module SHIFT_RIGHT_ARITHMETIC(input [31:0] in1, output [31:0] out);
    assign out = {1'b0, in1[31:1]}; // Arithmetic right shift on in1, result assigned to out.
endmodule

// Module for a 32-bit logical right shift operation
module SHIFT_RIGHT_LOGICAL(input [31:0] in1, output [31:0] out);
    assign out = {in1[31], in1[31:1]}; // Logical right shift on in1, result assigned to out.
endmodule

// Module for a 32-bit arithmetic left shift operation
module SHIFT_LEFT_ARITHMETIC(input [31:0] in1, output [31:0] out);
    assign out = {in1[30:0], 1'b0}; // Arithmetic left shift on in1, result assigned to out.
endmodule

// Module for a 32-bit OR operation
module OR32(input [31:0] in1, input [31:0] in2, output [31:0] out);
    assign out = in1 | in2; // Bitwise OR operation between in1 and in2, result assigned to out.
endmodule

// Module for a 32-bit XOR operation
module XOR32(input [31:0] in1, input [31:0] in2, output [31:0] out);
    assign out = in1 ^ in2; // Bitwise XOR operation between in1 and in2, result assigned to out.
endmodule

// Module for a 4-bit carry look-ahead adder
module carry_look_ahead_4(input [3:0] in1, input [3:0] in2, input cin, output [3:0] out, output cout);
    // Define a 4-bit wire for the propagation result
    wire [3:0] prop;

    // Define a 4-bit wire for the generation result
    wire [3:0] gen;

    // Define individual wires for carry outputs at different stages
    wire c0; // Carry 0
    wire c1; // Carry 1
    wire c2; // Carry 2
    wire c3; // Carry 3


    assign prop = in1 ^ in2; // Calculate propagate signals based on in1 and in2.
    assign gen = in1 & in2;  // Calculate generate signals based on in1 and in2.

    assign c0 = cin; // Set carry-in c0 to the input carry signal.

    assign c1 = gen[0] | (prop[0] & c0); // Calculate carry bit c1.
    assign c2 = gen[1] | (prop[1] & c1); // Calculate carry bit c2.
    assign c3 = gen[2] | (prop[2] & c2); // Calculate carry bit c3.
    assign out[0] = prop[0] ^ c0; // Calculate sum bit for the first bit.
    assign out[1] = prop[1] ^ c1; // Calculate sum bit for the second bit.
    assign out[2] = prop[2] ^ c2; // Calculate sum bit for the third bit.
    assign out[3] = prop[3] ^ c3; // Calculate sum bit for the fourth bit.

    assign cout = gen[3] | (prop[3] & c3); // Calculate the carry-out signal.
endmodule

// Module for an 8-bit carry look-ahead adder
module CLA_8(input [7:0] in1, input [7:0] in2, input cin, output [7:0] out, output cout);
    wire c1;
    carry_look_ahead_4 cla1(.in1(in1[3:0]), .in2(in2[3:0]), .cin(cin), .out(out[3:0]), .cout(c1)); // Instantiate the first CLA block for the lower 4 bits.
    carry_look_ahead_4 cla2(.in1(in1[7:4]), .in2(in2[7:4]), .cin(c1), .out(out[7:4]), .cout(cout)); // Instantiate the second CLA block for the upper 4 bits.
endmodule

// Module for a 32-bit adder
module ADD32(input [31:0] in1, input [31:0] in2, output [31:0] out);
    wire c1, c2, c3, cin,cout;
    assign cin = 1'b0; // Set initial carry-in to 0.
    CLA_8 CLA1(.in1(in1[7:0]), .in2(in2[7:0]), .cin(cin), .out(out[7:0]), .cout(c1)); // Instantiate the first CLA block for the least significant 8 bits.
    CLA_8 CLA2(.in1(in1[15:8]), .in2(in2[15:8]), .cin(c1), .out(out[15:8]), .cout(c2)); // Instantiate the second CLA block for the next 8 bits.
    CLA_8 CLA3(.in1(in1[23:16]), .in2(in2[23:16]), .cin(c2), .out(out[23:16]), .cout(c3)); // Instantiate the third CLA block for the next 8 bits.
    CLA_8 CLA4(.in1(in1[31:24]), .in2(in2[31:24]), .cin(c3), .out(out[31:24]), .cout(cout)); // Instantiate the fourth CLA block for the most significant 8 bits.
endmodule

// Module for a 32-bit subtractor
module SUBTRACT32(input [31:0] in1, input [31:0] in2, output [31:0] out);
    wire [31:0] t;
    NOT32 getNot(.in1(in2), .out(t)); // Calculate the bitwise complement of in2.
    wire [31:0] t1;
    assign t1 = 1; // Set t1 to 1 for subtraction.
    wire [31:0] out1;
    ADD32 getAdd(.in1(t), .in2(t1), .out(out1)); // Add t and t1 to perform subtraction.
    ADD32 getAdd2(.in1(out1), .in2(in1), .out(out)); // Add the result of the previous addition to in1 to obtain the subtraction result.
endmodule


// Module for an Arithmetic Logic Unit (ALU)
module ALU(
    input [3:0] opcode,                    // Input: ALU operation code
    input signed [31:0] A,                // Input: Operand A (signed)
    input signed [31:0] B,                // Input: Operand B (signed)
    input shift_amount,                   // Input: Shift amount
    output signed [31:0] ALU_result       // Output: ALU result (signed)
);

// Define a 32-bit output for addition operation
wire [31:0] outputADD;
// Define a 32-bit output for subtraction operation
wire [31:0] outputSUB;
// Define a 32-bit output for arithmetic right shift operation
wire [31:0] outputRSHIFT_ARITHMETIC;
// Define a 32-bit output for arithmetic left shift operation
wire [31:0] outputLSHIFT_ARITHMETIC;
// Define a 32-bit output for logical right shift operation
wire [31:0] outputRSHIFT_LOGICAL;
// Define a 32-bit output for bitwise AND operation
wire [31:0] outputAND;
// Define a 32-bit output for bitwise OR operation
wire [31:0] outputOR;
// Define a 32-bit output for bitwise NOT operation
wire [31:0] outputNOT;
// Define a 32-bit output for bitwise XOR operation
wire [31:0] outputXOR;
// Define a single wire for carrying purposes (for example, in addition)
wire cout;

   
    NOT32 not32(.in1(A), .out(outputNOT)); // Calculate the bitwise complement of A.
    ADD32 add32(.in1(A), .in2(B), .out(outputADD)); // Perform addition of A and B.
    XOR32 xor32(.in1(A), .in2(B), .out(outputXOR)); // Perform bitwise XOR of A and B.
    SHIFT_RIGHT_ARITHMETIC shiftRightA(.in1(A), .out(outputRSHIFT_ARITHMETIC)); // Perform arithmetic right shift on A.
    SHIFT_LEFT_ARITHMETIC shiftLeftA(.in1(A), .out(outputLSHIFT_ARITHMETIC)); // Perform arithmetic left shift on A.
    SHIFT_RIGHT_LOGICAL shiftRightL(.in1(A), .out(outputRSHIFT_LOGICAL)); // Perform logical right shift on A.
    AND32 and32(.in1(A), .in2(B), .out(outputAND)); // Perform bitwise AND of A and B.
    OR32 or32(.in1(A), .in2(B), .out(outputOR)); // Perform bitwise OR of A and B.
    SUBTRACT32 sub(.in1(A), .in2(B), .out(outputSUB)); // Perform subtraction of A and B.

    reg signed [31:0] result;             // Internal register for the ALU result (signed)

    always @(*)                           // Combinational logic for ALU operation
    begin
        case (opcode)
            4'b0000: begin
                result = outputADD;  // Select ADD operation result
            end
            4'b0001: begin
                result = outputSUB;  // Select SUB operation result
            end
            4'b0010: begin
                result = outputAND;  // Select AND operation result
            end
            4'b0011: begin
                result = outputOR;   // Select OR operation result
            end
            4'b0100: begin
                result = outputXOR;  // Select XOR operation result
            end
            4'b0101: begin
                result = outputNOT;  // Select NOT operation result
            end
            4'b0110: begin
                case (shift_amount)
                    1'b0: begin
                        result = A;  // Select SLA operation result (0 bits shifted)
                    end
                    1'b1: begin
                        result = outputLSHIFT_ARITHMETIC;  // Select SLA operation result (1 bit shifted)
                    end
                endcase
            end
            4'b0111: begin
                case (shift_amount)
                    1'b0: begin
                        result = A;  // Select SRA operation result (0 bits shifted)
                    end
                    1'b1: begin
                        result = outputRSHIFT_ARITHMETIC;  // Select SRA operation result (1 bit shifted)
                    end
                endcase
            end
            4'b1000: begin
                case (shift_amount)
                    1'b0: begin
                        result = A;  // Select SRL operation result (0 bits shifted)
                    end
                    1'b1: begin
                        result = outputRSHIFT_LOGICAL;  // Select SRL operation result (1 bit shifted)
                    end
                endcase
            end
        endcase
    end

    assign ALU_result = result;             // Assign the ALU result to the output port
//    assign carry_out = cout;       // Assign the carry-out signal to the output port
endmodule

