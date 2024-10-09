#include <sstream>
#include "IntQueue.hpp"

using namespace std;

IntQueue::IntQueue(int mxSz){
    nE = insertPos = removePos = 0;
    mE = (mxSz < 1) ? 10 : mxSz;
    queue = new int[mE];
}
IntQueue::~IntQueue(){ delete[] queue; }

int IntQueue::size() const { return nE; }
int IntQueue::maxSize() const { return mE; }
bool IntQueue::isEmpty() const {return (nE ==0 ); }
bool IntQueue::isFull() const {return (nE == mE); }
void IntQueue::clear() { nE = insertPos = removePos = 0; }

bool IntQueue::enqueue(const int e) {
    if(nE == mE){ return false;
    } else {
        queue[insertPos++] = e;
        if(insertPos == mE){ insertPos = 0; }
        nE++;
        return true;
    }
}
bool IntQueue::dequeue(int &e) {
    if(nE == 0){ return false;
    } else {
        e = queue[removePos++];
        if(removePos == mE){ removePos = 0; }
        --nE;
        return true;
    }
}
bool IntQueue::head(int &e) const {
    if(nE == 0){ return false;
    } else {
        e = queue[removePos];
        return true;
    }
}
string IntQueue::str() const {
    int i;
    stringstream ss;
    ss << "|";
    for(i = 0;i < mE; i++){
        if ( (removePos == insertPos && nE != 0) ||
           (removePos < insertPos && (i >= removePos && i < insertPos)) ||
           (removePos > insertPos && (i >= removePos || i < insertPos)) ) ss << queue[i] << "|";
      else ss << " |";
    }
    return ss.str();
}