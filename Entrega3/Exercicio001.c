#include <stdio.h>

int main(){

    double trabLab, avSem, exFin, res;

    scanf("%lf\n",&trabLab);
    scanf("%lf\n",&avSem);
    scanf("%lf",&exFin);

    res = ((2*trabLab)+(3*avSem)+(5*exFin))/(2+3+5);

    printf("%.4lf\n", res);

    if (res>=8.0 && res<=10.0)
    {
        printf("A");
    } else if (res>=7.0 && res<8.0)
    {
        printf("B");
    } else if (res>=6.0 && res<7.0)
    {
        printf("C");
    } else if (res>=5.0 && res<6.0)
    {
        printf("D");
    } else if (res>=0.0 && res<5.0)
    {
        printf("E");
    }
    
    

    return 0;
}