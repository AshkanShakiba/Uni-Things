`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:17:07 12/04/2021 
// Design Name: 
// Module Name:    Multiplexer 
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
module Multiplexer(O,S,W3,W2,W1,W0);
	output [3:0]O;
	input [1:0]S;
	input [3:0]W3;
	input [3:0]W2;
	input [3:0]W1;
	input [3:0]W0;
	
	assign O=S[1]?(S[0]?W0:W1):(S[0]?W2:W3);
endmodule
