#include <stdio.h>


int main(){

    double custoFab, percDist, percImp, valor;
    
    scanf("%lf", &custoFab);
    scanf("%lf", &percDist);
    scanf("%lf", &percImp);

    valor = custoFab+(custoFab*percDist/100)+(custoFab*percImp/100);


    printf("%.4lf", valor);

    return 0;
}