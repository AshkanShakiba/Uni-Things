`timescale 1ns / 1ps

module test();
  reg A, B, En;
  wire x0, x1, x2, x3, C, D;
  
  Decoder_2X4 d(A, B, En, x0, x1, x2, x3);
  Encoder_4X2 e(x0, x1, x2, x3, D, C);
  
  initial begin
    En = 1'b1;A = 1'b1;B = 1'b1;
  #100;
    En = 1'b1;A = 1'b1;B = 1'b0;
  #100;
    En = 1'b1;A = 1'b0;B = 1'b1;
  #100;  
    En = 1'b1;A = 1'b0;B = 1'b0;
  #100;
    En = 1'b0;A = 1'b1;B = 1'b1;
  #100;
    En = 1'b0;A = 1'b1;B = 1'b0;
  #100;
    En = 1'b0;A = 1'b0;B = 1'b1;
  #100;
    En = 1'b0;A = 1'b0;B = 1'b0;
  #100;
  end
endmodule
