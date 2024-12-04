`timescale 1ns / 1ps
module RISC_tb;

	reg clk;
	reg rst;

	wire [31:0] retReg;

	RISC uut (
		.clk(clk), 
		.rst(rst),
		.retReg(retReg)
	);
	
	always #2 clk = ~clk;
	
	initial begin

		$monitor("Return value: ", $signed(retReg));

		clk = 0;
		rst = 1;

		#10;
        
		rst = 0;

	end
      
endmodule
