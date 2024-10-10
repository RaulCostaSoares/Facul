#ifndef _INTLINKEDSTACK_HPP
#define _INTLINKEDSTACK_HPP
#include <string>
using namespace std;

class IntLinkedStack {
private:
  int numE;
  struct Node {
    int info;
    Node *next;
    Node(int d) {
        info = d;
        next = nullptr;
    }
  };
  Node *stack;
public:
  IntLinkedStack();
  ~IntLinkedStack();
  void push(const int e);
  bool pop(int &e);
  bool top(int &e) const;
  int size() const;
  bool isEmpty() const;
  void clear();
  string str() const; // APENAS PARA DEPURACAO
};
#endif
