#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){

    // Com STL

    map <string, int> m;

    m["Primeiro"] = 1;
    m["Segundo"] = 2;
    m["Terceiro"] = 3;
    m["Quarto"] = 4;

    cout << "Tamanho do Map: " << m.size() << endl;




    return 0;
}