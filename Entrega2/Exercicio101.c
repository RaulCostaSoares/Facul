#include <stdio.h>
#include <math.h>

int main(){

    double a, b, c, ma, mh, mg, mp;

    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    // 
    ma = (a + b + c) / 3;
    // 
    mh = 3/((1/a)+(1/b)+(1/c));
    // 
    mg = cbrt(a*b*c);
    // 
    mp = ((1*a)+(2*b)+(3*c))/(1+2+3);
    // 
    printf("%.4lf\n", ma);
    printf("%.4lf\n", mh);
    printf("%.4lf\n", mg);
    printf("%.4lf\n", mp);

    return 0;
}