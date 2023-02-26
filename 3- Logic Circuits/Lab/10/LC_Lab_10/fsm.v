`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:07:55 12/27/2021 
// Design Name: 
// Module Name:    fsm 
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
module fsm (
	input        rst ,
	input        clk ,
	input        confirm ,
	input  [3:0] pass_data ,
	output       en_left ,
	output       en_right ,
	output [3:0] dout ,
	output [2:0] state
);

	parameter reset = 3'b000;
	parameter active = 3'b001;
	parameter request = 3'b101;
	parameter save = 3'b110;
	parameter trap = 3'b111;
	parameter correct_pass = 4'b1111;
	
	reg [2:0] state;
	reg [3:0] dout;
	reg en_right, en_left;
	
	
	always @(posedge clk)
		begin
			if(~rst)
				state=reset;
				
			else
			case(state)
				active: 
					begin
						if(confirm)
							begin
								if(correct_pass==pass_data) state=request;
								if(correct_pass!=pass_data) state=trap;
							end
						if(~confirm) state=active;
					end
					
				reset: state=active;
					
				save: state=save;
				
				trap: state=trap;
				
				request: 
					begin
						state=save;
						if(confirm)
							begin
							if(pass_data[0])
								begin
									en_left=1;
									en_right=0;
									dout=pass_data;
								end
							if(~pass_data[0])
								begin
									en_left=0;
									en_right=1;
									dout=pass_data;
								end
							end
						if(~confirm) state=request;
					end
			endcase
		end			
endmodule
