`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:40:50 12/13/2021
// Design Name:   D_latch
// Module Name:   E:/University/LC Lab/Codes/LCL9/test_D_latch.v
// Project Name:  LCL9
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: D_latch
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////
module test_D_latch;
reg d,c;
wire q,qb;
D_latch dl(d,c,q,qb);
//D_latch_delay dl(d,c,q,qb);
    initial begin
    d = 1'b0;c = 1'b0;
    #100;
    d = 1'b0;c = 1'b1;
    #100;
    d = 1'b1;c = 1'b0;
    #100;
    d = 1'b1;c = 1'b1;
    #100;
    end
endmodule
