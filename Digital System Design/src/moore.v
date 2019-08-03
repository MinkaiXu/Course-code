module moore( output reg flag, input din, clk,rst);
    parameter IDLE = 9'b000000001, A = 9'b000000010,
              B = 9'b000000100, C = 9'b000001000,
              D = 9'b000010000, E = 9'b000100000,
              F = 9'b001000000, G = 9'b010000000, 
              H = 9'b100000000;
    reg [8:0] state;
    always@(posedge clk or posedge rst)
    begin 
        if (rst)  begin state <= IDLE; flag <= 1'b0; end
        else begin
            if (state == H) flag <= 1'b1;
            else flag <= 1'b0;
            case(state)
            IDLE: state <= (din)?IDLE:A;
            A: state <= (din)?B:A;
            B: state <= (din)?IDLE:C;
            C: state <= (din)?D:A;
            D: state <= (din)?IDLE:E;
            E: state <= (din)?F:A;
            F: state <= (din)?IDLE:G;
            G: state <= (din)?H:A;
            H: state <= (din)?IDLE:G;
            default: state <= IDLE;
            endcase
        end
    end
endmodule
