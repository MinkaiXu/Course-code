module seq_detect(output reg flag, 
                  input din, clk, rst_n);
    parameter IDLE = 7'b1000000, A = 7'b0100000,
              B = 7'b0010000, C = 7'b0001000, D = 7'b0000100,
              E = 7'b0000010, F = 7'b0000001; 
    reg [6:0] state;
    always@(posedge clk)
    begin
        if (!rst_n) begin state <= IDLE; flag<=1'b0; end
        else  begin
            case(state)
            IDLE: if (din) begin state <= B; flag <= 1'b0; end
                  else  begin state <= A; flag <= 1'b0; end
            A: if (din) begin state <= C; flag <= 1'b0; end
                  else  begin state <= A; flag <= 1'b0; end
            B: if (din) begin state <= D; flag <= 1'b0; end
                  else  begin state <= A; flag <= 1'b0; end
            C: if (din) begin state <= E; flag <= 1'b0; end
                  else  begin state <= A; flag <= 1'b0; end
            D: if (din) begin state <= D; flag <= 1'b0; end
                  else  begin state <= F; flag <= 1'b0; end
            E: if (din) begin state <= D; flag <= 1'b0; end
                  else  begin state <= F; flag <= 1'b1; end
            F: if (din) begin state <= C; flag <= 1'b1; end
                  else  begin state <= A; flag <= 1'b0; end
            default: begin state <= IDLE; flag <= 1'b0; end
            endcase
        end
    end
endmodule
