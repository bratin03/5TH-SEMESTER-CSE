`timescale 1ns / 1ps

module instruction_fetcher(
    input [31:0] pc,
    input clk,
    output [31:0] instr
    );

    instructions InstrROM (.clka(clk), .addra(pc[11:0]), .douta(instr));

endmodule