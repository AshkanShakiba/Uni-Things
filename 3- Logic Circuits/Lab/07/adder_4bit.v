`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:17:07 11/29/2021 
// Design Name: 
// Module Name:    adder_4bit 
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

module adder_4bit(A,B,C0,S,C4);
input [3:0] A;
input [3:0] B;
input C0;
output [3:0] S;
wire C1;
wire C2;
wire C3;
output C4;
adder_2bit a1(A[0],B[0],C0,C0,C1,S[0]);
adder_2bit a2(A[1],B[1],C0,C1,C2,S[1]);
adder_2bit a3(A[2],B[2],C0,C2,C3,S[2]);
adder_2bit a4(A[3],B[3],C0,C3,C4,S[3]);
endmodule
