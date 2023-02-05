`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:31:17 12/04/2021 
// Design Name: 
// Module Name:    ArithmeticUnit 
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
module ArithmeticUnit(P,S,A,B);
	output [3:0]P;
	output [3:0]S;
	input [1:0]A;
	input [1:0]B;
	
	Multiply m(P,A,B);
	Add a(S,A,B);
endmodule
