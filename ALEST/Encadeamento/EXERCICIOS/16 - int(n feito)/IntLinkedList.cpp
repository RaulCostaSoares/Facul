#include <sstream>
#include "IntLinkedList.hpp"

using namespace std;

IntLinkedList::IntLinkedList() {
    numE = 0;
    head = tail = nullptr;;
}
IntLinkedList::~IntLinkedList() { clear(); }
int IntLinkedList::size() const { return numE; }
bool IntLinkedList::isEmpty() const { return (numE==0); }
void IntLinkedList::clear() {
    while (head != nullptr){
        Node *aux = head;
        head = head->next;
        delete aux;
        numE--;
    }
    tail = nullptr;
}
void IntLinkedList::pushHead(const int e) {
    Node *nodo = new Node(e);
    if(isEmpty()){
        head = tail = nodo;  // Inicializa tanto o head quanto o tail
    } else{
        nodo->next = head;
        head = nodo;
    }
    numE++;
}
void IntLinkedList::pushTail(const int e) {
    Node *nodo = new Node(e);
    if(isEmpty()){
        head = tail = nodo;
    } else {
        tail->next = nodo;
        tail = nodo;
    }
    numE++;
}
bool IntLinkedList::popHead() {
    if(numE == 0) return false;
    Node *aux = head;
    head = head->next;
    delete aux;
    numE--;
    return true;
}
bool IntLinkedList::popTail() {
    if(isEmpty()) return false;  // Verifica se a lista está vazia
    
    if (numE == 1) {  // Se houver apenas um elemento
        delete head;
        head = tail = nullptr;
    } else {
        Node *current = head;
        // Percorre a lista até o penúltimo nó
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    numE--;
    return true;
}
bool IntLinkedList::insert(const int index, const int e) { 
    if (index < 0 || index > numE) return false;  
    if(index == 0){
        Node *node = new Node(e);
        node->next = head;
        head = node;
        numE++;
        return true;
    }else if(index==numE){
        Node *node = new Node(e);
        tail->next = node;
        tail = node;
        numE++;
        return true;
    } else{
        Node *node = new Node(e);
        Node *current = head;
        for(int i = 0;i<index;i++){
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
        numE++;        
        return true;
    }
}
bool IntLinkedList::remove(const int index) { 
    if (index < 0 || index > numE) return false;  
    if(index == 0){
        Node *aux;
        aux = head;
        head = head->next;
        delete aux;
        numE--;
        return true;
    }else if(index==numE){
        Node *aux;
        Node *current = head;
        while(current->next!=tail){
            current = current->next;
        }
        aux = tail;
        tail = current;
        delete aux;
        numE--;
        return true;
    } else{
        Node *aux;
        Node *current = head;
        for(int i = 0;i<index-1;i++){
            current = current->next;
        }
        aux = current->next;
        current->next = aux->next;
        delete aux;
        numE--;        
        return true;
    }
}
void IntLinkedList::printList() const {
    Node *current = head;
    if (isEmpty()) {
        cout << "Lista vazia." << endl;
    } else {
        cout << "Conteúdo da lista: ";
        while (current != nullptr) {
            cout << current->info << " ";  // Mostra o valor de cada nó
            current = current->next;
        }
        cout << endl;
    }
}