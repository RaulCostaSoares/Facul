#ifndef LIVRO_HPP
#define LIVRO_HPP

#include <string>

using namespace std;

class Livro {
public:
    Livro(const string& titulo, const string& autor, const string& genero, int anoPublicacao, int vendas);

    string getTitulo() const;
    string getAutor() const;
    string getGenero() const;
    int getAnoPublicacao() const;
    int getVendas() const;

private:
    string titulo;
    string autor;
    string genero;
    int anoPublicacao;
    int vendas;
};

#endif
