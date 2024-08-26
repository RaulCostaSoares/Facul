#include <iostream>
#include <iomanip>

using namespace std;

class Calculator{
    public:

        void soma(int a, int b) const;

};

void Calculator::soma(int a, int b) const{

    cin >> a;
    cin >> b;
    cout << "SOMA = " << (a+b) << endl; 
}

int main(){
    
    int a, b;
    
    Calculator code;
    code.soma(a, b);

    return 0;
}