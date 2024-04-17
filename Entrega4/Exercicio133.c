#include <stdio.h>

int main(){

    int cod1, cod2, cod3, cod4, cod5, cod6;
    double prec1, prec2, prec3, prec4, prec5, prec6;

        scanf("%d", &cod1);
        if(cod1 == 0){
            return 0;
        }
        scanf("%lf",&prec1);
        scanf("%d", &cod2);
        if(cod2 == 0){
            return 0;
        }
        scanf("%lf",&prec2);
        scanf("%d", &cod3);
        if(cod3 == 0){
            return 0;
        }
        scanf("%lf",&prec3);    
        scanf("%d", &cod4);
        if(cod4 == 0){
            return 0;
        }
        scanf("%lf",&prec4);
        scanf("%d", &cod5);
        if(cod5 == 0){
            return 0;
        }
        scanf("%lf",&prec5);
        scanf("%d", &cod6);
        if(cod6 == 0){
            return 0;
        }
        scanf("%lf",&prec6);
        if (cod1 % 2 == 0) {
            prec1 *= 1.15;
        } else {
            prec1 *= 1.20;
        }
        if (cod2 % 2 == 0) {
            prec2 *= 1.15;
        } else {
            prec2 *= 1.20;
        }
        if (cod3 % 2 == 0) {
            prec3 *= 1.15;
        } else {
            prec3*= 1.20;
        }
        if (cod4 % 2 == 0) {
            prec4 *= 1.15;
        } else {
            prec4 *= 1.20;
        }
        if (cod5 % 2 == 0) {
            prec5 *= 1.15;
        } else {
            prec5 *= 1.20;
        }
        if (cod6 % 2 == 0) {
            prec6 *= 1.15;
        } else {
            prec6 *= 1.20;
        }

        // Imprimir o código e o preço reajustado
        printf("%d %.4lf\n", cod1, prec1);
        printf("%d %.4lf\n", cod2, prec2);
        printf("%d %.4lf\n", cod3, prec3);
        printf("%d %.4lf\n", cod4, prec4);
        printf("%d %.4lf\n", cod5, prec5);
        printf("%d %.4lf\n", cod6, prec6);
    




    return 0;
}