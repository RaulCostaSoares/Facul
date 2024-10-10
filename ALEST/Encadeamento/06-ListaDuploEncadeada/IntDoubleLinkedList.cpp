#include <sstream>
#include "IntDoubleLinkedList.hpp"

using namespace std;

IntDoubleLinkedList::IntDoubleLinkedList(int mxSz) {
    numE = 0;
    maxE = (mxSz<1)?10:mxSz;
    head = tail = nullptr;
}

IntDoubleLinkedList::~IntDoubleLinkedList() { clear(); }

int IntDoubleLinkedList::size() const { return numE; }
int IntDoubleLinkedList::maxSize() const { return maxE; }
bool IntDoubleLinkedList::isEmpty() const { return (numE == 0); }
bool IntDoubleLinkedList::isFull() const { return (numE == maxE); }
void IntDoubleLinkedList::clear() {
    while(head !=nullptr){
        Node *aux = head;
        head = head->next;
        delete aux;
        numE--;
    }
    tail = nullptr;
}

void IntDoubleLinkedList::pushHead(const int e) {
    Node *nodo = new Node(e);
    if(isEmpty()){
        head = tail = nodo;
    }else{
        head->prev = nodo;
        nodo->next = head;
        head = nodo;
    }
        numE++;
}
void IntDoubleLinkedList::pushTail(const int e) {
    Node *nodo = new Node(e);
    if (isEmpty()){
        head = tail = nodo;
    } else{
        tail->next = nodo;
        nodo->prev = tail;
        tail = nodo;
    }
        numE++;
}

bool IntDoubleLinkedList::insert(const int index, const int e) {
    if(index < 0 || index > maxE) return false;
    if(index == 0){
        Node *nodo = new Node(e);
        nodo->next = head;
        head->prev = nodo;
        head = nodo;
        return true;
    } else if(index == numE){
        Node *nodo = new Node(e);
        nodo->prev = tail;
        tail->next = nodo;
        tail = nodo;
        numE++;
        return true;
    } else{
        Node *nodo = new Node(e);
        Node *current = head;
        for(int i = 0;i<index-1;i++){
            current = current->next;
        }
        nodo->next = current->next;
        current->next = nodo;
        nodo->prev = current;
        nodo->next->prev = nodo;
        numE++;
        return true;
    }
}
bool IntDoubleLinkedList::remove(const int index){
    if(index < 0 || index > maxE) return false;
    if(index == 0){
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
    } else{
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
}
bool IntDoubleLinkedList::popHead() {
    if(numE == 0) return false;
    Node *aux = head;
    head = head->next;
    head->prev = nullptr;
    delete aux;
    numE--;
    return true;
}
bool IntDoubleLinkedList::popTail() {
    if(numE == 0) return false;
    Node *aux = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete aux;
    numE--;
    return true;
}
bool IntDoubleLinkedList::get(const int index, int &e){
    if(index < 0 || index > maxE) return false;
    Node *current = head;
    for(int i = 0; i<index;i++){
        current = current->next;
    }
    e = current->info;
    return true;
}
bool IntDoubleLinkedList::set(const int index, const int e) {
    if(index < 0 || index > maxE) return false;
    Node *current = head;
    for(int i = 0;i<index;i++){
        current = current->next;
    }
    current->info = e;
    return true;
}
bool IntDoubleLinkedList::contains(const int e){
    Node *current = head;
    while(current != nullptr){
        if(current->info == e){
            return true;
        } else{
            current = current->next;
        }
    }
    return false;
}
int IntDoubleLinkedList::indexOf(const int e){
    Node *current = head;
    int i = 0;
    while(current != nullptr){
        if(current->info == e){
            return i;
        } else{
            current = current->next;
            i++;
        }
    }
    return -1;
}
int IntDoubleLinkedList::indexOf(int index, const int e){
    Node *current = head;
    int i = 0;
    for(int i = 0;i<index;i++){
        current = current->next;
    }
    while(current != nullptr){
        if(current->info == e){
            return i;
        } else{
            current = current->next;
            i++;
        }
    }
    return -1;
}
string IntDoubleLinkedList::str() const {
    int i;
    stringstream ss;
    ss<<"|";
    for(Node *aux = head; aux!=nullptr;aux = aux->next){
        ss<<aux->info<<"|";
    }
    return ss.str();
}