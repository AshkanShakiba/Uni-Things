`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:52:43 11/29/2021
// Design Name:   fulladder
// Module Name:   D:/LC-Lab-12/test_fulladder.v
// Project Name:  LC-Lab-12
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: fulladder
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test_fulladder();
  reg A, B, CI;
  wire S, CO;

  fulladder fa(A, B, CI, CO, S);
  
    initial begin
    A = 1'b0;B = 1'b0;CI = 1'b0;
    #100;
    A = 1'b0;B = 1'b0;CI = 1'b1;
    #100;
    A = 1'b0;B = 1'b1;CI = 1'b0;
    #100;
    A = 1'b0;B = 1'b1;CI = 1'b1;
    #100;
    A = 1'b1;B = 1'b0;CI = 1'b0;
    #100;
    A = 1'b1;B = 1'b0;CI = 1'b1;
    #100;
    A = 1'b1;B = 1'b1;CI = 1'b0;
    #100;
    A = 1'b1;B = 1'b1;CI = 1'b1;
    #100;
    end

endmodule
