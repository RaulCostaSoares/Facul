#ifndef _INTDOUBLELINKEDDEQUE_HPP
#define _INTDOUBLELINKEDDEQUE_HPP

#include <iostream>
#include <string>

using namespace std;

class IntDoubleLinkedDeque{
private:
    int numE;
    struct Node{
        int info;
        Node *prev, *next;
        Node(int e){
            info = e;
            prev = next = nullptr;
        }
    };
    Node *head, *tail;
public:
    IntDoubleLinkedDeque();
    ~IntDoubleLinkedDeque();
    int size() const;
    bool isEmpty() const;
    void clear();

    void addFirst(const int e);
    void addLast(const int e);

    bool removeFirst(int &e);
    bool removeLast(int &e);

    bool first(int &e) const;
    bool last(int &e) const;
    
    string str() const;
    string reverseStr() const;
};

#endif