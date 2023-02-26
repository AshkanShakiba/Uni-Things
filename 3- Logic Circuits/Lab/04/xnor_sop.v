`timescale 1ns / 1ps

module xnor_sop(a,b,c,f);
    input a, b, c;
    wire d, e, g, h, i, j, k;
    output f;
    not g1(d, a);
    not g2(e, b);
    not g3(g, c);
    and g4(h, d, e, g);
    and g5(i, d, b, c);
    and g6(j, a, e, c);
    and g7(k, a, b, g);
    or g8(f, h, i, j, k);
endmodule
