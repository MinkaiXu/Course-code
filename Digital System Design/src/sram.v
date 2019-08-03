module sram(output [7:0] dout,
          input [7:0] din, addr,
          input wr, rd, cs );
reg [7:0] ram [0:255];

assign dout = (cs & !rd)? ram[addr]:8'bz;

    always@(posedge wr)
        if (cs)
            ram[addr] <= din;  
endmodule

