#include <stdio.h>
#include <string.h>

int main(){

    char s[2];
    double h, out;


    scanf("%lf", &h);
    scanf("%s", s);

    if(strcmp(s, "M") == 0){
        out = (72.7*h)-58.0;
    } else {
        out = (62.1*h)-44.7;
    }

    printf("%.4lf", out);
// tem q analisar melhor o char
    return 0;
}