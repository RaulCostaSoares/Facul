#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void addPerson(const Person& person) {
        Node* newNode = new Node(person);
        newNode->next = head;
        head = newNode;
    }

    void loadFromFile(const std::string& filename) {
        std::ifstream infile(filename);
        if (!infile) {
            std::cerr << "Erro ao abrir o arquivo!" << std::endl;
            return;
        }

        std::string name, jobTitle;
        int age;
        while (infile >> name >> age >> jobTitle) {
            addPerson(Person(name, age, jobTitle));
        }
        infile.close();
    }

    void printList() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << "Nome: " << current->person.name
                      << ", Idade: " << current->person.age
                      << ", Título de Trabalho: " << current->person.jobTitle << std::endl;
            current = current->next;
        }
    }
};

#endif // LINKEDLIST_H
