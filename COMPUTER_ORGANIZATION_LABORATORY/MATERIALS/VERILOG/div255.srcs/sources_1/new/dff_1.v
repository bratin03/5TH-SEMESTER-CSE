`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04.11.2022 14:13:08
// Design Name: 
// Module Name: dff_1
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


module dff_1(input in, input clk, input rst, output reg out);

always @(posedge clk)
    begin
        if(rst)
            begin
                out<=1'd0;         
            end
        else
            begin
                out<=in;
            end
    end
    
endmodule
