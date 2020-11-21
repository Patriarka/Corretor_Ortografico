#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asciitrie.h"
#include "TAD_ListaEncadeada.h"

void TRIE_ChavesQueCasam_R(ASCIITrie* Trie, char* padrao, int n_extras, Lista* lista){

    if(Trie == NULL) return;

    if(Trie->estado = ATE_OCUPADO) printf("palavra a ser inserida: %s\n", padrao);

    char* novo_padrao;
    
    novo_padrao = malloc((strlen(padrao) + 1) * sizeof(char));

    for(int i = 0; i < 26; i++){
        if(Trie->filhos[i] != NULL){
            int j;

            printf("Letra inserida: %c\n", i+97);

            for(j = 0; j < strlen(padrao); j++)
                novo_padrao[j] = padrao[j];

            novo_padrao[j] = (char) i+97;
            novo_padrao[j+1] = '\0';

            TRIE_ChavesQueCasam_R(Trie->filhos[i], novo_padrao, n_extras-1, lista);
        }
    }

}

Lista* TRIE_ChavesQueCasam(ASCIITrie* Trie, char* padrao, int n_extras){
    
    Lista* lista_chaves = lista_criar();

    TRIE_ChavesQueCasam_R(Trie, padrao, n_extras, lista_chaves);

    lista_imprimir(lista_chaves);

    return lista_chaves;
}


          
