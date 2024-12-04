`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11.09.2023 13:40:03
// Design Name: 
// Module Name: test_simp_dual
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


module test_simp_dual;

reg clk, ena, wea, enb; 
reg[3:0] addra, addrb;
reg[15:0] dina;
wire[15:0] doutb;

topmod_simp_dual uut(
  .clk(clk),      // input wire clk
  .ena(ena),      // input wire ena
  .wea(wea),      // input wire [0 : 0] wea
  .addra(addra),  // input wire [3 : 0] addra
  .dina(dina),    // input wire [15 : 0] dina
  .enb(enb),      // input wire enb
  .addrb(addrb),  // input wire [3 : 0] addrb
  .doutb(doutb));  // output wire [15 : 0] doutb

initial
    begin
        clk<=1'd0;
    end

always #10 clk=~clk;

initial
    begin
        ena <= 1'b1;
        wea <= 1'b0;
        addra <= 4'd1;
        dina <= 16'd1;
        enb <= 1'b1;
        addrb <= 4'd2;
        #10
        
        ena <= 1'b1;
        wea <= 1'b1;
        addra <= 4'd2;
        dina <= 16'd0;
        enb <= 1'b1;
        addrb <= 4'd4;  
               
    end

endmodule
