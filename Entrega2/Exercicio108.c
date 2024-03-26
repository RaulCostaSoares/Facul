#include <stdio.h>
#include <math.h>


int main(){

    double v, a, d;
    
    scanf("%lf", &v);
    scanf("%lf", &a);
    
    d = sqrt(pow(v * 30, 2) - pow(a, 2));
    
    printf("%.4lf\n", d);

    return 0;
}