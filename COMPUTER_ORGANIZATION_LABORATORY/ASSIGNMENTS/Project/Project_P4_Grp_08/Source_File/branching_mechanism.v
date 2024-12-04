`timescale 1ns / 1ps

module branching_mechanism(
    input [31:0] pc_in,
	input [31:0] dest_addr,
	input [31:0] reg1,
	input branch_control_signal,
	input [5:0] ins_func_code,
	input [2:0] alu_flag,
	input rst,
	input clk,
    output reg [31:0] pc_out,
	output reg [31:0] ref
    );
	reg [2:0] old_flag;

	always @(posedge clk) begin
		if(rst)
			old_flag <= 3'b000;
		else
			old_flag <= alu_flag;
	end

	always @(*) begin
		ref <= pc_in+32'd1;
		if(rst)
			pc_out <= 32'd0;
		else begin 
			case(branch_control_signal)
				1'b0: pc_out <= pc_in+32'd1;
				1'b1:
				case(ins_func_code)
				6'b000100: pc_out <= pc_in+dest_addr;
				6'b000101: if(reg1[31]==1) begin 
					pc_out <= pc_in+dest_addr;
				end else begin
				pc_out <= pc_in+1;
				end
				6'b000110: if(reg1[31]!=1 && reg1!=32'b0) begin 
					pc_out <= pc_in+dest_addr;
				end else begin
				pc_out <= pc_in+1;
				end
				6'b000111: if(reg1==32'b0) begin 
					pc_out <= pc_in+dest_addr;
				end else begin
				pc_out <= pc_in+1;
				end
				endcase
			endcase
		end
	end
endmodule