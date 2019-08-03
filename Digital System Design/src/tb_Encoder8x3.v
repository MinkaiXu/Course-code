`timescale 1ns/100ps
`include "Encoder8x3.v"
module tb_Encoder8x3();
  
    reg [7:0] p_data;
    wire [2:0] p_code;
    
    Encoder8x3 t( .code(p_code), .data(p_data));
    
    integer i;
    initial 
    begin
        p_data = 8'b0;
        #5 p_data = 8'b1;
        for(i = 1 ; i < 8; i = i+1)
            #5 p_data = p_data << 1;
        #5 p_data = 8'bx;
        #5 $stop;
    end
    
    initial
    $monitor("At %4t ns, data = %8b, code = %3d", $time, p_data, p_code);
endmodule