#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    std::string name;
    int age;
    std::string jobTitle;

    Person(std::string name, int age, std::string jobTitle)
        : name(name), age(age), jobTitle(jobTitle) {}

    Person() : name("Desconhecido"), age(0), jobTitle("Desconhecido") {}
};

#endif // PERSON_H
