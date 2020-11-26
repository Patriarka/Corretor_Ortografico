#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "asciitrie.h"

ASCIITrie* AT_Buscar_R(ASCIITrie* T, unsigned char *chave, int n, int p){

    if(T == NULL)
        return NULL;

    if(p == n) 
        return T;

    return AT_Buscar_R(T->filhos[chave[p]-97], chave, n, p+1); 
};

ASCIITrie* AT_Buscar(ASCIITrie* T, unsigned char *chave){
    // printf("%s", chave);
    // printf("%p", &chave);
    return AT_Buscar_R(T, chave, strlen(chave), 0);
};

ASCIITrie* AT_Criar(){

    ASCIITrie* noh;
    int i;

    noh = malloc(sizeof(ASCIITrie));
    noh->estado = ATE_LIVRE;
    noh->val = 0;
    noh->tam = 0;

    for(i = 0; i < 26; i++)
        noh->filhos[i] = NULL;

    return noh;
};

void AT_Inserir_R(ASCIITrie **T, unsigned char *chave, int val, int n, int p){

    if(*T == NULL)
        *T = AT_Criar();
    
    if(p == n){
        (*T)->val = val;
        (*T)->estado = ATE_OCUPADO;
        return;
    };

    AT_Inserir_R(&(*T)->filhos[chave[p]-97], chave, val, n, p+1);  
};

void AT_Inserir(ASCIITrie **T, unsigned char *chave, int val){
    AT_Inserir_R(T, chave, val, strlen(chave), 0);
}

void AT_Remover_R(ASCIITrie **T, unsigned char *chave, int n, int p){

    int i;

    if(*T == NULL)
      return;

    if(p == n)
      (*T)->estado = ATE_LIVRE;
    
    else{
      AT_Remover_R(&(*T)->filhos[chave[p]], chave, n, p+1);
    }

    if((*T)->estado == ATE_OCUPADO)
      return;
    
    for(i = 0; i < 26; i++)
      if((*T)->filhos[i] != NULL)
        return;
        
    free(*T);
    *T = NULL;
}

void AT_Remover(ASCIITrie **T, unsigned char *chave){
    AT_Remover_R(T, chave, strlen(chave), 0);
}

static void AT_Imprimir_R(ASCIITrie *T, unsigned char c, int nivel){
    
    if(T == NULL) return;
  
    for(int i = 0; i < nivel; i++) printf("-");
    char e = (T->estado == 0) ? 'L': 'O';
    printf("(%c) %d (%c)\n", c, T->val, e);

    for(int i = 0; i < 26; i++)
        if(T->filhos[i] != NULL)
            AT_Imprimir_R(T->filhos[i], i+97, nivel+1);

}

void AT_Imprimir(ASCIITrie* T){
    AT_Imprimir_R(T, 0, 0);
    printf("/*========================*/\n");
};
