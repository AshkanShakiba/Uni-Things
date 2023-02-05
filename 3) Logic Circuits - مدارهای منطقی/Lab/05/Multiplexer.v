`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:05:44 11/15/2021 
// Design Name: 
// Module Name:    Multiplexer 
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
module Multiplexer(x,s,f);
input[0:3] x;
input[0:1] s;
wire[0:1] s_not;
wire[0:3] and_gate;
output f;
not g1(s_not[0],s[0]);
not g2(s_not[1],s[1]);
and g3(and_gate[0],s_not[0],s_not[1],x[0]);  
and g4(and_gate[1],s_not[0],s[1],x[1]);  
and g5(and_gate[2],s[0],s_not[1],x[2]);  
and g6(and_gate[3],s[0],s[1],x[3]);
or g7(f,and_gate[0],and_gate[1],and_gate[2],and_gate[3]);
endmodule
