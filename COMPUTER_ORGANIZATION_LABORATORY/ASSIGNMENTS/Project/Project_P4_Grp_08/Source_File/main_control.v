`timescale 1ns / 1ps

module main_control(
    input [5:0] opcode,
    output reg branch,
    output reg mem_read,
    output reg mem_write,
    output reg [1:0] mem_reg_pc,
    output reg [4:0] alu_op,
    output reg alu_source,
    output reg [1:0] write_reg
    );


    always @(*) begin
        case(opcode)
            6'b000001:
                begin
                    branch <= 1'b0;
                    mem_read <= 1'b0;
                    mem_write <= 1'b0;
                    mem_reg_pc <= 2'b00;
                    alu_op <= 5'b00001;
                    alu_source <= 1'b1;
                    write_reg <= 2'b10;
                end
            6'b000010:
                begin
                    branch <= 1'b0;
                    mem_read <= 1'b0;
                    mem_write <= 1'b0;
                    mem_reg_pc <= 2'b00;
                    alu_op <= 5'b00010;
                    alu_source <= 1'b1;
                    write_reg <= 2'b10;
                end
            6'b000011:
                begin
                    branch <= 1'b0;
                    mem_read <= 1'b0;
                    mem_write <= 1'b0;
                    mem_reg_pc <= 2'b00;
                    alu_op <= 5'b00011;
                    alu_source <= 1'b1;
                    write_reg <= 2'b11;
                end
            6'b000100:
                begin
                    branch <= 1'b1;
                    mem_read <= 1'b0;
                    mem_write <= 1'b0;
                    mem_reg_pc <= 2'b00;
                    alu_op <= 5'b00000;
                    alu_source <= 1'b1;
                    write_reg <= 2'b00;
                end
            6'b000101:
                begin
                    branch <= 1'b1;
                    mem_read <= 1'b0;
                    mem_write <= 1'b0;
                    mem_reg_pc <= 2'b00;
                    alu_op <= 5'b00000;
                    alu_source <= 1'b1;
                    write_reg <= 2'b00;
                end
            6'b000110:
                begin
                    branch <= 1'b1;
                    mem_read <= 1'b0;
                    mem_write <= 1'b0;
                    mem_reg_pc <= 2'b00;
                    alu_op <= 5'b00000;
                    alu_source <= 1'b1;
                    write_reg <= 2'b01;
                end
            6'b000111:
                begin
                    branch <= 1'b1;
                    mem_read <= 1'b0;
                    mem_write <= 1'b0;
                    mem_reg_pc <= 2'b00;
                    alu_op <= 5'b00000;
                    alu_source <= 1'b1;
                    write_reg <= 2'b01;
                end
            6'b110000:
                begin
                    branch <= 1'b0;
                    mem_read <= 1'b0;
                    mem_write <= 1'b0;
                    mem_reg_pc <= 2'b00;
                    alu_op <= 5'b00101;
                    alu_source <= 1'b0;
                    write_reg <= 2'b10;
                end
            6'b110001:
                begin
                    branch <= 1'b0;
                    mem_read <= 1'b0;
                    mem_write <= 1'b0;
                    mem_reg_pc <= 2'b00;
                    alu_op <= 5'b00110;
                    alu_source <= 1'b0;
                    write_reg <= 2'b10;
                end
            6'b110010:
                begin
                    branch <= 1'b0;
                    mem_read <= 1'b0;
                    mem_write <= 1'b0;
                    mem_reg_pc <= 2'b00;
                    alu_op <= 5'b00111;
                    alu_source <= 1'b0;
                    write_reg <= 2'b10;
                end
            6'b110011:
                begin
                    branch <= 1'b0;
                    mem_read <= 1'b0;
                    mem_write <= 1'b0;
                    mem_reg_pc <= 2'b00;
                    alu_op <= 5'b01000;
                    alu_source <= 1'b0;
                    write_reg <= 2'b10;
                end
            6'b110100:
                begin
                    branch <= 1'b0;
                    mem_read <= 1'b0;
                    mem_write <= 1'b0;
                    mem_reg_pc <= 2'b00;
                    alu_op <= 5'b01001;
                    alu_source <= 1'b0;
                    write_reg <= 2'b10;
                end
            6'b110101:
                begin
                    branch <= 1'b0;
                    mem_read <= 1'b0;
                    mem_write <= 1'b0;
                    mem_reg_pc <= 2'b00;
                    alu_op <= 5'b01010;
                    alu_source <= 1'b0;
                    write_reg <= 2'b10;
                end
            6'b110110:
                begin
                    branch <= 1'b0;
                    mem_read <= 1'b0;
                    mem_write <= 1'b0;
                    mem_reg_pc <= 2'b00;
                    alu_op <= 5'b01011;
                    alu_source <= 1'b0;
                    write_reg <= 2'b10;
                end
            6'b110111:
                begin
                    branch <= 1'b0;
                    mem_read <= 1'b0;
                    mem_write <= 1'b0;
                    mem_reg_pc <= 2'b00;
                    alu_op <= 5'b01100;
                    alu_source <= 1'b0;
                    write_reg <= 2'b10;
                end
            6'b111110:
                begin
                    branch <= 1'b0;
                    mem_read <= 1'b1;
                    mem_write <= 1'b0;
                    mem_reg_pc <= 2'b01;
                    alu_op <= 5'b01101;
                    alu_source <= 1'b0;
                    write_reg <= 2'b01;
                end
            6'b111111:
                begin
                    branch <= 1'b0;
                    mem_read <= 1'b1;
                    mem_write <= 1'b1;
                    mem_reg_pc <= 2'b00;
                    alu_op <= 5'b01101;
                    alu_source <= 1'b0;
                    write_reg <= 2'b00;
                end
            default:
                begin
                    branch <= 1'b0;
                    mem_read <= 1'b0;
                    mem_write <= 1'b0;
                    mem_reg_pc <= 2'b00;
                    alu_op <= 5'b00000;
                    alu_source <= 1'b0;
                    write_reg <= 2'b00;
                end
        endcase
    end

endmodule