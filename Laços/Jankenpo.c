#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define PEDRA 0
#define PAPEL 1
#define TESOURA 2

void joken(){

    char inp[20];
    int opcao, random, i, vit_eu = 0, vit_comp = 0;
    
        printf("Jankenpo 1.0\n");
        printf("Digite sua resposta: ");
        fgets(inp, 20, stdin);

        if(strcmp("PEDRA\n", inp)==0 || strcmp("pedra\n", inp)==0){
            opcao = PEDRA;
        } else if(strcmp("PAPEL\n", inp)==0 || strcmp("papel\n", inp)==0){
            opcao = PAPEL;
        } else if(strcmp("TESOURA\n", inp)==0 || strcmp("tesoura\n", inp)==0){
            opcao = TESOURA;
        } else {
            printf("Opcao invalida!\n");
            return 1;
        }
        // computador
        srand(time(NULL));
        random = rand() % 3;

        switch (random){
        case PEDRA:
            printf("Computador jogou pedra\n");
            break;
        case PAPEL:
            printf("Computador jogou papel\n");
            break;
        case TESOURA:
            printf("Computador jogou tesoura\n");
            break;
        default:
            printf("Deu errado\n");
            break;
        }
        // VITÓRIA
        if(random == opcao){
            vit_eu++;
            vit_comp++;
        } else if((random == PEDRA && opcao == TESOURA) ||
                (random == TESOURA && opcao == PAPEL) ||
                (random == PAPEL && opcao == PEDRA)){
            vit_comp++;
        } else {
            vit_eu++;
        }    
}

int main(){

    char inp[20];
    int opcao, random, i, vit_eu = 0, vit_comp = 0, final;

    
    printf("Jankenpo 1.0\n");
    for(i=0;i<3;i++){
        printf("Digite sua resposta: ");
        fgets(inp, 20, stdin);

        if(strcmp("PEDRA\n", inp)==0 || strcmp("pedra\n", inp)==0){
            opcao = PEDRA;
        } else if(strcmp("PAPEL\n", inp)==0 || strcmp("papel\n", inp)==0){
            opcao = PAPEL;
        } else if(strcmp("TESOURA\n", inp)==0 || strcmp("tesoura\n", inp)==0){
            opcao = TESOURA;
        } else {
            printf("Opcao invalida!\n");
            return 1;
        }
        // computador
        srand(time(NULL));
        random = rand() % 3;

        switch (random){
        case PEDRA:
            printf("Computador jogou pedra\n");
            break;
        case PAPEL:
            printf("Computador jogou papel\n");
            break;
        case TESOURA:
            printf("Computador jogou tesoura\n");
            break;
        default:
            printf("Deu errado\n");
            break;
        }
        // VITÓRIA
        if(random == opcao){
            // printf("Empatou\n");
            vit_eu++;
            vit_comp++;
        } else if((random == PEDRA && opcao == TESOURA) ||
                (random == TESOURA && opcao == PAPEL) ||
                (random == PAPEL && opcao == PEDRA)){
            // printf("Computador ganhou!\n");
            vit_comp++;
        } else {
            // printf("Voce ganhou!\n");
            vit_eu++;
        }
    }
    if(vit_comp>vit_eu){
        printf("Computador ganhou");
    } else if(vit_comp<vit_eu){
        printf("Voce ganhou");
    } else {
        printf("Empate, refaca\n");
        while(vit_comp == vit_eu){
                    printf("Digite sua resposta: ");
        fgets(inp, 20, stdin);

        if(strcmp("PEDRA\n", inp)==0 || strcmp("pedra\n", inp)==0){
            opcao = PEDRA;
        } else if(strcmp("PAPEL\n", inp)==0 || strcmp("papel\n", inp)==0){
            opcao = PAPEL;
        } else if(strcmp("TESOURA\n", inp)==0 || strcmp("tesoura\n", inp)==0){
            opcao = TESOURA;
        } else {
            printf("Opcao invalida!\n");
            return 1;
        }
        // computador
        srand(time(NULL));
        random = rand() % 3;

        switch (random){
        case PEDRA:
            printf("Computador jogou pedra\n");
            break;
        case PAPEL:
            printf("Computador jogou papel\n");
            break;
        case TESOURA:
            printf("Computador jogou tesoura\n");
            break;
        default:
            printf("Deu errado\n");
            break;
        }
        // VITÓRIA
        if(random == opcao){
            // printf("Empatou\n");
            vit_eu++;
            vit_comp++;
        } else if((random == PEDRA && opcao == TESOURA) ||
                (random == TESOURA && opcao == PAPEL) ||
                (random == PAPEL && opcao == PEDRA)){
            // printf("Computador ganhou!\n");
            vit_comp++;
        } else {
            // printf("Voce ganhou!\n");
            vit_eu++;
        }
        // retornar o valor maior e conferir com um if depois do while
        }

    }
    return 0;
}