#include <stdio.h>

#define NUMERO_PRODUTOS 10
#define MAXIMO_PEDIDOS 100

int main() {
    int codigosProdutos[NUMERO_PRODUTOS];
    int estoque[NUMERO_PRODUTOS];
    int pedidosCodigoCliente[MAXIMO_PEDIDOS];
    int pedidosCodigoProduto[MAXIMO_PEDIDOS];
    int pedidosQuantia[MAXIMO_PEDIDOS];
    int quantidadePedidos = 0;

    for (int i = 0; i < NUMERO_PRODUTOS; i++) {
        scanf("%d %d", &codigosProdutos[i], &estoque[i]);
    }

    int codigoCliente, codigoProduto, quantia;

    while (1) {
        scanf("%d", &codigoCliente);
        if (codigoCliente == 0) {
            break;
        }
        scanf("%d %d", &codigoProduto, &quantia);

        pedidosCodigoCliente[quantidadePedidos] = codigoCliente;
        pedidosCodigoProduto[quantidadePedidos] = codigoProduto;
        pedidosQuantia[quantidadePedidos] = quantia;
        quantidadePedidos++;
    }

    for (int i = 0; i < quantidadePedidos; i++) {
        codigoProduto = pedidosCodigoProduto[i];
        quantia = pedidosQuantia[i];

        int indiceProduto = -1;
        for (int j = 0; j < NUMERO_PRODUTOS; j++) {
            if (codigosProdutos[j] == codigoProduto) {
                indiceProduto = j;
                break;
            }
        }

        if (indiceProduto == -1) {
            printf("PRODUTO INEXISTENTE\n");
        } else {
            if (estoque[indiceProduto] >= quantia) {
                estoque[indiceProduto] -= quantia;
                printf("PEDIDO ATENDIDO\n");
            } else {
                printf("SEM ESTOQUE\n");
            }
        }
    }

    for (int i = 0; i < NUMERO_PRODUTOS; i++) {
        printf("%d %d\n", codigosProdutos[i], estoque[i]);
    }

    return 0;
}
