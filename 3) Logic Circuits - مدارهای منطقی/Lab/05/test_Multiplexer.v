`timescale 1ns / 1ps

module test_Multiplexer();
  reg [0:1] s;
  reg [0:3] x;
  wire f;
  
  Multiplexer m(x,s,f);
  
  initial begin
    x[3] = 1'b1;s[0] = 1'b1;s[1] = 1'b1;
  #100;
    x[2] = 1'b1;s[0] = 1'b1;s[1] = 1'b0;
  #100;
    x[1] = 1'b1;s[0] = 1'b0;s[1] = 1'b1;
  #100;  
    x[0] = 1'b1;s[0] = 1'b0;s[1] = 1'b0;
  #100;
    x[3] = 1'b0;s[0] = 1'b1;s[1] = 1'b1;
  #100;
    x[2] = 1'b0;s[0] = 1'b1;s[1] = 1'b0;
  #100;
    x[1] = 1'b0;s[0] = 1'b0;s[1] = 1'b1;
  #100;
    x[0] = 1'b0;s[0] = 1'b0;s[1] = 1'b0;
  #100;
  end
endmodule
