#include <iostream>
#include <iomanip>

using namespace std;

class Calculator{
    public:

        void prod(int a, int b) const;

};

void Calculator::prod(int a, int b) const{

    cin >> a;
    cin >> b;
    cout << "PROD = " << (a*b) << endl; 
}

int main(){
    
    int a, b;
    
    Calculator code;
    code.prod(a, b);

    return 0;
}