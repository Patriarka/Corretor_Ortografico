#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "asciitrie.h"
#include "TAD_ListaEncadeada.h"
#include "TRIE_ChavesComPrefixo.h"
#include "TRIE_ChavesQueCasam.h"

char* Converter_Minusculo(unsigned char* palavra){

    for(int i = 0; i < strlen(palavra); i++){
        palavra[i] = tolower(palavra[i]);
    }

    return palavra;
}

ASCIITrie* Construir_Dicionario(unsigned char* arq_lista_palavras){

    ASCIITrie* Trie = NULL;  

    FILE* arquivo_dicionario = fopen(arq_lista_palavras, "r");
    
    char* palavra_auxiliar = (char*) malloc(sizeof(char));
    
    int i = 0;

    while(!feof(arquivo_dicionario)){
        fscanf(arquivo_dicionario, "%s", palavra_auxiliar);

        palavra_auxiliar = Converter_Minusculo(palavra_auxiliar);

        AT_Inserir(&Trie, palavra_auxiliar, i++); 
    }

    return Trie;
}

char* Ler_Texto(unsigned char* nome_arquivo_entrada){

    FILE* arquivo_entrada = fopen(nome_arquivo_entrada, "r");

    if(arquivo_entrada == NULL){ 
       printf ("Erro ao abrir o arquivo!\n");
       return NULL;
    } 

    char* texto;

    while(!feof(arquivo_entrada))
        fscanf (arquivo_entrada, "%s", texto);

    return texto;
}

void Corrigir_Ortografia(ASCIITrie* Trie, unsigned char* texto){

    ASCIITrie* Trie_buscada = AT_Buscar(Trie, texto);

    AT_Imprimir(Trie_buscada);

    // receber o conteúdo nessa variavel

    // Fazer isso para todas as palavras contidas no texto
    //     Se a palavra estiver no dicionario 
    //     Se a palavra não estiver no dicionario
    //         Sugerir outras palavras a partir das regras abaixo

    // printf("palavra que não está no dicionário: %s\n", );
    // printf("sugestões: ");
};

int main(int argc, char** argv){   

    // char* nome_arquivo = argv[1];   
 
    // char* texto = Ler_Texto(nome_arquivo);    
 
    ASCIITrie* Trie = Construir_Dicionario("dicionario.txt");   
 
    // Corrigir_Ortografia(Trie, texto); 
 
    // Lista* nome_teste = TRIE_ChavesComPrefixo(Trie, "chamado"); 

    // Lista* nome_teste = TRIE_ChavesQueCasam(Trie, "chamado", 1);

    printf("%s\n", TRIE_ChaveMaiorPrefixoDe(Trie, "chamado"));

    // lista_imprimir(nome_teste);

    return 0;
};
