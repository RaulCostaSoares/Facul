#include <sstream>
#include "StringArrayList.hpp"

using namespace std;

StringArrayList::StringArrayList(int mxSz) {
    numE = 0;
    maxE = (mxSz<1)? 10:mxSz;
    list = new string[maxE];
}
StringArrayList::~StringArrayList() { delete[] list; }

int StringArrayList::size() const { return numE; }
int StringArrayList::maxSize() const { return maxE; }

bool StringArrayList::isEmpty() const { return (numE == 0); }
bool StringArrayList::isFull() const { return (numE == maxE); }

void StringArrayList::clear() { numE = 0; }

bool StringArrayList::add(const string &s) {
    if(numE >= maxE) { return false;
    } else {
        list[numE++] = s;
        return true;
    }

}
bool StringArrayList::add(const int index, const string &s) {
    if(numE == maxE) { return false;
    } else {
        for(int i = numE;i>index;i--){
            list[i] = list[i-1];
        }
        list[index] = s;
        numE++;
        return true;
    }
}
bool StringArrayList::get(const int index, string &s) {
    if(index < 0 || index > numE ){ return false;
    } else {
        s = list[index];
        return true;
    }
}
bool StringArrayList::set(const int index, string s) {
    if(index < 0 || index > numE ){ return false;
    } else {
        list[index] = s;
        return true;
    }
}
bool StringArrayList::remove(const int index) {
    if(index < 0 || index > numE ){ return false;
    } else {
        --numE;
        for(int i = index; i<numE;i++){
            list[i] = list[i+1];
        }
        return true;
    }
}
bool StringArrayList::contains(const string &s) {
    for(int i = 0; i<numE;i++){
        if(list[i]==s){
            return true;
        }
    }
    return false;
}


int StringArrayList::indexOf(const string &s) { 
    for(int i = 0; i<numE;i++){
        if(list[i]==s){
            return i;
        }
    }
    return -1;

}
int StringArrayList::indexOf(int index, const string &s) { 
    if(index < 0 || index > numE ){ return false;
    } else {
        for(int i = index;i<numE;i++){
            if(list[i]==s){
                return i;
            }
        }
        return -1;
    }
}

string StringArrayList::str() const {
    int i;
    stringstream ss;
    for(i=0;i<numE;i++){
        ss<<list[i];
    }
    return ss.str();
}