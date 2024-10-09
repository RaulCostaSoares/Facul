#ifndef _INTLINKEDLIST_HPP
#define _INTLINKEDLIST_HPP

#include <iostream>
#include <string>

using namespace std;

class IntLinkedList{
private:
    int numE, maxE;
    struct Node{
        int info;
        Node *next;
        Node (int e) {
            info = e;
            next = nullptr;    
        }
    };
    Node *head, *tail;
public:
    IntLinkedList(int mxSz = 10);
    ~IntLinkedList();
    int size() const;
    int maxSize() const;
    bool isEmpty() const;
    bool isFull() const;
    void clear();

    void pushHead(const int e);
    void pushTail(const int e);

    bool insert(const int index, const int e);
    bool remove(const int index);

    bool popHead();
    bool popTail();

    bool get(const int index, int &e);
    bool set(const int index, const int e);
    bool contains(const int e);

    int indexOf(const int e);
    int indexOf(int index, const int e);

    string str() const;

};

#endif