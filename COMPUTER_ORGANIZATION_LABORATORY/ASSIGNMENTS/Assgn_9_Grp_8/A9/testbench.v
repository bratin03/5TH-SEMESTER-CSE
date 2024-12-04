// Define the time scale for the testbench
`timescale 1ns / 1ps

// Define the testbench module
module tb();

    // Declare testbench inputs
    reg [1:0] opcode;
    reg [3:0] data_in;
    reg [3:0] address;
    reg [2:0] regNo;
    reg clka;

    // Declare testbench output
    wire [3:0] result;

    // Instantiate the 'reg2mem' module under test (UUT)
    reg2mem uut(opcode, data_in, address, regNo, clka, result);

    // Generate a clock signal with a 10ns period
    always #10 clka = ~clka;

    // Initial block for simulation setup
    initial 
    begin
        // Initialize inputs
        clka = 0;
        address = 7;
        opcode = 0;
        data_in = 5;

        // Wait for 40 time units
        #40;

        // Perform operation 1
        opcode = 2;
        address = 7;
        regNo = 1;

        // Wait for 50 time units
        #50;

        // Perform operation 2
        opcode = 1;
        regNo = 1;
        address = 2;

        // Wait for 50 time units
        #50;

        // Perform operation 3
        opcode = 3;
        address = 2;

        // Wait for 50 time units
        #50;

        // Display the result
        $display("Output is %d\n", result);

        // Wait for 50 time units
        #50;

        // Finish the simulation
        $finish;
    end
endmodule
