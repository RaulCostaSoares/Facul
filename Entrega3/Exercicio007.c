#include <stdio.h>

int main(){

    double a, b, c;

    scanf("%lf\n",&a);
    scanf("%lf\n",&b);
    scanf("%lf",&c);

    if (a>b && a>c){

        printf("%.4lf", a);

    } else if(b>c && b>a){

        printf("%.4lf", b);

    } else{

        printf("%.4lf", c);
        
    }

    return 0;
}