#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asciitrie.h"
#include "TAD_ListaEncadeada.h"
#include "TRIE_ChavesComPrefixo.h"
#include "TRIE_ChavesQueCasam.h"

void regra1_R(ASCIITrie **Trie, char *nova_palavra, char *palavra, int p, Lista *lista)
{
    if (*Trie == NULL)
        return;

    if (strlen(nova_palavra) == strlen(palavra) && (*Trie)->estado == ATE_OCUPADO)
        lista_inserir_fim(lista, nova_palavra);

    nova_palavra[p] = (char) palavra[p];
    nova_palavra[p + 1] = '\0';

    regra1_R(&(*Trie)->filhos[palavra[p] - 97], nova_palavra, palavra, p + 1, lista);
}

Lista *regra1(ASCIITrie *Dicionario, char *palavra)
{
    Lista *lista1 = lista_criar();

    char *palavra_coringa = (char *)malloc(strlen(palavra) + 1);

    for (int i = 0; i < strlen(palavra); i++)
    {
        strncpy(palavra_coringa, palavra, i);
        palavra_coringa[i] = '\0';

        Lista* lista = TRIE_ChavesQueCasam(Dicionario, palavra_coringa, 1, 1, 1);

        No *aux = lista->primeiro;

        for (int j = 0; j < lista->qtde; j++)
        {
            if (aux != NULL)
            {
                ASCIITrie *Auxiliar = AT_Buscar(Dicionario, aux->dado);
                regra1_R(&Auxiliar, aux->dado, palavra, i + 1, lista1);
            }
            aux = aux->prox;
        };
    };

    free(palavra_coringa);

    return lista1;
};

Lista *regra2(ASCIITrie *Dicionario, char *palavra)
{
    // saladq
    char *palavran_3 = (char *) calloc((strlen(palavra)-1), sizeof(char)); // sala     saladq = 6d  sala = 4d
    char *palavran_2 = (char *) calloc((strlen(palavra)), sizeof(char)); // salad    saladq = 6d  salad = 5d

    strncpy(palavran_3, palavra, (strlen(palavra)-2));
    strncpy(palavran_2, palavra, (strlen(palavra)-1));

    // palavran_3[strlen(palavra)-2] = '\0';
    // palavran_2[strlen(palavra)-1] = '\0';

    Lista *lista2 = TRIE_ChavesComPrefixo(Dicionario, palavran_3);
    Lista *lista3 = TRIE_ChavesComPrefixo(Dicionario, palavran_2);

    free(palavran_3);
    free(palavran_2);

    // lista_imprimir(lista3); 
    
    if(lista2->qtde > 0 && lista3->qtde > 0){
        Lista* lista4 = lista_uniao(lista2, lista3);
        // lista_imprimir(lista4);
        return lista4;
    };
    if(lista2->qtde == 0 && lista3->qtde == 0){
        return lista2;
    };
    if(lista2->qtde > 0 && lista3->qtde == 0){
        return lista2;
    }
    if(lista2->qtde == 0 && lista3->qtde > 0){
        return lista3;
    }
};


char *regra3(ASCIITrie *Dicionario, char *palavra)
{
    return TRIE_ChaveMaiorPrefixoDe(Dicionario, palavra);
};

/* Lista* regra4(char *palavra, ASCIITrie* Dicionario){

} */