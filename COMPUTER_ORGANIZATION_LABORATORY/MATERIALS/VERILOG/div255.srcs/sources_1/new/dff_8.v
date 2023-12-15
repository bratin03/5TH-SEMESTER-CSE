`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04.11.2022 14:13:21
// Design Name: 
// Module Name: dff_8
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


module dff_8(input[7:0] in, input clk, input rst, output reg[7:0] out);

always @(posedge clk)
    begin
        if(rst)
            begin
                out<=8'd0;         
            end
        else
            begin
                out<=in;
            end
    end
    
endmodule
