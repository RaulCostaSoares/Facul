#ifndef EXERCICIO003_HPP
#define EXERCICIO003_HPP

#include <iostream>
#include <string>

using namespace std;

class ListaDuplamenteEncadada {
private:
    struct Node {
        std::string word;
        Node *prev;
        Node *next;
        Node(const std::string &w) : word(w), prev(nullptr), next(nullptr) {
            std::cout << "+" << std::endl; // Node creation
        }
        ~Node() {
            std::cout << "-" << std::endl; // Node deletion
        }
    };
    
    Node *head;
    Node *tail;

public:
    ListaDuplamenteEncadada();
    ~();
    
    void insertFront(const std::string &word);
    void insertBack(const std::string &word);
    bool removeFront();
    bool removeBack();
    void insertAt(const std::string &word, int index);
    bool removeAt(int index);
    void displayForward() const;
    void displayReverse() const;
};

#endif