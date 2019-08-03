`include "filter.v"
`timescale 1ns/1ns
module tb_filter;
    reg clock,reset,sig_in;
    wire sig_out;

    filter f (.sig_out(sig_out), .clock(clock), .reset(reset), .sig_in(sig_in));

    initial
    begin
        clock = 1'b0;
        forever #5 clock=~clock;
    end

    reg [19:0] inflow;
    integer i;
    initial 
    begin
        inflow = 20'b1000_1100_0010_1101_1110;
        for(i=0; i<20; i=i+1)
            #10 sig_in = inflow[i];
    end

    initial
    begin
        reset = 1'b0;
        #20 reset = 1'b1;
        #200 $stop;
    end

    initial
        $monitor("At %t,reset = %b,sig_in = %b,sig_out = %b",
                  $time,reset,sig_in,sig_out);
endmodule

