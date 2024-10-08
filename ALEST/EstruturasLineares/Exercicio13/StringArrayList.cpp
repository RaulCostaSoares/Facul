#include <string>
#include <sstream>
#include "StringArrayList.hpp"

using namespace std;

StringArrayList::StringArrayList(int mxSz){
    maxElements = mxSz;
    list = new string[maxElements];
    numElements = 0;
}
StringArrayList::~StringArrayList(){ delete[] list; }

void StringArrayList::clear(){numElements = 0; }
int StringArrayList::size() const { return numElements; }
int StringArrayList::maxSize() const {return maxElements; }
bool StringArrayList::isEmpty() const { return numElements == 0; }
bool StringArrayList::isFull() const { return numElements == maxElements; }

bool StringArrayList::add(const string &s) {
    
    if(numElements == maxElements){
        return false; 
    } else {
        list[numElements++]=s;
        return true;
    }
}
bool StringArrayList::add(const int index, const string &s) { 
    if(numElements == maxElements|| index < 0 || index > numElements){
        return false;
    }
    for(int i = numElements;i>index;--i){
        list[i] = list[i-1];
    }
    list[index] = s;
    ++numElements;
    return true;
}
bool StringArrayList::get(const int index, string &s) {
    if(index<0 || index>= numElements){
        return false;
    }
    s=list[index];
    return true;
}
bool StringArrayList::remove(const int index) {
    if(numElements == 0 || index < 0 || index >=numElements){
        return false;
    }
    --numElements;
    for(int i=index;i<numElements-1;++i){
        list[i]=list[i+1];
    }
    return true;
}

bool StringArrayList::set(const int index, const string &s) {
    if(index<0 || index >=numElements){
        return false;
    } else {
        list[index] = s;
        return true;
    }
}

bool StringArrayList::contains(const string &s) { 
    for(int i=0; i < numElements ;i++){
        if(list[i]==s){
            return true;
        }
    }
    return false;
 }
int StringArrayList::indexOf(const string &s) { return 0; }
int StringArrayList::indexOf(const int index, const string &s) { return 0; }

string StringArrayList::str() const {

    stringstream ss;

    for(int i=0;i<numElements;i++){
        ss << list[i];
    }
    return ss.str();
}
