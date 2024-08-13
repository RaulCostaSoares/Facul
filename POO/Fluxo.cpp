#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int x = 10;
    cout << hex << x << endl;
    cout << oct << x << endl;
    cout << setbase(10) << x << endl;
    cout << "Numero = " << setw(10) << right << x << endl;
    cout << "Numero = " << setw(10) << left << x << endl;

    double pi = 3.14159265;
    cout << fixed << setprecision(5);
    cout << pi << endl;
    return 0;
}