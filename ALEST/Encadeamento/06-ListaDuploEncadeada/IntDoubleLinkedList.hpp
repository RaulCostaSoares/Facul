#ifndef _INTDOUBLELINKEDLIST_HPP
#define _INTDOUBLELINKEDLIST_HPP

#include <iostream>
#include <string>

using namespace std;

class IntDoubleLinkedList{
private:
    int numE, maxE;
    struct Node{
        int info;
        Node *next, *prev;
        Node(int e){
            info = e;
            next = prev = nullptr;  
        }
    };
    Node *head, *tail;    
public:
    IntDoubleLinkedList(int mxSz = 10);
    ~IntDoubleLinkedList();
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