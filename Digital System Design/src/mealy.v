module mealy( output reg flag, input din, clk, rst );
    parameter IDLE = 8'b00000001, A = 8'b00000010,
              B = 8'b00000100, C = 8'b00001000,
              D = 8'b00010000, E = 8'b00100000,
              F = 8'b01000000, G = 8'b10000000;
    reg [7:0] state;
    always@(posedge clk or posedge rst)
    begin
        if (rst) begin state <= IDLE;flag <= 1'b0;end
        else begin
            case(state)
            IDLE: if (din) begin state <= IDLE; flag <= 1'b0; end
                      else begin state <= A; flag <= 1'b0; end
            A: if (din) begin state <= B; flag <= 1'b0; end
                      else begin state <= A; flag <= 1'b0; end
            B: if (din) begin state <= IDLE; flag <= 1'b0; end
                      else begin state <= C; flag <= 1'b0; end
            C: if (din) begin state <= D; flag <= 1'b0; end
                      else begin state <= A; flag <= 1'b0; end
            D: if (din) begin state <= IDLE; flag <= 1'b0; end
                      else begin state <= E; flag <= 1'b0; end
            E: if (din) begin state <= F; flag <= 1'b0; end
                      else begin state <= A; flag <= 1'b0; end
            F: if (din) begin state <= IDLE; flag <= 1'b0; end
                      else begin state <= G; flag <= 1'b0; end
            G: if (din) begin state <= F; flag <= 1'b1; end
                      else begin state <= A; flag <= 1'b0; end      
            default: begin state <= IDLE;flag <= 1'b0; end
            endcase
        end
    end
endmodule
