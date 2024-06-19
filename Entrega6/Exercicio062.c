#include <stdio.h>

#define tamanho 4

int main() {
    int matrizz[tamanho][tamanho];

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            scanf("%d", &matrizz[i][j]);
        }
    }

    int magicSum = 0;
    for (int j = 0; j < tamanho; j++) {
        magicSum += matrizz[0][j];
    }

    int quadradoMagico = 1;

    for (int i = 1; i < tamanho && quadradoMagico; i++) {
        int rowSum = 0;
        for (int j = 0; j < tamanho; j++) {
            rowSum += matrizz[i][j];
        }
        if (rowSum != magicSum) {
            quadradoMagico = 0;
        }
    }

    for (int j = 0; j < tamanho && quadradoMagico; j++) {
        int colSum = 0;
        for (int i = 0; i < tamanho; i++) {
            colSum += matrizz[i][j];
        }
        if (colSum != magicSum) {
            quadradoMagico = 0;
        }
    }

    int diagSum1 = 0;
    for (int i = 0; i < tamanho; i++) {
        diagSum1 += matrizz[i][i];
    }
    if (diagSum1 != magicSum) {
        quadradoMagico = 0;
    }

    int diagSum2 = 0;
    for (int i = 0; i < tamanho; i++) {
        diagSum2 += matrizz[i][tamanho - 1 - i];
    }
    if (diagSum2 != magicSum) {
        quadradoMagico = 0;
    }

    if (quadradoMagico) {
        printf("Forma quadrado magico\n");
    } else {
        printf("Nao forma quadrado magico\n");
    }

    return 0;
}
