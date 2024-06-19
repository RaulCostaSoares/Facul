#include <stdio.h>

#define LINHAS 6
#define COLUNAS 4

int main() {
    int matrizz[LINHAS][COLUNAS];
    int newMatrizz[LINHAS][COLUNAS];
    int count = 0;

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            scanf("%d", &matrizz[i][j]);
        }
    }

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (matrizz[i][j] > 30) {
                count++;
            }
            if (matrizz[i][j] == 30) {
                newMatrizz[i][j] = 0;
            } else {
                newMatrizz[i][j] = matrizz[i][j];
            }
        }
    }

    printf("%d\n\n", count);

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", newMatrizz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
