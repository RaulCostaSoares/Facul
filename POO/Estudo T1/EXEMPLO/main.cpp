#include "LinkedList.h"

int main() {
    LinkedList list;
    list.loadFromFile("data.txt");
    list.printList();
    return 0;
}

