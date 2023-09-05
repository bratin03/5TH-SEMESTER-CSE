// Define timescale for simulation accuracy
`timescale 1ns / 1ps

// Define the testbench module
module tb_bsa;
    // Inputs for the testbench
    reg signed [7:0] num1, num2;   // Input numbers
    reg clk = 1'b1;                 // Clock signal
    reg reset = 1'b0;               // Reset signal
    reg load = 1'b0;                // Load signal for the multiplier module

    // Output for the testbench
    wire signed [15:0] out;         // Output of the multiplier module

    // Generate a clock signal with a period of 4 time units
    always #4 clk = ~clk;

    // Instantiate the Booth multiplier module (uut: Unit Under Test)
    booth_mult uut (
        .multiplier(num1),
        .multiplicand(num2),
        .clk(clk),
        .reset(reset),
        .load(load),
        .result(out)
    );

    // Initial block for simulation setup
    initial begin
        // Display simulation time, input values, and product
        $monitor($time, "\t num1 = %d, num2 = %d \t product = %d", num1, num2, out);
        
        // Set initial conditions
        reset = 1'b1;
        num1 = 8'b11010101;
        num2 = 8'b11110101;

        // Wait for some time
        #80

        // Release reset and set load
        reset = 1'b0;
        load = 1'b1;

        // Wait for some time
        #80

        // Release load
        load = 1'b0;

        // Wait for a longer time
        #640

        // Finish the simulation
        $finish;
    end

endmodule
