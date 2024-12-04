`timescale 1ns/1ps

module ALU_tb;

    reg [3:0] opcode;                      // Input: ALU operation code
    reg signed [31:0] A;                  // Input: Operand A
    reg signed [31:0] B;                  // Input: Operand B
    reg shift_amount;                     // Input: Shift amount
    wire signed [31:0] ALU_result;        // Output: ALU result

    // Instantiate the ALU module
    ALU ALU_inst (
        .opcode(opcode),
        .A(A),
        .B(B),
        .shift_amount(shift_amount),
        .ALU_result(ALU_result)
    );

    // Initial values for inputs
    initial begin
        // Start the simulation
        $display("Starting the ALU Testbench");
        $display("");

        // Test ADD operation
        $display("Starting Test: ADD operation");
        opcode = 4'b0000;                 // Set operation code to ADD
        A = 10;                           // Set operand A
        B = 5;                            // Set operand B
        shift_amount = 0;                 // Set shift amount to 0
        #10;                              // Wait for 10 time units
        if (ALU_result != 15) begin
            $display("ADD operation failed");
            // Display details of the failed test case
            $display("A         = %d (Decimal) = %b (Binary)", A, A);
            $display("B         = %d (Decimal) = %b (Binary)", B, B);
            $display("Expected  = %d (Decimal) = %b (Binary)", 15, 15);
            $display("Actual    = %d (Decimal) = %b (Binary)", ALU_result, ALU_result);
        end else begin
            $display("ADD operation passed");
            // Display details of the passed test case
            $display("A         = %d (Decimal) = %b (Binary)", A, A);
            $display("B         = %d (Decimal) = %b (Binary)", B, B);
            $display("Result    = %d (Decimal) = %b (Binary)", ALU_result, ALU_result);
        end
        $display("Ending Test: ADD operation");
        $display(""); // Newline

        // Test SUB operation
        $display("Starting Test: SUB operation");
        opcode = 4'b0001;                 // Set operation code to SUB
        A = 10;                           // Set operand A
        B = 5;                            // Set operand B
        shift_amount = 0;                 // Set shift amount to 0
        #10;                              // Wait for 10 time units
        if (ALU_result != 5) begin
            $display("SUB operation failed");
            // Display details of the failed test case
            $display("A         = %d (Decimal) = %b (Binary)", A, A);
            $display("B         = %d (Decimal) = %b (Binary)", B, B);
            $display("Expected  = %d (Decimal) = %b (Binary)", 5, 5);
            $display("Actual    = %d (Decimal) = %b (Binary)", ALU_result, ALU_result);
        end else begin
            $display("SUB operation passed");
            // Display details of the passed test case
            $display("A         = %d (Decimal) = %b (Binary)", A, A);
            $display("B         = %d (Decimal) = %b (Binary)", B, B);
            $display("Result    = %d (Decimal) = %b (Binary)", ALU_result, ALU_result);
        end
        $display("Ending Test: SUB operation");
        $display(""); // Newline

        // Test AND operation
        $display("Starting Test: AND operation");
        opcode = 4'b0010;                 // Set operation code to AND
        A = 65535;                        // Set operand A
        B = 4294901760;                   // Set operand B
        shift_amount = 0;                 // Set shift amount to 0
        #10;                              // Wait for 10 time units
        if (ALU_result != 0) begin
            $display("AND operation failed");
            // Display details of the failed test case
            $display("A         = %d (Decimal) = %b (Binary)", A, A);
            $display("B         = %d (Decimal) = %b (Binary)", B, B);
            $display("Expected  = %d (Decimal) = %b (Binary)", 0, 0);
            $display("Actual    = %d (Decimal) = %b (Binary)", ALU_result, ALU_result);
        end else begin
            $display("AND operation passed");
            // Display details of the passed test case
            $display("A         = %d (Decimal) = %b (Binary)", A, A);
            $display("B         = %d (Decimal) = %b (Binary)", B, B);
            $display("Result    = %d (Decimal) = %b (Binary)", ALU_result, ALU_result);
        end
        $display("Ending Test: AND operation");
        $display(""); // Newline

        // Test OR operation
        $display("Starting Test: OR operation");
        opcode = 4'b0011;                 // Set operation code to OR
        A = -11;                          // Set operand A
        B = 12;                           // Set operand B
        shift_amount = 0;                 // Set shift amount to 0
        #10;                              // Wait for 10 time units
        if (ALU_result != -3) begin
            $display("OR operation failed");
            // Display details of the failed test case
            $display("A         = %d (Decimal) = %b (Binary)", A, A);
            $display("B         = %d (Decimal) = %b (Binary)", B, B);
            $display("Expected  = %d (Decimal) = %b (Binary)", -3, -3);
            $display("Actual    = %d (Decimal) = %b (Binary)", ALU_result, ALU_result);
        end else begin
            $display("OR operation passed");
            // Display details of the passed test case
            $display("A         = %d (Decimal) = %b (Binary)", A, A);
            $display("B         = %d (Decimal) = %b (Binary)", B, B);
            $display("Result    = %d (Decimal) = %b (Binary)", ALU_result, ALU_result);
        end
        $display("Ending Test: OR operation");
        $display(""); // Newline

        // Test XOR operation
        $display("Starting Test: XOR operation");
        opcode = 4'b0100;                 // Set operation code to XOR
        A = 12;                           // Set operand A
        B = 15;                           // Set operand B
        shift_amount = 0;                 // Set shift amount to 0
        #10;                              // Wait for 10 time units
        if (ALU_result != 3) begin
            $display("XOR operation failed");
            // Display details of the failed test case
            $display("A         = %d (Decimal) = %b (Binary)", A, A);
            $display("B         = %d (Decimal) = %b (Binary)", B, B);
            $display("Expected  = %d (Decimal) = %b (Binary)", 3, 3);
            $display("Actual    = %d (Decimal) = %b (Binary)", ALU_result, ALU_result);
        end else begin
            $display("XOR operation passed");
            // Display details of the passed test case
            $display("A         = %d (Decimal) = %b (Binary)", A, A);
            $display("B         = %d (Decimal) = %b (Binary)", B, B);
            $display("Result    = %d (Decimal) = %b (Binary)", ALU_result, ALU_result);
        end
        $display("Ending Test: XOR operation");
        $display(""); // Newline

        // Test NOT operation
        $display("Starting Test: NOT operation");
        opcode = 4'b0101;                 // Set operation code to NOT
        A = 65535;                        // Set operand A
        B = 0;                            // Set operand B
        shift_amount = 0;                 // Set shift amount to 0
        #10;                              // Wait for 10 time units
        if (ALU_result != -65536) begin
            $display("NOT operation failed");
            // Display details of the failed test case
            $display("A         = %d (Decimal) = %b (Binary)", A, A);
            $display("B         = %d (Decimal) = %b (Binary)", B, B);
            $display("Expected  = %d (Decimal) = %b (Binary)", -65536, -65536);
            $display("Actual    = %d (Decimal) = %b (Binary)", ALU_result, ALU_result);
        end else begin
            $display("NOT operation passed");
            // Display details of the passed test case
            $display("A         = %d (Decimal) = %b (Binary)", A, A);
            $display("B         = %d (Decimal) = %b (Binary)", B, B);
            $display("Result    = %d (Decimal) = %b (Binary)", ALU_result, ALU_result);
        end
        $display("Ending Test: NOT operation");
        $display(""); // Newline

        // Test SLA operation
        $display("Starting Test: SLA operation");
        opcode = 4'b0110;                 // Set operation code to SLA
        A = 15;                           // Set operand A
        B = 0;                            // Set operand B
        shift_amount = 1;                 // Set shift amount to 1
        #10;                              // Wait for 10 time units
        if (ALU_result != 30) begin
            $display("SLA operation failed");
            // Display details of the failed test case
            $display("A         = %d (Decimal) = %b (Binary)", A, A);
            $display("B         = %d (Decimal) = %b (Binary)", B, B);
            $display("Expected  = %d (Decimal) = %b (Binary)", 30, 30);
            $display("Actual    = %d (Decimal) = %b (Binary)", ALU_result, ALU_result);
        end else begin
            $display("SLA operation passed");
            // Display details of the passed test case
            $display("A         = %d (Decimal) = %b (Binary)", A, A);
            $display("B         = %d (Decimal) = %b (Binary)", B, B);
            $display("Result    = %d (Decimal) = %b (Binary)", ALU_result, ALU_result);
        end
        $display("Ending Test: SLA operation");
        $display(""); // Newline

        // Test SRA operation
        $display("Starting Test: SRA operation");
        opcode = 4'b0111;                 // Set operation code to SRA
        A = -65536;                       // Set operand A (negative number)
        B = 0;                            // Set operand B
        shift_amount = 1;                 // Set shift amount to 1
        #10;                              // Wait for 10 time units
        if (ALU_result != 2147450880) begin
            $display("SRA operation failed");
            // Display details of the failed test case
            $display("A         = %d (Decimal) = %b (Binary)", A, A);
            $display("B         = %d (Decimal) = %b (Binary)", B, B);
            $display("Expected  = %d (Decimal) = %b (Binary)", 2147450880, 2147450880);
            $display("Actual    = %d (Decimal) = %b (Binary)", ALU_result, ALU_result);
        end else begin
            $display("SRA operation passed");
            // Display details of the passed test case
            $display("A         = %d (Decimal) = %b (Binary)", A, A);
            $display("B         = %d (Decimal) = %b (Binary)", B, B);
            $display("Result    = %d (Decimal) = %b (Binary)", ALU_result, ALU_result);
        end
        $display("Ending Test: SRA operation");
        $display(""); // Newline

        // Test SRL operation
        $display("Starting Test: SRL operation");
        opcode = 4'b1000;                 // Set operation code to SRL
        A = -65536;                       // Set operand A (negative number)
        B = 0;                            // Set operand B
        shift_amount = 1;                 // Set shift amount to 1
        #10;                              // Wait for 10 time units
        if (ALU_result != -32768) begin
            $display("SRL operation failed");
            // Display details of the failed test case
            $display("A         = %d (Decimal) = %b (Binary)", A, A);
            $display("B         = %d (Decimal) = %b (Binary)", B, B);
            $display("Expected  = %d (Decimal) = %b (Binary)", -32768, -32768);
            $display("Actual    = %d (Decimal) = %b (Binary)", ALU_result, ALU_result);
        end else begin
            $display("SRL operation passed");
            // Display details of the passed test case
            $display("A         = %d (Decimal) = %b (Binary)", A, A);
            $display("B         = %d (Decimal) = %b (Binary)", B, B);
            $display("Result    = %d (Decimal) = %b (Binary)", ALU_result, ALU_result);
        end
       
        $display(""); // Newline
        // Finish simulation
        $display("Ending the ALU Testbench");
        $finish;
    end

endmodule

