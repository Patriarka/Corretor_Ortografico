#pragma once

#include "asciitrie.h"
#include "TAD_ListaEncadeada.h"

Lista* regra1(ASCIITrie* Dicionario, unsigned char *palavra);
Lista* regra2(ASCIITrie* Dicionario, unsigned char *palavra);
char* regra3(ASCIITrie* Dicionario, unsigned char *palavra);
Lista* regra4(Lista* lista, unsigned char* palavra);

