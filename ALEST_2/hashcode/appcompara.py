from separatechaining import SeparateChainingHashTable
from linearprobing import LinearProbingHashTable

if __name__=="__main__":

    ht2 = SeparateChainingHashTable(10000)
    ht = LinearProbingHashTable(10000)

    words = []
    with open("DomCasmurro_utf8.txt") as arq:
        for line in arq:
            aux = line[:-1].split()
            for word in aux:
                words.append(word)

    print("Total de palavras:",len(words))

    for word in words:
        if word not in ht:
            ht.insert(word, 0)
        ht.insert(word, ht.search(word)+1)

    print("Total de palavras distintas:", ht.size)

