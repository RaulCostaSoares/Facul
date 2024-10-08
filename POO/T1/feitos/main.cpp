#include <iostream>
#include "3.hpp"

using namespace std;

int main(){

    carro uno(1900, 3123.123, 100.001);

    cout << "O ano do uno é: " << uno.getAno() << endl;
    cout << "O valor do uno é: " << uno.getValor() << endl;
    cout << "O km do uno é: " << uno.getKm() << endl;

    return 0;
}