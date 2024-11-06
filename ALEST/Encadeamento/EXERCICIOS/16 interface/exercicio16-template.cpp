#include <iostream>
#include "IntLinkedList.hpp"

using namespace std;

int main() {
  IntLinkedList list;
  char c;
  bool fim = false;
  unsigned pos;

  cout << "'<' = PUSH_FRONT / '>' = PUSH_BACK / '{' = POP_FRONT / '}' = POP_BACK '+' = INSERT / '-' = REMOVE / '.' = QUIT" << endl;

  while (!fim) {
    cout << "Tamanho atual da lista: " << list.size() << endl;
    list.printList();  // Mostra o conteúdo da lista

    cin >> c;
    switch(c) {
      case '<':  
        cin >> c;
        list.pushHead(c);  
        break;
      case '>':  
        cin >> c;         
        list.pushTail(c);  
        break;
      case '+':  
        cin >> c >> pos;  
        list.insert(pos, c);  
        break;
      case '{':  
        list.popHead();  
        break;
      case '}':  
        list.popTail();  
        break;
      case '-':  
        cin >> pos;       
        list.remove(pos);  
        break;
      case '.':  
        fim = true;  
        break;
    }
  }
  list.clear();
  return 0;
}