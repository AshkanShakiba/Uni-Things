`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:52:05 11/29/2021 
// Design Name: 
// Module Name:    fulladder 
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

module fulladder(
    input x,
    input y,
    input ci,
    output co,
    output s
    );
	 
	 wire e1, e2, e3;

	xor #(10) (s, x, y, ci);
	
	and #(5) (e1, x, y);
	and #(5) (e2, x, ci);
	and #(5) (e3, y, ci);
	or #(5) (co, e1, e2, e3);

endmodule
