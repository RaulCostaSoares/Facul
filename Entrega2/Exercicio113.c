#include <stdio.h>


int main(){

    int num, numCarros;
    double valCarros, salFixo, comCarros, salario;
    
    scanf("%d", &num);
    scanf("%d", &numCarros);
    scanf("%lf", &valCarros);
    scanf("%lf", &salFixo);
    scanf("%lf", &comCarros);

    salario = (salFixo)+(numCarros*comCarros)+((numCarros*valCarros)*0.05);


    printf("%.4lf", salario);

    return 0;
}