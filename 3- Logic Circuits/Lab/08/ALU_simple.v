`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:34:23 12/06/2021 
// Design Name: 
// Module Name:    ALU_simple 
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
module ALU_simple(O,A,B,S);
	output [3:0] O;
	input [1:0] A;
	input [1:0] B;
	input [1:0] S;
	reg [3:0] T;
	
	assign O = T;
	always @ (A or B or S)
		begin
			case (S)
				2'b00 : T = A * B;
				2'b01 : T = {1'b0 ,( A + B)};
				2'b10 : T = {2'b00,(~(A & B))};
				2'b11 : T = {2'b00 , (~A)};
			endcase
		end
endmodule
