`timescale 1ns / 1ps

module div_tb;
reg [15:0] X;
wire [15:0] Y;
reg rst, clk;

div div1(.X(X), .rst(rst), .Y(Y), .clk(clk));

initial begin
    clk = 0;
    rst = 1;
    X = 0;
    #20 rst = 0;
    #10 $display("The division of %d by 255 gives %d.",X,Y);
    #10 $display("The division of %d by 255 gives %d.",X,Y);
    #10 $display("The division of %d by 255 gives %d.",X,Y);
    #10 $display("The division of %d by 255 gives %d.",X,Y);
    #10 $display("The division of %d by 255 gives %d.",X,Y);
    #10 $display("The division of %d by 255 gives %d.",X,Y);
    #10 $display("The division of %d by 255 gives %d.",X,Y);
    #10 $display("The division of %d by 255 gives %d.",X,Y);
    #5000000 $display("The division of %d by 255 gives %d.",X,Y);

    #10 $finish;
end
always #5 clk = ~clk;

endmodule