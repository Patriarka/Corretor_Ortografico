#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asciitrie.h"
#include "TRIE_ChavesComPrefixo.h"
#include "TAD_ListaEncadeada.h"
#include "TRIE_ChavesQueCasam.h"
/* 
void TRIE_ChavesQueCasam_R(ASCIITrie *Trie, char *padrao, int flag, int n_extras, Lista *lista, int pos)
{

    if (Trie == NULL)
        return;

    if (Trie->estado == ATE_OCUPADO)
        if (flag == 1 && strlen(padrao) == pos)
            lista_inserir_fim(lista, padrao, pos);
        else if (flag == 0)
            lista_inserir_fim(lista, padrao, pos);

    for (int i = 0; i < 26; i++)
    {
        if (Trie->filhos[i] != NULL)
        {
            if (n_extras > 0)
            {
                padrao[pos] = (char)i + 97;
                padrao[pos + 1] = '\0';

                TRIE_ChavesQueCasam_R(Trie->filhos[i], padrao, flag, n_extras - 1, lista, pos + 1);
            }
        }
    }
}

Lista *TRIE_ChavesQueCasam(ASCIITrie *Trie, char *padrao, int flag, int n_extras)
{

    Lista *lista_chaves = lista_criar();

    ASCIITrie *arvore_palavras = AT_Buscar(Trie, padrao);
    
    // ratp
    // rato
    // “*atp”, “r*tp”, “ra*p” e “rat*”.

    // letras +  string
    // printf("%s\n", padrao);

    char *novo_padrao = (char *)malloc(strlen(padrao) + n_extras * sizeof(char));

    TRIE_ChavesQueCasam_R(Trie, padrao, flag, n_extras, lista_chaves, strlen(padrao));

    free(novo_padrao);

    lista_imprimir(lista_chaves);

    return lista_chaves;
};
 */

/* 
void TRIE_ChavesQueCasam_R(ASCIITrie *Trie, char *padrao, int tam_padrao_ini, int flag, int n_extras, Lista *lista)
{
    if (Trie->estado != ATE_LIVRE)
        if (flag == 1 && strlen(padrao) == tam_padrao_ini)
            lista_inserir_fim(lista, padrao, strlen(padrao));
        else if (flag == 0)
            lista_inserir_fim(lista, padrao, strlen(padrao));
    
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
    char* novo_padrao = (char*) malloc(strlen(padrao) + n_extras * sizeof(char));
    
    TRIE_ChavesQueCasam_R(arvore_palavras, padrao, strlen(padrao), flag, n_extras, lista_chaves);
    
    lista_imprimir(lista_chaves);

    return lista_chaves;
};

 */



void TRIE_ChavesQueCasam_R(ASCIITrie *Trie, char *padrao, int tam_padrao_ini, int flag, int flag_regra_1, int n_extras, Lista *lista)
{

    if (Trie->estado != ATE_LIVRE || flag_regra_1 == 1){
        if(flag == 1 && strlen(padrao) == tam_padrao_ini)
            lista_inserir_fim(lista, padrao, strlen(padrao));
            
        else if(flag == 0 && strlen(padrao) >= tam_padrao_ini )
            lista_inserir_fim(lista, padrao, strlen(padrao)); 
    }

    if (Trie == NULL || n_extras == 0)
        return;

    for (int i = 0; i < 26; i++)
    {
        if (Trie->filhos[i] != NULL)
        {
            if (n_extras > 0)
            {
                char *novo_padrao = malloc((strlen(padrao) + 2) * sizeof(char));

                strcpy(novo_padrao, padrao);

                novo_padrao[strlen(padrao)] = (char)i + 97;
                novo_padrao[strlen(padrao) + 1] = '\0';

                TRIE_ChavesQueCasam_R(Trie->filhos[i], novo_padrao, tam_padrao_ini, flag, flag_regra_1, n_extras - 1, lista);
                free(novo_padrao);
            }
        }
    }
}

Lista *TRIE_ChavesQueCasam(ASCIITrie *Trie, char *padrao, int flag, int flag_regra_1, int n_extras)
{
    
    Lista *lista_chaves = lista_criar();
    
    ASCIITrie *arvore_palavras = AT_Buscar(Trie, padrao);
    
    if(arvore_palavras == NULL)
        return lista_chaves;
    
    TRIE_ChavesQueCasam_R(arvore_palavras, padrao, strlen(padrao)+n_extras, flag, flag_regra_1, n_extras, lista_chaves);

    lista_imprimir(lista_chaves);
    printf("\n");

    return lista_chaves;
};

static void TRIE_ChaveMaiorPrefixoDe_Aux(ASCIITrie *Trie, char *nova_str, char *str, Lista *lista, int pos)
{
    if (Trie == NULL)
        return;

    if (Trie->estado == ATE_OCUPADO)
        lista_inserir_fim(lista, nova_str, pos);

    nova_str[pos] = str[pos];
    nova_str[pos + 1] = '\0';

    TRIE_ChaveMaiorPrefixoDe_Aux(Trie->filhos[str[pos] - 97], nova_str, str, lista, pos + 1);
};

char *TRIE_ChaveMaiorPrefixoDe(ASCIITrie *Trie, char *str)
{

    Lista *lista = lista_criar();

    char *nova_str = (char *)malloc(strlen(str) + 1 * sizeof(char));

    TRIE_ChaveMaiorPrefixoDe_Aux(Trie, nova_str, str, lista, 0);

    free(nova_str);

    if (lista->qtde == 0)
        return "";

    return lista->ultimo->dado;
};
