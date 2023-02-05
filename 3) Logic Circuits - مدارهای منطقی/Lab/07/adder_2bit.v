`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:05:46 11/29/2021 
// Design Name: 
// Module Name:    adder_2bit 
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

module adder_2bit(
    input a,
    input b,
    input s,
    input cin,
    output cout,
    output sum
    );
	 
	 wire e;
	 xor #(10) (e, s, b);
	 fulladder f(a, e, cin, cout, sum);

endmodule
