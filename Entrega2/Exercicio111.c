#include <stdio.h>
#include <math.h>


int main(){

    double a, b, c, s, area;
    
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    s = (a+b+c)/2;

    area = sqrt(s*(s-a)*(s-b)*(s-c));

    printf("%.4lf", area);

    return 0;
}