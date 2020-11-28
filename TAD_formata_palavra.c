#include <ctype.h>
#include <string.h>
#include "TAD_formata_palavra.h"

void Converter_Minusculo(unsigned char *palavra)
{
    for (int i = 0; i < strlen(palavra); i++)
        palavra[i] = tolower(palavra[i]);
};

void Apagar_Pontuacao(unsigned char *palavra)
{
    for (int i = 0; i < strlen(palavra); i++)
        if (ispunct(palavra[i]) || isspace(palavra[i]))
            palavra[i] = '\0';

    // Ver sobre o uso do hífen EX: guarda-chuva / amava-me
};

void Formatacao_Palavra(unsigned char *palavra)
{
    Converter_Minusculo(palavra);
    Apagar_Pontuacao(palavra);
}
