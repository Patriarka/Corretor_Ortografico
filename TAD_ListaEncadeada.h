#pragma once

typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

typedef struct no{
    Tipo dado;
    struct no* prox;
    struct no* ant;
}No;

typedef struct{
    No* primeiro;
    No* ultimo;
    int qtde;
}Lista;

Lista* lista_criar();
No* getNo(Lista* l, int posicao);
void lista_inserir(Lista* l, Tipo elemento, int posicao);
void lista_imprimir(Lista* l);
void lista_inserir_fim(Lista* l, Tipo elemento);
Tipo* lista_remover1(Lista* l, int posicao);
Boolean lista_buscar(Lista* l, int posicao, int* endereco);
Boolean lista_remover2(Lista* l, int posicao, int* endereco);
Boolean lista_remover_elemento(Lista* l, Tipo elemento);
Boolean lista_contem(Lista* l, Tipo elemento);
int lista_posicao(Lista* l, Tipo elemento);
int lista_tamanho(Lista* l);
void lista_destruir(Lista* l);