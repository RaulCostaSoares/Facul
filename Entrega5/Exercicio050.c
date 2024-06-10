#include <stdio.h>

#define tam 15

int main() {
    int vetor[tam];
    float maior = 0;

    for (int i = 0; i < tam; i++) {
        scanf("%d", &vetor[i]);
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }

    for (int i = 0; i < tam; i++) {
        printf("%.4f ", (float) vetor[i] / maior);
    }
    printf("\n");

    return 0;
}
