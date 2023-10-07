`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04.11.2022 12:25:19
// Design Name: 
// Module Name: control_fsm
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module control_unit(input clk, input rst, input indicator, input[31:0] x_comp, input[7:0] add_out, input cout, output reg[7:0] add_1, output reg[7:0] add_2, output reg cin,output reg en);

reg[2:0] pstate,nstate;
reg[7:0] count;
always@(posedge clk)
    begin
        if(rst)
            pstate<=3'd0;
        else
            pstate<=nstate;
    end

always@(posedge clk)
    begin
        if(rst)
            count<=8'd0;
        else if(pstate==3'd4)
            count<=count+1;
        else
            count<=count;
    end

always@(*)
    begin
        case(pstate)
        3'd0:nstate<=3'd1;
        3'd1:nstate<=3'd2;
        3'd2:nstate<=3'd3;
        3'd3:nstate<=3'd4;
        3'd4:
                begin
                    if(indicator==1'd0 || count==8'd254)
                        nstate<=3'd5;
                    else
                        nstate<=3'd1;
                end
        default: nstate<=3'd5;
        endcase
end


always@(*)
    begin
    case(pstate)
        3'd0:
            begin
                add_1<=8'd0;
                add_2<=8'd0;
                cin<=1'd0;
                en<=1'd0;
            end
        3'd1:
            begin
                add_1<=x_comp[7:0];
                add_2<=count;
                cin<=1'd0;
                en<=1'd1;
            end
        3'd2:
            begin
                add_1<=x_comp[15:8];
                add_2<=add_out;
                cin<=cout;
                en<=1'd1;
            end
        3'd3:
            begin
                add_1<=x_comp[23:16];
                add_2<=add_out;
                cin<=cout;
                en<=1'd1;
            end
        3'd4:
            begin
                add_1<=x_comp[31:24];
                add_2<=add_out;
                cin<=cout;
                en<=1'd1;
            end
        default:
            begin
                add_1<=add_1;
                add_2<=add_2;
                cin<=cin;
                en<=1'd0;
            end
        endcase
    end
 
endmodule
