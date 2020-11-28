#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_ListaEncadeada.h"

Lista *lista_criar()
{
    Lista *nova_lista = (Lista *) malloc(sizeof(Lista));

    nova_lista->primeiro = NULL;
    nova_lista->ultimo = NULL;
    nova_lista->qtde = 0;

    return nova_lista;
};

void lista_imprimir(Lista *l)
{

    int i = 0;
    No *aux = l->primeiro;

    while (aux != NULL)
    {
        printf("%s", aux->dado);
        if (i < l->qtde - 1)
            printf(", ");
        aux = aux->prox;
        i++;
    }
    printf("\n");
}

void lista_inserir(Lista *l, Tipo elemento, int posicao)
{
    posicao -= 1;
    if (posicao >= l->qtde + 1 || posicao < 0 || l == NULL)
        return;

    No *noInsere = (No *)malloc(sizeof(No) + 1);
    noInsere->dado = elemento;

    if (l->qtde == 0)
    {
        l->primeiro = noInsere;
        l->ultimo = noInsere;
        noInsere->prox = NULL;
        noInsere->ant = NULL;
    }
    else
    {
        if (posicao == l->qtde)
        {
            noInsere->ant = l->ultimo;  // anterior do ultimo recebe o penultimo
            l->ultimo->prox = noInsere; // prox penultimo recebe o ultimo
            noInsere->prox = NULL;      // prox ultimo recebe null
            l->ultimo = noInsere;       // ultimo lista recebe o novo
        }
        else if (posicao == 0)
        {
            noInsere->ant = NULL;
            noInsere->prox = l->primeiro;
            l->primeiro = noInsere;
        }
        else
        {
            No *aux = getNo(l, posicao);
            noInsere->ant = aux->ant->prox = noInsere;
            noInsere->prox = aux;
            aux->ant = noInsere;
        }
    }
    l->qtde++;
};

Lista* lista_uniao(Lista *lista1, Lista *lista2){ // ant primeiro lista e depois do ultimo da lista 2

    if(lista1->qtde == 0 && lista2->qtde == 0) return lista1;
    if(lista1->qtde == 0 && lista2->qtde > 0) return lista1;
    if(lista2->qtde == 0 && lista1->qtde > 0) return lista1;

    lista1->ultimo->prox = lista2->primeiro;
    lista2->primeiro->ant = lista1->ultimo;
    lista1->ultimo = lista2->ultimo;
    lista1->ultimo->prox = NULL;

    lista1->qtde += lista2->qtde;

    return lista1;
} 

/* 
Lista* lista_uniao(Lista *lista1, Lista *lista2){ // ant primeiro lista e depois do ultimo da lista 2

    Lista* nova_lista = lista_criar();

    No* aux = lista1->primeiro;
    for(int i = 0; i < lista1->qtde; i++){
        lista_inserir_fim(nova_lista, aux->dado);
        aux = aux->prox;
    }

    aux = lista2->primeiro;
    for(int i = 0; i < lista2->qtde; i++){
        lista_inserir_fim(nova_lista, aux->dado);
        aux = aux->prox;
    }

    return nova_lista;
} 
 */
void lista_inserir_fim(Lista *l, Tipo elemento)
{

    if(strlen(elemento) < 1) return;
    No* novo = (No*) malloc(sizeof(No));
    
    novo->dado = elemento;

    if (l->qtde == 0)
    {
        l->primeiro = novo;
        l->ultimo = novo;
        novo->ant = NULL;
    }
    else
    {
        novo->ant = l->ultimo;
        l->ultimo->prox = novo;
        l->ultimo = novo;
    }
    novo->prox = NULL;

    l->qtde++;
}

No *getNo(Lista *l, int posicao)
{

    int i;
    No *aux;

    if (posicao <= l->qtde / 2)
    {
        i = 0;
        aux = l->primeiro;
        while (i != posicao)
        {
            aux = aux->prox;
            i++;
        }
    }
    else
    {
        i = l->qtde;
        aux = l->ultimo;
        while (i != posicao)
        {
            aux = aux->prox;
            i--;
        }
    }

    return aux;
}

Boolean lista_contem(Lista *l, Tipo elemento)
{
    if (l == NULL || l->qtde == 0)
        return false;

    No *aux = l->primeiro;

    while (aux != NULL)
    {
        if (aux->dado == elemento)
            return true;
        aux = aux->prox;
    }
    return false;
}

int lista_posicao(Lista *l, Tipo elemento)
{
    if (l == NULL)
        return -1;

    int i = 1;
    No *aux = l->primeiro;

    while (aux != NULL)
    {
        if (aux->dado == elemento)
            return i;
        i++;
        aux = aux->prox;
    }

    return -1;
};

/*
void lista_destruir(Lista *lista){
    No *no = lista->primeiro;
    for(int i=0; i<lista->qtde - 1; i++){
        lista->primeiro = no->prox;
        free(no);
    };
    free(lista);
}
*/
/* 
void lista_destruir(Lista* l){
    if(l == NULL) return;
    
}
 */

void destruir_no(No* no){
    if(no == NULL){
         printf("no null\n");
        return;
    }
    printf("dado: %s\n", no->dado);
    destruir_no(no->prox);
    //free(no->dado);
    free(no);
}

void lista_destruir(Lista* lista){
    if(lista == NULL) return;
    if(lista->qtde <= 0) return;
    
    destruir_no(lista->ultimo);

    free(lista);
    printf("aq\n");
}
