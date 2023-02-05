`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:21:16 12/04/2021 
// Design Name: 
// Module Name:    ALU 
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
module ALU(O,A,B,S);
	output [3:0]O;
	input [1:0]A;
	input [1:0]B;
	input [1:0]S;
	wire [3:0]W3;
	wire [3:0]W2;
	wire [3:0]W1;
	wire [3:0]W0;
	
	ArithmeticUnit a(W3,W2,A,B);
	LogicUnit l(W1,W0,A,B);
	Multiplexer m(O,S,W3,W2,W1,W0);
endmodule
