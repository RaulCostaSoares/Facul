#ifndef _REVERSEINTLINKEDLIST_HPP
#define _REVERSEINTLINKEDLIST_HPP

#include <iostream>
#include <string>

using namespace std;

class ReverseIntLinkedList{
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
    ReverseIntLinkedList();
    ~ReverseIntLinkedList();
    int size() const;
    bool isEmpty() const;
    void clear();
    bool enqueue(const int e);
    bool dequeue(int &e);
    bool first(int &e) const;
    string str() const;
    void reverse(Node **head, Node **tail);
    void reverseList();
};

#endif