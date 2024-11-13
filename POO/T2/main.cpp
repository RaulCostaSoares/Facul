// main.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "Livro.hpp"

// Função para exibir os livros em formato de tabela
void exibirTabela(const std::vector<Livro>& livros) {
    std::cout << "Titulo | Autor | Genero | Ano Publicacao | Vendas\n";
    for (const auto& livro : livros) {
        std::cout << livro.getTitulo() << " | " 
                  << livro.getAutor() << " | "
                  << livro.getGenero() << " | "
                  << livro.getAnoPublicacao() << " | "
                  << livro.getVendas() << "\n";
    }
}

// Função para encontrar o livro mais vendido
void livroMaisVendido(const std::vector<Livro>& livros) {
    auto it = std::max_element(livros.begin(), livros.end(), 
                               [](const Livro& a, const Livro& b) { return a.getVendas() < b.getVendas(); });
    if (it != livros.end()) {
        std::cout << "Livro mais vendido: " << it->getTitulo() << " com " << it->getVendas() << " vendas.\n";
    }
}

// Função para contar autores com múltiplos livros
void autoresComMaisDeUmLivro(const std::vector<Livro>& livros) {
    std::map<std::string, int> contagemAutores;
    for (const auto& livro : livros) {
        contagemAutores[livro.getAutor()]++;
    }
    std::cout << "Autores com mais de um livro:\n";
    for (const auto& autor : contagemAutores) {
        if (autor.second > 1) {
            std::cout << autor.first << " - " << autor.second << " livros\n";
        }
    }
}

int main() {
    // Exemplo de livros para testar
    std::vector<Livro> livros = {
        Livro("Livro A", "Autor X", "Ficcao", 2020, 5000),
        Livro("Livro B", "Autor Y", "Romance", 2018, 7500),
        Livro("Livro C", "Autor X", "Ficcao", 2021, 6000),
        Livro("Livro D", "Autor Z", "Suspense", 2015, 4500),
        Livro("Livro E", "Autor Y", "Romance", 2019, 3200)
    };

    // Exibe tabela
    exibirTabela(livros);

    // Responde perguntas
    livroMaisVendido(livros);
    autoresComMaisDeUmLivro(livros);

    return 0;
}
