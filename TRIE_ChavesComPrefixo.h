#pragma once

#include "TAD_ListaEncadeada.h"
#include "asciitrie.h"

Lista *TRIE_ChavesQueCasam(ASCIITrie *Trie, char *padrao, int flag, int flag_regra_1, int n_extras);
Lista* TRIE_ChavesComPrefixo(ASCIITrie * Trie, char* prefixo);