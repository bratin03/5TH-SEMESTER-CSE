`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04.11.2022 13:01:47
// Design Name: 
// Module Name: test_div255
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


module test_div255;

reg[15:0] x;
reg clk;
reg rst;
wire[15:0] out;

div255 dut(x, clk, rst, out);

initial
    begin
        clk<=1'd0;
        rst<=1'd1;
    end

always #10 clk=~clk;

initial
    begin
        //x<=16'd47619;
        //x<=16'd13;
        //x<=16'd24760;
        //x<=16'd513;
        x<=16'd510;
        //x<=16'd13;
        
        #30 rst<=1'd0;
    end


endmodule
