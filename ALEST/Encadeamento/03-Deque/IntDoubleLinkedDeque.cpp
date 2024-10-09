#include <sstream>
#include "IntDoubleLinkedDeque.hpp"

using namespace std;

IntDoubleLinkedDeque::IntDoubleLinkedDeque(int mxSz){
    numE = 0;
    maxE = (mxSz<1)? 10 : mxSz;
    head = tail = nullptr;
}
IntDoubleLinkedDeque::~IntDoubleLinkedDeque() { clear(); }

int IntDoubleLinkedDeque::size() const { return numE; }
int IntDoubleLinkedDeque::maxSize() const { return maxE; }
bool IntDoubleLinkedDeque::isEmpty() const { return (numE == 0); }
bool IntDoubleLinkedDeque::isFull() const { return (numE == maxE); }

void IntDoubleLinkedDeque::clear() {
    while(head != nullptr){
        Node *aux;
        aux = head;
        head = head->next;
        delete aux;
    }
}
void IntDoubleLinkedDeque::addFirst(const int e){
    Node *aux = new Node(e);
    if(head == nullptr) {
        head = tail = aux;
    } else{
        head->prev = aux;
        aux->next = head;
        head = aux;
        numE++;
    }
}
void IntDoubleLinkedDeque::addLast(const int e){
    Node *aux = new Node(e);
    if(tail == nullptr) {
        head = tail = aux;
    } else{
        aux->prev = tail;
        tail->next = aux;
        tail = aux;
        numE++;
    }
}
bool IntDoubleLinkedDeque::removeFirst(int &e){
    if(numE == 0){ return false;
    } else {
        --numE;
        e = head->data;
        Node *aux = head;
        head = head->next;
        delete aux;
    }
    if(head == nullptr) {tail = nullptr;
    } else {
        head->prev = nullptr;
    }
    return true;
}
bool IntDoubleLinkedDeque::removeLast(int &e){
    if(numE == 0){ return false;
    } else {
        --numE;
        e = tail->data;
        Node *aux = tail;
        tail = tail->prev;
        delete aux;
    }
    if(tail == nullptr) {head = nullptr;
    } else {
        tail->next = nullptr;
    }
    return true;
}
bool IntDoubleLinkedDeque::first(int &e) const {
    if(numE == 0) { return false;
    } else {
        e = head->data;
        return true;
    }
}
bool IntDoubleLinkedDeque::last(int &e) const {
    if(numE == 0) { return false;
    } else {
        e = tail->data;
        return true;
    }
}
string IntDoubleLinkedDeque::str() const {
    stringstream ss;
    ss << "|";
    for (Node *aux = head; aux != nullptr; aux = aux->next)
        ss << aux->data << "|"; return ss.str();
}
string IntDoubleLinkedDeque::reverseStr() const { stringstream ss;
    ss << "|";
    for (Node *aux = tail; aux != nullptr; aux = aux->prev)
        ss << aux->data << "|"; return ss.str();
}