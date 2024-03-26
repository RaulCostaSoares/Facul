#include <stdio.h>

int main(){

    int num, res;

    scanf("%d", &num);

    for(res=1;num>1;num=num-1){

        res= res*num;
    };
   
    printf("%d\n", res);

    return 0;
}