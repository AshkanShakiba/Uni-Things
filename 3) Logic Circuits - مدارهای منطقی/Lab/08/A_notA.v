`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:11:57 12/04/2021 
// Design Name: 
// Module Name:    notA_A 
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
module notA_A(O,A);
	output [3:0]O;
	input [1:0]A;
	
	assign O[0]=~A;
	assign O[1]=~A;
	assign O[2]=0;
	assign O[3]=0;
endmodule
