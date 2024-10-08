#include <iostream>
#include "3.hpp"

using namespace std;

carro::carro(int a, double b, double c) : ano(a), valor(b), km(c) { }
    // this->ano = a;
    // this->valor = b;
    // this->km = c;

int carro::getAno() const {return ano;}
double carro:: getValor() const {return valor;}
double carro:: getKm() const {return km;}