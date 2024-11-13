#include "Livro.hpp"

using namespace std;

Livro::Livro(const string& titulo, const string& autor, const string& genero, int anoPublicacao, int vendas)
    : titulo(titulo), autor(autor), genero(genero), anoPublicacao(anoPublicacao), vendas(vendas) {}

string Livro::getTitulo() const {
    return titulo;
}

string Livro::getAutor() const {
    return autor;
}

string Livro::getGenero() const {
    return genero;
}

int Livro::getAnoPublicacao() const {
    return anoPublicacao;
}

int Livro::getVendas() const {
    return vendas;
}
