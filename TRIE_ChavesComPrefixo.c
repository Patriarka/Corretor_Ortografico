#include <stdio.h>
#include "asciitrie.h"
#include "TAD_ListaEncadeada.h"

void Imprimir_em_Ordem(ASCIITrie* Trie){

   /*  if(Trie == NULL) return;

    for(int i = 0; i < 256; i++)
        for(int j = 0; j < 256; j++)
            if(Trie->filhos[i] != NULL){
                Imprimir_em_Ordem(Trie->filhos);
                printf("%d", j);
            } */
    // é fim de palavra?
    // se for, adiciona na lista
        // tem filhos?
        // se tiver, continua a busca pelo fim da palavra
        // se não, volta ao prefixo 
    
}

/* 
void Imprimir_em_Ordem(ASCIITrie* Trie){

    if(Trie == NULL) return;
    Imprimir_em_Ordem(Trie->esq)
    printf("%d\n", Trie->chave);
    Imprimir_em_Ordem(Trie->dir);

}
 */

// insercao em ordem(prefixo)

    // Insercao    
    // for( i++)
        // if T != NULL
            // AUX_R(prefixo+ novo prefixo) 

Lista* TRIE_ChavesComPrefixo(ASCIITrie * Trie, char* prefixo){
    
    Lista* lista_chaves = lista_criar();

    ASCIITrie* sufixo = AT_Buscar(Trie, prefixo);
    
    // sufixo = prefixo + palavra 

    // Percorrer toda essa trie T
    // Vai inserindo todas as palavras que a gnt encontrar, dentro da lista
    // prefix + palavras que encontrar

    // cada palavra completa possui um valor inteiro associado

    

    return lista_chaves;
} 