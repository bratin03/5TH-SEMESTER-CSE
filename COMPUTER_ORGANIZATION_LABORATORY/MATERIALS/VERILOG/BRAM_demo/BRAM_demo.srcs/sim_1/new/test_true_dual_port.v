`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11.09.2023 14:11:44
// Design Name: 
// Module Name: test_true_dual_port
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


module test_true_dual_port;

reg clk, ena, wea, web, enb; 
reg[3:0] addra, addrb;
reg[15:0] dina, dinb;
wire[15:0] douta, doutb;

topmod_dual_port uut(
  .clk(clk),    // input wire clka
  .ena(ena),      // input wire ena
  .wea(wea),      // input wire [0 : 0] wea
  .addra(addra),  // input wire [3 : 0] addra
  .dina(dina),    // input wire [15 : 0] dina
  .douta(douta),  // output wire [15 : 0] douta
  .enb(enb),      // input wire enb
  .web(web),      // input wire [0 : 0] web
  .addrb(addrb),  // input wire [3 : 0] addrb
  .dinb(dinb),    // input wire [15 : 0] dinb
  .doutb(doutb)  // output wire [15 : 0] doutb
);

initial
    begin
        clk<=1'd0;
    end

always #10 clk=~clk;

initial
    begin
        ena <= 1'b1;
        wea <= 1'b0;
        web <= 1'b0;
        addra <= 4'd1;
        dina <= 16'd11;
        dinb <= 16'd24;
        enb <= 1'b1;
        addrb <= 4'd2;
        #10
        
        ena <= 1'b1;
        wea <= 1'b0;
        web <= 1'b1;
        addra <= 4'd1;
        dina <= 16'd11;
        dinb <= 16'd24;
        enb <= 1'b1;
        addrb <= 4'd2;  
               
    end

endmodule