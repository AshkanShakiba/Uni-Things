`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:38:30 12/13/2021 
// Design Name: 
// Module Name:    Falling_Edge_D_FF_delay 
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
module Falling_Edge_D_FF_delay(d,clk,q,qb);

input d, clk;
output q, qb;

wire clknot, q1, qb1;

not #10 g1 (clknot, clk);

D_latch_delay #10 g2 (d, clk, q1, qb1);
D_latch_delay #10 g3 (q1, clknot, q, qb);
   
endmodule
