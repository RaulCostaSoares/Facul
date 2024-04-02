#include <stdio.h>

int main(){

    double prec, desc, valF, valD;

    scanf("%lf", &prec);

    if(prec<=30.0){
        desc = 1.0;
    } else if(prec>30.0 && prec <=100.0){
        desc = 0.9;
    } else if(prec>100.0){
        desc = 0.85;
    }

    valF = (prec*desc);
    valD = prec - valF;

    printf("%.4lf\n", valD);
    printf("%.4lf", valF);

    return 0;
}