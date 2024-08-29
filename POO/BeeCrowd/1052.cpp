#include <iostream>
#include <iomanip>

using namespace std;

class Mes{
    public:

        void ver(int a) const;

};

void Mes::ver(int a) const{

    cin >> a;
    
}

int main(){
    
    int a, b;
    
    Mes code;
    code.ver(a, b);

    return 0;
}