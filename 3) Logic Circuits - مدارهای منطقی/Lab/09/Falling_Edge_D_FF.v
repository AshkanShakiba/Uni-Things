`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:41:26 12/13/2021 
// Design Name: 
// Module Name:    Falling_Edge_D_FF 
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
module Falling_Edge_D_FF(d,clk,q,qb);

input d, clk;
output q, qb;

wire clknot, q1, qb1;

not g1 (clknot, clk);

D_latch g2 (d, clk, q1, qb1);
D_latch g3 (q1, clknot, q, qb);
   
endmodule
