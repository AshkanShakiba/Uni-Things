`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:40:22 11/15/2021 
// Design Name: 
// Module Name:    Decoder_2X4 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module Decoder_2X4(A,B,En,y0,y1,y2,y3);
input A, B, En;
output y0,y1,y2,y3;
wire A_not, B_not;
not g1(A_not,A);
not g2(B_not,B);
and g3(y0,A_not,B_not,En);
and g4(y1,A_not,B,En);
and g5(y2,A,B_not,En);
and g6(y3,A,B,En);
endmodule
