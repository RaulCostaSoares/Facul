/*
Usando como ponto de partida a classe IntStack, apresentada anteriormente e implementada usando alocação sequencial ou contígua,
 implemente a classe IntLinkedStack, que funciona da mesma forma, porém usando alocação encadeada. 
Observações:
    A versão usando alocação encadeada eliminará a necessidade de se trabalhar com um limite máximo de elementos,
     consequentemente, os métodos maxSize() e isFull() NÃO farão parte da nova implementação.
    A definição da classe (arquivo IntLinkedStack.hpp) e um programa de teste (arquivo IntLinkedStackMain.cpp)
     estão listados nas lâminas a seguir.
*/

#include <iostream>

using namespace std;

struct Node {
    char info;
    Node *next;
    Node *prev;
    Node(char i) { 
        info = i;
        next = nullptr;
        
            cout << "+ Node(" << info << ") criado..." << endl;
        } 
    ~Node() { 
        cout << "- Node(" << info << ") destruido..." << endl; 
    }
};

int main() { 
  
    int tam;
    cout<<"Qual o tamannho da pilha?"<<endl;
    cin>>tam;
        
    Node *topo = nullptr, *base=nullptr;

    for(int i=0;i<tam;i++){
        Node *novo = new Node('A'+i);
        if(topo!=nullptr){
            topo->prev = novo;
            novo->next = topo;
        }else{
            base = novo;
        }
        topo = novo;
    }
    cout<<topo->info<<" "<<base->info<<endl;
    
    // for (Node *aux = topo; aux != nullptr; aux = aux->next){
    //     cout << aux->info << endl;
    // }
    while (topo != nullptr) { Node *aux = topo;
        topo = topo ->next; delete aux;
    }

    return 0;
}