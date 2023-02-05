`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:11:26 12/04/2021 
// Design Name: 
// Module Name:    Multiply 
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
module Multiply(P,A,B);
	output [3:0]P;
	input [1:0]A;
	input [1:0]B;
	
	/*
	wire A1aB0;
	wire A0aB1;
	wire A1aB1;
	wire C1;
	
	and g1(P[0],A[0],B[0]);
	and g2(A1aB0,A[1],B[0]);
	and g3(A0aB1,A[0],B[1]);
	and g4(A1aB1,A[1],B[1]);
	xor g5(P[1],A1aB0,A0aB1);
	and g6(C1,A1aB0,A0aB1);
	xor g7(P[2],C1,A1aB1);
	and g8(P[3],C1,A1aB1);
	*/
	
	assign P=A*B;
endmodule
