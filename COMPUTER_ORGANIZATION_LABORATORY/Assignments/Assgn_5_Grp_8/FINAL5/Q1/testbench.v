`timescale 1ns/1ps

module testbench;

reg [2:0] src_reg_num;      // Source Register Number
reg [2:0] dest_reg_num;     // Destination Register Number
reg move;                   // Control signal for moving a register's content to other
reg in;                     // Control signal for moving data from input port to destination register
reg clock;                  // Clock signal

reg [15:0] data_input;      // 16-bit input port 
wire [15:0] output_port;    // 16-bit output port
reg enabled;                // Enable signal. The Output port data is only available when enable = 1
reg res;                    // Control signal for reset 
// Creating an instance of the `register_file` module
register_file R1 (.enabled(enabled),
    .res(res), .src_reg_num(src_reg_num), .dest_reg_num(dest_reg_num), .move(move), .in(in), .data_input(data_input), .clock(clock), .output_port(output_port));    

initial begin
    res = 1;        // Reset set to 1 to initialize the registers to 0
    clock = 0;      // Initialize clock to 0
    enabled = 0;      // Initialize enabled to 0; so that output_port is zzzzzzzzzzzzzzzz
    // Initialize inputs
    #15             // Time delay of 15 units for reset to take effect
    res = 0;        // reset set to 0 to start the register file
    in = 1;         // Set in to 1 to move data_input to destination register
    data_input = 123;   // Set data_input to 123
    dest_reg_num = 3;   // Set destination register number to 3
    enabled=1;      // Set enabled to 1 to enable output_port
    #10             // Time delay of 10 units for the register file to move data_input to destination register
    $display("Output_port = %d, Data_input= %d", output_port, data_input);  // Display output_port and data_input
    src_reg_num=3;  // Set source register number to 3
    dest_reg_num=4; // Set destination register number to 4
    move=1;         // Set move to 1 to move the content of source register to destination register
    in=0;           // Set in to 0 to disable moving data_input to destination register
    #10;            // Time delay of 10 units for the register file to move the content of source register to destination register
    $display("Output_port = %d", output_port);      // Display output_port
    src_reg_num=4;  // Set source register number to 4
    dest_reg_num=6; // Set destination register number to 6
    move=1;         // Set move to 1 to move the content of source register to destination register
    in=0;           // Set in to 0 to disable moving data_input to destination register
    #10;            // Time delay of 10 units for the register file to move the content of source register to destination register
    $display("Output_port = %d", output_port);      // Display output_port
    move=0;         // Set move to 0 to disable moving the content of source register to destination register
    in=0;           // Set in to 0 to disable moving data_input to destination register
    enabled=0;      // Set enabled to 0 to disable output_port
    #10;            // Time delay of 10 units for the register file to move the content of source register to destination register
    $display("output_port = %d", output_port);      // Display output_port
    $finish;        // Finish the simulation
end

    always #5 clock = ~clock;
endmodule

