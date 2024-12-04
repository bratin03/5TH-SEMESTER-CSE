`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04.11.2022 09:20:38
// Design Name: 
// Module Name: adder
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


module adder(input[7:0] a, input[7:0] b, input cin, output[7:0] sum, output cout);

wire[8:0] sum_out;
assign sum_out = a + b + cin;
assign sum=sum_out[7:0];
assign cout=sum_out[8];
endmodule
