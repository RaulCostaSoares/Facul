#include <stdio.h>

int main(){

    double x, y, z;

    scanf("%lf", &x);
    scanf("%lf", &y);
    scanf("%lf", &z);

    if(x>=y+z){
        printf("NAO EH TRIANGULO");
    } else if(z>=x+y){
        printf("NAO EH TRIANGULO");
    } else if(y>=z+x){
        printf("NAO EH TRIANGULO");
    } else if(x==y && x==z){
        printf("EQUILATERO");
    } else if(x!=y && x!=z && y!=z){
        printf("ESCALENO");
    } else {
        printf("ISOSCELES");        
    }

    return 0;
}