#include <stdio.h>

int main(){

    double e, f, p, h;

    scanf("%lf\n", &e);
    scanf("%lf", &f);

    h = (e-((2.0/3.0)*f))*60;

    if (h>=2400.0){
        p = 500.0;
    } else if(h>=1800.0 && h<2400.0){
        p = 400.0;
    } else if(h>=1200.0 && h<1800.0){
        p = 300.0;
    } else if(h>=600.0 && h<1200.0){
        p = 200.0;
    } else if(h<600.0){
        p = 100.0;
    }
    printf("%.4lf",p);
    

    return 0;
}