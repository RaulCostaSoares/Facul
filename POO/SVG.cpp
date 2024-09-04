#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void generate_svg(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo para escrita.\n";
        return;
    }

    file << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"100\" height=\"100\">\n";
    file << "  <circle cx=\"50\" cy=\"50\" r=\"40\" stroke=\"black\" stroke-width=\"3\" fill=\"red\" />\n";
    file << "</svg>\n";

    file.close();
    cout << "Arquivo SVG gerado com sucesso.\n";
}

int main() {
    generate_svg("output.svg");
    return 0;
}