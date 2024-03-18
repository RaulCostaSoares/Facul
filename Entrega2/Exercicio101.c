#include <stdio.h>

int main(){

    int a, b, c, media;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    media = (a + b + c) / 3;
    printf("A media e:%d", media);
    // printf("%d %d %d", a, b, c);
    return 0;
}