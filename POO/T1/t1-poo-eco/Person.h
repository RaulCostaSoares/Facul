#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person {
public:
    string name;
    int age;
    string jobTitle;
    string senioridade;

    Person(string name, int age, string jobTitle, string senioridade)
        : name(name), age(age), jobTitle(jobTitle), senioridade(senioridade) {}

    Person() : name("Desconhecido"), age(0), jobTitle("Desconhecido"), senioridade("Desconhecido") {}
};

#endif // PERSON_H
