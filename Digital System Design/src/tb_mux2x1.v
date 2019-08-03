`timescale 1ns/1ns
`include "mux2x1.v"
module tb_mux2x1();
    reg [1:0] p_din;
    reg p_sel;
    wire p_dout;
    
    mux2x1 m( .dout( p_dout ), .sel(p_sel), .din(p_din) );
    
    integer i;
    initial
    begin
        {p_sel, p_din} = 3'b0;
        for(i=0 ; i<7 ; i=i+1)
            #5 {p_sel, p_din} = {p_sel, p_din} + 1;
        #5 $stop;
    end
    
    initial 
    $monitor( "At time %t ns, dout=%1b, sel=%1b, din=%2b", 
              $time, p_dout, p_sel, p_din);
endmodule
