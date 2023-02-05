`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:24:59 12/20/2021 
// Design Name: 
// Module Name:    register 
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
module register(
	input        rst ,
	input        clk ,
	input        en ,
	input  [3:0] din ,
	output reg [3:0] qout
    );
	always@(negedge rst or posedge clk)
		if (~rst) 
				qout<=4'b0000;
		else
		begin
			if	(en)
				qout<=din;
		end
endmodule
