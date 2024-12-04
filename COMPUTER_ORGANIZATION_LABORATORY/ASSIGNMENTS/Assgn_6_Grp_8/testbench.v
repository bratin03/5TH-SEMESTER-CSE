`timescale 1ns / 1ps


module testbench;

    reg [7:0] in1;
    reg [7:0] in2;
    wire [7:0] result;
    reg [2:0] func;
    reg[7:0] temp_in1, temp_in2;
    reg clk,rst;
    TOP_MODULE uut (.in1(in1), .in2(in2), .result(result),.func(func));
    
    always@(posedge clk)
        begin
            if(rst)
                begin
                    in1<=8'd0;
                    in2<=8'd0;
                end
            else
                begin
                    in1<=temp_in1;
                    in2<=temp_in2;
                end
             
        end
    
    initial begin
        rst<=1'd1;
        clk<=1'd0;
    end
    
    always #10 clk=~clk;
    
    initial
        begin
        temp_in1 <= 8'd0;
        temp_in2 <= 8'd0;
        func <= 3'd0;
        #30 rst<=1'd0;
        temp_in1 <= 8'd24;
        temp_in2 <= 8'd16;
        func <= 3'd0;        
    end

endmodule
