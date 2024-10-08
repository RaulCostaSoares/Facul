#include <iostream>
#include <sstream>
#include "IntDoubleLinkedDeque.hpp"

using namespace std;

IntDoubleLinkedDeque::IntDoubleLinkedDeque(){ front = back = nullptr; }
IntDoubleLinkedDeque::~IntDoubleLinkedDeque(){ clear(); }

int IntDoubleLinkedDeque::size() const { return numElements; }
bool IntDoubleLinkedDeque::isEmpty() const { return numElements == 0; }

void IntDoubleLinkedDeque::addFirst(const int e){ 
    Node *aux = new Node(e);
    if(front==nullptr){
        front = back = aux;
    } else{
        front->prev = aux;
        aux->next = front;
        front = aux;
    }
    numElements++;
}
void IntDoubleLinkedDeque::addLast(const int e){ }

void IntDoubleLinkedDeque::clear(){
    while(front != nullptr){
        Node *aux = front;
        front=front->next;
        delete aux;
    }
    back = nullptr;
    numElements = 0;
}

bool IntDoubleLinkedDeque::removeFirst(int &e){ 

    if(front==nullptr){ return false; }
    e = front->data;
    Node *aux = front;
    front = front->next;
    if(front==nullptr) {
        back = nullptr;
    } else {
        front->prev = nullptr;
    }
    return true;
}

bool IntDoubleLinkedDeque::removeLast(int &e){
    if(front==nullptr){return false;}
    e = front->data;
    Node *aux = back;
    back = back->prev;
    if(back == nullptr){front = nullptr;}
    else {back->next = nullptr;}
    --numElements;
    return true;
}

bool IntDoubleLinkedDeque::first(int &e)const {
    if(front==nullptr){ return false; }
    e = front->data;

    return true;

}

bool IntDoubleLinkedDeque::last(int &e)const { return false; }


string IntDoubleLinkedDeque::str() const{ return ""; }
string IntDoubleLinkedDeque::reverseStr() const{ return ""; }
