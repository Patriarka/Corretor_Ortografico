#pragma once

#include "TAD_ListaEncadeada.h"
#include "asciitrie.h"

// void Inserir_Trie_Lista(ASCIITrie* Trie, unsigned char* prefixo, Lista* lista);
void Inserir_Trie_Lista_R(ASCIITrie* Trie, char** prefixo, int tam_deslocamento, Lista* lista);
Lista* TRIE_ChavesComPrefixo(ASCIITrie * Trie, char* prefixo);