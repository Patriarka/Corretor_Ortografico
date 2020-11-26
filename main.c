#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Regras.h"
#include "asciitrie.h"
#include "TAD_formata_palavra.h"
#include "TAD_ListaEncadeada.h"
#include "TRIE_ChavesComPrefixo.h"
#include "TRIE_ChavesQueCasam.h"

ASCIITrie *Construir_Dicionario(unsigned char *arq_lista_palavras)
{

    ASCIITrie *Trie = NULL;

    FILE *arquivo_dicionario = fopen(arq_lista_palavras, "r");

    char *palavra_auxiliar = (char *)malloc(sizeof(char));

    int i = 0;

    while (!feof(arquivo_dicionario))
    {
        fscanf(arquivo_dicionario, "%s", palavra_auxiliar);

        palavra_auxiliar = Converter_Minusculo(palavra_auxiliar);

        AT_Inserir(&Trie, palavra_auxiliar, i++);
    }

    return Trie;
};

void Imprimir_Sugestao(ASCIITrie *Trie_aux, Lista *lista, int i)
{
    if (lista->qtde < 0)
        return;

    No *aux = lista->primeiro;

    while (aux != lista->ultimo)
    {
        AT_Inserir(&Trie_aux, aux->dado, i);
        aux = aux->prox;
        i++;
    };

    AT_Imprimir(Trie_aux);
};

void Corrigir_Ortografia(unsigned char *arquivo_dicionario, unsigned char *arquivo_textual)
{

    FILE *arquivo_entrada = fopen(arquivo_textual, "r");
    if (arquivo_entrada == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    ASCIITrie *Dicionario = Construir_Dicionario(arquivo_dicionario);

    ASCIITrie *Palavras_verificadas = NULL;
    AT_Inserir(&Palavras_verificadas, "", 0);

    char *palavra = (char *)malloc(sizeof(char));

    while (!feof(arquivo_entrada))
    {
        fscanf(arquivo_entrada, "%s", palavra);

        palavra = Formatacao_Palavra(palavra);

        if (!isdigit(palavra[0]))
        { // verifica se a palavra é um número
            if (!AT_Buscar(Dicionario, palavra)) // verifica se a palavra não está no dicionário
            { 
                Lista *lista1, *lista2, *lista3, *lista4;

                lista1 = regra1(Dicionario, palavra);

                if (strlen(palavra) > 5)
                    lista2 = regra2(Dicionario, palavra);

                // char *palavra_regra3 = regra3(Dicionario, palavra);

                // lista_inserir_fim(lista3, palavra_regra3, strlen(palavra_regra3));

                //  regra4(palavra, Dicionario);

                //  sugestoes(lista1, lista2, lista3, lista4);
            };
        };

    }
};

int main(int argc, char **argv)
{
    char dicionario[] = "dicionario.txt"; // nome do arquivo em que está contido o nosso dicionário
    char *arquivo_textual = argv[1];      // recebe o nome do arquivo a ser corrigido

    Corrigir_Ortografia(dicionario, arquivo_textual); // Função que executa a correção do arquivo_textual de acordo com o dicionário

    return 0;
}
