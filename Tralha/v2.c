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

char dado[6][4]; // cada elemento é uma string de 3 caracteres mais o terminador nulo
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

void criaSpec() {
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

void criaPos(int pos[], int bolasBuraco) {
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

void situation(char *nomeJogador, int bolasJogador, int bolasMaquina, int r[]) {
    // Configurar os valores de dado
    for (int i = 0; i < 6; i++) {
        if (r[i] == 1) {
            strcpy(dado[i], "|X|");
        } else {
            strcpy(dado[i], "| |");
        }
    }

    printf(" ______________________________________________________________________________________________________________\n");
    printf("|                                  |                                   |         %s   %s   %s                   |\n", dado[0], dado[1], dado[2]);
    printf("|   Jogador: %s            |           Oponente: Maquina               |                              |\n", nomeJogador);
    printf("|                                  |                                   |         %s   %s   %s                   |\n", dado[3], dado[4], dado[5]);
    printf("|   Bolas na possuidas: %d         |   Bolas na possuidas: %d          |                            |\n", bolasJogador, bolasMaquina);
    printf("|                                  |                                   |         %s   texto texto                      |\n", dado[0]); // Ajuste aqui para um índice válido se necessário
    printf("|__________________________________|___________________________________|____________________________|\n");
}

void jogadorJoga(char *nomeJogador) {
    printf("Joragas quantas vezes?\n");
    printf("Minimo de %d vezes\n", bolasJogador);

    while (1) {
        scanf("%d", &jogadas);
        if (jogadas <= bolasJogador) {
            for (int i = 0; i < jogadas; i++) {
                printf("Deseja jogar o dado?(s/n)");
                scanf("%s", s);
                while (strcmp(s, "n") == 0) {
                    scanf("%s", s);
                }
                int r[6];
                for (int j = 0; j < 6; j++) {
                    r[j] = rolar_dado();
                }

                if (r[0] >= 1 && r[0] <= 5) {
                    if (pos[r[0] - 1] == 1) {
                        bolasJogador++;
                        pos[r[0] - 1] = 0;
                    } else {
                        pos[r[0] - 1] = 1;
                        bolasJogador--;
                    }
                } else if (r[0] == 6) {
                    bolasBuraco++;
                    bolasJogador--;
                }

                limparTerminal();
                criaSpec();
                criaPos(pos, bolasBuraco);
                situation(nomeJogador, bolasJogador, bolasMaquina, r);
                printf("Resultado do dado: %d\n", r[0]);
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
    }
}

void maquinaJoga() {
    for (int i = 0; i < bolasMaquina; i++) {
        sleep(1);  // delay de 1 segundo para a maquina

        int r[6];
        for (int j = 0; j < 6; j++) {
            r[j] = rolar_dado();
        }

        if (r[0] >= 1 && r[0] <= 5) {
            if (pos[r[0] - 1] == 1) {
                bolasMaquina++;
                pos[r[0] - 1] = 0;
            } else {
                pos[r[0] - 1] = 1;
                bolasMaquina--;
            }
        } else if (r[0] == 6) {
            bolasBuraco++;
            bolasMaquina--;
        }

        limparTerminal();
        criaSpec();
        criaPos(pos, bolasBuraco);
        situation(nomeJogador, bolasJogador, bolasMaquina, r);

        printf("Resultado do dado: %d\n", r[0]);
        for (int i = 0; i < 5; i++) {
            printf("%d", pos[i]);
        }
        printf("\n");
    }
}

void completa(char n[10]) {
    int tam = strlen(n);
    while (tam < 10) {
        n[tam] = ' ';
        tam++;
    }
    n[tam] = '\0';
}

void roboGanha() {
    limparTerminal();
    printf(" _________________________________________________________________\n");
    printf("|                _             _                    _             |\n");
    printf("|               | |           | |                  (_)            |\n");
    printf("|   _ __   ___  | |__    ___  | |_     __      __ _  _ __   ___   |\n");
    printf("|  | '__| / _ \\ | '_ \\  / _ \\ | __|    \\ \\ /\\ / /| || '_ \\ / __|  |\n");
    printf("|  | |   | (_) || |_) || (_) || |_      \\ V  V / | || | | |\\__ \\  |\n");
    printf("|  |_|    \\___/ |_.__/  \\___/  \\__|      \\_/\\_/  |_||_| |_||___/  |\n");
    printf("|_________________________________________________________________|\n");
    printf(" _________________________________________________________________\n");
    printf("|                                                                 |\n");
    printf("|           Infelizmente %s voce perdeu                   |\n", nomeJogador);
    printf("|_________________________________________________________________|\n");
}

void jogadorGanha() {
    limparTerminal();
    printf(" _________________________________________________________________\n");
    printf("|     _   _   ___   _   _                     _                   |\n");
    printf("|    | | | | / _ \\ | | | |                   (_)                  |\n");
    printf("|    | |_| || (_) || |_| |        __      __ _  _ __   ___        |\n");
    printf("|     \\__, | \\___/  \\__,        \\ \\ /\\ / / | || '_ \\ / __|       |\n");
    printf("|  | | (_) || |                  \\ V  V / | || | | |\\__ \\        |\n");
    printf("|  |_|\\___/ |_|          \\_/\\_/  |_||_| |_||___/        |\n");
    printf("|_________________________________________________________________|\n");
}
int main(){
    srand(time(NULL));
    
    printf("Qual seu nome?"); // lembrar de fazer com que o nome nao pegue o espaço porque da errado
    scanf("%s",nomeJogador);
    completa(nomeJogador);
    
    while(bolasJogador != 0 && bolasMaquina != 0){
        
        jogadorJoga(nomeJogador);
        if (bolasJogador != 0){
            maquinaJoga();
        }
    }

    if (bolasJogador == 0){
        jogadorGanha(nomeJogador);
        // printf("Parabens, %s voce ganhou!", nomeJogador);
    } else {
        roboGanha(nomeJogador);
        // printf("Que pena, a maquina ganhou");
    }
    
    return 0;
}