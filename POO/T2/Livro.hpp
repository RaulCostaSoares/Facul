// Livro.hpp
#ifndef LIVRO_HPP
#define LIVRO_HPP

#include <string>

class Livro {
public:
    Livro(const std::string& titulo, const std::string& autor, const std::string& genero, int anoPublicacao, int vendas);

    // Getters para acessar os atributos
    std::string getTitulo() const;
    std::string getAutor() const;
    std::string getGenero() const;
    int getAnoPublicacao() const;
    int getVendas() const;

private:
    std::string titulo;
    std::string autor;
    std::string genero;
    int anoPublicacao;
    int vendas;
};

#endif
