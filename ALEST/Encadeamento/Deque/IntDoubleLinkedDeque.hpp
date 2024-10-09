#ifndef _INTDOUBLELINKEDDEQUE_HPP
#define _INTDOUBLELINKEDDEQUE_HPP

#include <iostream>
#include <string>

using namespace std;

class IntDoubleLinkedDeque{
    private:
        int numE, maxE;
        struct Node{
            int data;
            Node *prev, *next;
            Node (int d){
                data = d;
                prev = next = nullptr;
            };
        };
        Node *head, *tail;
    public:
        IntDoubleLinkedDeque(int mxSz = 10);
        ~IntDoubleLinkedDeque();
        int size() const;
        int maxSize() const;
        bool isEmpty() const;
        bool isFull() const;
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