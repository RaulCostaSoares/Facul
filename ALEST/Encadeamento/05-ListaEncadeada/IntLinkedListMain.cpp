#include <iostream>
#include "IntLinkedList.hpp"

using namespace std;

int main() {
    IntLinkedList list(10); // Cria uma lista com capacidade máxima de 10

    // Verifica se a lista está vazia
    if (!list.isEmpty()) {
        cerr << "ERRO01: A lista deve estar vazia no início." << endl;
    }

    // Adiciona elementos no início
    list.pushHead(1);
    list.pushHead(2);
    list.pushHead(3);
    cout << "Lista após adicionar elementos no início: " << list.str() << endl; // Esperado: |3|2|1|

    // Adiciona elementos no final
    list.pushTail(4);
    list.pushTail(5);
    cout << "Lista após adicionar elementos no final: " << list.str() << endl; // Esperado: |3|2|1|4|5|

    // Insere elemento no índice 2
    list.insert(2, 10);
    cout << "Lista após inserir 10 no índice 2: " << list.str() << endl; // Esperado: |3|2|10|1|4|5|

    // Remove o elemento no índice 1
    list.remove(1);
    cout << "Lista após remover o elemento no índice 1: " << list.str() << endl; // Esperado: |3|10|1|4|5|

    // Remove o primeiro e o último elementos
    list.popHead();
    cout << "Lista após remover o primeiro elemento: " << list.str() << endl; // Esperado: |10|1|4|5|
    list.popTail();
    cout << "Lista após remover o último elemento: " << list.str() << endl; // Esperado: |10|1|4|

    // Verifica se um elemento está contido na lista
    if (!list.contains(1)) {
        cerr << "ERRO02: A lista deve conter o elemento 1." << endl;
    }
    if (list.contains(99)) {
        cerr << "ERRO03: A lista não deve conter o elemento 99." << endl;
    }

    // Obtém e define elementos na lista
    int value;
    if (list.get(1, value)) {
        cout << "Valor no índice 1 é: " << value << endl; // Esperado: 4
    } else {
        cerr << "ERRO04: Não foi possível obter o valor no índice 1." << endl;
    }

    list.set(1, 20);
    cout << "Lista após definir o valor no índice 1 para 20: " << list.str() << endl; // Esperado: |10|20|

    // Testa o método indexOf
    int index = list.indexOf(20);
    if (index != 1) {
        cerr << "ERRO05: O índice do valor 20 deve ser 1." << endl;
    }

    // Limpa a lista
    list.clear();
    if (!list.isEmpty()) {
        cerr << "ERRO06: A lista deve estar vazia após a limpeza." << endl;
    }

    return 0;
}