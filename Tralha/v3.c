#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int bolas = 33;
int bolasJogador = 1;
int bolasMaquina = 15;
int bolasBuraco = 0;
int pontuacao = 0;
int praTabela[8] = {10000};
char nomeTab[8][20];
//            0 1 2 3 4 
int pos[5] = {1,0,1,0,1};

int jogadas;

// char dado[3][6];
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

void situation(char *nomeJogador, int bolasJogador, int bolasMaquina, int r){
    char dadio[9][4];
    
    switch (r){

        case 1:
    
            strcpy(dadio[0], "   ");
            strcpy(dadio[1], "   ");
            strcpy(dadio[2], "   ");
            strcpy(dadio[3], "|X|");
            strcpy(dadio[4], "   ");
            strcpy(dadio[5], "   ");
            strcpy(dadio[6], "   ");

        break;
        case 2:

            strcpy(dadio[0], "   ");
            strcpy(dadio[1], "|X|");
            strcpy(dadio[2], "   ");
            strcpy(dadio[3], "   ");
            strcpy(dadio[4], "   ");
            strcpy(dadio[5], "|X|");
            strcpy(dadio[6], "   ");


        break;
        case 3:

            strcpy(dadio[0], "   ");
            strcpy(dadio[1], "|X|");
            strcpy(dadio[2], "   ");
            strcpy(dadio[3], "|X|");
            strcpy(dadio[4], "   ");
            strcpy(dadio[5], "|X|");
            strcpy(dadio[6], "   ");


        break;
        case 4:

            strcpy(dadio[0], "|X|");
            strcpy(dadio[1], "|X|");
            strcpy(dadio[2], "   ");
            strcpy(dadio[3], "   ");
            strcpy(dadio[4], "   ");
            strcpy(dadio[5], "|X|");
            strcpy(dadio[6], "|X|");

        break;
        case 5:

            strcpy(dadio[0], "|X|");
            strcpy(dadio[1], "|X|");
            strcpy(dadio[2], "   ");
            strcpy(dadio[3], "|X|");
            strcpy(dadio[4], "   ");
            strcpy(dadio[5], "|X|");
            strcpy(dadio[6], "|X|");

        break;
        case 6:

            strcpy(dadio[0], "|X|");
            strcpy(dadio[1], "|X|");
            strcpy(dadio[2], "|X|");
            strcpy(dadio[3], "   ");
            strcpy(dadio[4], "|X|");
            strcpy(dadio[5], "|X|");
            strcpy(dadio[6], "|X|");

        break;
    }

    printf(" \n\n");
    printf(" ______________________________________________________________________________________________________________\n");
    printf("|                                  |                                   |           _______________             |\n");
    printf("|                                  |                                   |          | %s       %s |            |\n", dadio[0], dadio[1]);
    printf("|   Jogador: %s            |   Oponente: Maquina               |          |               |            |\n", nomeJogador);
    printf("|                                  |                                   |          | %s  %s  %s |            |\n", dadio[2], dadio[3], dadio[4]);
    printf("|   Bolas na possuidas: %d         |   Bolas na possuidas: %d          |          |               |            |\n", bolasJogador, bolasMaquina);
    printf("|                                  |                                   |          | %s       %s |            |\n", dadio[5], dadio[6]);
    printf("|__________________________________|___________________________________|_______________________________________|\n");


}

void jogadorJoga(char *nomeJogador){
    
    printf("Joragas quantas vezes?\n");
    printf("Maximo de %d vezes\n", bolasJogador);
    
    while(1){
        scanf("%d", &jogadas);
        if(jogadas<=bolasJogador){
            for(int i=0;i<jogadas;i++){

                printf("Deseja jogar o dado?(enter/n)");
                scanf("%s", s);

                // while(strcmp(s, "n")==0){
                    // scanf("%s", s);
                // }

                while(1){
                    fgets(s, sizeof(s), stdin);
                    if(s[strlen(s)-1]=='\n'){
                        s[strlen(s)-1]='\0';
                    }
                    if(strlen(s) ==0){
                        break;
                    }
                    
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
                // printf("Resultado do dado: %d\n",r);
                // for (int i = 0; i < 5; i++) {
                    // printf("%d ", pos[i]);
                // }

                //  corrigindo
                situation(nomeJogador, bolasJogador, bolasMaquina, r);


                printf("\n");
                printf("Numero de bolas do jogador: %d \n\n", bolasJogador);


            }    
                break;
        }
        printf("MAXIMO DE %d VEZEZ\n", bolasJogador);
        // criaSpec();
        // criaPos(pos, bolasBuraco);
        // limparTerminal();
    }
    // return 0;
}

void maquinaJoga(){

        for(int i=0;i<bolasMaquina;i++){
            // sleep(1);          // delay de 1 segundo para a maquina
            
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
            situation(nomeJogador, bolasJogador, bolasMaquina, r);
            
            printf("Resultado do dado: %d\n",r);
            for (int i = 0; i < 5; i++) {
                printf("%d", pos[i]);
            }
                printf("\n");
            // printf("\n");
            // printf("Numero de bolas do jogador: %d \n\n", bolasJogador);
        }    
            // break;
    // }
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

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void roboGanha(char *nomeJogador, int pontuacao) {
    limparTerminal();

    FILE *myFile;
    int i = 0;
    char nomes[100][10];
    int pontuacoes[100];

    // Arrays para armazenar os 8 menores scores e seus nomes correspondentes
    int praTabela[8] = {10000};
    char nomeTab[8][10] = {{0}};

    myFile = fopen("tabela.txt", "r");

    if (!myFile) { //caso nao abrir
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    //le e armazena os dados para depois selecionar os 8 menores
    while (fscanf(myFile, "%s %d", nomes[i], &pontuacoes[i]) != EOF && i < 100) { // Número máximo de jogadores 100
        
        //armazena os 8 menoes        
        for (int j = 0; j < 8; j++) {
            if (praTabela[j] == 0 || pontuacoes[i] < praTabela[j]) {
                //desloca pra frente
                for (int k = 7; k > j; k--) {
                    praTabela[k] = praTabela[k - 1];
                    strcpy(nomeTab[k], nomeTab[k - 1]);
                }
                //adiciona a informação pro j atual
                praTabela[j] = pontuacoes[i];
                strcpy(nomeTab[j], nomes[i]);
                break;
            }
        }
        
        i++;
    }
    

    fclose(myFile);

    

    printf(" _________________________________________________________________    _________________________________________\n");
    printf("|                _             _                    _             |  |  1->  %s: %d          |   2->  %s: %d         |\n", nomeTab[0], praTabela[0], nomeTab[1], praTabela[1]);
    printf("|               | |           | |                  (_)            |  |___________________|_____________________|\n");
    printf("|   _ __   ___  | |__    ___  | |_     __      __ _  _ __   ___   |  |  3->  %s: %d        |  4->  %s: %d          |\n", nomeTab[2], praTabela[2], nomeTab[3], praTabela[3]);
    printf("|  | '__| / _ \\ | '_ \\  / _ \\ | __|    \\ \\ /\\ / /| || '_ \\ / __|  |  |___________________|_____________________|\n");
    printf("|  | |   | (_) || |_) || (_) || |_      \\ V  V / | || | | |\\__ \\  |  |  5->  %s: %d         |  6->  %s: %d          |\n", nomeTab[4], praTabela[4],nomeTab[5], praTabela[5]);
    printf("|  |_|    \\___/ |_.__/  \\___/  \\__|      \\_/\\_/  |_||_| |_||___/  |  |___________________|_____________________|\n");
    printf("|_________________________________________________________________|  |  7->  %s: %d        |  8->  %s: %d         |\n", nomeTab[6], praTabela[6], nomeTab[7], praTabela[7]);
    printf(" _________________________________________________________________   |___________________|_____________________|\n");
    printf("|                                                                 |  |                                         |\n");
    printf("|           Infelizmente %s voce perdeu                   |  |           %s: %d              |\n", nomeJogador, nomeJogador, pontuacao);
    printf("|_________________________________________________________________|  |_________________________________________|\n");
}

void jogadorGanha(char *nomeJogador, int pontuacao){

            
    limparTerminal();

    FILE *myFile;
    int i = 0;
    char nomes[100][10];
    int pontuacoes[100];

    int praTabela[8] = {0};
    char nomeTab[8][10] = {{0}};

    myFile = fopen("tabela.txt", "a"); //abrindo arquivo pra escrita

    if (!myFile) {//caso nao abrir
        printf("Erro ao abrir o arquivo.\n");
        return; 
    }

    fprintf(myFile, "\n%s\n %d\n", nomeJogador, pontuacao);
    fclose(myFile);

    

    myFile = fopen("tabela.txt", "r"); //abrindo arquivo pra LEITURA

    //le e armazena os dados para depois selecionar os 8 menores
    while (fscanf(myFile, "%s %d", nomes[i], &pontuacoes[i]) != EOF && i < 100) { // Número máximo de jogadores 100
        
        //armazena os 8 menoes        
        for (int j = 0; j < i; j++) {
        for (int k = 0; k < 8; k++) {
            if (praTabela[k] == 10000 || pontuacoes[j] < praTabela[k]) {
                // Desloca para frente
                for (int m = 7; m > k; m--) {
                    praTabela[m] = praTabela[m - 1];
                    strcpy(nomeTab[m], nomeTab[m - 1]);
                }
                // Adiciona a informação para o k atual
                praTabela[k] = pontuacoes[j];
                strcpy(nomeTab[k], nomes[j]);
                break;
            }
        }
    }
        i++;
    }


    fclose(myFile);

    // Imprimir novamente todos os dados lidos
    printf("\nDados lidos do arquivo:\n");
    for (int j = 0; j < i; j++) {
        printf("nome: %s, pontuacao: %d\n", nomes[j], pontuacoes[j]);
    }

    // Imprimir os 8 menores scores encontrados
    printf("\n8 menores scores:\n");
    for (int j = 0; j < 8; j++) {
        if (praTabela[j] != 0) {
            printf("nome: %s, pontuacao: %02d    %d\n", nomeTab[j], praTabela[j], j);
        }
    }

    printf(" _________________________________________________________________    _________________________________________\n");
    printf("|     _   _   ___   _   _                     _                   |  |  1->  %s: %02d    |   2->  %s: %02d    |\n", nomeTab[0], praTabela[0], nomeTab[1], praTabela[1]);
    printf("|    | | | | / _ \\ | | | |                   (_)                  |  |___________________|_____________________|\n");
    printf("|    | |_| || (_) || |_| |        __      __ _  _ __   ___        |  |  3->  %s: %02d      |  4->  %s: %02d      |\n", nomeTab[2], praTabela[2], nomeTab[3], praTabela[3]);
    printf("|     \\__, | \\___/  \\__,_|        \\ \\ /\\ / /| || '_ \\ /  __|      |  |___________________|_____________________|\n");
    printf("|      __/ |                       \\ V  V / | || | | |\\__ \\       |  |  5->  %s: %02d       |  6->  %s: %02d       |\n", nomeTab[4], praTabela[4],nomeTab[5], praTabela[5]);
    printf("|     |___/                         \\_/\\_/  |_||_| |_||___/       |  |___________________|_____________________|\n");
    printf("|_________________________________________________________________|  |  7->  %s: %02d      |  8->  %s: %02d         |\n", nomeTab[6], praTabela[6], nomeTab[7], praTabela[7]);
    printf(" _________________________________________________________________   |___________________|_____________________|\n");
    printf("|                                                                 |  |                                         |\n");
    printf("|           Parabens %s!       voce ganhou                |  |           %s:  %02d               |\n", nomeJogador, nomeJogador, pontuacao);
    printf("|_________________________________________________________________|  |_________________________________________|\n");
    printf("%d",pontuacao);


}

int main(){
    srand(time(NULL));
    pontuacao = 0;

    printf("Qual seu nome?"); // lembrar de fazer com que o nome nao pegue o espaço porque da errado
    scanf("%s",nomeJogador);
    completa(nomeJogador);
    
    // jogadorGanha();
    // criaSpec();
    
    // /*
    
    while(bolasJogador != 0 && bolasMaquina != 0){
        
        jogadorJoga(nomeJogador);
        if (bolasJogador != 0){
            pontuacao++;
            maquinaJoga();
        }
    }

    if (bolasJogador == 0){
        jogadorGanha(nomeJogador, pontuacao);
        // salvaPonto(nomeJogador, pontuacao);
        // printf("Parabens, %s voce ganhou!", nomeJogador);
    } else {
        roboGanha(nomeJogador, pontuacao);
        // printf("Que pena, a maquina ganhou");
    }
    // */
    return 0;
}