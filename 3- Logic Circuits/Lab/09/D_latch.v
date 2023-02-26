`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:40:36 12/13/2021 
// Design Name: 
// Module Name:    D_latch 
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
module D_latch(d,c,q,qb);

input d, c;
output q, qb;

wire snot, rnot, dnot;

not g1 (dnot, d);

nand g2 (snot, c, d);
nand g3 (rnot, c, dnot);

nand g4(q, snot, qb);
nand g5(qb, rnot, q);

endmodule
