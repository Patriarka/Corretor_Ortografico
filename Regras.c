#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asciitrie.h"
#include "TAD_ListaEncadeada.h"
#include "TRIE_ChavesComPrefixo.h"
#include "TRIE_ChavesQueCasam.h"

Lista* regra1(ASCIITrie* Dicionario, char *palavra){
    // return TRIE_ChavesQueCasam(Dicionario, palavra, 1, 1);
}

Lista* regra2(ASCIITrie* Dicionario, char *palavra)
{
    printf("palavra não está no dicionário: %s\n", palavra);

    char *palavran_3 = (char *)malloc(strlen(palavra) - 3);
    char *palavran_2 = (char *) malloc(strlen(palavra) - 2);

    strncpy(palavran_3, palavra, strlen(palavra) - 3);
    strncpy(palavran_2, palavra, strlen(palavra) - 2);

    palavran_3[strlen(palavra) - 3] = '\0';
    palavran_2[strlen(palavra) - 2] = '\0';

    Lista* lista2 = TRIE_ChavesComPrefixo(Dicionario, palavran_3);
    Lista* lista3 = TRIE_ChavesComPrefixo(Dicionario, palavran_2);
    
    Lista* lista_final;

    return lista_final;
}

char* regra3(ASCIITrie* Dicionario, char* palavra){
    return TRIE_ChaveMaiorPrefixoDe(Dicionario, palavra);
}