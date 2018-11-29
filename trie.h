#include "array_list.h"

namespace strutures {

//! class Trie
class Trie {
    public:
        Trie() {
            raiz = nullptr;
        }

        NoTrie get (String palavra) {
            NoTrie x = get(this->raiz, palavra, 0);
            if(x == nullptr) {
                return nullptr;
            }
            return x;
        }
        
        // completa get acima
        NoTrie get(NoTrie x, String palavra, int d) {
            if (x == nullptr) {
                return nullptr;
            }
            if (d == palavra.length()) {
                return x;
            }
            cha c = palavra.charAt(d);
            return get(x.filhos[c], palavra, d +1);
        }

        void put (String palavra, long posicao, long comprimento) {
            this->raiz = put(this->raiz, palavra, posicao, comprimento, 0);
        }

        NoTrie put(NoTrie x, String palavra, long posicao,
         long comprimento, int d) {
            if (x == nullptr) {
                x = new NoTrie();
            }
            if (d == palavra.length()) {
                x.posicao = posicao;
                x.comprimento = comprimento;
                return x;
            }
            char c =  palavra.charAt(d);
            x.filhos[c] = put(x.filhos[c], palavra, posicao, comprimento, d+1);
            return x;
        }

        void delete(String palavra) {
            this.raiz = delete(raiz, palavra, 0);
        }

        NoTrie delete(NoTrie x, String palavra, int d) {
            if (x ==nullptr) {
                return nullptr;
            }
            if (d == palavra.length()){
                x.posicao = nullptr;
                x.comprimento = nullptr;
            } else {
                char c = palavra.charAt(d);
                x.filhos[c] = delete(x.filhos[c], palavra, d +1);
            }
            if (x.posicao != nullptr || x.comprimento != nullptr) {
                return x;
            }
            for (char c = 0; c < 26); c++ {
                if (x.filhos[c] != nullptr) {
                    return x;
                }
                return nullptr;
            }
        }

    private:
        // atributos da trie
        NoTrie *raiz;
        
        struct NoTrie{
            public:
                // atributos do nodo
                char letra;
                NoTrie *filhos[26];
                unsigned long posicao;
                unsigned long comprimento;
        }
    
}
}