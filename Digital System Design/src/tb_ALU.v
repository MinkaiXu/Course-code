`timescale 1ns/1ns
`include "ALU.v"
module tb_ALU;
    reg [7:0] a,b;
    reg cin;
    reg [2:0] oper;
    wire cout;
    wire [7:0] sum;
integer i;

ALU alu(.sum(sum),.c_out(cout),.c_in(cin),.a(a),.b(b),.oper(oper));

    initial
    begin
        {oper,cin} = 4'b0;
        a = 8'b1001_1101;
        b = 8'b0111_0101;
        $display("a = %b, b = %b",a,b);
        for (i = 0; i < 15; i=i+1)
            #5 {oper,cin} = {oper,cin} + 1;
        #5 $stop;
end
    initial
        $monitor("At %t ns, oper = %b, cin = %b, cout = %b, sum = %b",
                  $time, oper, cin, cout, sum);
endmodule  

