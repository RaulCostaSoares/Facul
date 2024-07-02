#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int bolas = 33;
int bolasJogador = 15;
int bolasMaquina = 15;
int bolasBuraco = 0;
//            0 1 2 3 4 
int pos[5] = {1,0,1,0,1};
int jogadas;

char s[3]; // sim ou nao
char nomeJogador[10];


void limparTerminal() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
int rolar_dado() {
    return (rand() % 6) + 1;
}

void criaSpec(){
    printf(" ______________________________________________________________________________________________________________\n");
    printf("|   ____     _____     _______     _____                                             _____________   _______   |\n");
    printf("|  /        /     |   |           /          |         |   |               /\\              |        |          |\n");
    printf("|  |        |     |   |          |           |         |   |              /  \\             |        |          |\n");
    printf("|   \\       |_____/   |_______   |           |         |   |             /    \\            |        |_______   |\n");
    printf("|     \\     |         |          |           |         |   |            /______\\           |        |          |\n");
    printf("|      |    |         |          |           |         |   |           /        \\          |        |          |\n");
    printf("|   ___/    |         |_______   \\_______     \\_______/    |_______   /          \\         |        |_______   |\n");
    printf("|______________________________________________________________________________________________________________|\n");
}

void criaPos(int pos[], int bolasBuraco){
    printf(" ______________________________________________________________________________________________________________\n");
    printf("|                                                                                                              |\n");
    printf("|       1                2                  3                 4                  5                 6           |\n");
    printf("|      ___              ___                ___               ___                ___               ___          |\n");
    printf("|      |%d|              |%d|                |%d|               |%d|                |%d|               |%d|          |\n", pos[0], pos[1], pos[2], pos[3], pos[4], 0);
    printf("|                                                                                                /  /          |\n");
    printf("|_______________________________________________________________________________________________/  /___________|\n");
    printf("|                                                                                                              |\n");
    printf("|                                                   %d                                                          |\n", bolasBuraco);
    printf("|______________________________________________________________________________________________________________|\n");

}

void situation(char *nomeJogador, int bolasJogador, int bolasMaquina){
    printf(" ______________________________________________________________________________________________________________\n");
    printf("|                                                |                                                              |\n");
    printf("|   Jogador: %s  Bolas na mao: %d        |          Oponente: Maquina      Bolas na mao: %d             |\n", nomeJogador, bolasJogador, bolasMaquina);
    printf("|                                                |                                                              |\n");
    printf("|                                                |                                                              |\n");
    printf("|________________________________________________|______________________________________________________________|\n");


}

void jogadorJoga(char *nomeJogador){
    
    printf("Joragas quantas vezes?\n");
    printf("Minimo de %d vezes\n", bolasJogador);

    while(1){
        scanf("%d", &jogadas);
        if(jogadas<=bolasJogador){
            for(int i=0;i<jogadas;i++){

                printf("Deseja jogar o dado?(s/n)");
                scanf("%s", s);
                while(strcmp(s, "n")==0){
                    scanf("%s", s);
                }
                int r = rolar_dado();

                if(r>=1 && r<=5){
                    if(pos[r-1] == 1){
                        bolasJogador++;
                        pos[r-1] = 0;
                    } else {
                        pos[r-1] = 1;
                        bolasJogador--;
                    }
                } else if(r==6){
                    bolasBuraco++;
                    bolasJogador--;
                }

                limparTerminal();
                criaSpec();
                criaPos(pos, bolasBuraco);
                situation(nomeJogador, bolasJogador, bolasMaquina);
                printf("Resultado do dado: %d\n",r);
                for (int i = 0; i < 5; i++) {
                    printf("%d ", pos[i]);
                }


                printf("\n");
                printf("Numero de bolas do jogador: %d \n\n", bolasJogador);


            }    
                break;
        }
        printf("MENOR QUE %d VEZEZ\n", bolasJogador);
        criaSpec();
        criaPos(pos, bolasBuraco);
        // limparTerminal();
    }
    // return 0;
}

void maquinaJoga(){

    while(1){
        for(int i=0;i<bolasMaquina;i++){
            sleep(1);                         // delay de 1 segundo
            
            int r = rolar_dado();
            if(r>=1 && r<=5){
                if(pos[r-1] == 1){
                    bolasMaquina++;
                    pos[r-1] = 0;
                } else {
                    pos[r-1] = 1;
                    bolasMaquina--;
                }
            } else if(r==6){
                bolasBuraco++;
                bolasMaquina--;
            }

            limparTerminal();
            criaSpec();
            criaPos(pos, bolasBuraco);
            situation(nomeJogador, bolasJogador, bolasMaquina);
            printf("Resultado do dado: %d\n",r);
            for (int i = 0; i < 5; i++) {
                printf("%d ", pos[i]);
            }
            // printf("\n");
            // printf("Numero de bolas do jogador: %d \n\n", bolasJogador);
        }    
            break;
    }
        // printf("MENOR QUE %d VEZEZ\n", bolasJogador);
        // criaSpec();
        // criaPos(pos, bolasBuraco);
        // // limparTerminal();
}

void completa(char n[10]) {
    int tam = strlen(n);
    while (tam<10) {
        n[tam] = ' ';
        tam++;
    }

    n[tam] = '\0';
}

int main(){
    srand(time(NULL));
    
    printf("Qual seu nome?");
    scanf("%s",nomeJogador);
    completa(nomeJogador);
    
    jogadorJoga(nomeJogador);    
    maquinaJoga();
    return 0;
}