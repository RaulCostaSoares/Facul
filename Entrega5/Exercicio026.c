#include <stdio.h>

int main() {
    int num[6];
    int event[6], casos[6];
    int contaEvento = 0, contaCaso = 0;

    for (int i = 0; i < 6; i++) {
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < 6; i++) {
        if (num[i] % 2 == 0) {
            event[contaEvento] = num[i];
            contaEvento++;
        } else {
            casos[contaCaso] = num[i];
            contaCaso++;
        }
    }

    printf("%d\n", contaEvento);

    for (int i = 0; i < contaEvento; i++) {
        printf("%d ", event[i]);
    }
    if (contaEvento > 0) {
        printf("\n");
    }

    printf("%d\n", contaCaso);

    for (int i = 0; i < contaCaso; i++) {
        printf("%d ", casos[i]);
    }
    if (contaCaso > 0) {
        printf("\n");
    }

    return 0;
}
