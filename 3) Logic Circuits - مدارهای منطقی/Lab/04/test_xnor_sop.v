`timescale 1ns / 1ps

module test_xnor_sop();
  reg A, B, C;
  wire F;
  
  xnor_sop xso(A, B, C, F);
  
  initial begin
    A = 1'b1;B = 1'b1;C = 1'b1;
  #100;
    A = 1'b1;B = 1'b1;C = 1'b0;
  #100;
    A = 1'b1;B = 1'b0;C = 1'b1;
  #100;  
    A = 1'b1;B = 1'b0;C = 1'b0;
  #100;
    A = 1'b0;B = 1'b1;C = 1'b1;
  #100;
    A = 1'b0;B = 1'b1;C = 1'b0;
  #100;
    A = 1'b0;B = 1'b0;C = 1'b1;
  #100;
    A = 1'b0;B = 1'b0;C = 1'b0;
  #100;
  end
endmodule
