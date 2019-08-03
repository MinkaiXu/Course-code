`timescale 10ns/1ns
module wavegen;
  reg wave;
  initial 
  begin
    wave = 1'b0;
    #2 wave = ~wave;
    #1 wave = ~wave;
    #9 wave = ~wave;
    #10 wave = ~wave;
    #2 wave = ~wave;
    #3 wave = ~wave;
    #5 wave = ~wave;
    #2 $stop;
  end
endmodule
