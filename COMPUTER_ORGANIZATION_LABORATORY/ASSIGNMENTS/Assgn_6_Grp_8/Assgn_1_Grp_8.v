`timescale 1ns/1ps

module NOT8(input [7:0] in1,output [7:0] out);
    assign out = ~in1;
endmodule

module AND8(input [7:0] in1,input [7:0] in2,output [7:0] out);
    assign out = in1 & in2;
endmodule

module SHIFT_RIGHT(input [7:0] in1,output [7:0] out);
    assign out= {1'b0, in1[7:1]};
endmodule

module SHIFT_LEFT(input [7:0] in1,output [7:0] out);
    assign out = {in1[6:0], 1'b0};
endmodule

module IDENTITY8(input [7:0] in1,output [7:0] out);
    assign out = in1;
endmodule

module OR8(input [7:0] in1, input [7:0] in2, output [7:0] out);
    assign out = in1 | in2;
endmodule



module carry_look_ahead_4(input[3:0] in1,input[3:0] in2,input cin,output[3:0] out,output cout);

    wire[3:0] prop;
    wire[3:0] gen;
    wire c0, c1, c2, c3;

    assign prop = in1 ^ in2;
    assign gen = in1 & in2;

    assign c0 = cin;

    assign c1 = gen[0] | (prop [0] & c0);
    assign c2 = gen[1] | (prop [1] & c1);
    assign c3 = gen[2] | (prop [2] & c2);
    assign out[0] = prop[0] ^ c0;
    assign out[1] = prop[1] ^ c1;
    assign out[2] = prop[2] ^ c2;
    assign out[3] = prop[3] ^ c3;
    
    assign cout = gen[3] | (prop[3] & c3);
endmodule

module ADD8(input[7:0] in1,input[7:0] in2,output[7:0] out,output cout);
    
    wire c1, cin;
    assign cin = 1'b0;
    carry_look_ahead_4 cla1(.in1(in1[3:0]), .in2(in2[3:0]), .cin(cin), .out(out[3:0]), .cout(c1));
    carry_look_ahead_4 cla2(.in1(in1[7:4]), .in2(in2[7:4]), .cin(c1), .out(out[7:4]), .cout(cout));
   
endmodule

module SUBTRACT8(input [7:0] in1, input [7:0] in2, output [7:0] out);
    wire [7:0] t;
    NOT8 getNot(.in1(in2), .out(t));
    wire [7:0] t1;
    assign t1 =1;
    wire [7:0] out1;
    ADD8 getAdd(.in1(t), .in2(t1), .out(out1));
    ADD8 getAdd2 (.in1(out1), .in2(in1), .out(out));
endmodule




module TOP_MODULE(input [7:0] in1,input [7:0] in2,output reg [7:0] result, input [2:0]func );

    wire [7:0] outputADD;
    wire [7:0] outputSUB;
    wire [7:0] outputRSHIFT;
    wire [7:0] outputLSHIFT;
    wire [7:0] outputAND; 
    wire [7:0] outputIDENTITY;
    wire [7:0] outputOR;
    wire [7:0] outputNOT;
    wire cout;
    NOT8 not8(.in1(in1), .out(outputNOT));
    ADD8 add8(.in1(in1), .in2(in2), .out(outputADD), .cout(cout));
    SHIFT_RIGHT shiftRight(.in1(in1), .out(outputRSHIFT));
    SHIFT_LEFT shiftLeft(.in1(in1), .out(outputLSHIFT));
    AND8 and8(.in1(in1), .in2(in2), .out(outputAND));
    IDENTITY8 identity8(.in1(in1), .out(outputIDENTITY));
    OR8 or8(.in1(in1), .in2(in2), .out(outputOR));
    SUBTRACT8 sub(.in1(in1), .in2(in2), .out(outputSUB));
        always @(in1 or in2 or func) begin
            case (func)
                3'd0: result <= outputADD;
                3'b001: result <= outputSUB;
                3'b010: result <= outputIDENTITY ;            
                3'b011: result <= outputLSHIFT;
                3'b100: result <= outputRSHIFT ;            
                3'b101: result <= outputAND;
                3'b110: result <= outputNOT;
                3'b111: result <= outputOR;
                default: result <=result;
            endcase
        end
endmodule