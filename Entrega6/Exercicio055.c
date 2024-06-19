#include <stdio.h>

#define LINHAS 4
#define COLUNAS 7

int main() {
    double matrizz[LINHAS][COLUNAS];

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            scanf("%lf", &matrizz[i][j]);
        }
    }

    int minLin = 0, minCol = 0;
    double minValue = matrizz[0][0];

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (matrizz[i][j] < minValue) {
                minValue = matrizz[i][j];
                minLin = i;
                minCol = j;
            }
        }
    }

    double maxInMinLin = matrizz[minLin][0];
    int maxCol = 0;
    for (int j = 1; j < COLUNAS; j++) {
        if (matrizz[minLin][j] > maxInMinLin) {
            maxInMinLin = matrizz[minLin][j];
            maxCol = j;
        }
    }

    printf("%.4f %d %d\n", maxInMinLin, minLin, maxCol);

    return 0;
}
