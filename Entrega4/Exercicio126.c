#include <stdio.h>

int fator(int o) {
      if (o == 0) {
          return 1;
      } else {
          return o * fator(o - 1);
      }
}

int main(){

    int n, quantia1 = 0, quantia2=0, quantia3=0, quantia4=0, quantia5=0, fat;
    double raiz;
    scanf("%d\n", &n);

    switch (n)
    {
    case 1:
        scanf("%d", &quantia1);
    break;

    case 2:
        scanf("%d\n", &quantia1);
        scanf("%d", &quantia2);
    break;
    case 3:
        scanf("%d\n", &quantia1);
        scanf("%d\n", &quantia2);
        scanf("%d", &quantia3);
    break;
    case 4:
        scanf("%d\n", &quantia1);
        scanf("%d\n", &quantia2);
        scanf("%d\n", &quantia3);
        scanf("%d", &quantia4);
    break;
    case 5:
        scanf("%d\n", &quantia1);
        scanf("%d\n", &quantia2);
        scanf("%d\n", &quantia3);
        scanf("%d\n", &quantia4);
        scanf("%d", &quantia5);
    break;

    default:
        break;
    }

        switch (n)
    {
    case 1:
        fat = fator(quantia1);
        raiz = cbrt(quantia1);
        printf("%d %d %.4lf\n", quantia1, fat, raiz);    
    break;

    case 2:
        fat = fator(quantia1);
        raiz = cbrt(quantia1);
        printf("%d %d %.4lf\n", quantia1, fat, raiz);
        
        fat = fator(quantia2);
        raiz = cbrt(quantia2);
        printf("%d %d %.4lf\n", quantia2, fat, raiz);
    break;
    case 3:
        fat = fator(quantia1);
        raiz = cbrt(quantia1);
        printf("%d %d %.4lf\n", quantia1, fat, raiz);
        
        fat = fator(quantia2);
        raiz = cbrt(quantia2);
        printf("%d %d %.4lf\n", quantia2, fat, raiz);
        

        fat = fator(quantia3);
        raiz = cbrt(quantia3);
        printf("%d %d %.4lf\n", quantia3, fat, raiz);
    break;
    case 4:
        fat = fator(quantia1);
        raiz = cbrt(quantia1);
        printf("%d %d %.4lf\n", quantia1, fat, raiz);
        
        fat = fator(quantia2);
        raiz = cbrt(quantia2);
        printf("%d %d %.4lf\n", quantia2, fat, raiz);
        

        fat = fator(quantia3);
        raiz = cbrt(quantia3);
        printf("%d %d %.4lf\n", quantia3, fat, raiz);

        fat = fator(quantia4);
        raiz = cbrt(quantia4);
        printf("%d %d %.4lf\n", quantia4, fat, raiz);
    break;
    case 5:
        fat = fator(quantia1);
        raiz = cbrt(quantia1);
        printf("%d %d %.4lf\n", quantia1, fat, raiz);
        
        fat = fator(quantia2);
        raiz = cbrt(quantia2);
        printf("%d %d %.4lf\n", quantia2, fat, raiz);
        

        fat = fator(quantia3);
        raiz = cbrt(quantia3);
        printf("%d %d %.4lf\n", quantia3, fat, raiz);

        fat = fator(quantia4);
        raiz = cbrt(quantia4);
        printf("%d %d %.4lf\n", quantia4, fat, raiz);
        
        fat = fator(quantia5);
        raiz = cbrt(quantia5);
        printf("%d %d %.4lf\n", quantia5, fat, raiz);
    break;

    default:
    break;
    }

    return 0;
}