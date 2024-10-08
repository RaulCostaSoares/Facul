#include <sstream>
#include "IntStack.hpp"

using namespace std;

IntStack::IntStack(int mxSz){
    numE = 0;
    maxE = (mxSz < 1) ? 10 : mxSz;
    stack = new int[maxE];
}

IntStack::~IntStack(){ delete[] stack; }
int IntStack::size() const { return numE; }
int IntStack:: maxSize() const { return maxE; }
bool IntStack::isEmpty() const { return numE == 0; }
bool IntStack::isFull() const { return numE == maxE; }
void IntStack::clear() { numE = 0; }

bool IntStack::push(const int e) {
    if(numE == maxE){ return false;
    } else { 
        stack[numE++] = e;
        return true;
    }
}
bool IntStack::pop(int &e) {
    if(numE == 0){ return false;
    } else {
        e = stack[--numE];
        return true;
    }



}