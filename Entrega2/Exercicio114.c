#include <stdio.h>


int main(){

    int num;
    double salAtual, inTemp, indProd, aumento, novoSalario;
    
    scanf("%d", &num);
    scanf("%lf", &salAtual);
    scanf("%lf", &inTemp);
    scanf("%lf", &indProd);

    aumento = (inTemp*0.8)+indProd;
    aumento = aumento*salAtual/100;

    novoSalario = salAtual + aumento;

    printf("%d ", num);
    printf("%.4lf ", aumento);
    printf("%.4lf", novoSalario);

    return 0;
}