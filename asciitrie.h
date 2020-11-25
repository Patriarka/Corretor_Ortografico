#pragma once
// #define tamanho_alfabeto 26

typedef enum ASCIITrie_ESTADO{
    ATE_LIVRE,
    ATE_OCUPADO
} ASCIITrie_ESTADO;

typedef struct ASCIITrie{
    int val;
    int tam;
    ASCIITrie_ESTADO estado;
    struct ASCIITrie* filhos[26];
} ASCIITrie;

ASCIITrie* AT_Criar();
void AT_Inserir(ASCIITrie **T, unsigned char *chave, int val);
void AT_Inserir_R(ASCIITrie **T, unsigned char *chave, int val, int n, int p);
void AT_Inserir_Iterativo(ASCIITrie **T, unsigned char *chave, int val, int n);
ASCIITrie* AT_Buscar(ASCIITrie* T, unsigned char *chave);
void AT_Inserir(ASCIITrie **T, unsigned char *chave, int val);
void AT_Remover(ASCIITrie **T, unsigned char *chave);
void AT_Imprimir(ASCIITrie* T);
