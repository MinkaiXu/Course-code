`timescale 1ns/1ns
`include "sram.v"
module tb_sram;
    reg cs,wr,rd;
    reg [7:0] din, addr;
    wire [7:0] dout;

    sram s(.dout(dout),.din(din),.addr(addr),.wr(wr),.rd(rd),.cs(cs));
    initial
    begin
        cs = 1'b1;
        rd = 1'b1;
        wr = 1'b0;

        addr = 8'b1110_1100;
        din = 8'b0010_0110;
        #5 wr = 1'b1;
        #5 wr = 1'b0;
        rd = 1'b0;
        addr = 8'b1110_1101;
        din = 8'b0010_0111;
        #5 wr = 1'b1;
        
        #5 addr = 8'b1110_1100;
        #5 addr = 8'b1110_1101;
        
        #5 cs = 1'b0;
        #5 $stop;
    end

    initial
        $monitor("At %t ns,cs=%b,wr=%b,rd=%b,addr=%b,din=%b,dout=%b",
                  $time,cs,wr,rd,addr,din,dout);
endmodule

