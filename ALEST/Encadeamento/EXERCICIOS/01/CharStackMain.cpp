#include <iostream>
#include "CharStack.hpp"

using namespace std;

void print(CharStack &stack) {
  cout << "  " << stack.str() << "  size=" << stack.size() << "/" << stack.maxSize() << "  top=";
  char t;   bool res = stack.top(t);
  if (res) cout << t; else cout << "X";
  cout << "  isEmpty=" << stack.isEmpty() << "  isFull=" << stack.isFull() << endl;
}

int main() {
  char e;
  bool res;
  cout << "CharStack(4): ";  CharStack stack(4);  print(stack);
  e = 'A';  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO");  print(stack);
  e = 'B';  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO");  print(stack);
  e = 'C';  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO");  print(stack);
  res = stack.pop(e); cout << "pop(" << e << "):  ";  cout << (res?"OK  ":"ERRO");  print(stack);
  e = 'D';  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO"); print(stack);
  e = 'E';  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO"); print(stack);
  e = 'F';  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO"); print(stack);
  res = stack.pop(e); cout << "pop(" << e << "):  ";  cout << (res?"OK  ":"ERRO");  print(stack);
  res = stack.pop(e); cout << "pop(" << e << "):  ";  cout << (res?"OK  ":"ERRO");  print(stack);
  res = stack.pop(e); cout << "pop(" << e << "):  ";  cout << (res?"OK  ":"ERRO");  print(stack);
  res = stack.pop(e); cout << "pop(" << e << "):  ";  cout << (res?"OK  ":"ERRO");  print(stack);
  res = stack.pop(e); cout << "pop(X):  ";  cout << (res?"OK  ":"ERRO");  print(stack);
  e = 'G';  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO"); print(stack);
  cout << "clear(): OK  ";  stack.clear();  print(stack);
  return 0;
}

