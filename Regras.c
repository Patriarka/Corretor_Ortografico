#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asciitrie.h"
#include "TAD_ListaEncadeada.h"
#include "TRIE_ChavesComPrefixo.h"
#include "TRIE_ChavesQueCasam.h"

void regra1_R(ASCIITrie *Trie, char *chave, char *nova_chave, int n, int p)
{
    if (Trie == NULL)
        return;

    if (strlen(chave) == n && Trie->estado == ATE_OCUPADO)
    {
        printf("%s\n", chave);
    }

    for (int i = 0; i < 26; i++)
    {
        if (Trie->filhos[chave[p] - 97])
        {
            chave[p] = (char)i + 97;
            chave[p + 1] = '\0';

            regra1_R(Trie->filhos[chave[p] - 97], chave, nova_chave, n, p + 1);
        }
    }
}

Lista *regra1(ASCIITrie *Dicionario, char *palavra)
{
    Lista *lista;

    char *palavra_coringa = (char *)malloc(strlen(palavra) + 1);
    for (int i = 0; i < strlen(palavra); i++)
    {
  
        strncpy(palavra_coringa, palavra, i);
        palavra_coringa[i] = '\0';

        lista = TRIE_ChavesQueCasam(Dicionario, palavra_coringa, 1, 1, 1);

        No *aux = lista->primeiro;

        int j = 0;
        for (; j < lista->qtde; j++)
        {
            if(aux != NULL){
                ASCIITrie *Auxiliar = AT_Buscar(Dicionario, aux->dado);
                regra1_R(Auxiliar, aux->dado, palavra, strlen(palavra), i + 1);
            }
            aux = aux->prox;
        };
    };

    free(palavra_coringa);

    return lista;
};

Lista *regra2(ASCIITrie *Dicionario, char *palavra)
{
    char *palavran_3 = (char *)malloc(strlen(palavra) - 3);
    char *palavran_2 = (char *)malloc(strlen(palavra) - 2);

    strncpy(palavran_3, palavra, strlen(palavra) - 3);
    strncpy(palavran_2, palavra, strlen(palavra) - 2);

    palavran_3[strlen(palavra) - 3] = '\0';
    palavran_2[strlen(palavra) - 2] = '\0';

    Lista *lista2 = TRIE_ChavesComPrefixo(Dicionario, palavran_3);
    Lista *lista3 = TRIE_ChavesComPrefixo(Dicionario, palavran_2);

    Lista *lista_final;

    return lista_final;
};

char *regra3(ASCIITrie *Dicionario, char *palavra)
{
    return TRIE_ChaveMaiorPrefixoDe(Dicionario, palavra);
};