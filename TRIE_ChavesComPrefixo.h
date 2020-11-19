#pragma once

#include "TAD_ListaEncadeada.h"
#include "asciitrie.h"

void Inserir_Trie_Lista(ASCIITrie* Trie, char* prefixo, Lista* lista);
Lista* TRIE_ChavesComPrefixo(ASCIITrie * Trie, char* prefixo);