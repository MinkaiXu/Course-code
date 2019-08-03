module LFSR( output reg [1:26] q, // 26 bit data output.
          input clk, // Clock input.
          input rst_n, // Synchronous reset input.
          input load, // Synchronous load input.
          input [1:26] din // 26 bit parallel data input.
);
    always@(posedge clk)
    begin
    if (~rst_n)
        q <= 26'b0;
    else
        begin
        if (load)
            q <= (|din)? din:26'b1; 
        else
            begin
            if (q == 26'b0)
                q <= 26'b1;
            else
                begin
                q[10:26] <= q[9:25];
                q[9] <= q[8]^q[26];//x8
                q[8] <= q[7]^q[26];//x7
                q[3:7] <= q[2:6];
                q[2] <= q[1]^q[26];//x
                q[1] <= q[26]; 
                end
            end
        end
    end
endmodule  

