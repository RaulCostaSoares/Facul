#include <stdio.h>

#define tam 15

int main() {
    int array[tam];

    for (int i = 0; i < tam; i++) {

        scanf("%d", &array[i]);

    }
    for (int i = 0; i < tam; i++) {
        if (array[i] == 30) {

            printf("%d\n", i);

        }
    }
    return 0;
}
