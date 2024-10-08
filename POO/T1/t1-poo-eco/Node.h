#ifndef NODE_H
#define NODE_H

#include "Person.h"

class Node {
public:
    Person person;
    Node* next;

    Node(Person person) : person(person), next(nullptr) {}
};

#endif // NODE_H
