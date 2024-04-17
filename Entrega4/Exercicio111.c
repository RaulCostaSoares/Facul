#include <stdio.h>

int main(){

    int a, b, c, d, e, i=0;

    while(i==0){
        scanf("%d\n", &a);
        if(a<0){
            break;
        } else {
            i = 0;
        }
        scanf("%d\n", &b);
        if(b<0){
            break;
        } else {
            i = 0;
        }
        scanf("%d\n", &c);
        if(c<0){
            break;
        } else {
            i = 0;
        }
        scanf("%d\n", &d);
        if(d<0){
            break;
        } else {
            i = 0;
        }
        scanf("%d", &e);
        if(e<0){
            break;
        } else {
            i = 0;
        }
    }


    printf("%d\n ", a);
    printf("%d\n", b);
    printf("%d\n ", c);
    printf("%d\n ", d);
    printf("%d", e);

    return 0;
}