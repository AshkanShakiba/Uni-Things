`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:52:00 11/15/2021 
// Design Name: 
// Module Name:    Function 
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
module Function(I,F);
input[0:3] I;
wire [0:15] P;
output F;
Decoder4X16 d(I,P);
or g1(F,P[2],P[3],P[5],P[11],P[13]);
endmodule
