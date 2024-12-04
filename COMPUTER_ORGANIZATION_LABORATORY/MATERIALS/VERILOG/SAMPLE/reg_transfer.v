// This is a draft Verilog specification for register-to-register
// transfer with four 16-bit registers.

// Note: This code has not been tested for correctness.

// In the top-level module, “my_reg” has been instantiated four times,
// and “my_decoder” two times.

module my_reg (ld, en, d_in, d_out, clk)
  input ld, en, clk;
  input [15:0] d_in;
  output [15:0] d_out;
  reg [15:0] d_out, R;

  always @(posedge clk)
    begin
      if (ld)
	  R <= d_in;
	else if (en)
			d_out <= R;
	     else
			d_out <= 16’bz;
    end
endmodule


module my_decoder (inp, outp)    // A 2-to-4 decoder
  input [1:0] inp;
  output [3:0] outp;
  
  always (inp)
    case (inp)
      2’b00:  outp = 4’b0001;
	2’b01:  outp = 4’b0010;
	2’b10:  outp = 4’b0100;
	2’b11:  outp = 4’b1000;
    endcase
endmodule


module top_level (src, dest, MOVE, IN, clk )
  input [1:0] src, dest;
  input MOVE, IN;
  wire [3:0] enable, load;
  wire [15:0] data_in, data_out;

  assign data_in = data_out;

  my_decoder D1 (enable, src);
  my_decoder D2 (load, dest);
  my_reg R0 (load[0], enable[0], data_in, data_out, clk);
  my_reg R1 (load[1], enable[1], data_in, data_out, clk);
  my_reg R2 (load[2], enable[2], data_in, data_out, clk);
  my_reg R3 (load[3], enable[3], data_in, data_out, clk);

endmodule