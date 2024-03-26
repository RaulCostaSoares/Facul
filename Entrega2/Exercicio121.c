#include <stdio.h>


int main(){

    int num, d1, d2, d3, numInv;
    
    scanf("%d", &num);

    d1 = num/100;
    d2 = (num/10)%10;
    d3 = num%10;

    numInv = d3*100+d2*10+d1;

    printf("%d ", numInv);

    return 0;
}