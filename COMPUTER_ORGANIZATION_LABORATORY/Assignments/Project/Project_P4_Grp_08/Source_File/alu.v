`timescale 1ns / 1ps

module alu(
    input signed [31:0] input1,
    input signed [31:0] input2,
    input shamt,
    input [4:0] control,
    output reg [31:0] out,
    output reg [2:0] flags
    );

	wire shamt_muxout;

	assign shamt_muxout = control[4] ? input2[0] : shamt;
	
    always @(*) begin
		flags[0] = input1 == 32'b0 ? 1'b1 : 1'b0;
		flags[1] = input1[31] == 1'b1 ? 1'b1 : 1'b0;
        case(control[3:0])
            4'b0000: 
                begin
                    {flags[2], out} = input1 + input2;
                end
            4'b0001:
                begin
                    out = input1 - input2;
                    flags[2] = 1'b0;
                end
            4'b0010:
                begin
                    out = input1 & input2;
                    flags[2] = 1'b0;
                end
            4'b0011:
                begin
                    out = input1 | input2;
                    flags[2] = 1'b0;
                end                
            4'b0100:
                begin
                    out = input1 ^ input2;
                    flags[2] = 1'b0;
                end
            4'b0101:
                begin
                    out = ~input1;
                    flags[2] = 1'b0;
                end              
            4'b0110:
                begin
                    out = input1 << shamt_muxout;
                    flags[2] = 1'b0;
                end
            4'b0111:
                begin
                    out = input1 >> shamt_muxout;
                    flags[2] = 1'b0;
                end
            4'b1000:
                begin
                    out = input1 >>> shamt_muxout;
                    flags[2] = 1'b0;
                end
            default:
                begin
                    out = 32'b0;
                    flags[2] = 1'b0;
                end
        endcase
    end
endmodule