#ifndef _INTLINKEDLIST_HPP
#define _INTLINKEDLIST_HPP

#include <iostream>
#include <string>

using namespace std;

class IntLinkedList{
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
    IntLinkedList();
    ~IntLinkedList();
    int size() const;
    bool isEmpty() const;
    void clear();

    void pushHead(const int e);
    void pushTail(const int e);

    bool popHead();
    bool popTail();

    bool insert(const int index, const int e);
    bool remove(const int index);
    void printList() const;
    void quit();
};

#endif