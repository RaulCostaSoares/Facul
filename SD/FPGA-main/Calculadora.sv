// ==============================
// Módulo: Calculadora
// Função: Calculadora simples com 2 operandos e 1 operador
// Suporta: Soma, Subtração, Multiplicação (usando soma repetida) e reset
// ===============================

// =========================
//  Soma   = 4'b1010;
//  Subt   = 4'b1011;
//  Mult   = 4'b1100;
//  Igual  = 4'b1110;
//  Backs  = 4'b1111;
// =========================

module Calculadora(
    input logic [3:0] cmd,  // comando para receber digito ou operador
    input logic reset,
    input logic clock,

    output logic [1:0] status, // estado atual
    output logic [3:0] pos,     // posição do display 
    output logic [3:0] dig      // dígito do display
);


    // ====================
    // Estados possíveis
    // ====================
    typedef enum logic [1:0] {ERRO, PRONTA, OCUPADA} statetype;
    statetype estados;

    // ========================
    // Registradores internos
    // ========================
    reg [31:0] reg1, reg2, saida, contador;
    reg [3:0] op;
    reg set_op, flag;
    reg [31:0] resultado, temp;
    reg [3:0] dig_count;
    reg exibir_resultado;

    assign status = estados[1:0];

    always @(posedge clock) begin
        if (reset) begin
            estados         <= PRONTA;
            op              <= 4'b1010;
            dig             <= 0;
            pos             <= 0;
            set_op          <= 0;
            flag            <= 0;
            reg1            <= 32'd0;
            reg2            <= 32'd0;
            saida           <= 32'b0;
            contador        <= 32'd0;
            resultado       <= 0;
            temp            <= 0;
            dig_count       <= 0;
            exibir_resultado <= 0;
        end else begin
            case (estados)
                PRONTA: begin
                    if (exibir_resultado) begin
                        if (dig_count < 8) begin
                            dig <= temp % 10;
                            pos <= dig_count;
                            temp <= temp / 10;
                            dig_count <= dig_count + 1;
                        end else begin
                            exibir_resultado <= 0;
                        end
                    end else if (cmd < 10 && !set_op) begin
                        reg1 <= (reg1 * 10) + cmd;
                        dig  <= cmd;
                        if (flag) pos <= pos + 1;
                        flag <= 1;
                    end else if (cmd < 10 && set_op) begin
                        reg2 <= (reg2 * 10) + cmd;
                        dig  <= cmd;
                        if (flag) pos <= pos + 1;
                        flag <= 1;
                    end else if (cmd >= 10 && cmd != 4'b1110 && cmd != 4'b1111) begin
                        op     <= cmd;
                        set_op <= 1;
                    end else if (cmd == 4'b1110) begin
                        case (op)
                            4'b1010: begin  // Soma
                                resultado <= reg1 + reg2;
                                temp <= reg1 + reg2;
                                dig_count <= 0;
                                exibir_resultado <= 1;
                            end
                            4'b1011: begin  // Subtração
                                resultado <= reg1 - reg2;
                                temp <= reg1 - reg2;
                                dig_count <= 0;
                                exibir_resultado <= 1;
                            end
                            4'b1100: begin  // Multiplicação
                                if (reg1 == 0 || reg2 == 0) begin
                                    resultado <= 0;
                                    temp <= 0;
                                    dig_count <= 0;
                                    exibir_resultado <= 1;
                                end else begin
                                    saida <= 0;
                                    contador <= 0;
                                    estados <= OCUPADA;
                                end
                            end
                            default: estados <= ERRO;
                        endcase
                    end else if (cmd == 4'b1111) begin
                        if (set_op) begin
                            reg2 <= reg2 / 10;
                            pos  <= pos - 1;
                        end else begin
                            reg1 <= reg1 / 10;
                            pos  <= pos - 1;
                        end
                    end
                    if ((!set_op && reg1 > 32'd99999999) || (set_op && reg2 > 32'd99999999))
                        estados <= ERRO;
                end
                ERRO: begin
                    if (cmd == 4'b1111) begin
                        estados  <= PRONTA;
                        reg1     <= 0;
                        reg2     <= 0;
                        saida    <= 0;
                        op       <= 0;
                        set_op   <= 0;
                        contador <= 0;
                        dig      <= 0;
                        pos      <= 0;
                        exibir_resultado <= 0;
                    end
                end
                OCUPADA: begin
                    if (contador < reg2) begin
                        saida    <= saida + reg1;
                        contador <= contador + 1;
                    end else begin
                        contador <= 0;
                        if (saida > 32'd99999999)
                            estados <= ERRO;
                        else begin
                            estados <= PRONTA;
                            resultado <= saida;
                            temp <= saida;
                            dig_count <= 0;
                            exibir_resultado <= 1;
                        end
                    end
                end
            endcase
        end
    end
endmodule