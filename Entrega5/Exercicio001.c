#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int num[9];

    for (int i = 0; i < 9; i++) {
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < 9; i++) {
        if (is_prime(num[i])) {
            printf("%d %d\n", num[i], i);
        }
    }

    return 0;
}
