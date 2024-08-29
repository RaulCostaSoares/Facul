#include <iostream>
#include <cstdlib>
#include <sys/time.h>

#define TAM 10000

using namespace std;
/////////////////////

void quickSort(int *dados, int ini, int fim){

    int i, j, pivo, aux;

    i = ini;
    j = fim;
    pivo = dados[(ini+fim)/2];

    while(i<=j){
        while(dados[i]<pivo){
            ++i;
        }
        while(dados[j]>pivo){
            --j;
        }
        if(i<=j){

            aux = dados[i];
            dados[i] = dados[j];
            dados[j] = aux;
            ++i;
            --j;         
        }
    }
    if (ini < j){
        quickSort(dados, ini, j);
    }
    if(i < fim){
        quickSort(dados, i, fim);
    }
}
/////////////////////
int estaOrdenado(int *dados, int tam) {
    for (int i=0; i<tam-1; ++i) if (dados[i] > dados[i+1]) return 0;     
    return 1;
}

int main() {
    
    int vetor[TAM];
    struct timeval antes, depois;
    unsigned long microssegundos;
    srand(time(0));

    cout << "> Ordenado: ";         //preenche o vetor ordenado
    for (int i=0; i<TAM; i++){
        vetor[i] = i; 
        // cout << vetor[i] << endl;
    }
    gettimeofday(&antes, NULL); quickSort(vetor,0,TAM-1); gettimeofday(&depois, NULL); 
    microssegundos = (depois.tv_sec - antes.tv_sec) * 1000000 + depois.tv_usec - antes.tv_usec;
    if (estaOrdenado(vetor,TAM)) cout <<    microssegundos << " us" << endl; else cout << "FALHOU" << endl;

    cout << "> Invertido: ";        //preenche o vetor invertido
    for (int i=0; i<TAM; i++){              
        vetor[i] = TAM - i; 
        // cout << vetor[i] << endl;
    }
    gettimeofday(&antes, NULL); quickSort(vetor,0,TAM-1); gettimeofday(&depois, NULL);
    microssegundos = (depois.tv_sec - antes.tv_sec) * 1000000 + depois.tv_usec - antes.tv_usec;
    if (estaOrdenado(vetor,TAM)) cout << microssegundos << " us" << endl; else cout << "FALHOU" << endl;

    cout << "> Aleatório: ";       //preenche o vetor aleatoriamente
    for (int i=0; i<TAM; i++){ 
        vetor[i] = rand()%TAM;
        // cout << vetor[i] << endl;
    } 
    gettimeofday(&antes, NULL); quickSort(vetor,0,TAM-1); gettimeofday(&depois, NULL); 
    microssegundos = (depois.tv_sec - antes.tv_sec) * 1000000 + depois.tv_usec - antes.tv_usec;
    if (estaOrdenado(vetor,TAM)) cout << microssegundos << " us" << endl; else cout << "FALHOU" << endl;

    return 0;
} 