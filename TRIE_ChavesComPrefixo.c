#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asciitrie.h"
#include "TAD_ListaEncadeada.h"

static void Inserir_Trie_Lista_R(ASCIITrie *Trie, char *prefixo, char* novo_prefixo, Lista *lista, int p)
{
    if (Trie == NULL)
        return;

    if (Trie->estado != ATE_LIVRE)
        lista_inserir_fim(lista, novo_prefixo, p);        

    for (int i = 0; i < 26; i++)
    {
        novo_prefixo[p] = (char)i + 97;   
        Inserir_Trie_Lista_R(Trie->filhos[i], prefixo, novo_prefixo, lista, p+1);
    }
};

Lista *TRIE_ChavesComPrefixo(ASCIITrie *Trie, char *prefixo)
{

    Lista *lista_chaves = lista_criar();

    ASCIITrie *arvore_palavras = AT_Buscar(Trie, prefixo);

    char *novo_prefixo = (char *) malloc(47 * sizeof(char));;

    strcpy(novo_prefixo, prefixo);

    Inserir_Trie_Lista_R(arvore_palavras, prefixo, novo_prefixo, lista_chaves, strlen(prefixo));

    lista_imprimir(lista_chaves);

    free(novo_prefixo);

    return lista_chaves;
};
