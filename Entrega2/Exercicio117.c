#include <stdio.h>


int main(){

    double compraDolar, taxaDolar, valorReais;
    
    scanf("%lf", &compraDolar);
    scanf("%lf", &taxaDolar);

    valorReais = compraDolar*taxaDolar;

    printf("%.4lf", valorReais);

    return 0;
}