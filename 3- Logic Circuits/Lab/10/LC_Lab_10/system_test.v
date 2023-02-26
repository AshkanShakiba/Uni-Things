`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:09:04 12/27/2021
// Design Name:   system
// Module Name:   E:/University/LC Lab/Codes/LC_Lab_10/system_test.v
// Project Name:  LC_Lab_10
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: system
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////
module system_test;
	reg reset;
	reg clock;
	reg confirm;
	reg [3:0]in;
	wire [3:0]left;
	wire [3:0]right;
	wire [2:0]state;
	
	system s(confirm,reset,clock,in,state,left,right);
	
	initial begin
	  clock = 0;
			repeat (50)
	   #10 clock = ~clock;
	end

	initial begin
		#5 reset = 0;
		#20 confirm = 1; reset = 1;
		#20 in = 4'b1111;
		#20 in = 4'b1010;
		#20 reset = 0;
		#20 reset = 1; in = 4'b1111;
		#40 in = 4'b1011;
		#20 reset = 0;
		#20 in = 4'b1111;
		#20 in = 4'b1010;
		#20 reset = 1;
		#20 in = 4'b0000;
		#20 in = 4'b1111;
		#20 reset = 0;
		#20 reset = 1;
		#20 in = 4'b1111;
		#20 in = 4'b0110;
		#50
		$finish;
	end
endmodule
