#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include "separatechaining_hashtable.h"
#include "linearprobing_hashtable.h"

using namespace std;

int main()
{
    SeparateChainingHashTable<string, int> ht(2000);
    LinearProbingHashTable<string, int> ht2(2000);

    ifstream arq("DomCasmurro_utf8.txt");
    string str;
    vector<string> words;
    if (arq.is_open())
    {
        while (getline(arq, str))
        {
            // cout << str << endl;
            istringstream aux(str);
            copy(istream_iterator<string>(aux),
                 istream_iterator<string>(),
                 back_inserter(words));
        }
    }
    cout << "Total de palavras: " << words.size() << endl;

    long start = clock();
    long end;
    float tempo;

    for (auto word : words)
    {
        if (!ht.contains(word))
            ht.insert(word, 0);
        ht.insert(word, ht.get(word) + 1);
    }
    end = clock();
    tempo = (end - start) / (float)1e3;
    cout << "=== Encadeamento separado ===" << endl;
    cout << "Total de palavras distintas: " << ht.size() << endl;
    cout << "Tempo para inserção: " << tempo << " ms" << endl;

    start = clock();
    for (auto word : words)
    {
        if (!ht2.contains(word))
            ht2.insert(word, 0);
        ht2.insert(word, ht2.get(word) + 1);
    }
    end = clock();
    tempo = (end - start) / (float)1e3;
    cout << "=== Exploração linear ===" << endl;
    cout << "Total de palavras distintas: " << ht2.size() << endl;
    cout << "Tempo para inserção: " << tempo << " ms" << endl;
    return 0;
}