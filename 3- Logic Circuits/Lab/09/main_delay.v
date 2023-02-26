`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:39:54 12/13/2021 
// Design Name: 
// Module Name:    main_delay 
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
module main_delay(a,b,clk,y,z);

input a, b, clk;
output y, z;

wire s, w1, w2, qb1, qb2, r, q2;

and #10 g1 (s, b , qb2);
or #10 g2 (w1, s, a);
nor #10 g3 (w2, w1, qb1);
Falling_Edge_D_FF_delay #10 g4 (w1, clk, y, qb1);
Falling_Edge_D_FF_delay #10 g5 (w2, clk, q2, qb2);
and #10 g6 (r, b, qb2);
or #10 g7 (z, qb1, r);
    
endmodule
