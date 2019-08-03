`include "shift_counter.v"
`timescale 1ns /1ns
module tb_shift_counter;
    reg clk, reset;
    wire [7:0] count;
shift_counter sc(.count(count),.clk(clk),.reset(reset));

    initial
    begin
        clk = 1'b0;
        forever #5 clk = ~clk;
end

    initial
    begin    
        reset = 1;
        #20 reset = 0;
        #200 reset = 1;
        #20 $stop;
end

    initial
        $monitor("At %t ns, reset=%b, count=%b", $time, reset, count);    
endmodule

