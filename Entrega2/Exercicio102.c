#include <stdio.h>

int main(){

    double hTrab, valHora, salFam, salTot;
    int numFunc, numFilho;

    scanf("%d", &numFunc);
    scanf("%lf", &hTrab);
    scanf("%lf", &valHora);
    scanf("%d", &numFilho);
    scanf("%lf", &salFam);
    // 
    salTot = (hTrab*valHora)+salFam;
    // 
   
    printf("%d\n", numFunc);
    printf("%.4lf", salTot);


    return 0;
}