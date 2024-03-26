#include <stdio.h>

int main(){

    int num1, num2;
    double prec1, prec2, perc, soma, somaIpi;
    
    scanf("%d", &num1);
    scanf("%lf", &prec1);
    scanf("%d", &num2);
    scanf("%lf", &prec2);
    scanf("%lf", &perc);
    
    soma = (num1*prec1)+(num2*prec2);
    somaIpi = soma+(soma*(perc/100));
    
    printf("%.4lf\n", somaIpi);

    return 0;
}