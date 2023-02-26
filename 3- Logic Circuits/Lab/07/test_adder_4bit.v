`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:19:25 11/29/2021
// Design Name:   adder_4bit
// Module Name:   D:/LC-Lab-12/test_adder_4bit.v
// Project Name:  LC-Lab-12
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: adder_4bit
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////


module test_adder_4bit();

	// Inputs
	reg [3:0] A;
	reg [3:0] B;
	reg C0;

	// Outputs
	wire [3:0] S;
	wire C4;

	adder_4bit a4b(A,B,C0,S,C4);

	initial begin
		// Initialize Inputs
			A = 4'b0000; B = 4'b0000; C0 = 4'b0000;
		// Wait 100 ns for global reset to finish
		#100;
			A = 4'b0000; B = 4'b0001; C0 = 4'b0000;
		#100
			A = 4'b0001; B = 4'b0001; C0 = 4'b0000;
		#100
			A = 4'b0001; B = 4'b0011; C0 = 4'b0000;
		#100
			A = 4'b1000; B = 4'b1000; C0 = 4'b0000;
		#100
			A = 4'b0011; B = 4'b0001; C0 = 4'b0001;
		#100
			A = 4'b0111; B = 4'b0001; C0 = 4'b0001;
		#100
			A = 4'b0001; B = 4'b0111; C0 = 4'b0001;
						

        
		// Add stimulus here

	end
      
endmodule
