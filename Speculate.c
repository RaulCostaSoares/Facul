#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int bolas = 33;
int bolasJogador = 15;
int bolasMaquina = 1;
int bolasBuraco = 0;
int pontuacao = 0;
int praTabela[8] = {0};
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
    printf("|   Bolas na possuidas: %02d         |   Bolas na possuidas: %02d          |          |               |            |\n", bolasJogador, bolasMaquina);
    printf("|                                  |                                   |          | %s       %s |            |\n", dadio[5], dadio[6]);
    printf("|__________________________________|___________________________________|_______________________________________|\n\n");


}

void jogadorJoga(char *nomeJogador){
    
    // pergunta o nome
    printf("Joragas quantas vezes?\n");
    printf("Maximo de %d vezes\n", bolasJogador);
    
    while(1){
        scanf("%d", &jogadas);
        if(jogadas<=bolasJogador){       // verifica se a quantidade selecionada é aceitavel/menor que o que carrega
            for(int i=0;i<jogadas;i++){  // para cada jogada espera confirmar o lançamento

                printf("Deseja jogar o dado?(enter/n)");
                scanf("%s", s);
                
                // nao tem muita utilidade, caso der enter em um "n" ele vai repitir ate ser enviado qualquer digito que nao seja "n"
                while(strcmp(s, "n")==0){
                    scanf("%s", s);
                }

                int r = rolar_dado();    //rolagem de dados

                // verifica de acordo com a posição se devera recolher ou adicionar da posição, definindo se aumentara a quantidade de bolas carregadas ou não
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

                limparTerminal();        // Limpa o terminal para ser impresso o jogo
                criaSpec();              // Escreve em ASCII o nome do jogo
                criaPos(pos, bolasBuraco); // Desenha a situação das posições
                situation(nomeJogador, bolasJogador, bolasMaquina, r); // mostra o valor do dado, seu nome e a quantidade de bolas possuidas
            }    
                break;
        }
        printf("MAXIMO DE %d VEZEZ\n", bolasJogador); // Caso for selecionado um numero maior do que o possuido
    }
}

void maquinaJoga(){

    for(int i=0;i<bolasMaquina;i++){
            
        // sleep(1);          // delay de 1 segundo para a maquina

        int r = rolar_dado();    //rolagem de dados
        
        // verifica de acordo com a posição se devera recolher ou adicionar da posição, definindo se aumentara a quantidade de bolas carregadas ou não
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

        limparTerminal();        // Limpa o terminal para ser impresso o jogo
        criaSpec();              // Escreve em ASCII o nome do jogo
        criaPos(pos, bolasBuraco); // Desenha a situação das posições
        situation(nomeJogador, bolasJogador, bolasMaquina, r); // mostra o valor do dado, seu nome e a quantidade de bolas possuidas
        
    }    
}


// Funão que completa o nome com " "/espaço para caber em certos lugares
void completa(char n[10]) {
    int tam = strlen(n);
    while (tam<10) {
        n[tam] = ' ';
        tam++;
    }

    n[tam] = '\0';
}

void roboGanha(char *nomeJogador, int pontuacao) {
    limparTerminal();

    FILE *myFile;
    int i = 0;
    char nomes[100][10];
    int pontuacoes[100];

    int praTabela[8] = {0};      // Valores dos players salvos
    char nomeTab[8][10] = {{0}}; // Nome dos players salvos

    myFile = fopen("tabela.txt", "r"); //abrindo arquivo pra LEITURA

    if (!myFile) { //caso nao abrir
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // le e armazena os dados para depois selecionar os 8 menores
    while (fscanf(myFile, "%s %d", nomes[i], &pontuacoes[i]) != EOF && i < 100) { // Número máximo de jogadores 100
        
        // armazena os 8 menoes        
        for (int j = 0; j < 8; j++) {
            if (praTabela[j] == 0 || pontuacoes[i] < praTabela[j]) {
                // desloca pra frente
                for (int k = 7; k > j; k--) {
                    praTabela[k] = praTabela[k - 1];
                    strcpy(nomeTab[k], nomeTab[k - 1]);
                }
                // adiciona a informação pro j atual
                praTabela[j] = pontuacoes[i];
                strcpy(nomeTab[j], nomes[i]);
                break;
            }
        }
        i++;
    }
    
    fclose(myFile);

    printf(" _________________________________________________________________    ___________________________________________________\n");
    printf("|                _             _                    _             |  |  1->  %-10s: %02d   |  2->  %-10s: %02d     |\n", nomeTab[0], praTabela[0], nomeTab[1], praTabela[1]);
    printf("|               | |           | |                  (_)            |  |________________________|__________________________|\n");
    printf("|   _ __   ___  | |__    ___  | |_     __      __ _  _ __   ___   |  |  3->  %-10s: %02d   |  4->  %-10s: %02d     |\n", nomeTab[2], praTabela[2], nomeTab[3], praTabela[3]);
    printf("|  | '__| / _ \\ | '_ \\  / _ \\ | __|    \\ \\ /\\ / /| || '_ \\ / __|  |  |________________________|__________________________|\n");
    printf("|  | |   | (_) || |_) || (_) || |_      \\ V  V / | || | | |\\__ \\  |  |  5->  %-10s: %02d   |  6->  %-10s: %02d     |\n", nomeTab[4], praTabela[4],nomeTab[5], praTabela[5]);
    printf("|  |_|    \\___/ |_.__/  \\___/  \\__|      \\_/\\_/  |_||_| |_||___/  |  |________________________|__________________________|\n");
    printf("|_________________________________________________________________|  |  7->  %-10s: %02d   |  8->  %-10s: %02d     |\n", nomeTab[6], praTabela[6], nomeTab[7], praTabela[7]);
    printf(" _________________________________________________________________   |________________________|__________________________|\n");
    printf("|                                                                 |  |                                                   |\n");
    printf("|           Infelizmente %s voce perdeu                   |  |                %s:  %02d                    |\n", nomeJogador, nomeJogador, pontuacao);
    printf("|_________________________________________________________________|  |___________________________________________________|\n");
}

void jogadorGanha(char *nomeJogador, int pontuacao){
    limparTerminal();

    FILE *myFile;
    int i = 0;
    char nomes[100][10];
    int pontuacoes[100];

    int praTabela[8] = {0};      // Valores dos players salvos
    char nomeTab[8][10] = {{0}}; // Nome dos players salvos

    myFile = fopen("tabela.txt", "a"); //abrindo arquivo pra ESCRITA

    if (!myFile) {//caso nao abrir
        printf("Erro ao abrir o arquivo.\n");
        return; 
    }

    fprintf(myFile, "\n%s\n %d\n", nomeJogador, pontuacao); // Escrevendo no arquivo
    fclose(myFile);

    myFile = fopen("tabela.txt", "r"); //abrindo arquivo pra LEITURA

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

    printf(" _________________________________________________________________    ___________________________________________________\n");
    printf("|     _   _   ___   _   _                     _                   |  |  1->  %-10s: %02d   |  2->  %-10s: %02d     |\n", nomeTab[0], praTabela[0], nomeTab[1], praTabela[1]);
    printf("|    | | | | / _ \\ | | | |                   (_)                  |  |________________________|__________________________|\n");
    printf("|    | |_| || (_) || |_| |        __      __ _  _ __   ___        |  |  3->  %-10s: %02d   |  4->  %-10s: %02d     |\n", nomeTab[2], praTabela[2], nomeTab[3], praTabela[3]);
    printf("|     \\__, | \\___/  \\__,_|        \\ \\ /\\ / /| || '_ \\ /  __|      |  |________________________|__________________________|\n");
    printf("|      __/ |                       \\ V  V / | || | | |\\__ \\       |  |  5->  %-10s: %02d   |  6->  %-10s: %02d     |\n", nomeTab[4], praTabela[4],nomeTab[5], praTabela[5]);
    printf("|     |___/                         \\_/\\_/  |_||_| |_||___/       |  |________________________|__________________________|\n");
    printf("|_________________________________________________________________|  |  7->  %-10s: %02d   |  8->  %-10s: %02d     |\n", nomeTab[6], praTabela[6], nomeTab[7], praTabela[7]);
    printf(" _________________________________________________________________   |________________________|__________________________|\n");
    printf("|                                                                 |  |                                                   |\n");
    printf("|           Parabens %s!       voce ganhou                |  |                %s:  %02d                    |\n", nomeJogador, nomeJogador, pontuacao);
    printf("|_________________________________________________________________|  |___________________________________________________|\n");

}

int main(){
    srand(time(NULL));
    pontuacao = 0;

    // questiona sobre o nome e adapta o tamanho
    printf("Qual seu nome?");
    scanf("%s",nomeJogador);
    completa(nomeJogador);
    
    //Verificação para ver se o jogo continua   
    while(bolasJogador != 0 && bolasMaquina != 0){
        jogadorJoga(nomeJogador);
            pontuacao++;
        if (bolasJogador != 0){
            maquinaJoga(pontuacao);
        }
    }
    // Verifica quem ganhou e executa a função para cada caso
    if (bolasJogador == 0){
        jogadorGanha(nomeJogador, pontuacao);
    } else {
        roboGanha(nomeJogador, pontuacao);
    }
    
    return 0;
}