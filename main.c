#include <stdio.h>
#include "asciitrie.h"
#include "TRIE_ChavesComPrefixo.h"
#include "TAD_ListaEncadeada.h"

ASCIITrie* ConstruirDicionario(char* arq_lista_palavras){

    ASCIITrie* Trie_saida = NULL;  

    FILE* arquivo_dicionario = fopen(arq_lista_palavras, "r");
    
    char* palavra_auxiliar;
    
    int i = 0;
    
    while(!feof(arquivo_dicionario)){
        fscanf(arquivo_dicionario, "%s", palavra_auxiliar);
        AT_Inserir(&Trie_saida, palavra_auxiliar, i++); 
    }

    return Trie_saida;
};

int main(int argc, char** argv) {    

    ASCIITrie* Trie = ConstruirDicionario("dicionario.txt");

    // Trie = AT_Buscar(Trie, "pa");

    // AT_Imprimir(Trie);

    Lista* nome_teste = TRIE_ChavesComPrefixo(Trie, "pao");

    return 0;
}

