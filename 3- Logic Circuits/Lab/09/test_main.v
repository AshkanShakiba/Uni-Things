`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:43:38 12/13/2021
// Design Name:   main
// Module Name:   E:/University/LC Lab/Codes/LCL9/test_main.v
// Project Name:  LCL9
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: main
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////
module test_main;
reg CLK,A,B;
wire Y,Z;
main m(A,B,CLK,Y,Z);
//main_delay m(A,B,CLK,Y,Z);
    initial begin
		{CLK,A,B} = 3'b000;
		#40;
		{CLK,A,B} = 3'b100;
		#40;
		{CLK,A,B} = 3'b001;
		#40;
		{CLK,A,B} = 3'b111;
		#40;
		{CLK,A,B} = 3'b011;
		#40;
		{CLK,A,B} = 3'b101;
		#40;
		{CLK,A,B} = 3'b001;
		#40;
		{CLK,A,B} = 3'b100;
		#40;
		{CLK,A,B} = 3'b010;
		#40;
		{CLK,A,B} = 3'b110;
		#40;
		{CLK,A,B} = 3'b010;
		#40;
		{CLK,A,B} = 3'b111;
		#40;
		{CLK,A,B} = 3'b000;
		#40;
		{CLK,A,B} = 3'b100;
		#40;
		{CLK,A,B} = 3'b000;
		#40;
		{CLK,A,B} = 3'b101;
		#40;
		{CLK,A,B} = 3'b011;
		#40;
		{CLK,A,B} = 3'b111;
		#40;
    end
endmodule
