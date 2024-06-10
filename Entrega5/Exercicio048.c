#include <stdio.h>

#define tam 5

int main() {
    int A[tam], B[tam];

    for (int i = 0; i < tam; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < tam; i++) {
        scanf("%d", &B[i]);
    }

    for (int i = 0; i < tam; i++) {
        printf("%d ", B[i] - A[tam - 1 - i]);
    }
    printf("\n");

    return 0;
}
