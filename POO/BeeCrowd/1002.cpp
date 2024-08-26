#include <iostream>
#include <iomanip>

using namespace std;

class Circle{
    public:

        void area(double a) const;

};

void Circle::area(double a) const{

    cin >> a;
    cout << "A=" <<fixed<<setprecision(4)<< 3.14159*(a*a) << endl; 
}

int main(){
    
    double a;
    
    Circle code;
    code.area(a);

    return 0;
}