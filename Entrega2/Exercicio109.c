#include <stdio.h>
#include <math.h>


int main(){

    int salT, sal, nota100, nota50, nota10, nota5, nota1;
    
    scanf("%d", &sal);
    salT = sal;
    nota100 = sal / 100;
    sal %= 100;
    nota50 = sal / 50;
    sal %= 50;
    nota10 = sal / 10;
    sal %= 10;
    nota5 = sal / 5;
    sal %= 5;
    nota1 = sal;
    
    printf("%d %d %d %d %d %d\n", salT, nota100, nota50, nota10, nota5, nota1);

    return 0;
}