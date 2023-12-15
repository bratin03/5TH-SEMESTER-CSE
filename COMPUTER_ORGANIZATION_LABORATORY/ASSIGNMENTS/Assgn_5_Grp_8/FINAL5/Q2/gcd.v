`timescale 1ns/1ps  // Set the timescale for simulation accuracy

module GCD (
    input wire rst,           // Reset signal
    input wire clk,           // Clock signal
    input [7:0] A,            // Input A (8-bit number)
    input [7:0] B,            // Input B (8-bit number)
    output reg [7:0] result   // Output for the computed GCD
);
    reg [7:0] reg_A;           // Register to hold value of A
    reg [7:0] reg_B;           // Register to hold value of B
    reg [7:0] reg_result;      // Register to hold intermediate GCD result
  
    always @(posedge clk) begin
        if (rst) begin
            // On reset, initialize registers
            reg_A <= A;          // Initialize reg_A with A
            reg_B <= B;          // Initialize reg_B with B
            reg_result <= 8'b0;  // Initialize intermediate result with 0
            result <= 8'b0;      // Initialize final result with 0
        end else begin
            if (reg_A == 8'b0) begin
                // GCD computation done, assign reg_B to result
                reg_result <= reg_B;
                result <= reg_result;
            end else if (reg_B == 8'b0) begin
                // GCD computation done, assign reg_A to result
                reg_result <= reg_A;
                result <= reg_result;
            end else begin
                // GCD computation iteration
                if (reg_A > reg_B)
                    reg_A <= reg_A - reg_B;
                else
                    reg_B <= reg_B - reg_A;
            end
        end
    end
endmodule
