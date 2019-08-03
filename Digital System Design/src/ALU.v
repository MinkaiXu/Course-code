module ALU( output reg c_out,
            output reg[7:0] sum, 
            input [2:0] oper,
            input [7:0] a, b,
            input c_in );
    parameter iand = 3'b000,
              subtract = 3'b001, 
              subtract_a = 3'b010,
              or_ab = 3'b011,
              and_ab = 3'b100, 
              not_ab = 3'b101,
              exor = 3'b110,
              exnor = 3'b111;
    always@(*)
    begin
        case(oper)
            iand:  {c_out,sum} = a + b + c_in;
            subtract:  {c_out,sum} = a + ~b + c_in;
            subtract_a: {c_out,sum} = b + ~a + ~c_in;  
            or_ab:  {c_out,sum} = {1'b0, a | b };
            and_ab:  {c_out,sum} = { 1'b0, a & b };
            not_ab:  {c_out,sum} = { 1'b0, (~a) & b };
            exor:  {c_out,sum} = { 1'b0, a ^ b };
            exnor:  {c_out,sum} = { 1'b0, a ~^ b };
            default: {c_out,sum} = 9'bx;
        endcase
    end 
endmodule  

