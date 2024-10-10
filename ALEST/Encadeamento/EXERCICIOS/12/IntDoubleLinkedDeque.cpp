#include <sstream>
#include "IntDoubleLinkedDeque.hpp"

using namespace std;

IntDoubleLinkedDeque::IntDoubleLinkedDeque() {
    numE = 0;
    head = tail = nullptr;
}
IntDoubleLinkedDeque::~IntDoubleLinkedDeque() { clear(); }
int IntDoubleLinkedDeque::size() const { return numE; }
bool IntDoubleLinkedDeque::isEmpty() const { return (numE == 0); }
void IntDoubleLinkedDeque::clear() { 
    while (head != nullptr){
        Node *aux = head;
        head = head->next;
        delete aux;
        numE--;
    }
    tail = nullptr;
}
void IntDoubleLinkedDeque::addFirst(const int e) {
    Node *nodo = new Node(e);
    if(head ==nullptr){
        head = tail = nodo;
    } else {
        head->prev = nodo;
        nodo->next = head;
        head = nodo;
    }
    numE++;
}
void IntDoubleLinkedDeque::addLast(const int e) {
    Node *nodo = new Node(e);
    if(tail == nullptr){
        head = tail = nodo;
    } else {
        tail->next = nodo;
        nodo->prev = tail;
        tail = nodo;
    }
    numE++;
}
bool IntDoubleLinkedDeque::removeFirst(int &e) {
    if(numE == 0) return false;
    Node *aux = head;
    head = head->next;
    if(head==nullptr){tail = nullptr;}else{
        head->prev = nullptr;
    }
    e = aux->info;
    delete aux;
    numE--;
    return true;
}
bool IntDoubleLinkedDeque::removeLast(int &e) {
    if(numE == 0) return false;
    Node *aux = tail;
    tail = tail->prev;
    tail->next = nullptr;
    e = aux->info;
    delete aux;
    numE--;
    return true;
}
bool IntDoubleLinkedDeque::first(int &e) const {
    if(numE == 0) return false;
    e = head->info;
    return true;
}
bool IntDoubleLinkedDeque::last(int &e) const {
    if(numE == 0) return false;
    e = tail->info;
    return true;
}
string IntDoubleLinkedDeque::str() const {
    stringstream ss;
    ss<<"|";
    for(Node *aux = head; aux!=nullptr;aux = aux->next){
        ss<<aux->info<<"|";
    }
    return ss.str();
}
string IntDoubleLinkedDeque::reverseStr() const {
    stringstream ss;
    ss<<"|";
    for(Node *aux = tail; aux!=nullptr;aux = aux->prev){
        ss<<aux->info<<"|";
    }
    return ss.str();
}