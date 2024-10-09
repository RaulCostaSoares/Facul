#include <iostream>

using namespace std;
	
struct Node {
    char info;
    Node *next;
    Node(char i) {  
        info = i;
        next = nullptr;
        cout << "+ Node(" << info << ") criado..." << endl;
    }
    ~Node() {  cout << "- Node(" << info << ") destruido..." << endl;  }
};

int main() {
  Node *nodo1 = new Node('A');
  Node *nodo2 = new Node('B');
  Node *nodo3 = new Node('C');
  Node *nodo4 = new Node('D');
  Node *nodo5 = new Node('E');

  Node *topo  = nodo5;
  nodo5->next = nodo4;
  nodo4->next = nodo3;
  nodo3->next = nodo2;
  nodo2->next = nodo1;

  for (Node *aux = topo; aux != nullptr; aux = aux->next)
      cout << aux->info << endl;

  while (topo != nullptr) {
        Node *aux = topo;
        topo = topo->next;
        delete aux;
  }

  return 0;	
}
