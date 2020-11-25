#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "asciitrie.h"
#include "TAD_ListaEncadeada.h"
#include "TRIE_ChavesComPrefixo.h"
#include "TRIE_ChavesQueCasam.h"

char *Converter_Minusculo(unsigned char *palavra)
{

    for (int i = 0; i < strlen(palavra); i++)
        palavra[i] = tolower(palavra[i]);

    return palavra;
};

char *Apagar_Pontuacao(unsigned char *palavra)
{
    for (int i = 0; i < strlen(palavra); i++)
        if (ispunct(palavra[i]) || isspace(palavra[i]))
            palavra[i] = '\0';

    // Ver sobre o uso do hífen EX: guarda-chuva / amava-me

    return palavra;
};

char *Formatacao_Palavra(unsigned char *palavra)
{
    palavra = Converter_Minusculo(palavra);
    palavra = Apagar_Pontuacao(palavra);
    return palavra;
}

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

void Corrigir_Ortografia(unsigned char *arquivo_dicionario, unsigned char *arquivo_textual)
{
    ASCIITrie *Dicionario = Construir_Dicionario(arquivo_dicionario); 
    ASCIITrie *Palavras_verificadas = NULL;
    AT_Inserir(&Palavras_verificadas, "", 0);

    FILE *arquivo_entrada = fopen(arquivo_textual, "r");
    if (arquivo_entrada == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return;
    };

    char *palavra = (char *) malloc(sizeof(char));
    while (!feof(arquivo_entrada))
    {
        ASCIITrie *Aux;
        fscanf(arquivo_entrada, "%s\n", palavra);
        palavra = Formatacao_Palavra(palavra);

        if (!isdigit(palavra[0])) 
            Aux = AT_Buscar(Dicionario, palavra); // verifica se a palavra está no dicionário

        if (strlen(palavra) > 5) // Se a palavra tiver tamanho maior do que 5
        {

            char *palavran_3 = (char *) malloc(sizeof(char));
            char *palavran_2 = (char *) malloc(sizeof(char));

            strncpy(palavran_3, palavra, strlen(palavra) - 3);
            strncpy(palavran_2, palavra, strlen(palavra) - 2);

            printf("\npalavra não está no dicionário: %s\n", palavra);
            printf("sugestões:\n");

            Lista *lista_palavras_sugestoes_regra1_1 = TRIE_ChavesComPrefixo(Dicionario, palavran_3);
            Lista *lista_palavras_sugestoes_regra1_2 = TRIE_ChavesComPrefixo(Dicionario, palavran_2);
        };
    }
};

int main(int argc, char **argv)
{

    char dicionario[] = "dicionario.txt"; // nome do arquivo em que está contido o nosso dicionário
    char *arquivo_textual = argv[1];      // recebe o nome do arquivo a ser corrigido

    Corrigir_Ortografia(dicionario, arquivo_textual); // Função que executa a correção do arquivo_textual de acordo com o dicionário

    return 0;
};



// regra 1
// ratp    >>>  *atp, r*tp, ra*p, rat*

// TRIE_ChavesQueCasam(Dicionario, palavra, 0, 1);

        // Lista *lista_palavras_sugestoes_regra3 = TRIE_ChaveMaiorPrefixoDe(Dicionario, palavra);

        // juntar listas em uma trie
        
        //    No* primeiro_lista_1 = lista_palavras_sugestoes_regra_1->primeiro;
        //    No* primeiro_lista_2 = lista_palavras_sugestoes_regra2_1->primeiro;
        //    No* primeiro_lista_3 = lista_palavras_sugestoes_regra2_2->primeiro;

      /*
        // falta fazer regra 1
        for(int i=0; i<lista_palavras_sugestoes_regra_1->qtde; i++){
            AT_Inserir(Sugestoes, primeiro_lista_1->dado, i)
            primeiro_lista_1 = primeiro_lista_1->prox;
        }
        
        for(int i=0; i<lista_palavras_sugestoes_regra2_1->qtde; i++){
            AT_Inserir(Sugestoes, primeiro_lista_1->dado, i)
            primeiro_lista_1_1 = primeiro_lista_1->prox;
        }

        for(int i=0; i<lista_palavras_sugestoes_regra2_2->qtde; i++){
            AT_Inserir(Sugestoes, primeiro_lista_1->dado, i)
            primeiro_lista_2_2 = primeiro_lista_1->prox;
        }

        for(int i=0; i<lista_palavras_sugestoes_regra3->qtde; i++){
            AT_Inserir(Sugestoes, primeiro_lista_1->dado, i)
            primeiro_lista_3 = primeiro_lista_1->prox;
        }

        // falta criar regra 4 
      */

            // char* texto = TRIE_ChaveMaiorPrefixoDe(Dicionario, palavra); // Essa função retorna um texto ou uma lista?
            // Lista *lista_palavras_sugestoes_regra2 = TRIE_ChavesQueCasam(Dicionario, palavra, 1, 1);
