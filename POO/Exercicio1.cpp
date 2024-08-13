#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

struct data
{
    int dia;
    int mes;
    int ano;
};

typedef struct
{
    string nome;
    double altura;
    struct data nascimento;

}pessoa;

pessoa p1, p2, p3, p4, p5, p6, p7, p8, p9, p10;
pessoa pessoas[10] = {p1, p2, p3, p4, p5, p6, p7, p8, p9, p10};

int main(){

    int res, usuario;
    for(usuario=0;usuario<10;usuario++){
        cout << "Deseja incluir novo usuário? (1/0)" <<endl;
        cin >> res;
        if(res == 0){
            break; // aqui eu to cancelando 
        } else {
            cout << "insina o dia" << endl;
            cin >> pessoas[usuario].nascimento.dia;
            cout << "insina o mes" << endl;
            cin >> pessoas[usuario].nascimento.mes;
            cout << "insina o ano" << endl;
            cin >> pessoas[usuario].nascimento.ano;
            cout << "insina o nome" << endl;
            cin >> pessoas[usuario].nome;
            cout << "insina o altura" << endl;
            cin >> pessoas[usuario].altura;
        }
    }     
    for (int i = 0; i < usuario; i++) {
        cout << "Usuario " << i+1 << ":" << endl;
        cout << "Nome: " << pessoas[i].nome << endl;
        cout << "Data de Nascimento: " 
             << pessoas[i].nascimento.dia << "/"
             << pessoas[i].nascimento.mes << "/"
             << pessoas[i].nascimento.ano << endl;
        cout << "Altura: " << pessoas[i].altura << "m" << endl << endl;
    }   
    return 0;
}
