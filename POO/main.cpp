#include <iostream>
#include "a.hpp"

using namespace std;

int main() {

    Garrafa coca(1, 412);
    Garrafa pepsi(2, 253);

    cout<< "Id:" <<coca.getId()<< " Quantidade:" << coca.getNum()<<endl;
    cout<< "Id:" <<pepsi.getId()<< " Quantidade:" << pepsi.getNum()<<endl;

    return 0;
}