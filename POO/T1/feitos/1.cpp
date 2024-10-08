#include <iostream>
#include <iomanip>

using namespace std;

class carro{
    private:
    
    int ano;
    double valor, km;

    public:

    carro(int a=0, double b=0, double c=0){
        ano = a;
        valor = b;
        km = c;
    }
    int getAno(){ return ano; }
    double getValor(){ return valor; }
    double getKm(){ return km; }

};


int main(){

    carro uno(1900, 10.40, 51.21);

    /*  uno.setAno(1990);
        uno.setValor(1000.500);
        uno.setKm(5132.12);*/

    cout << "O ano do uno é: " << uno.getAno() << endl;
    cout << "O valor do uno é: " << uno.getValor() << endl;
    cout << "O km do uno é: " << uno.getKm() << endl;

    return 0;
}