#include <iostream>
#include "CharStack.cpp"

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
  cout << "IntStack(4): ";  CharStack stack(4);  print(stack);
  e = '1';  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO");  print(stack);
  e = '2';  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO");  print(stack);
  e = '3';  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO");  print(stack);
  res = stack.pop(e); cout << "pop(" << e << "):  ";  cout << (res?"OK  ":"ERRO");  print(stack);
  e = '4';  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO"); print(stack);
  e = '5';  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO"); print(stack);
  e = '6';  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO"); print(stack);
  res = stack.pop(e); cout << "pop(" << e << "):  ";  cout << (res?"OK  ":"ERRO");  print(stack);
  res = stack.pop(e); cout << "pop(" << e << "):  ";  cout << (res?"OK  ":"ERRO");  print(stack);
  res = stack.pop(e); cout << "pop(" << e << "):  ";  cout << (res?"OK  ":"ERRO");  print(stack);
  res = stack.pop(e); cout << "pop(" << e << "):  ";  cout << (res?"OK  ":"ERRO");  print(stack);
  res = stack.pop(e); cout << "pop(X):  ";  cout << (res?"OK  ":"ERRO");  print(stack);
  e = 7;  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO"); print(stack);
  cout << "clear(): OK  ";  stack.clear();  print(stack);
  return 0;
}

