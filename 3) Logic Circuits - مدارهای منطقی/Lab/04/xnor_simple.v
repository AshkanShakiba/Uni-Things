`timescale 1ns / 1ps

module xnor_simple(a,b,c,f);
    input a, b, c;
    output f;
    xnor g1(f,a,b,c);
endmodule
