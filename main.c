#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "asciitrie.h"
#include "TAD_ListaEncadeada.h"
#include "TRIE_ChavesComPrefixo.h"
#include "TRIE_ChavesQueCasam.h"

char* Converter_Minusculo(char* palavra){

    for(int i = 0; i < strlen(palavra); i++){
        palavra[i] = tolower(palavra[i]);
    }

    return palavra;
}

ASCIITrie* ConstruirDicionario(char* arq_lista_palavras){

    ASCIITrie* Trie = NULL;  

    FILE* arquivo_dicionario = fopen(arq_lista_palavras, "r");
    
    char* palavra_auxiliar;
    
    int i = 0;

    while(!feof(arquivo_dicionario)){
        fscanf(arquivo_dicionario, "%s", palavra_auxiliar);

        palavra_auxiliar = Converter_Minusculo(palavra_auxiliar);

        AT_Inserir(&Trie, palavra_auxiliar, i++); 
    }

    return Trie;
};

int main(int argc, char** argv) {    

    ASCIITrie* Trie = ConstruirDicionario("dicionario.txt");
    
    Lista* nome_teste = TRIE_ChavesComPrefixo(Trie, "chamado");

    // Lista* nome_teste = TRIE_ChavesQueCasam(Trie, "chamado", 3);
    
    // lista_imprimir(nome_teste);

    return 0;
}

