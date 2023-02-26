`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:40:38 11/15/2021 
// Design Name: 
// Module Name:    Encoder_4X2 
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
module Encoder_4X2 (x0,x1,x2,x3,a0,a1);
input x0,x1,x2,x3;
output a0,a1;
wire x3_not,x3nx1;
not g1(x3_not,x3);
and g2(x3nx1,x3_not,x1);
or g3(a0,x3nx1,x3);
or g4(a1,x2,x3);
endmodule
