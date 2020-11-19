#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asciitrie.h"
#include "TAD_ListaEncadeada.h"

void Inserir_Trie_Lista(ASCIITrie* Trie, char* prefixo, Lista* lista){
    
    // printf("Trie %p prefixo: %s lista: %p\n", Trie, prefixo, lista);
    if(Trie == NULL){
        printf("é nulo");
        return;
    }
    printf("não é nulo");
    char* str;

     /*
     if(strlen(prefixo) >= sizeof(prefixo) / 2) {
                printf("aq");
                prefixo = (char*) realloc(prefixo, sizeof(prefixo) * 2);
            }*/

    for(char caractere = 0; caractere < 26; caractere++){
        printf("qq");
        if(Trie->filhos[caractere] != NULL){
            // caractere[0] = (char)i;
           
            strcat(prefixo, str); 
            printf("%s\n", prefixo);
        
        };
    };


   /*  char* caractere;
    for(int i = 0; i < 26; i++){
        if(Trie->filhos[i] != NULL){
            caractere[0] = (char)i;
            if(strlen(prefixo) >= sizeof(prefixo) / 2) 
                prefixo = (char*) realloc(prefixo, sizeof(prefixo) * 2);
            strncat(prefixo, caractere, 1);
            printf("%s\n", prefixo);
        }
    }
 */
}

Lista* TRIE_ChavesComPrefixo(ASCIITrie * Trie, char* prefixo){

    
    Lista* lista_chaves = lista_criar();

    ASCIITrie* sufixo = AT_Buscar(Trie, prefixo);
    
    Inserir_Trie_Lista(Trie, prefixo, lista_chaves);

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
