#ifndef _INTLINKEDQUEUE_HPP
#define _INTLINKEDQUEUE_HPP

#include <iostream>
#include <string>

using namespace std;

class IntLinkedQueue{
private:
    int numE;
    struct Node{
        int info;
        Node *next;
        Node(int e){
            info = e;
            next = nullptr;
        }
    };
    Node *head, *tail;
public:
    IntLinkedQueue();
    ~IntLinkedQueue();
    int size() const;
    bool isEmpty() const;
    void clear();
    bool enqueue(const int e);
    bool dequeue(int &e);
    bool front(int &e) const;
    string str() const;
};
#endif