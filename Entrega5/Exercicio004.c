#include <stdio.h>

int main() {
    int orig[8];
    int pos[8];
    int neg[8];
    int posConta = 0;
    int negConta = 0;

    for (int i = 0; i < 8; i++) {
        scanf("%d", &orig[i]);
    }

    for (int i = 0; i < 8; i++) {
        if (orig[i] > 0) {
            pos[posConta] = orig[i];
            posConta++;
        } else if (orig[i] < 0) {
            neg[negConta] = orig[i];
            negConta++;
        }
    }

    if (posConta > 0) {
        for (int i = 0; i < posConta; i++) {
            printf("%d ", pos[i]);
        }
        printf("\n");
    } else {
        printf("\n");
    }

    if (negConta > 0) {
        for (int i = 0; i < negConta; i++) {
            printf("%d ", neg[i]);
        }
        printf("\n");
    } else {
        printf("\n");
    }

    return 0;
}
