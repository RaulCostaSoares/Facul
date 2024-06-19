#include <stdio.h>

#define tamanho 8

int main() {
    int matrizz[tamanho][tamanho];

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            scanf("%d", &matrizz[i][j]);
        }
    }

    int simetrica = 1;
    for (int i = 0; i < tamanho && simetrica; i++) {
        for (int j = 0; j < tamanho && simetrica; j++) {
            if (matrizz[i][j] != matrizz[j][i]) {
                simetrica = 0;
            }
        }
    }

    if (simetrica) {
        printf("Matriz Simetrica\n");
    } else {
        printf("Matriz Assimetrica\n");
    }

    return 0;
}
