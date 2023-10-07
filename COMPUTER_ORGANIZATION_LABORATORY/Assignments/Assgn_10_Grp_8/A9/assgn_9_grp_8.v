// Define the time scale for the module
`timescale 1ns / 1ps

// Declare the 'reg2mem' module with its inputs and outputs
module reg2mem(
    input [1:0] opcode,         // 2-bit opcode input
    input [3:0] data_in,        // 4-bit data input
    input [3:0] address,        // 4-bit address input
    input [2:0] regNo,          // 3-bit register number input
    input clka,                 // Clock input
    output reg [3:0] result    // 4-bit result output
);

    // Declare a wire 'ena'
    wire ena;

    // Declare two registers 'wea' and 'addra'
    reg wea;
    reg [3:0] addra;

    // Declare a register 'dina'
    reg [3:0] dina;

    // Declare a wire 'douta'
    wire [3:0] douta;

    // Assign 'ena' to be always 1
    assign ena = 1;

    // Instantiate a block memory generator 'memBlock'
    blk_mem_gen_0 memBlock (
        .clka(clka),    // Connect 'clka' input
        .ena(ena),      // Connect 'ena' input
        .wea(wea),      // Connect 'wea' input
        .addra(addra),  // Connect 'addra' input
        .dina(dina),    // Connect 'dina' input
        .douta(douta)   // Connect 'douta' output
    );

    // Declare an array of 8 registers 'regBank'
    reg [3:0] regBank[7:0];

    // Define an always block sensitive to the positive edge of 'clka'
    always @(posedge clka) begin
        // Use a case statement to select behavior based on 'opcode'
        case(opcode)
            0: begin
                // When 'opcode' is '00', write operation
                wea = 1;
                dina = data_in;
                addra = address;
            end
            1: begin
                // When 'opcode' is '01', read operation from 'regBank' and save in memory
                wea = 1;
                dina = regBank[regNo];
                addra = address;
            end 
            2: begin
                // When 'opcode' is '10', write operation to 'regBank' from memory
                wea = 0;
                addra = address; 
                regBank[regNo] = douta;
            end
            3: begin
                // When 'opcode' is '11', read operation from memory and assign to 'result'
                wea = 0;
                addra = address;
                result = douta;
            end
            default: begin
                // Default case, set 'wea' to 0
                wea = 0;
            end
        endcase
    end
endmodule
