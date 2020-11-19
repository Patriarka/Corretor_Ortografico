#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asciitrie.h"
#include "TAD_ListaEncadeada.h"

void Inserir_Trie_Lista(ASCIITrie* Trie, unsigned char* prefixo, Lista* lista){
    
    printf("Trie %p prefixo: %s lista: %p\n", Trie, prefixo, lista);
    if(Trie == NULL){
        printf("é nulo\n");
        return;
    }
    printf("não é nulo\n");

    char prefixoNovo[] = "";

    printf("tamanho do prefixo %ld\n", strlen(prefixo));

    for(int i=0; i< strlen(prefixo) + 1; i++){
        prefixoNovo[i] = prefixo[i];
        // printf("%c %c\n", prefixoNovo[i], prefixo[i]);
    }
    
    printf("depois %s\n", prefixoNovo);
    
    /*
        for(int i = 0; i < 26; i++){
            if(Trie->filhos[i] != NULL){
                caractere[0] = (char)i;
                if(strlen(prefixo) >= sizeof(prefixo) / 2) 
                    prefixo = (char*) realloc(prefixo, sizeof(prefixo) * 2);
                
                printf("%s\n", prefixo);
            }
        };
    */
}

Lista* TRIE_ChavesComPrefixo(ASCIITrie * Trie, char* prefixo){

    Lista* lista_chaves = lista_criar();

    ASCIITrie* arvore_palavras = AT_Buscar(Trie, prefixo);

    // AT_Imprimir(arvore_palavras);

    Inserir_Trie_Lista(arvore_palavras, prefixo, lista_chaves);

    printf("saiu da função inserir");

    //AT_Imprimir(sufixo);
    
    return lista_chaves;
}  


/* 
char* concatenar(char s1[], char s2[]) {
    int i, j;

    i = strlen(s1);

    for (j = 0; s2[j] != 0; i++, j++) {
        s1[i] = s2[j];
    }

    s1[i] = 0;

    return s1;
}

void collect(ASCIITrie* Trie, char* pre, Lista* l, int pos) {

    if (Trie == NULL) return;
    if (Trie->estado != 'O') {
        lista_inserir(l, pre, pos);
        // pre = '';
        printf("pos: %d\n", pos);
    };
    
    for (char c = 0; c < 26; c++)
        if(Trie->filhos[c] != NULL)
            collect(Trie->filhos[c], pre + c, l, pos+1);
}
*/
