#include <sstream>
#include "IntLinkedList.hpp"

using namespace std;

IntLinkedList::IntLinkedList(int mxSz) { 
    numE = 0;
    maxE = (mxSz<1)? 10:mxSz;
    head = tail = nullptr;
}
IntLinkedList::~IntLinkedList() {clear(); }

int IntLinkedList::size() const { return numE; }
int IntLinkedList::maxSize() const { return maxE; }
bool IntLinkedList::isEmpty() const { return (numE == 0); }
bool IntLinkedList::isFull() const { return (numE == maxE); }
void IntLinkedList::clear() {
    while(head != nullptr){
        Node *aux = head;
        head = head->next;
        delete aux;
        numE--;
    }
        tail = nullptr;
}
void IntLinkedList::pushHead(const int e) {
    Node *node = new Node(e);
    if(isEmpty()){
        head = tail = node;
    } else {
        node->next = head;
        head = node;
    }   
    numE++;
}
void IntLinkedList::pushTail(const int e) {
    Node *node = new Node(e);
    if(isEmpty()){
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
    numE++;
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
bool IntLinkedList::popHead(){
    if(numE == 0){ return false; }
    Node *aux = head;
    head = head->next;
    delete aux;
    numE--;
    return true;
}
bool IntLinkedList::popTail(){
    if(numE == 0){ return false; }
    Node *aux;
    Node *current = head;
    while(current->next != tail){
        current = current->next;
    }
    delete tail;
    tail = current;
    tail->next = nullptr;
    numE--;
    return true;
}
bool IntLinkedList::get(const int index, int &e) {
    if (index < 0 || index >= numE) return false;
    Node *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    e = current->info;
    return true;
}
bool IntLinkedList::set(const int index, const int e){
    if (index < 0 || index >= numE) return false;
    Node *current = head;
    for(int i=0;i<index;i++){
        current = current->next;
    }
    current->info = e;
    return true;

}
bool IntLinkedList::contains(const int e){
    Node *current = head;
    while(current != nullptr){
        if(current->info ==e) return true;
        current = current->next;
    }
    return false;
}
int IntLinkedList::indexOf(const int e){
    int i = 0;
    Node *current = head;
    while(current != nullptr){
        if(current->info!=e){
            current = current->next;
            i++;
        } else {
            return i;
        }
        
    }
    return -1;

}
int IntLinkedList::indexOf(int index, const int e){
    int i = 0;
    Node *current = head;
    for(int j=0;j<index;j++){
        current = current->next;
    }
    while(current != nullptr){
        if(current->info!=e){
            current = current->next;
            i++;
        } else {
            return i;
        }
        
    }
    return -1;
}

string IntLinkedList::str() const {
    stringstream ss;
    ss<<"|";
    for(Node *aux = head; aux!= nullptr; aux = aux->next){
        ss << aux->info << "|";
    }
    return ss.str();
}