`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:35:57 12/13/2021 
// Design Name: 
// Module Name:    D_latch_delay 
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
module D_latch_delay(d,c,q,qb);

input d, c;
output q, qb;

wire snot, rnot, dnot;

not #10 g1 (dnot, d);

nand #10 g2 (snot, c, d);
nand #10 g3 (rnot, c, dnot);

nand #10 g4(q, snot, qb);
nand #10 g5(qb, rnot, q);

endmodule
