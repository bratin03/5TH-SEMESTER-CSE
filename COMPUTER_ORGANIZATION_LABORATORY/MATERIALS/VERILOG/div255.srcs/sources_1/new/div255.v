`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04.11.2022 10:43:19
// Design Name: 
// Module Name: div255
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


module div255(input[15:0] x, input clk, input rst, output[15:0] out);

wire cout;
wire cin;
wire[31:0] y;
wire[31:0] x_comp;
wire[7:0] add_1,add_2;
wire[7:0] add_out;
wire[7:0] add_in;
wire cout_in;
wire en;
wire[31:0] x_;

assign x_={16'd0,x};

assign x_comp = ~x_ + 32'd1;

assign out=y[15:0];

adder add(.a(add_1),.b(add_2),.cin(cin),.sum(add_out),.cout(cout));

wire indicator;

or mod_gate(indicator, add_out[7],add_out[6],add_out[5],add_out[4],add_out[3],add_out[2],add_out[1]);

control_unit control_mod(clk, rst, indicator, x_comp, add_in, cout_in, add_1, add_2, cin,en);

shifter_mod shift(add_out, clk, en, rst, y);

dff_8 dff_8_mod(add_out, clk, rst, add_in);

dff_1 dff_1_mod(cout, clk, rst, cout_in);

endmodule
