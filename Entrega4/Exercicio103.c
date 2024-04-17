#include <stdio.h>

int main(){

    double a, b, c, d, e, f, g, h, i, j;
    int quantD = 0, quantF = 0;

    scanf("%lf\n", &a);
    scanf("%lf\n", &b);
    scanf("%lf\n", &c);
    scanf("%lf\n", &d);
    scanf("%lf\n", &e);
    scanf("%lf\n", &f);
    scanf("%lf\n", &g);
    scanf("%lf\n", &h);
    scanf("%lf\n", &i);
    scanf("%lf", &j);

    if(a>=10.0 && a<=20.0){
        quantD++;
    } else {
        quantF++;
    }
    if(b>=10.0 && b<=20.0){
        quantD++;
    } else {
        quantF++;
    }
    if(c>=10.0 && c<=20.0){
        quantD++;
    } else {
        quantF++;
    }
    if(d>=10.0 && d<=20.0){
        quantD++;
    } else {
        quantF++;
    }
    if(e>=10.0 && e<=20.0){
        quantD++;
    } else {
        quantF++;
    }
    if(f>=10.0 && f<=20.0){
        quantD++;
    } else {
        quantF++;
    }
    if(g>=10.0 && g<=20.0){
        quantD++;
    } else {
        quantF++;
    }
    if(h>=10.0 && h<=20.0){
        quantD++;
    } else {
        quantF++;
    }
    if(i>=10.0 && i<=20.0){
        quantD++;
    } else {
        quantF++;
    }
    if(j>=10.0 && j<=20.0){
        quantD++;
    } else {
        quantF++;
    }

    printf("%d\n", quantD);
    printf("%d", quantF);

    return 0;
}