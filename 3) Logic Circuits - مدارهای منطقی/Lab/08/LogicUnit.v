`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:16:22 12/04/2021 
// Design Name: 
// Module Name:    LogicUnit 
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
module LogicUnit(Na,Nt,A,B);
	output [3:0]Na;
	output [3:0]Nt;
	input [1:0]A;
	input [1:0]B;
	
	NAND na(Na,A,B);
	notA_A nt(Nt,A);
endmodule
