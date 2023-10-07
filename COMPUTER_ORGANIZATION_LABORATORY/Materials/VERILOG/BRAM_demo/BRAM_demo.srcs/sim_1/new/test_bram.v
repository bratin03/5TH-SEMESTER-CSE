`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11.09.2023 12:50:01
// Design Name: 
// Module Name: test_bram
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


module test_bram;
    
// Inputs
	reg clk;
	reg ena;
	reg wea;
	reg [3:0] addra;
	reg [15:0] dina;

	// Outputs
	wire [15:0] douta;

	// Instantiate the Unit Under Test (UUT)
	topmod uut (
		.clka(clk), 
		.ena(ena), 
		.wea(wea), 
		.addra(addra), 
		.dina(dina), 
		.douta(douta)
	);

	initial 
		begin
			clk <= 0;
		end
	always #10 clk=~clk;

	initial 
		begin
			ena <= 1'b1;
			wea <= 1'b0;
			addra <= 4'd1;
			dina <= 16'd24;
			#70
			wea <= 1'b1;
			addra <= 4'd10;
			dina <= 16'd333;
		end
      
endmodule
