#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
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

    char *palavra_auxiliar = (char *)malloc(47 * sizeof(char));

    int i = 0;

    while (!feof(arquivo_dicionario))
    {
        fscanf(arquivo_dicionario, "%s", palavra_auxiliar);

        Converter_Minusculo(palavra_auxiliar);

        AT_Inserir(&Trie, palavra_auxiliar, i++);
    }

    free(palavra_auxiliar);
    fclose(arquivo_dicionario);

    return Trie;
};

void Imprimir_Sugestao_R(ASCIITrie *Trie, unsigned char *palavra, int pos)
{

    if (strcmp(palavra, "") != 0 && Trie->estado == ATE_OCUPADO)
        printf(", ");

    if (Trie->estado == ATE_OCUPADO)
    {
        if (strcmp(palavra, "") != 0)
            printf("%s", palavra);
    }

    if (Trie == NULL)
        return;

    for (int i = 0; i < 26; i++)
    {
        if (Trie->filhos[i] != NULL)
        {
            palavra[pos] = (char)i + 97;
            palavra[pos + 1] = '\0';

            Imprimir_Sugestao_R(Trie->filhos[i], palavra, pos + 1);
        };
    }
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
    char *palavra = (char *)malloc(sizeof(char));
    int palavras = 0;
    int palavras_erradas = 0;
    int palavras_sugeridas = 0;
    float numero_medio_sugestoes_palavras_incorretas = 0;
    
    while (!feof(arquivo_entrada))
    {
        ASCIITrie *Palavras_verificadas = NULL;
        fscanf(arquivo_entrada, "%s", palavra);

        palavras++;
        Formatacao_Palavra(palavra);

        if (!isdigit(palavra[0])) // verifica se a palavra é um número
        {
            if (!AT_Buscar(Dicionario, palavra)) // verifica se a palavra não está no dicionário
            {
                palavras_erradas++;
                Lista *lista1 = NULL, *lista2 = NULL, *lista3 = NULL, *lista_final = NULL;

                printf("\npalavra não está no dicionário: %s\n", palavra);
                printf("sugestões:\n");

                lista1 = regra1(Dicionario, palavra);

                if (strlen(palavra) > 5)
                {
                    lista2 = regra2(Dicionario, palavra);
                }

                char *palavra_regra3 = regra3(Dicionario, palavra);

                printf("%s\n", palavra_regra3);

                lista_inserir_fim(lista1, palavra_regra3);

                if (lista2 != NULL)
                    lista_final = lista_uniao(lista1, lista2); // União da lista da ChavesComPrefixo e ChavesQueCasam
                else
                    lista_final = lista1;

                lista3 = regra4(lista_final, palavra);

                Inserir_Lista_Trie(&Palavras_verificadas, lista_final);

                Lista *lista_total = TRIE_ChavesComPrefixo(Palavras_verificadas, "");

                palavras_sugeridas += lista_total->qtde;

                lista_imprimir(lista_total);
            };
        };
        numero_medio_sugestoes_palavras_incorretas = (float) palavras_sugeridas / palavras_erradas;
    };

    printf("%d %d %f\n", palavras, palavras_erradas, numero_medio_sugestoes_palavras_incorretas);

    AT_Destruir(Dicionario);
    free(palavra);
    fclose(arquivo_entrada);
};

int main(int argc, char **argv)
{
    clock_t t;

    t = clock();

    // recebe o nome do arquivo do dicionário
    char dicionario[] = "dicionario.txt";

    // recebe o nome do arquivo a ser corrigido
    char *arquivo_textual = argv[1];

    // Executa a correção do arquivo_textual de
    // acordo com o conteúdo do dicionário
    Corrigir_Ortografia(dicionario, arquivo_textual);

    t = clock() - t;
    
    printf("%f seconds\n",((float)t)/CLOCKS_PER_SEC);

    return 0;
}