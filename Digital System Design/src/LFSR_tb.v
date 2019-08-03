`include "LFSR.v"
`timescale 1ns / 1ns
module tb_LFSR;
    reg clk,load,rst_n;
    reg [0:25] din;
    wire [0:25] q;

    LFSR lfsr(.q(q),.clk(clk),.rst_n(rst_n),.load(load),.din(din));

    initial
    begin
        clk = 1'b0;
        forever #5 clk=~clk;
    end

    initial
    begin
        rst_n = 1'b0;
        #20  rst_n = 1'b1;
    end

    initial
    begin
        load = 1'b0;
        din = 26'b10_1010_1010_0101_1100_1000_0001;
		    
        #50 load = 1'b1;
        #20 load = 1'b0;
		
        #170 load = 1'b1;
        din = 26'b0;  
        #10 load = 1'b0;
        #50 $stop;
    end 

    initial
        $monitor("At time t=%4t, rst_n=%b, load=%b, din=%d, q=%d", 
                  $time,rst_n,load,din,q);
endmodule    

