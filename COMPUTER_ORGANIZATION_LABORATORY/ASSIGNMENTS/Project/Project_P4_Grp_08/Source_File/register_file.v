`timescale 1ns / 1ps

module register_file(
    input [4:0] reg1Addr,
    input [4:0] reg2Addr,
    input [4:0] regWriteAddr,
    input [1:0] writeReg,
    input [31:0] writeData,
    output [31:0] reg1Out,
    output [31:0] reg2Out,
    input clk,
    input rst,
	output [31:0] retReg 
    );

    reg [31:0] registers[16:0];

    always @(posedge clk) begin
        if(rst) begin
            registers[0] <= 0;
            registers[1] <= 0;
            registers[2] <= 0;
            registers[3] <= 0;
            registers[4] <= 0;
            registers[5] <= 0;
            registers[6] <= 0;
            registers[7] <= 0;
            registers[8] <= 0;
            registers[9] <= 0;
            registers[10] <= 0;
            registers[11] <= 0;
            registers[12] <= 0;
            registers[13] <= 0;
            registers[14] <= 0;
            registers[15] <= 0;
            registers[16] <= 1024;
        end else begin
            case(writeReg)
                2'b10:
                    begin
                        registers[regWriteAddr] <= writeData;
                    end 
                2'b11:
                    begin
                        registers[reg1Addr] <= writeData;
                    end
                2'b01:
                    begin
                        registers[reg2Addr] <= writeData;
                    end
                default:
                    begin
                        // do nothing
                    end 
            endcase
        end
    end

    assign reg1Out = registers[reg1Addr];
    assign reg2Out = registers[reg2Addr];
	assign retReg = registers[5'b00001];
endmodule