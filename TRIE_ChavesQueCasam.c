#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asciitrie.h"
#include "TAD_ListaEncadeada.h"

void TRIE_ChavesQueCasam_R(ASCIITrie* Trie, char* padrao, int n_extras, Lista* lista){
    
    if (Trie->estado != ATE_LIVRE){
        lista_inserir_fim(lista, padrao);      
    }
    
    if(Trie == NULL || n_extras == 0) return;
    
    int i;
    for(i = 0; i < 26; i++)
    {
        if(Trie->filhos[i] != NULL)
        {
            if(n_extras >= 0){
                int j;
                char* novo_padrao = malloc((strlen(padrao)) * sizeof(char));

                strcpy(novo_padrao, padrao);

                novo_padrao[strlen(padrao)] = (char)i+97;
                novo_padrao[strlen(padrao)+1] = '\0';
                
                TRIE_ChavesQueCasam_R(Trie->filhos[i], novo_padrao, n_extras-1, lista);
            } else return;
        }
    }
}

Lista* TRIE_ChavesQueCasam(ASCIITrie* Trie, char* padrao, int n_extras){
    
    Lista* lista_chaves = lista_criar();

    ASCIITrie *arvore_palavras = AT_Buscar(Trie, padrao);

    TRIE_ChavesQueCasam_R(arvore_palavras, padrao, n_extras, lista_chaves);

    lista_imprimir(lista_chaves);

    return lista_chaves;
}

/* 

char* TRIE_ChaveMaiorPrefixoDe(ASCIITrie* Trie, char* str){
    int max = -1;

    printf("Tamanho de str: %ld\n", strlen(str));

    for(int i = 0; Trie != NULL; i++){
        if(Trie->filhos[i] != NULL) max = i;
        if(i == strlen(str)) break;
        Trie = Trie->filhos[i];
    }

    printf("%d\n", max);

    char str2[max];
    if(max == -1) return NULL;
    else return strncat(str2, str, max);
}

 */
          
