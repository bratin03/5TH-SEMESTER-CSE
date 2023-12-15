`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11.09.2023 13:35:21
// Design Name: 
// Module Name: topmod_simp_dual
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


module topmod_simp_dual(input clk, input ena, input wea, input[3:0] addra, input[15:0] dina, input enb, input[3:0] addrb, output[15:0] doutb);

bram_simp_dual simp_dual (
  .clka(clk),    // input wire clka
  .ena(ena),      // input wire ena
  .wea(wea),      // input wire [0 : 0] wea
  .addra(addra),  // input wire [3 : 0] addra
  .dina(dina),    // input wire [15 : 0] dina
  .clkb(clk),    // input wire clkb
  .enb(enb),      // input wire enb
  .addrb(addrb),  // input wire [3 : 0] addrb
  .doutb(doutb)  // output wire [15 : 0] doutb
);


endmodule
