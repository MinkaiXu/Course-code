`include "mealy.v"
`include "moore.v"
`timescale 1ns / 1ns
module top;
    reg clk,rst,din;
    reg[23:0] inflow;
    wire flag1,flag2;
    integer i;
    
    mealy ml(.flag(flag1),.clk(clk),.rst(rst),.din(din));
    moore mo(.flag(flag2),.clk(clk),.rst(rst),.din(din));
    
    initial
    begin
        clk = 1'b0;
        forever #5 clk=~clk;
    end
    
    initial
    begin
        inflow = 40'b0101_0101_0101_1101_0101_0101;
        din = inflow[23];
        rst = 1'b1;
        #10 rst = 1'b0;
        for (i=23;i>0;i=i-1) 
        begin
            #10 din = inflow[i-1];
        end
        #10 rst = 1'b1;
        #10 $stop;
    end
    initial
        $monitor("At%t ns,rst=%b,din=%b,flag1=%b,flag2=%b",
                $time,rst,din,flag1,flag2);
endmodule
