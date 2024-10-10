#include <sstream>
#include "IntLinkedQueue.hpp"

using namespace std;

IntLinkedQueue::IntLinkedQueue() {
    numE = 0;
    head = tail = nullptr;
}
IntLinkedQueue::~IntLinkedQueue() { clear(); }

int IntLinkedQueue::size() const { return numE; }
bool IntLinkedQueue::isEmpty() const { return (numE == 0); }
void IntLinkedQueue::clear() {
    while(head !=nullptr){
        Node *aux = head;
        head = head->next;
        delete aux;
        numE--;
    }
    tail = nullptr;
}
bool IntLinkedQueue::enqueue(const int e) {
    Node *nodo = new Node(e);
    if(numE == 0) { head = tail = nodo;
    } else {
        tail->next = nodo;
        tail = nodo;
    }
    numE++;
    return true;
}

bool IntLinkedQueue::dequeue(int &e) {
    if(numE == 0) return false;
    numE--;
    e = head->info;
    Node *aux = head;
    head = head->next;
    delete aux;
    return true;
    
}
bool IntLinkedQueue::front(int &e) const {
    if(numE == 0) return false;
    e = head->info;
    return true;
}
string IntLinkedQueue::str() const {
    stringstream ss;
    ss<<"|";
    for(Node *aux = head; aux!=nullptr;aux = aux->next){
        ss<<aux->info<<"|";
    }
    return ss.str();
}