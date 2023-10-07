`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11.09.2023 12:06:44
// Design Name: 
// Module Name: topmod
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


module topmod(input clka, input ena, input wea, input[3:0] addra, input[15:0] dina, input[15:0] douta);
    
bram_mod single_port_bram(
  .clka(clka),    
  .ena(ena),      
  .wea(wea),      
  .addra(addra),  
  .dina(dina),    
  .douta(douta)  
);


endmodule
