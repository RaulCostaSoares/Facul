#include <stdio.h>

int main(){

    double a, b, c, res;

    scanf("%lf\n",&a);
    scanf("%lf\n",&b);
    scanf("%lf",&c);

    res = (a+b+c)/3;

    printf("%.4lf\n", res);

    if (res>=7.0 && res<=10.0)
    {
        printf("Aprovado");
    } else if (res>=3.0 && res<7.0)
    {
        printf("Exame");
    } else if (res>=0.0 && res<3.0)
    {
        printf("Reprovado");
    }
    
    return 0;
}