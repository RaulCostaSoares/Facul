#include <stdio.h>

int bolas = 33;
int bolasJogador = 15;
int pos[5];
int jogadas;

int main(){

    printf("Joragas quantas vezes?\n");
    printf("Minimo de %d vezes\n", bolasJogador);
    while(1){
        scanf("%d", &jogadas);
        if(jogadas<=bolasJogador){
            // int r = rand() % 6 + 1;
            // printf("%d",r);
            // fazer funcao que de um numero aleatorio de 1 a 6
            break;
        }
        printf("MENOR QUE %d VEZEZ\n", bolasJogador);
    }

    return 0;
}