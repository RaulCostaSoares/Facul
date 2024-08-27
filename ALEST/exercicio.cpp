#include <iostream>

#define quant 10

using namespace std;

typedef struct{
    string nome;
    int numero;
}item;

void org (item col[], int quantidade){
    
    for(int j=0;j<quantidade-1;j++){
        for(int i=0; i<quantidade -j -1;i++){
            if(col[i].numero > col[i+1].numero){
                item aux = col[i+1];
                col[i+1] = col[i];
                col[i] = aux;
            }
        }
    }
}

item colecao[quant]={
{"H", 8}, {"B", 2}, {"A", 1}, {"E", 5}, {"I", 9}, {"F", 6}, {"G", 7}, {"D", 4}, {"C", 3}, {"J", 10}
};

int main(){

    for(int i=0;i<quant;i++){
        cout << colecao[i].nome << " ";
        cout << colecao[i].numero << endl << endl;
    }
    org(colecao, quant);
    for(int i=0;i<quant;i++){
        cout << colecao[i].nome << " ";
        cout << colecao[i].numero << endl << endl;
    }


    return 0;
}
