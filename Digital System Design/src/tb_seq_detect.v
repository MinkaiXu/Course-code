`timescale 1ns/1ns
`include "seq_detect.v"
module tb_seq_detect;
    reg clk,rst_n,din;
    reg[9:0] inflow;
    wire flag1;
    integer i;
    
    seq_detect sd(.flag(flag1),.clk(clk),.rst_n(rst_n),.din(din));
    
    initial
    begin
        clk = 0'b1;
        forever #5 clk=~clk;
    end
    
    initial
    begin
        inflow = 10'b11_0110_1101;
        din = inflow[9];
        rst_n = 1'b0;
        #10 rst_n = 1'b1;
        for (i=9;i>0;i=i-1) 
        begin
            #10 din = inflow[i-1];
        end
        #10 $stop;
    end
    
    initial
        $monitor("At%tns,rst_n=%b,din=%b,flag1=%b",
                $time,rst_n,din,flag1);
endmodule

