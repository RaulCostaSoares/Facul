#include <stdio.h>

int main(){

    double a, b, c, r1, r2, r3;

    scanf("%lf\n",&a);
    scanf("%lf\n",&b);
    scanf("%lf",&c);

    if (a>b && a>c){

        r3 = a;
        if(b>c){
            r2 = b;
            r1 = c;
        } else{
            r2 = c;
            r1 = b;
        }

    } else if(b>c && b>a){

        r3 = b;
        if(c>a){
            r2 = c;
            r1 = a;
        } else{
            r2 = a;
            r1 = c;
        }

    } else if(c>a && c>b){

        r3 = c;
        if(a>b){
            r2 = a;
            r1 = b;
        } else{
            r2 = b;
            r1 = a;
        }
        
    } else if(a==b && b==c){

        r1=a;
        r2=b;
        r3=c;
    }

    printf("%.4lf\n", r1);
    printf("%.4lf\n", r2);
    printf("%.4lf\n", r3);

    return 0;
}