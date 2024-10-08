#include <iostream>

using namespace std;

class carro{
    private:
        int ano;
        double valor, km;

    public:
        carro(int a, double b, double c);

        int getAno();
        double getValor();
        double getKm();

};

int main(){

    carro uno(1900, 10.40, 51.21);

    cout << "O ano do uno é: " << uno.getAno() << endl;
    cout << "O valor do uno é: " << uno.getValor() << endl;
    cout << "O km do uno é: " << uno.getKm() << endl;

    return 0;
}


carro::carro(int a, double b, double c){
        ano = a;
        valor = b;
        km = c;
} 

int carro::getAno(){ return ano; }
double carro::getValor(){ return valor; }
double carro::getKm(){ return km; }
