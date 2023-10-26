`timescale 1ns/1ps

module REG_BANK (
    input wire read,              // Input wire to control read operation
    input wire write,             // Input wire to control write operation
    input wire [2:0] portIN,      // Input port for specifying the register to write to
    input wire [2:0] portOUT1,    // Input port for specifying the first register to read from
    input wire [2:0] portOUT2,    // Input port for specifying the second register to read from
    input wire [31:0] writePort,  // Data to be written to the selected register
    output reg [31:0] readPort1,  // Output port for the data read from the first register
    output reg [31:0] readPort2,  // Output port for the data read from the second register
    input reset,
    input clk
);

    reg [31:0] registers [0:15]; // Array of registers to store data
    
    always @(posedge clk) begin
        if(reset == 1)begin
            registers[0] = 32'h00000001;  // Set register 0 to 2^0 = 1
            registers[1] = 32'h00000002;  // Set register 1 to 2^1 = 2
            registers[2] = 32'h00000004;  // Set register 2 to 2^2 = 4
            registers[3] = 32'h00000008;  // Set register 3 to 2^3 = 8
            registers[4] = 32'h00000010;  // Set register 4 to 2^4 = 16
            registers[5] = 32'h00000020;  // Set register 5 to 2^5 = 32
            registers[6] = 32'h00000040;  // Set register 6 to 2^6 = 64
            registers[7] = 32'h00000080;  // Set register 7 to 2^7 = 128
            registers[8] = 32'h00000100;  // Set register 8 to 2^8 = 256
            registers[9] = 32'h00000200;  // Set register 9 to 2^9 = 512
            registers[10] = 32'h00000400; // Set register 10 to 2^10 = 1024
            registers[11] = 32'h00000800; // Set register 11 to 2^11 = 2048
            registers[12] = 32'h00001000; // Set register 12 to 2^12 = 4096
            registers[13] = 32'h00002000; // Set register 13 to 2^13 = 8192
            registers[14] = 32'h00004000; // Set register 14 to 2^14 = 16384
            registers[15] = 32'h00008000; // Set register 15 to 2^15 = 32768
        end
        else begin 
            if(read == 1)
                registers[portIN] = writePort; // Write data to the selected register
            if (write == 1) begin
                readPort1 = registers[portOUT1]; // Read data from the first selected register
                readPort2 = registers[portOUT2]; // Read data from the second selected register
            end
        end
    end

endmodule
