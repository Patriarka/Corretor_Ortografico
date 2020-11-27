#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asciitrie.h"
#include "TAD_ListaEncadeada.h"

static void Inserir_Trie_Lista_R(ASCIITrie *Trie, char *prefixo, char* novo_prefixo, Lista *lista, int pos)
{
    if (Trie == NULL)
        return;

    if (Trie->estado != ATE_LIVRE)
        lista_inserir_fim(lista, novo_prefixo, pos);

    for (int i = 0; i < 26; i++)
    {
        if (Trie->filhos[i] != NULL)
        {
            novo_prefixo[pos] = (char)i + 97;
            novo_prefixo[pos + 1] = '\0';

            Inserir_Trie_Lista_R(Trie->filhos[i], prefixo, novo_prefixo, lista, pos+1);
        }
    }
};

Lista *TRIE_ChavesComPrefixo(ASCIITrie *Trie, char *prefixo)
{

    Lista *lista_chaves = lista_criar();

    ASCIITrie *arvore_palavras = AT_Buscar(Trie, prefixo);

    char* novo_prefixo = (char*) malloc(47 * sizeof(char));

    strcpy(novo_prefixo, prefixo);

    Inserir_Trie_Lista_R(arvore_palavras, prefixo, novo_prefixo, lista_chaves, strlen(prefixo));
 
    // lista_imprimir(lista_chaves);

    free(novo_prefixo);

    return lista_chaves;
};







