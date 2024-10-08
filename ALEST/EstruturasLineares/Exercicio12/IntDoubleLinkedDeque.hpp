#ifndef _INTDOUBLELINKEDDEQUE_HPP
#define _INTDOUBLELINKEDDEQUE_HPP
#include <string>
using namespace std;

class IntDoubleLinkedDeque {
  private:
    int numElements;
    struct Node {
      int data;
      Node *prev, *next;
      Node(int d) {  
        data = d;  
        prev = next = nullptr;  
      }
    };
    Node *front, *back;

  public:
    IntDoubleLinkedDeque();
    ~IntDoubleLinkedDeque();
    int size() const;
    bool isEmpty() const;
    void addFirst(const int e);   bool removeFirst(int &e);   bool first(int &e) const;
    void addLast(const int e);    bool removeLast(int &e);    bool last(int &e) const;
    void clear();
    string str() const;        // APENAS PARA DEPURACAO
    string reverseStr() const; // APENAS PARA DEPURACAO
};
#endif
