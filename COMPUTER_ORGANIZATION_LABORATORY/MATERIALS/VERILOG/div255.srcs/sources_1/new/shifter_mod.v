`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04.11.2022 12:48:49
// Design Name: 
// Module Name: shifter_mod
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module shifter_mod(input[7:0] in, input clk, input en, input rst, output reg [31:0] out);

always@(posedge clk)
    begin
        if(rst)
            out<=32'd0;
        else if(en==1)
            begin
                out[23:0]=out[31:8];
                out[31:24]=in;
            end
        else
            begin
                out<=out;
            end
    end
    
endmodule
