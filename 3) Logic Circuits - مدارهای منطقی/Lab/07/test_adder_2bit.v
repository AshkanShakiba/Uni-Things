`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:06:05 11/29/2021
// Design Name:   adder_2bit
// Module Name:   D:/LC-Lab-12/test_adder_2bit.v
// Project Name:  LC-Lab-12
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: adder_2bit
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test_adder_2bit();
  reg A, B, Cin, Switch;
  wire S, Cout;

  adder_2bit a2b(A, B, Switch, Cin, Cout, S);
  
    initial begin
    A = 1'b0;B = 1'b0;Cin = 1'b0;Switch = 1'b0;
    #100;
    A = 1'b0;B = 1'b0;Cin = 1'b0;Switch = 1'b1;
    #100;
    A = 1'b0;B = 1'b0;Cin = 1'b1;Switch = 1'b0;
    #100;
    A = 1'b0;B = 1'b0;Cin = 1'b1;Switch = 1'b1;
    #100;
    A = 1'b0;B = 1'b1;Cin = 1'b0;Switch = 1'b0;
    #100;
    A = 1'b0;B = 1'b1;Cin = 1'b0;Switch = 1'b1;
    #100;
    A = 1'b0;B = 1'b1;Cin = 1'b1;Switch = 1'b0;
    #100;
    A = 1'b0;B = 1'b1;Cin = 1'b1;Switch = 1'b1;
    #100;
    A = 1'b1;B = 1'b0;Cin = 1'b0;Switch = 1'b0;
    #100;
    A = 1'b1;B = 1'b0;Cin = 1'b0;Switch = 1'b1;
    #100;
    A = 1'b1;B = 1'b0;Cin = 1'b1;Switch = 1'b0;
    #100;
    A = 1'b1;B = 1'b0;Cin = 1'b1;Switch = 1'b1;
    #100;
    A = 1'b1;B = 1'b1;Cin = 1'b0;Switch = 1'b0;
    #100;
    A = 1'b1;B = 1'b1;Cin = 1'b0;Switch = 1'b1;
    #100;
    A = 1'b1;B = 1'b1;Cin = 1'b1;Switch = 1'b0;
    #100;
    A = 1'b1;B = 1'b1;Cin = 1'b1;Switch = 1'b1;
    #100;
    end

endmodule
