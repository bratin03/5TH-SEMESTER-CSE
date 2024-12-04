`timescale 1ns/1ps       // Set the timescale for simulation accuracy

module GCD_Test;         // Define the GCD_Test module
    reg rst;             // Declare a reset signal
    reg clk;             // Declare a clock signal
    reg [7:0] A;         // Declare an 8-bit input A
    reg [7:0] B;         // Declare an 8-bit input B
    wire [7:0] result;   // Declare an 8-bit wire for the result

    GCD uut (             // Instantiate the GCD module (unit under test)
        .rst(rst),        // Connect the rst input of GCD with rst signal
        .clk(clk),        // Connect the clk input of GCD with clk signal
        .A(A),            // Connect the A input of GCD with A signal
        .B(B),            // Connect the B input of GCD with B signal
        .result(result)   // Connect the result output of GCD with result wire
    );

    initial begin
        clk = 0;          // Initialize clock signal to low
        rst = 1;          // Assert the reset signal
        A = 120;          // Assign value 120 to input A
        B = 165;          // Assign value 165 to input B
        #15;              // Wait for a few time units (adjust as needed)

        rst = 0;          // De-assert the reset signal
        #10;              // Wait for a few time units (adjust as needed)
        
        #5000;            // Wait for GCD computation to complete (adjust as needed)
        $display("GCD of %d and %d is %d", A, B, result); // Display the result
        $finish;          // Finish the simulation

    end

    always #5 clk = ~clk; // Toggle the clock signal every 5 time units

endmodule
