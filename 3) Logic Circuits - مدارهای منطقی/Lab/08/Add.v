`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:16:50 12/04/2021 
// Design Name: 
// Module Name:    Add 
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
module Add(S,A,B);
	output [3:0]S;
	input [1:0]A;
	input [1:0]B;
	
	/*
	wire A0aB0; //w0
	wire A1xB1; //w1
	wire A1aB1; //w2
	wire W0aW1;
	
	xor g1(S[0],A[0],B[0]);
	and g2(A0aB0,A[0],B[0]);
	xor g3(A1xB1,A[1],B[1]);
	xor g4(S[1],A1xB1,A0aB0);
	and g5(A1aB1,A[1],B[1]);
	and g6(W0aW1,A0aB0,A1xB1);
	or g7(S[2],A1aB1,W0aW1);
	assign S[3]=0;
	*/
	
	assign S=A+B;
endmodule
