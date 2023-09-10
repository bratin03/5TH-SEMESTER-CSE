`timescale 1ns / 1ps

module divide(
     input [15:0] x,
     output reg [15:0] quotient

    );
    reg [8:0] remainder;
    integer i;

always @(*) begin
    remainder = 0;
    quotient = 0;
    for (i = 15; i >= 0; i = i - 1) begin
        remainder = (remainder << 1) | (x[i]);
        if (remainder >= 255) begin
            remainder = remainder - 255;
            quotient = (quotient << 1) | 1'b1;
        end else begin
            quotient = (quotient << 1);
        end
    end
end

endmodule
