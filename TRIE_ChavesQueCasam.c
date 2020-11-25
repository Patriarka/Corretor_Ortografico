#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asciitrie.h"
#include "TRIE_ChavesComPrefixo.h"
#include "TAD_ListaEncadeada.h"
#include "TRIE_ChavesQueCasam.h"

void TRIE_ChavesQueCasam_R(ASCIITrie *Trie, char *padrao, int tam_padrao_ini, int flag, int n_extras, Lista *lista)
{
    // Verificar se precisamos apagar os com n_extras a menos
    if (Trie->estado != ATE_LIVRE)
    {
        if (flag == 1 && strlen(padrao) == tam_padrao_ini)
        {
            lista_inserir_fim(lista, padrao, strlen(padrao));
        }
        else if (flag == 0)
            lista_inserir_fim(lista, padrao, strlen(padrao));
    }

    if (Trie == NULL || n_extras == 0)
        return;

    int i;
    for (i = 0; i < 26; i++)
    {
        if (Trie->filhos[i] != NULL)
        {
            if (n_extras >= 0)
            {
                int j;
                char *novo_padrao = malloc((strlen(padrao) + 2) * sizeof(char));

                strcpy(novo_padrao, padrao);

                novo_padrao[strlen(padrao)] = (char)i + 97;
                novo_padrao[strlen(padrao) + 1] = '\0';

                TRIE_ChavesQueCasam_R(Trie->filhos[i], novo_padrao, tam_padrao_ini, flag, n_extras - 1, lista);
            }
            else
                return;
        }
    }
}

Lista *TRIE_ChavesQueCasam(ASCIITrie *Trie, char *padrao, int flag, int n_extras)
{

    Lista *lista_chaves = lista_criar();

    ASCIITrie *arvore_palavras = AT_Buscar(Trie, padrao);

    // Fazer um for para movimentar o coringa

    TRIE_ChavesQueCasam_R(arvore_palavras, padrao, strlen(padrao) + n_extras, flag, n_extras, lista_chaves);

    lista_imprimir(lista_chaves);

    return lista_chaves;
};

static char *TRIE_ChaveMaiorPrefixoDe_Aux(ASCIITrie *Trie, char *nova_str, char *str, Lista *lista, int p)
{

    if (Trie == NULL)
        return NULL;

    if (Trie->estado == ATE_OCUPADO)
        lista_inserir_fim(lista, nova_str, strlen(nova_str));

    char *nova_str2 = (char *)malloc(p + 1 * sizeof(char));
    strncpy(nova_str2, str, p);

    nova_str2[strlen(nova_str2)] = str[p];

    nova_str2[strlen(nova_str2) + 1] = '\0';
    TRIE_ChaveMaiorPrefixoDe_Aux(Trie->filhos[str[p] - 97], nova_str2, str, lista, p + 1);

    if (lista->qtde == 0)
        return "";

    free(nova_str2);

    return lista->ultimo->dado;
};

char *TRIE_ChaveMaiorPrefixoDe(ASCIITrie *Trie, char *str)
{
    Lista *lista = lista_criar();
    return TRIE_ChaveMaiorPrefixoDe_Aux(Trie, "", str, lista, 0);
}
