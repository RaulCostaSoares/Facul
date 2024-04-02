#include <stdio.h>

int main(){

    double p, u, r, soma;
    
    scanf("%lf", &p);
    scanf("%lf", &u);
    scanf("%lf", &r);

    soma = (((p + u)*(u-p+r))/(2*r));
    
    printf("%.4lf\n", soma);

    return 0;
}