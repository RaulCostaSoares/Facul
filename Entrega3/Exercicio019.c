#include <stdio.h>

int main(){

    int i;

    scanf("%d", &i);

    if(i<5){
        printf("SEM CATEGORIA");
    } else if(i>=5 && i<=7){
        printf("Infantil");
    } else if(i>=8 && i<=10){
        printf("Juvenil");
    } else if(i>=11 && i<=15){
        printf("Adolescenet");
    } else if(i>=16 && i<=30){
        printf("Adulto");
    } else if(i>30){
        printf("Senior");
    }

    return 0;
}