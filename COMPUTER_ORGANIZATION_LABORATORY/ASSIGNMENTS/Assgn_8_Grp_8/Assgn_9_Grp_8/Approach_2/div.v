`timescale 1ns / 1ps

module leftshift(
    input [31:0] Y,
    output reg [31:0] res,
    input clk
    );
   
    always @(posedge clk)
    begin
        res = Y << 8;
    end
   
endmodule //leftshift_8



module div(
        input [15:0] X,
        input rst,
        output reg [15:0] Y,
        input clk
    );
    reg [31:0] temp;
    reg [31:0] Y2;
    wire [31:0] out1;
    reg [3:0] count;
    reg [15:0] r = 0;
    reg rst2=0;
    reg [7:0]r1;
    reg [7:0]r2;
    reg [7:0]r3;
    reg [7:0]r4;
    reg [7:0]r5;
    reg [7:0] r1_;
    reg [7:0] r2_;
    reg [7:0] r3_;
    reg [7:0] r4_;
    reg [7:0] r5_;
    reg [7:0] r6_;
    reg [7:0] r7_;
    leftshift_8 shifter(
        .Y(Y2),
        .res(out1),
        .clk(clk)
    );
    always @(posedge clk)
    begin
        if(rst | rst2) begin
            Y2 = 255;
            temp[31:16] = 0;
            temp[15:0] = X - r;
            r1=temp[31:24];
            r2=temp[23:16];
            r3=temp[15:8];
            r4=temp[7:0];
            r5=(r1^r2);
            r5=(r5^r3);
            r5=(r5^r4);
            r1_=(r1&r2);
            r2_=(r1&r3);
            r3_=(r1&r4);
            r4_=(r3&r2);
            r5_=(r4&r2);
            r6_=(r3&r4);
            r7_ = (r1_|r2_|r3_|r4_|r5_|r6_);
 
            count=0;
            rst2=0;
            if( r5!=255 | r7_!=0 )begin
                rst2=1;
                r=r+1;
            end
        end
        else begin
            Y2 = out1;
            Y2 = Y2 - temp;
            count = count+1;
            if( count == 4)begin
            Y[15:0]=Y2[15:0];
            count=0;
            end
            else if(count == 4)begin
            r=r+1;
            rst2 = 1;
            count=0;
            end
        end
    end
   
endmodule
