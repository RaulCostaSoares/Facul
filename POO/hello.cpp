#include <iostream>
#include <iomanip>

using namespace std;


int main(){
    
    string nome;

    double A, B, C;
    
    cin >> nome;
    cin >> A;
    cin >> B;
    
    C = A+(0.15*B);

    cout << "TOTAL = R$ "<<fixed<<setprecision(2) << C <<endl;
         
    return 0;
}