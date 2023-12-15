`timescale 1ns/1ps

// Module Name :    register_file
// Inputs :         enabled, res, src_reg_num, dest_reg_num, move, in, data_input, clock
// Outputs :        output_port
// Description :    This module implements a register file with 8 registers. The register file has 2 control signals, move and in. 
//                  When move is set to 1, the content of the source register is moved to the destination register. When in is set to 1, the 
//                  data_input is moved to the destination register. The register file has an enable signal, enabled. When enabled is set to 1, 
//                  the output_port is set to the content of the source register or the data_input depending on the control signals. When enabled 
//                  is set to 0, the output_port is set to zzzzzzzzzzzzzzzz.

module register_file (
    input wire enabled,
    input wire res,
    input wire [2:0] src_reg_num,
    input wire [2:0] dest_reg_num,
    input wire move,
    input wire in,
    input wire [15:0] data_input,
    input wire clock,
    output reg [15:0] output_port
);

    reg [15:0] registers [0:7];     // Declaring 8 registers of 16 bits each

    // Clock trigerred always block
    always @(posedge clock) begin
        // When the reset control is fed, the registers are initialized to 0
        if(res) begin
            registers[0] <= 0;
            registers[1] <= 0;
            registers[2] <= 0;
            registers[3] <= 0;
            registers[4] <= 0;
            registers[5] <= 0;
            registers[6] <= 0;
            registers[7] <= 0;
        end
        // When the move control is fed, the content of the source register is moved to the destination register
        if (in) begin
            registers[dest_reg_num] <= data_input;
        end
        // When the in control is fed, the data_input is moved to the destination register
        if (move) begin
            registers[dest_reg_num] <= registers[src_reg_num];
        end
        // When the enabled control is fed, the output_port is set to the content of the source register or the data_input depending on the control signals
        if(enabled == 1)begin
            if (move) begin
                output_port <= registers[src_reg_num];
            end
            // When in is set to 1, the data_input is moved to the destination register
            else
            if (in) begin
                output_port <= data_input;
            end
        end
        // When the enabled control is not fed, the output_port is set to zzzzzzzzzzzzzzzz
        if(enabled == 0)begin
            output_port <= 16'bzzzzzzzzzzzzzzzz;
        end
    end

endmodule
