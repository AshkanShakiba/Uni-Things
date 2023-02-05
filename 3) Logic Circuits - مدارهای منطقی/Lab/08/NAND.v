`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:35:15 12/04/2021 
// Design Name: 
// Module Name:    NAND 
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
module NAND(N,A,B);
	output [3:0]N;
	input [1:0]A;
	input [1:0]B;
	
	/*
	nand g1(N[0],A[0],B[0]);
	nand g2(N[1],A[1],B[1]);
	*/
	
	assign N[0]=~(A[0]&B[0]);
	assign N[1]=~(A[1]&B[1]);
	
	assign N[2]=0;
	assign N[3]=0;
endmodule
