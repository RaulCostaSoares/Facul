#include <sstream>
#include <iostream>
#include <string>

using namespace std;

class StringDoubleLinkedList{
private:
    int numE;
    struct Node{
        string info;
        Node *next, *prev;
        Node(string e){
            info = e;
            next = nullptr;
        }
    };
    Node *head, *tail;
public:
    StringDoubleLinkedList(){
        numE = 0;
        head = tail = nullptr;
    };
    ~StringDoubleLinkedList() {clear(); };
    int size() const { return numE; };
    bool isEmpty() const { return (numE == 0); };
    void clear() {
        while (head != nullptr) {
            Node *aux = head;
            head = head->next;
            delete aux;
            numE--;
    }
    tail = nullptr;

    };

    void pushHead(const string e){
    Node *nodo = new Node(e);
    if (isEmpty()) {
        head = tail = nodo;
    } else {
        head->prev = nodo;
        nodo->next = head;
        head = nodo;
    }
    numE++;
};
    void pushTail(const string e){
    Node *nodo = new Node(e);
    if (isEmpty()) {
        head = tail = nodo;
    } else {
        tail->next = nodo;
        nodo->prev = tail;
        tail = nodo;
    }
    numE++;
};

    bool popHead(){
    if (numE == 0) return false;
    Node *aux = head;
    head = head->next;
    head->prev = nullptr;
    delete aux;
    numE--;
    return true;
};
    bool popTail(){
    if (numE == 0) return false;
    if (numE == 1) {
        delete head;
        head = tail = nullptr;
    } else {
        Node *aux = tail;
        tail = tail->prev;
        delete aux;
    }
    numE--;
    return true;
};

    bool insert(const int index, const string e){
    if (index < 0 || index > numE) return false;
    if (index == 0) {
        Node *nodo = new Node(e);
        nodo->next = head;
        head->prev = nodo;
        head = nodo;
        numE++;
        return true;
    } else if (index == numE) {
        Node *nodo = new Node(e);
        nodo->prev = tail;
        tail->next = nodo;
        tail = nodo;
        numE++;
        return true;
    } else {
        Node *nodo = new Node(e);
        Node *current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        nodo->next = current->next;
        current->next = nodo;
        nodo->prev = current;
        nodo->next->prev = nodo;
        numE++;
        return true;
    }
};
    bool remove(const int index){
    if (index < 0 || index >= numE) return false;
    if (index == 0) {
        Node *aux = head;
        head = head->next;
        head->prev = nullptr;
        delete aux;
        numE--;
        return true;
    } else if(index == numE){
        Node *aux = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete aux;
        numE--;
        return true;
    } else {
        Node *current = head;
        for(int i = 0;i<index;i++){
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        numE--;
        return true;
    }
};
    void quit();
    
    void printList() const{
        Node *current = head;
        if (isEmpty()) {
            cout << "|" << endl;
            cout << "|" << endl;
        } else {
            cout <<endl<<"+"<< endl;
            cout << "|";
            while (current != nullptr) {
                cout << current->info << "|";
                current = current->next;
            }
            // cout<<endl <<"|";
        }
}; 
    void reverse(Node **head, Node **tail) {
    if (*head == nullptr) return; 
    
    Node *prev = nullptr;
    Node *current = *head;
    Node *next = nullptr;
    
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    *tail = *head;
    *head = prev;
}
void reverseList() {
    reverse(&head, &tail);
}
    
};


int main() {
  StringDoubleLinkedList list;
  char c;
  int m =0;
  string l;
  bool fim = false;
  unsigned pos;

  cout << "'<' = PUSH_FRONT / '>' = PUSH_BACK / '{' = POP_FRONT / '}' = POP_BACK '+' = INSERT / '-' = REMOVE / '.' = QUIT" << endl;

  while (!fim) {
    

    cin >> c;
    switch(c) {
      case '<':  
        cin >> l;
        list.pushHead(l);
        // cout << "|";
        break;
      case '>':  
        cin >> l;         
        list.pushTail(l);
        // cout << "+" << endl;
        break;
      case '+':  
        cin >> l >> pos;  
        list.insert(pos, l);  
        // cout << "+" << endl;
        break;
      case '{':  
        list.popHead();  
        // cout << "+" << endl;
        break;
      case '}':  
        list.popTail();  
        // cout << "+" << endl;
        break;
      case '-':  
        cin >> pos;       
        list.remove(pos);  
        // cout << "+" << endl;
        break;
      case '.':  
        fim = true;  
        // cout << "+" << endl;
        break;
    }
    if(m==0){
        cout <<"|";
        m++;
    }
    list.printList();
    // cout << "+"<<endl;
  }
    list.reverseList();
    list.printList();
  list.clear();
  return 0;
}