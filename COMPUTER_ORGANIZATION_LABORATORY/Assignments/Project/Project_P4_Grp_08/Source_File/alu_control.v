`timescale 1ns / 1ps

module alu_control(
    input [4:0] alu_op,
    input [5:0] func_code,
    output reg [4:0] alu_control_signal
    );

    always @(*) begin
        case(alu_op)
            5'b00001:
                begin
                    case(func_code)
                        6'b000000: alu_control_signal <= 5'b00000;
                        6'b000001: alu_control_signal <= 5'b00001;
                        default: alu_control_signal <= 5'b01111;
                    endcase
                end
            5'b00010:
                begin
                    case(func_code)
                        6'b000000: alu_control_signal <= 5'b00010;
                        6'b000001: alu_control_signal <= 5'b00011;
                        6'b000010: alu_control_signal <= 5'b00100;
                        6'b000011: alu_control_signal <= 5'b00101;
                        default: alu_control_signal <= 5'b01111;
                    endcase
                end
            5'b00011:
                begin
                    case(func_code)
                        6'b000000: alu_control_signal <= 5'b10110;
                        6'b000001: alu_control_signal <= 5'b10111;
                        6'b000010: alu_control_signal <= 5'b11000;
                        default: alu_control_signal <= 5'b01111;
                    endcase
                end
            5'b00101: alu_control_signal <= 5'b00000;
            5'b00110: alu_control_signal <= 5'b00001;
            5'b00111: alu_control_signal <= 5'b00010;
            5'b01000: alu_control_signal <= 5'b00011;
            5'b01001: alu_control_signal <= 5'b00100;
            5'b01010: alu_control_signal <= 5'b00110;
            5'b01011: alu_control_signal <= 5'b00111;
            5'b01100: alu_control_signal <= 5'b01000;
            5'b01101: alu_control_signal <= 5'b00000;
            default: alu_control_signal <= 5'b01111;
        endcase
    end

endmodule