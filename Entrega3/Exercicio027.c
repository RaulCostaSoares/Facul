#include <stdio.h>

int main(){

    double sal, aum, salF;

    scanf("%lf", &sal);

    if(sal<=300.0){
        aum = 15.0;
    } else if(sal>300.0 && sal<600.0){
        aum = 10.0;
    } else if(sal>=600.0 && sal<=900.0){
        aum = 5.0;
    } else {
        aum = 0;
    }

    salF = sal + (sal*(aum/100));

    printf("%.4lf\n", sal*(aum/100));
    printf("%.4lf", salF);


    return 0;
}