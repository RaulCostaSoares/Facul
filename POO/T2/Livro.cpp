// Livro.cpp
#include "Livro.hpp"

Livro::Livro(const std::string& titulo, const std::string& autor, const std::string& genero, int anoPublicacao, int vendas)
    : titulo(titulo), autor(autor), genero(genero), anoPublicacao(anoPublicacao), vendas(vendas) {}

std::string Livro::getTitulo() const {
    return titulo;
}

std::string Livro::getAutor() const {
    return autor;
}

std::string Livro::getGenero() const {
    return genero;
}

int Livro::getAnoPublicacao() const {
    return anoPublicacao;
}

int Livro::getVendas() const {
    return vendas;
}
