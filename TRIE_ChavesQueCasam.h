#pragma once

#include "asciitrie.h"
#include "TAD_ListaEncadeada.h"

Lista *TRIE_ChavesQueCasam(ASCIITrie *Trie, char *padrao, int flag, int flag_regra_1, int n_extras);
char* TRIE_ChaveMaiorPrefixoDe(ASCIITrie *Trie, char *str);



