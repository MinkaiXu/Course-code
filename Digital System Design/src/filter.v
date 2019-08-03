module filter(output reg sig_out, 
      input clock, reset, sig_in);

    reg [0:3] Q;
    wire J,K;
    
    assign J = Q[1] & Q[2] & Q[3];
    assign K = (~Q[1]) & (~Q[2]) & (~Q[3]);

    always @(posedge clock)
    begin
        if (!reset) begin
            Q <= 4'b0;
            sig_out <= 1'b0;
        end
        else begin
            Q[0:3] <= {sig_in, Q[0:2]};
            case({J,K})
                2'b10: sig_out<=1'b1;
                2'b01: sig_out<=1'b0;
                2'b11: sig_out<=~sig_out;
                default:  ;   
            endcase
        end
    end
endmodule

