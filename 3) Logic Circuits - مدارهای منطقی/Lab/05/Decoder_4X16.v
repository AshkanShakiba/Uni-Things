`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:41:53 11/15/2021 
// Design Name: 
// Module Name:    Decoder_4X16 
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
module Decoder_4X16 (I,D);
  input [0:3] I ;
  wire [0:7] G;
  output [0:15] D;
  Decoder_2X4 dec1(I[0:1],1,G[0:3]);
  Decoder_2X4 dec2(I[2:3],1,G[4:7]);
  and a1(D[0],G[0],G[4]);
  and a2(D[1],G[0],G[5]);
  and a3(D[2],G[0],G[6]);
  and a4(D[3],G[0],G[7]);
  and a5(D[4],G[1],G[4]);
  and a6(D[5],G[1],G[5]);
  and a7(D[6],G[1],G[6]);
  and a8(D[7],G[1],G[7]);
  and a9(D[8],G[2],G[4]);
  and a10(D[9],G[2],G[5]);
  and a11(D[10],G[2],G[6]);
  and a12(D[11],G[2],G[7]);
  and a13(D[12],G[3],G[4]);
  and a14(D[13],G[3],G[5]);
  and a15(D[14],G[3],G[6]);
  and a16(D[15],G[3],G[7]);
endmodule
