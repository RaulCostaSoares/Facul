import java.util.HashMap;
import java.util.TreeMap;

public class AppCompara {

    public static void main(String[] args) {

        SeparateChainingHashST<String, Integer> ht = new SeparateChainingHashST<>(2000);
        In arq = new In("DomCasmurro_utf8.txt");
        String[] words = arq.readAllStrings();
        arq.close();

        long start = System.nanoTime();
        for (String word : words) {
            // System.out.println(word);
            if (!ht.containsKey(word))
                ht.put(word, 0);
            ht.put(word, ht.get(word) + 1);
        }
        long end = System.nanoTime();
        long tempo = end - start;
        System.out.println("=== Encadeamento separado ===");
        System.out.println("Tempo para criar o dicionário: " + tempo + " ns");
        System.out.println("Qtd. de palavras distintas: " + ht.size());

        LinearProbingHashST<String, Integer> ht2 = new LinearProbingHashST<>(2000);
        start = System.nanoTime();
        for (String word : words) {
            // System.out.println(word);
            if (!ht2.containsKey(word))
                ht2.put(word, 0);
            ht2.put(word, ht2.get(word) + 1);
        }
        end = System.nanoTime();
        tempo = end - start;
        System.out.println();
        System.out.println("=== Exploração linear ===");
        System.out.println("Tempo para criar o dicionário: " + tempo + " ns");
        System.out.println("Qtd. de palavras distintas: " + ht.size());
    }
}
