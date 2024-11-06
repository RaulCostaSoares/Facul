#include <sstream>
#include "ReverseIntLinkedList.hpp"

using namespace std;

ReverseIntLinkedList::ReverseIntLinkedList() {
    numE = 0;
    head = tail = nullptr;
}
ReverseIntLinkedList::~ReverseIntLinkedList() { clear (); }
int ReverseIntLinkedList::size() const { return numE; }
bool ReverseIntLinkedList::isEmpty() const { return (numE == 0); }
void ReverseIntLinkedList::clear() {
    while(head !=nullptr){
        Node *aux = head;
        head = head->next;
        delete aux;
        numE--;
    }
    tail = nullptr;
}
bool ReverseIntLinkedList::enqueue(const int e) {
    Node *nodo = new Node(e);
    if(numE == 0){
        head = tail = nodo;
    } else {
        nodo->next = head;
        head = nodo;
    }
    numE++;
    return true;    
}
bool ReverseIntLinkedList::dequeue(int &e) {
    if(numE == 0) return false;
    if(head == tail){
        e = tail->info;
        delete tail;
        head = tail = nullptr;
    } else {
        Node *current = head;
        while(current->next!=tail){
            current = current->next;
        }
        e = tail->info;
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    numE--;
    return true;
}
bool ReverseIntLinkedList::first(int &e) const {
    if(numE == 0) return false;
    e = head->info;
    return true;
}
string ReverseIntLinkedList::str() const {
    stringstream ss;
    ss<<"|";
    for(Node *aux = head; aux!=nullptr;aux = aux->next){
        ss<<aux->info<<"|";
    }
    return ss.str();
}
void ReverseIntLinkedList::reverse(Node **head, Node **tail) {
    if (*head == nullptr) return;  // Lista vazia, nada a inverter
    
    ReverseIntLinkedList::Node *prev = nullptr;
    ReverseIntLinkedList::Node *current = *head;
    ReverseIntLinkedList::Node *next = nullptr;
    
    // Itera e inverte os ponteiros
    while (current != nullptr) {
        next = current->next;   // Armazena o próximo nó
        current->next = prev;   // Inverte o ponteiro
        prev = current;         // Avança prev
        current = next;         // Avança current
    }
    
    // Atualiza head e tail
    *tail = *head;    // O antigo head agora é o tail
    *head = prev;     // O antigo tail agora é o head
}
void ReverseIntLinkedList::reverseList() {
    reverse(&head, &tail);  // Chama a função auxiliar passando ponteiros para head e tail
}
int main() {
    ReverseIntLinkedList list;
    list.enqueue(1);
    list.enqueue(2);
    list.enqueue(3);
    
    cout << "Lista original: " << list.str() << endl;  // Deve imprimir: |3|2|1|
    
    list.reverseList();  // Inverte a lista
    
    cout << "Lista invertida: " << list.str() << endl;  // Deve imprimir: |1|2|3|
    
    return 0;
}