#include <iostream>
#include <string>

using namespace std;

int main()
{
    bool a = true, b = false;

    cout << "OR: " << (a || b) << endl;
    cout << "AND: " << (a && b) << endl << endl;    

    string str = "Esta eh uma string em C++";
    
    cout << "Tamanho: " << str.length() << endl;
    cout << "Letra de indice 2: " << str.at(2) << endl;
    cout << "Substring (inicio=5, tamanho=2): " << str.substr(5, 2) << endl;
    str = "FIM"; // str agora tem outro conteudo if (str == "FIM")
    cout << "> Encerrando o programa..." << endl;
    return 0;
}