#ifndef _INTQUEUE_HPP 
#define _INTQUEUE_HPP

#include <string>

using namespace std;

class IntQueue{
private:
    int numElements, maxElements;
    struct Node{
        int data;
        Node *next;
        Node(int d){
            data = d;
            next = nullptr;
        }
    };
    Node *queueHead, *queueTail;

public:
    IntQueue(int mxSz = 10);
    ~IntQueue();
    int size() const;
    int maxSize() const;
    bool isEmpty() const;
    bool isFull() const;
    void clear();
    bool enqueue(const int e);
    bool dequeue(int &e);
    bool head(int &e) const;
    string str() const; // APENAS PARA DEPURACAO
};
#endif