#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asciitrie.h"
#include "TAD_ListaEncadeada.h"

void Inserir_Trie_Lista_R(ASCIITrie *Trie, char *prefixo, Lista *lista)
{

    if (Trie == NULL)
        return;

    if (Trie->estado != ATE_LIVRE){
        lista_inserir_fim(lista, prefixo);      
    }

    for (int i = 0; i < 26; i++)
    {
        if (Trie->filhos[i] != NULL)
        {
            char* novo_prefixo = malloc(strlen(prefixo) * sizeof(char)+1);
            int j;

            for(j = 0; j < strlen(prefixo); j++)
                novo_prefixo[j] = prefixo[j];

            novo_prefixo[j] = (char) i+97;
            novo_prefixo[j+1] = '\0';

            Inserir_Trie_Lista_R(Trie->filhos[i], novo_prefixo, lista);
        };
    };
};

Lista *TRIE_ChavesComPrefixo(ASCIITrie *Trie, char *prefixo)
{

    Lista *lista_chaves = lista_criar();

    ASCIITrie *arvore_palavras = AT_Buscar(Trie, prefixo);

    AT_Imprimir(arvore_palavras);

    Inserir_Trie_Lista_R(arvore_palavras, prefixo, lista_chaves);

    lista_imprimir(lista_chaves);

    return lista_chaves;
}
