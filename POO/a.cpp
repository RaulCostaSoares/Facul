#include <iostream>
#include "a.hpp"

using namespace std;

Garrafa::Garrafa(const int a, const int b) : id(a), num(b) { }

int Garrafa::getId() const {return id;}
int Garrafa::getNum() const {return num;}