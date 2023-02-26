`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:43:05 12/13/2021 
// Design Name: 
// Module Name:    main 
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
module main(a,b,clk,y,z);

input a, b, clk;
output y, z;

wire s, w1, w2, qb1, qb2, r, q2;

and g1 (s, b , qb2);
or g2 (w1, s, a);
nor g4 (w2, w1, qb1);
Falling_Edge_D_FF g3 (w1, clk, y, qb1);
Falling_Edge_D_FF g5 (w2, clk, q2, qb2);
and g6 (r, b, qb2);
or g7 (z, qb1, r);
    
endmodule
