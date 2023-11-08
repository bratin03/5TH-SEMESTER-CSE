`timescale 1ns / 1ps

module data_memory(
    input [31:0] address,
    input clk,
    input enable,
    input write_enable,
    input [31:0] write_data,
    output [31:0] data_out
    );
	wire [11:0]addr;
    assign addr = address[11:0];
	datastore DataRAM (.clka(~clk), .ena(enable), .wea(write_enable), .addra(addr), .dina(write_data), .douta(data_out));

endmodule