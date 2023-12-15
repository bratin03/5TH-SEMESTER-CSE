// Define timescale for simulation accuracy
`timescale 1ns / 1ps

// Define an adder module
module adder(input [7:0] in1, input [7:0] in2, output [7:0] out);
    assign out = in1 + in2; // Assign the sum of inputs to the output
endmodule

// Define a subtractor module
module subtractor(input [7:0] in1, input [7:0] in2, output [7:0] out);
    assign out = in1 - in2; // Assign the difference of inputs to the output
endmodule

// Define a shifter module
module shifter(input [7:0] A, input [7:0] Q, output [7:0] shifted_A, output [7:0] shifted_Q);
    assign shifted_Q = {A[0], Q[7:1]}; // Shift Q to the left, replacing MSB with A's LSB
    assign shifted_A = {A[7], A[7:1]}; // Shift A to the left, replacing MSB with itself's second MSB
endmodule

// Define a Booth multiplier module
module booth_mult(
    input [7:0] multiplier,
    input [7:0] multiplicand,
    input clk,
    input reset,
    input load,
    output reg [15:0] result
);
    // Declare internal registers and wires
    reg [7:0] A, Q, M;
    reg Q_buff, done;
    reg [4:0] count;
    wire [7:0] tempSum;
    wire [7:0] tempSub;
    wire [7:0] temp_A;
    wire [7:0] temp_Q;

    // Instantiate the adder module
    adder ADD(.in1(A), .in2(M), .out(tempSum));

    // Instantiate the subtractor module
    subtractor SUB(.in1(A), .in2(M), .out(tempSub));

    // Instantiate the shifter module
    shifter SHIFTER(.A(A), .Q(Q), .shifted_Q(temp_Q), .shifted_A(temp_A));

    // Define the sequential behavior using always block
    always @(posedge clk) begin
        if (reset == 1'b1) begin
            // Reset conditions
            A = 0;
            Q = 0;
            M = 0;
            done = 1'b0;
            Q_buff = 1'b0;
            result = 0;
            count = 5'b01000;
        end else if (load == 1'b1) begin
            // Load conditions
            Q = multiplier;
            M = multiplicand;
            A = 0;
            count = 5'b01000;
            Q_buff = 1'b0;
        end else begin
            if (count != 5'b00000) begin
                if (Q[0] != Q_buff) begin
                    if (Q[0] == 1'b0) begin
                        A = tempSum; // Positive multiplier
                    end else begin
                        A = tempSub; // Negative multiplier
                    end
                end

                Q_buff = Q[0];
                Q = {A[0], Q[7:1]}; // Shift Q and replace its LSB with A's LSB
                A = {A[7], A[7:1]}; // Shift A and replace its MSB with itself's second MSB

                count = count - 5'b00001;
            end
            if (count == 5'b00000 && done == 1'b0) begin
                result <= {A, Q}; // Combine A and Q to form the result
                done <= 1'b1;
            end
        end
    end
endmodule
