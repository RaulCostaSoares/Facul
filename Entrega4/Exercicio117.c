#include <stdio.h>

int main(){

    int i, o;
    double en=1.0, fat = 1.0;
    scanf("%d", &o);
 
    for (i = 1; i <= o; i++) {
      fat *= i;
      en += 1.0 / fat;
    }
   
    printf("%.4lf\n", en);

    return 0;
}