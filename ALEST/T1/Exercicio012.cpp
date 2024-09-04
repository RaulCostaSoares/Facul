#include <iostream>

using namespace std;

void imprimeVetor(int *dados, int tam) {
  cout << dados[0];
  for (int i=1; i<tam; ++i) cout << " " << dados[i];
  cout << endl;
}

void selectionSort(int *dados, int tam) { 
    for (int i = 0; i < tam - 1; ++i) {
        int max = i;
        for (int j = i + 1; j < tam; ++j)
            if (dados[j] > dados[max]) max = j;
        if (max != i) {
            int aux = dados[max]; 
            dados[max] = dados[i]; 
            dados[i] = aux;
        }          
    imprimeVetor(dados, tam);
    } 
}

int main(){

    int tam;
    cin >> tam;
    int *dados = new int[tam];
    for (int m=0; m<tam; m++){
        cin >> dados[m];
    }
    selectionSort(dados, tam);

    return 0;
}
