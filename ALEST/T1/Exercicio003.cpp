#include <iostream>
#include <string>

using namespace std;

typedef struct {
    int nu;
    string le;
}obj;

void imprimeVetor(obj *dados, int tam) {
    cout << dados[0].le<<"/";
    cout << dados[0].nu;
    for (int i=1; i<tam; ++i){
        cout << " " << dados[i].le<<"/";
        cout << "" << dados[i].nu;
  }
//   cout<<endl;
}

void bubble_sort(obj *v, int tam) {
    int trocado;
    do {
        trocado = 0;
        for (int i = 0; i < tam-1; ++i) {
            if (v[i].le > v[i+1].le|| (v[i].le == v[i+1].le && v[i].nu>v[i+1].nu)) {
                obj aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                trocado = 1;
            }
        }
        cout<<endl;
        imprimeVetor(v, tam);

    } while (trocado);
    
}

int esta_ordenado(obj *dados, int tam) {
    for (int i = 0; i < tam-1; ++i) {
        if (dados[i].le > dados[i+1].le) return 0;
    }
    return 1;
}

int main() {

    int tam;
    cin >>tam;

    obj *palavras= new obj[tam];
    for(int i=0;i<tam;i++){
        cin >> palavras[i].le;
        cin >> palavras[i].nu;
    }

    bubble_sort(palavras, tam);

    return 0;
}