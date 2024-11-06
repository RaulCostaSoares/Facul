/*

    Nome do arquivo: Exercicio003.cpp
    Nome do autor: Raul Costa Soares
    Finalidade:
    Data: 10/10/2024

*/
#include "Exercicio003.hpp"
#include <iostream>

ListaDuplamenteEncadada::ListaDuplamenteEncadada() : head(nullptr), tail(nullptr) {}

ListaDuplamenteEncadada::~ListaDuplamenteEncadada() {
    while (head) {
        removeFront();
    }
}

void ListaDuplamenteEncadada::insertFront(const std::string &word) {
    Node *newNode = new Node(word);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    displayForward();
}

void ListaDuplamenteEncadada::insertBack(const std::string &word) {
    Node *newNode = new Node(word);
    if (!tail) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    displayForward();
}

bool ListaDuplamenteEncadada::removeFront() {
    if (!head) {
        std::cout << "ERRO" << std::endl;
        return false;
    }
    Node *temp = head;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    displayForward();
    return true;
}

bool ListaDuplamenteEncadada::removeBack() {
    if (!tail) {
        std::cout << "ERRO" << std::endl;
        return false;
    }
    Node *temp = tail;
    if (tail == head) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    displayForward();
    return true;
}

void ListaDuplamenteEncadada::insertAt(const std::string &word, int index) {
    if (index <= 0) {
        insertFront(word);
        return;
    }
    
    Node *current = head;
    int i = 0;
    while (current && i < index - 1) {
        current = current->next;
        i++;
    }

    if (!current || !current->next) {
        insertBack(word);
    } else {
        Node *newNode = new Node(word);
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
        displayForward();
    }
}

bool ListaDuplamenteEncadada::removeAt(int index) {
    if (index < 0 || !head) {
        std::cout << "ERRO" << std::endl;
        return false;
    }
    if (index == 0) {
        return removeFront();
    }
    
    Node *current = head;
    int i = 0;
    while (current && i < index) {
        current = current->next;
        i++;
    }

    if (!current) {
        std::cout << "ERRO" << std::endl;
        return false;
    }

    if (current == tail) {
        return removeBack();
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    displayForward();
    return true;
}

void ListaDuplamenteEncadada::displayForward() const {
    Node *current = head;
    std::cout << "|";
    while (current) {
        std::cout << current->word << "|";
        current = current->next;
    }
    std::cout << std::endl;
}

void ListaDuplamenteEncadada::displayReverse() const {
    Node *current = tail;
    std::cout << "|";
    while (current) {
        std::cout << current->word << "|";
        current = current->prev;
    }
    std::cout << std::endl;
}