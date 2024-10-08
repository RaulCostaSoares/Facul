#include <iostream>
#include "IntDoubleLinkedDeque.hpp"

using namespace std;

void print(IntDoubleLinkedDeque &deque) {
  int h;  bool res;  cout << "  " << deque.str() << "  size=" << deque.size();
  cout << "  first="; res = deque.first(h);  if (res) cout << h; else cout << "X";
  cout << "  last=";  res = deque.last(h);   if (res) cout << h; else cout << "X";
  cout << "  isEmpty=" << deque.isEmpty() << "  reverse=" << deque.reverseStr() << endl;
}

int main() {
  int e;  bool res;
  cout << "IntDoubleLinkedDeque: ";  IntDoubleLinkedDeque deque;  print(deque);
  e = 6;  cout << "addFirst(" << e << "):    OK    "; deque.addFirst(e);  print(deque);
  e = 7;  cout << "addLast(" << e << "):     OK    "; deque.addLast(e);   print(deque);
  e = 5;  cout << "addFirst(" << e << "):    OK    "; deque.addFirst(e);  print(deque);
  e = 8;  cout << "addLast(" << e << "):     OK    "; deque.addLast(e);   print(deque);
  e = 4;  cout << "addFirst(" << e << "):    OK    "; deque.addFirst(e);  print(deque);
  e = 9;  cout << "addLast(" << e << "):     OK    "; deque.addLast(e);   print(deque);
  res = deque.removeFirst(e); cout << "removeFirst(" << e << "): " << (res?"OK    ":"ERRO  ");  print(deque);
  res = deque.removeLast(e);  cout << "removeLast(" << e << "):  " << (res?"OK    ":"ERRO  ");  print(deque);
  res = deque.removeLast(e);  cout << "removeLast(" << e << "):  " << (res?"OK    ":"ERRO  ");  print(deque);
  res = deque.removeFirst(e); cout << "removeFirst(" << e << "): " << (res?"OK    ":"ERRO  ");  print(deque);
  res = deque.removeLast(e);  cout << "removeLast(" << e << "):  " << (res?"OK    ":"ERRO  ");  print(deque);
  res = deque.removeFirst(e); cout << "removeFirst(" << e << "): " << (res?"OK    ":"ERRO  ");  print(deque);
  res = deque.removeLast(e);  cout << "removeLast(X):  "           << (res?"OK    ":"ERRO  ");  print(deque);
  e = 2;  cout << "addLast(" << e << "):     OK    "; deque.addLast(e);   print(deque);
  cout << "clear():        OK    ";  deque.clear();  print(deque);
  return 0;
}	
