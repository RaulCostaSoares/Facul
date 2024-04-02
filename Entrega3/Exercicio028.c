#include <stdio.h>

int main(){

    double sal, grat, salF;

    scanf("%lf", &sal);

    if(sal<=350.0){
        grat = 100.0;
    } else if(sal>350.0 && sal<600.0){
        grat = 75.0;
    } else if(sal>=600.0 && sal<=900.0){
        grat = 50.0;
    } else if(sal>900.0){
        grat = 35.0;
    }

    salF = (sal*0.93) + grat;

    printf("%.4lf", salF);

    return 0;
}