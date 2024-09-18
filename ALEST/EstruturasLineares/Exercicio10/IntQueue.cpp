#include <sstream>
#include "IntQueue.hpp"
#include <iomanip>

IntQueue::IntQueue(int mxSz){
/*
    numElements = insertPos = removePos = 0;
    maxElements = (mxSz < 1) ? 10 : mxSz;
    queue = new int[maxElements];
*/

    numElements = 0;
    queueHead = queueTail = nullptr;
}

IntQueue::~IntQueue() { 
    clear();
}

int IntQueue::size() const {
    return numElements;
    return 0;
}
int IntQueue::maxSize() const { 
    // return maxElements;
    return 0;
}

bool IntQueue::isEmpty() const { 
    return numElements == 0;
    return false;
}

bool IntQueue::isFull() const { 
    // return numElements == maxElements;
    return false;
}

void IntQueue::clear() { 

    while(queueHead!=nullptr){
        Node *aux = queueHead;
        queueHead = queueHead->next;
        delete aux;
    }
    numElements=0;
}

bool IntQueue::enqueue(const int e) {
/*
    if (numElements == maxElements)
        return false;
    else
    {
        queue[insertPos++] = e;
        insertPos %= maxElements;
        ++numElements;
        return true;
    }
*/
    // return false;

    Node *aux = new Node(e);
    if(queueHead==nullptr){
        queueHead=queueTail=aux;
    } else{
        queueTail->next = aux;
        queueTail = aux;
    }

}

bool IntQueue::dequeue(int &e){

    if (numElements == 0) return false;

    e = queueHead->data;
    Node *aux = queueHead;
    queueHead = queueHead->next;
    if(queueHead==nullptr) queueTail = nullptr;
    delete aux;
    --numElements;
    return true;
    

}

bool IntQueue::head(int &e) const{
/*
    if (numElements < 1)
        return false;
    else
    {
        e = queue[removePos];
        return true;
    }
*/
    return false;
}

string IntQueue::str() const{

    Node *aux = queueHead;
    stringstream ss;
    ss << "|";

        if (aux == nullptr){
            ss << queue[i] << "|";
        }
        else ss << " |";
    return ss.str();

    return "";
}