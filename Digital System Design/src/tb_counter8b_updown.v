`include "counter8b_updown.v"
`timescale 1ns/ 1ns
module tb_counter8b_updown;
    reg clk,reset,dir;
    wire [7:0] count;
counter8b_updown m(.count(count),.clk(clk),.reset(reset),.dir(dir));

    initial 
    begin
        clk = 1'b0;
        forever #5 clk = ~clk;//clk
end 

    initial
    begin
        reset = 1;
        dir = 1;
        #20 reset = 0;
        #150 dir = 0;
        #150 reset = 1;
        #20 $stop;
end

    initial 
        $monitor("At %t, reset=%b, dir=%b, count=%d",
                $time,reset,dir,count);
endmodule 
