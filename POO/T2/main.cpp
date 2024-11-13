#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include "Livro.hpp"

std::vector<Livro> carregarLivros(const std::string& nomeArquivo) {
    std::vector<Livro> livros;
    std::ifstream arquivo(nomeArquivo);
    
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << "\n";
        return livros;
    }

    std::string titulo, autor, genero;
    int anoPublicacao, vendas;

    while (arquivo >> titulo >> autor >> genero >> anoPublicacao >> vendas) {
        livros.emplace_back(titulo, autor, genero, anoPublicacao, vendas);
    }

    arquivo.close();
    return livros;
}

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

void livroMaisVendido(const std::vector<Livro>& livros) {
    auto it = std::max_element(livros.begin(), livros.end(), 
                               [](const Livro& a, const Livro& b) { return a.getVendas() < b.getVendas(); });
    if (it != livros.end()) {
        std::cout << "Livro mais vendido: " << it->getTitulo() << " com " << it->getVendas() << " vendas.\n";
    }
}

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

void generoMaisPopular(const std::vector<Livro>& livros) {
    std::map<std::string, int> contagemGeneros;
    for (const auto& livro : livros) {
        contagemGeneros[livro.getGenero()]++;
    }
    auto it = std::max_element(contagemGeneros.begin(), contagemGeneros.end(), 
                               [](const std::pair<const std::string, int>& a, const std::pair<const std::string, int>& b) { 
                                   return a.second < b.second; 
                               });
    if (it != contagemGeneros.end()) {
        std::cout << "Gênero mais popular: " << it->first << " com " << it->second << " livros.\n";
    }
}

int main() {
    std::vector<Livro> livros = carregarLivros("livros.txt");

    if (livros.empty()) {
        std::cerr << "Nenhum livro encontrado no arquivo.\n";
        return 1;
    }

    exibirTabela(livros);

    livroMaisVendido(livros);
    autoresComMaisDeUmLivro(livros);
    generoMaisPopular(livros);

    return 0;
}