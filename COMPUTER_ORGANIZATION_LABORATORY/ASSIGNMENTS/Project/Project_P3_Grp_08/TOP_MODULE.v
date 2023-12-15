module topModule(
    input read,                   // Control signal for reading from registers
    input write,                  // Control signal for writing to registers
    input [2:0] rd,               // Destination register address
    input [2:0] rs,               // Source register address
    input [2:0] rt,               // Target register address
    input [3:0] opcode,           // ALU operation code
    input dispBit,                // Display bit selection
    input rst,                    // Reset Signal
    output reg [15:0] disp,       // Output display value
    input clk                     // Clock Signal
);
    wire [31:0] result;           // ALU result
    wire [31:0] read1;            // Data read from source register
    wire [31:0] read2;            // Data read from target register
    
    // Instantiate the Register Bank (REG_BANK)
    REG_BANK reg_bank(
        .read(read),            // Connect the read control signal
        .write(write),          // Connect the write control signal
        .portIN(rd),            // Connect the destination register address
        .portOUT1(rs),          // Connect the source register address 1
        .portOUT2(rt),          // Connect the source register address 2
        .writePort(result),     // Connect the write data to the result
        .readPort1(read1),      // Connect data read from source register 1
        .readPort2(read2),      // Connect data read from target register 2
        .reset(rst),            // Connect the reset signal
        .clk(clk)               // Connect the clock signal
    );
    
    reg shamt;                    // Shift amount for ALU
    ALU alu(
        .opcode(opcode),            // Connect ALU operation code
        .A(read1),                  // Connect source operand A
        .B(read2),                  // Connect source operand B
        .shift_amount(shamt),       // Connect shift amount
        .ALU_result(result)         // Connect ALU result
    );
    
    always @(*)begin
        if(rst == 1)begin
            shamt = 1;
        end
    end
    always @(*) begin
        if (dispBit == 0) begin
            disp = result[15:0];    // Display lower 16 bits of the ALU result
        end else begin
            disp = result[31:16];   // Display upper 16 bits of the ALU result
        end
    end
endmodule
