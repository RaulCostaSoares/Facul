#include <vector>
#include <stack>
#include <iostream>

using namespace std;


struct Node{
    int data;
    Node *next;
    Node(int e){
        data = e;
        next = nullptr;
    }
};



int main(){

    // SEM STL

    Node *A = new Node(10);
    Node *B = new Node(20);
    Node *C = new Node(30);
    Node *D = new Node(40);

    D->next = C;
    C->next = B;
    B->next = A;

    // COUT do ultimo nodo adicionado "top"
    cout << D->data << endl;
    
/////////////////////////////////////
    cout<<endl;
/////////////////////////////////////

    // COM STL
    
    stack <int> pilha;

    pilha.push(10);
    pilha.push(20);
    pilha.push(30);
    pilha.push(40);

    cout << pilha.top() <<endl;

    return 0;
}