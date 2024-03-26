#include <stdio.h>


int main(){

    double a, b, c, maior;
    
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    if(a>=b && a>=c){

        maior = a;
    } else if(b>=a && b>=c){

        maior = b;

    } else{

        maior = c;
    }

    printf("%.4lf E O MAIOR", maior);

    return 0;
}