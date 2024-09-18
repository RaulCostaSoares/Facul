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
        
    Node *topo = nullptr;

    for(int i=0;i<tam;i++){
        Node *nodo = new Node('A'+i);
        nodo->next = topo;
        topo = nodo;
    }

    // for (Node *aux = topo; aux != nullptr; aux = aux->next){
    //     cout << aux->info << endl;
    // }
    while (topo != nullptr) { Node *aux = topo;
        topo = topo ->next; delete aux;
    }

    return 0;
}