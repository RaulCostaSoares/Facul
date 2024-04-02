#include <stdio.h>

int main(){

    double pi, a, b, c, aTri, aCirc, aTrap, aQuad, aRet, aSupCubo;
    
    pi = 3.14159265359;

    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    aTri = (a*b)/2;
    aCirc = (pi*(c*c));
    aTrap = ((a+b)/2)*c;
    aQuad = b*b;
    aRet = a*b;
    aSupCubo = (c*c)*6;

    printf("%.4lf\n", aTri);
    printf("%.4lf\n", aCirc);
    printf("%.4lf\n", aTrap);
    printf("%.4lf\n", aQuad);
    printf("%.4lf\n", aRet);
    printf("%.4lf\n", aSupCubo);

    return 0;
}