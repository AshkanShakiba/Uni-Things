`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:42:26 12/13/2021
// Design Name:   Falling_Edge_D_FF
// Module Name:   E:/University/LC Lab/Codes/LCL9/test_Falling_Edge_D_FF.v
// Project Name:  LCL9
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Falling_Edge_D_FF
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////
module test_Falling_Edge_D_FF;
reg d,clk;
wire q,qb;
Falling_Edge_D_FF f(d,clk,q,qb);
//Falling_Edge_D_FF_delay f(d,clk,q,qb);
    initial begin
	 d = 1'b1;clk = 1'b1;
	 #100;
    clk = 1'b0;
    #100;
    d = 1'b0;clk = 1'b1;
    #100;
    clk = 1'b0;
    #100;
    end
endmodule
