#include <stdio.h>


int main(){

    int num;
    double salFixo, totVendas, percVendas, sal;
    
    scanf("%d", &num);
    scanf("%lf", &salFixo);
    scanf("%lf", &totVendas);
    scanf("%lf", &percVendas);

    sal = salFixo+((totVendas*percVendas)/100);

    printf("%d ", num);
    printf("%.4lf", sal);

    return 0;
}