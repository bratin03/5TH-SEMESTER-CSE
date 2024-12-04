`timescale 1ns / 1ps

module mem_reg_pc_selector(
    input [1:0] mem_reg_pc,
    input [31:0] mem_in,
    input [31:0] reg_in,
    input [31:0] pc_in,
    output reg [31:0] write_data
    );
	
	always @(*) begin
		case(mem_reg_pc)
			2'b01:
				begin
					write_data <= mem_in;
				end
			2'b10:
				begin
					write_data <= pc_in;
				end
			default:
				begin
					write_data <= reg_in;
				end
		endcase
	end

endmodule