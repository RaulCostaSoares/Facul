#include <stdio.h>

#define tamanho 7

int main() {
    int matrizz[tamanho][tamanho];
    int linhas[tamanho];
    int minCol[tamanho];

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            scanf("%d", &matrizz[i][j]);
        }
    }

    for (int i = 0; i < tamanho; i++) {
        int max = matrizz[i][0];
        for (int j = 1; j < tamanho; j++) {
            if (matrizz[i][j] > max) {
                max = matrizz[i][j];
            }
        }
        linhas[i] = max;
    }

    for (int j = 0; j < tamanho; j++) {
        int min = matrizz[0][j];
        for (int i = 1; i < tamanho; i++) {
            if (matrizz[i][j] < min) {
                min = matrizz[i][j];
            }
        }
        minCol[j] = min;
    }

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", matrizz[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", linhas[i]);
    }
    printf("\n");

    for (int j = 0; j < tamanho; j++) {
        printf("%d ", minCol[j]);
    }
    printf("\n");

    return 0;
}
