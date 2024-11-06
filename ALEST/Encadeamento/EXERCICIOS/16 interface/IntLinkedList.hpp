#ifndef _INTLINKEDLIST_HPP
#define _INTLINKEDLIST_HPP

#include <iostream>
#include <string>

using namespace std;

class IntLinkedList{
private:
    int numE;
    struct Node{
        char info;  // Alterado para char
        Node *next;
        Node(char e){  // Alterado para char
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

    void pushHead(const char e);  // Alterado para char
    void pushTail(const char e);  // Alterado para char

    bool popHead();
    bool popTail();

    bool insert(const int index, const char e);  // Alterado para char
    bool remove(const int index);
    void quit();
    void printList() const;  // Método para exibir a lista
};

#endif