`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 14.09.2022 15:43:20
// Design Name: 
// Module Name: counter
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


module counter(s, clk, rst
    );
	 
	 input clk, rst;
	 output [3:0] s;
	 reg [3:0] s;
	 reg [25:0] counter;
	 wire clkslow;
	 
	 always@(posedge clk or posedge rst)
	 begin
	   if(rst) counter <= 0;
	   else counter <= counter + 1;	
	 end
	   
		assign clkslow = counter[25];
	 
	 always @(posedge clkslow or posedge rst)
	 begin
	   if(rst)
		  s <= 4'b0;
		else
        s <= s + 1;	
	 end


endmodule