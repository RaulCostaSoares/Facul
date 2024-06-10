#include <stdio.h>

#define tam 10

int main() {
    int numeros[tam];
    int even[tam], casos[tam];
    int contaEvento = 0, contaCasos = 0;

    for (int i = 0; i < tam; i++) {
        scanf("%d", &numeros[i]);
    }

    for (int i = 0; i < tam; i++) {
        if (numeros[i] % 2 == 0) {
            even[contaEvento] = numeros[i];
            contaEvento++;
        } else {
            casos[contaCasos] = numeros[i];
            contaCasos++;
        }
    }

    for (int i = 0; i < contaEvento; i++) {
        printf("%d ", even[i]);
    }
    printf("\n");

    for (int i = 0; i < contaCasos; i++) {
        printf("%d ", casos[i]);
    }
    printf("\n");

    return 0;
}
