`timescale 1ns/1ps

module tb_final;
    reg [3:0] cmd;
    reg reset;
    reg clock;
    wire [7:0] d0, d1, d2, d3, d4, d5, d6, d7;

    Calculadora_Top topo (
        .cmd(cmd), .reset(reset), .clock(clock),
        .d0(d0), .d1(d1), .d2(d2), .d3(d3),
        .d4(d4), .d5(d5), .d6(d6), .d7(d7)
    );

    initial clock = 0;
    always #5 clock = ~clock;

    initial begin
        cmd = 4'b0000;
        reset = 1;
        #10 reset = 0;

        // Teste 1: 3 + 1 =
        #8  cmd = 4'b0011;  // 3
        #10 cmd = 4'b1010;  // +
        #10 cmd = 4'b0001;  // 1
        #10 cmd = 4'b1110;  // =
        #80 reset = 1;      // Espera 8 ciclos
        #10 reset = 0;

        // Teste 2: 3 - 1 =
        #10 cmd = 4'b0011;  // 3
        #10 cmd = 4'b1011;  // -
        #10 cmd = 4'b0001;  // 1
        #10 cmd = 4'b1110;  // =
        #80 reset = 1;
        #10 reset = 0;

        // Teste 3: 3 + 8 =
        #8  cmd = 4'b0011;  // 3
        #10 cmd = 4'b1010;  // +
        #10 cmd = 4'b1000;  // 8
        #10 cmd = 4'b1110;  // =
        #80 reset = 1;
        #10 reset = 0;

        #100;
        $stop;
    end
endmodule