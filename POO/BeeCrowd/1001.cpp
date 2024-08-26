#include <iostream>
#include <iomanip>

using namespace std;

class Calculator{
    public:

        void add(int a, int b) const;

    private:
};

void Calculator::add(int a, int b) const{

    cin >> a;
    cin >> b;
    cout << "x = " << a+b << endl; 
}

int main(){
    
    int a, b;
    
    Calculator code;
    code.add(a, b);

    return 0;
}