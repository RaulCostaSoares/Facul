#include <stdio.h>

int main(){

    int inv;
    double val, porc, valF;

    scanf("%d", &inv);
    scanf("%lf", &val);

    if(inv==1){
        porc = 1.03;
    } else {
        porc = 1.04;
    }
    valF = (val*porc);

    printf("%.4lf", valF);

    return 0;
}