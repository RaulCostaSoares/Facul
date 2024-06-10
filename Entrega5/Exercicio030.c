#include <stdio.h>
#include <string.h>

#define ESTUDANTES_LOGICA_MAXIMO 15
#define ESTUDANTES_PROGRAMACAO_MAXIMO 10
#define TAMANHO_MATRICULA_MAXIMA 8

int main() {
    char estudantesLogica[ESTUDANTES_LOGICA_MAXIMO][TAMANHO_MATRICULA_MAXIMA];
    char estudantesProgramacao[ESTUDANTES_PROGRAMACAO_MAXIMO][TAMANHO_MATRICULA_MAXIMA];

    for (int i = 0; i < ESTUDANTES_LOGICA_MAXIMO; i++) {
        scanf("%s", estudantesLogica[i]);
    }

    for (int i = 0; i < ESTUDANTES_PROGRAMACAO_MAXIMO; i++) {
        scanf("%s", estudantesProgramacao[i]);
    }


    for (int i = 0; i < ESTUDANTES_LOGICA_MAXIMO; i++) {
        for (int j = 0; j < ESTUDANTES_PROGRAMACAO_MAXIMO; j++) {
            if (strcmp(estudantesLogica[i], estudantesProgramacao[j]) == 0) {
                printf("%s\n", estudantesLogica[i]);
                break;
            }
        }
    }

    return 0;
}
