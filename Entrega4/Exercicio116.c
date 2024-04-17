#include <stdio.h>

int main(){

    double base, altura, area;
    int i=0, o=0;

    while(i==0){
        scanf("%lf", &base);
        if(base>0){
            i++;
        } else {
            i = 0;
        }
    }
    while(o==0){
        scanf("%lf", &altura);
        if(altura>0){
            o++;
        } else {
            o = 0;
        }
    }

    area = (base*altura)/2;

    printf("%.4lf", area);
    // printf("%lf", altura);

    return 0;
}