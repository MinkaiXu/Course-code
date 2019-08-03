module shift_counter(count, clk, reset);
    output reg [7:0] count;
    input clk;
    input reset;
    reg [4:0] cnt;
    
    always @( posedge clk ) 
    begin
        if (reset)
            cnt <= 5'b0;
        else begin
            if (cnt < 17)
                cnt <= cnt + 1'b1;
            else
                cnt <= 5'b0;
        end
        
        case (cnt)
            0: count = 8'b0000_0001;
            1: count = 8'b0000_0001;
            2: count = 8'b0000_0001;
            3: count = 8'b0000_0001;
            4: count = 8'b0000_0010;
            5: count = 8'b0000_0100;
            6: count = 8'b0000_1000;
            7: count = 8'b0001_0000;
            8: count = 8'b0010_0000;
            9: count = 8'b0100_0000;
            10: count = 8'b1000_0000;
            11: count = 8'b0100_0000;
            12: count = 8'b0010_0000;
            13: count = 8'b0001_0000;
            14: count = 8'b0000_1000;
            15: count = 8'b0000_0100;
            16: count = 8'b0000_0010;
            17: count = 8'b0000_0001;
            default:count = 8'b0000_0001;
        endcase
    end   
endmodule
