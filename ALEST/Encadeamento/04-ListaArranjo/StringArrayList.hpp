#ifndef _STRINGARRAYLIST_HPP
#define _STRINGARRAYLIST_HPP

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class StringArrayList{
private:
    int numE, maxE;
    string *list;

public:

    StringArrayList(int mxSz = 10);
    ~StringArrayList();
    int size() const;
    int maxSize() const;
    bool isEmpty() const;
    bool isFull() const;
    void clear();

    bool add(const string &s);
    bool add(const int index, const string &s);

    bool get(const int index, string &s);
    bool set(const int index, const string s);
    bool remove(const int index);

    bool contains(const string &s);

    int indexOf(const string &s);
    int indexOf(int index, const string &s);

    string str() const;

};

#endif