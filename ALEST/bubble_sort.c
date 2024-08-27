#include <stdio.h> 
#include <stdlib.h> 
#include <sys/time.h>

#define INI 1000 
#define FIM 4000 
#define INC 50 // Aumentando o incremento para reduzir a quantidade de testes

void bubble_sort(int *v, int tam) {
    int trocado;
    do {
        trocado = 0;
        for (int i = 0; i < tam-1; ++i) {
            if (v[i] > v[i+1]) {
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                trocado = 1;
            }
        }
    } while (trocado);
}

int esta_ordenado(int *dados, int tam) {
    for (int i = 0; i < tam-1; ++i) {
        if (dados[i] > dados[i+1]) return 0;
    }
    return 1;
}

int main() {
    struct timeval antes, depois;
    
    int *vetor = malloc(sizeof(int) * FIM);
    
    if (vetor == NULL) return 1;

    for (int total = INI; total <= FIM; total += INC) {
        unsigned long min = 0;

        for (int j = 0; j < 10; ++j) {
            for (int pos = 0; pos < total; pos++) vetor[pos] = total - pos; // Preenche o vetor
            
            gettimeofday(&antes, NULL);
            bubble_sort(vetor, total);
            gettimeofday(&depois, NULL);

            if (!esta_ordenado(vetor, total)) return 1;

            unsigned long microssegundos = (depois.tv_sec - antes.tv_sec) * 1000000 + depois.tv_usec - antes.tv_usec;
            if (j == 0 || microssegundos < min) min = microssegundos;
        }
        printf("%d %lu\n", total, min);
    }

    free(vetor); 
    return 0;
}