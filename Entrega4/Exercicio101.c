#include <stdio.h>

int main(){

    double a, b, c, d, e;
    int quant = 0;

    scanf("%lf\n", &a);
    scanf("%lf\n", &b);
    scanf("%lf\n", &c);
    scanf("%lf\n", &d);
    scanf("%lf", &e);

    if(a<0){
        quant++;
    }
    if(b<0){
        quant++;
    }
    if(c<0){
        quant++;
    }
    if(d<0){
        quant++;
    }
    if(e<0){
        quant++;
    }

    printf("%d", quant);

    return 0;
}