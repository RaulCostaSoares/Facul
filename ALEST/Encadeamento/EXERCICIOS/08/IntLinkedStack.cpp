#include <sstream>
#include <iostream>
#include "IntLinkedStack.hpp"

using namespace std;

IntLinkedStack::IntLinkedStack() {
    numE = 0;
    stack = nullptr;
}
IntLinkedStack::~IntLinkedStack(){ clear(); }
int IntLinkedStack::size() const { return numE; }
bool IntLinkedStack::isEmpty() const { return (numE ==0); }
void IntLinkedStack::clear() {
    while (stack != nullptr){
        Node *aux = stack;
        stack = stack->next;
        delete aux;
        numE--;
    }
}

void IntLinkedStack::push (const int e){
    Node *nodo = new Node(e);
    if(isEmpty()){
        stack = nodo;   
    } else {
        nodo->next = stack;
        stack = nodo;
    }
    numE++;    
}
bool IntLinkedStack::pop(int &e) {
    if(numE ==0 ) return false;
    Node *aux = stack;
    stack = stack->next;
    e = aux->info;
    delete aux;
    numE--;
    return true;
}
bool IntLinkedStack::top(int &e) const {
    if(numE ==0 ) return false;
    e = stack->info;
    return true;
}
string IntLinkedStack::str() const {
    stringstream ss;
    ss << "|";
    for(Node *aux = stack; aux != nullptr; aux = aux->next){
        ss<<aux->info<<"|";
    }
    return ss.str();
}