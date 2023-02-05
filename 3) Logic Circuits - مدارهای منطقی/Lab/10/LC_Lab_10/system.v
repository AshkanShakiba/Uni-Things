`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:08:22 12/27/2021 
// Design Name: 
// Module Name:    system 
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
module system(confirm,reset,clock,in,state,left,right);
	input confirm;
	input reset;
	input clock;
	input [3:0]in;
	output [2:0]state;
	output [3:0]left;
	output [3:0]right;
	wire [3:0]out;
	register right_reg(1, clock, en_right, out, right);
	register left_reg(1, clock, en_left, out, left);
	fsm f( reset, clock, confirm, in, en_left, en_right, out, state);
endmodule
