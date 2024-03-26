#include <stdio.h>


int main(){

    double diaria, diariaPro, arrec, arrecPro, lucro;
    
    scanf("%lf", &diaria);

    diariaPro = diaria*0.78;
    arrec = (42*0.4)*100*30;
    arrecPro = (42*0.7)*(100*0.78)*30;
    lucro = arrecPro - arrec;    

    printf("%.4lf ", diariaPro);
    printf("%.4lf ", arrec);
    printf("%.4lf ", arrecPro);
    printf("%.4lf", lucro);

    return 0;
}