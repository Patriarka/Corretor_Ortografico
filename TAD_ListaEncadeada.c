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
}

/* 
void lista_inserir_fim(Lista* lista, Tipo elemento){

    if(lista == NULL) return;

    No* no = (No*) malloc(sizeof(No));

    no->dado = elemento;
    no->ant = lista->ultimo;

    lista->ultimo->prox = no;
    no->prox = NULL;
    lista->ultimo = no;
    lista->qtde++;

} 

 */

void lista_inserir_fim(Lista *l, Tipo elemento, int tam)
{

    No* novo = (No*) malloc(sizeof(No));
    
    novo->dado = (char*) malloc((tam+1) * sizeof(char));

    strncpy(novo->dado, elemento, tam);

    if (l->qtde == 0)
    {
        l->primeiro = novo;
        l->ultimo = novo;
    }
    else
    {
        novo->ant = l->ultimo;
        l->ultimo->prox = novo;
        l->ultimo = novo;
    }

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
}
/* 
void lista_destruir(Lista* l){

    Tipo* removidoFree;
    while(l->qtde != 0) removidoFree = lista_remover1(l, l->qtde);

    free(l->primeiro);
    free(l->ultimo);
    free(l);
}

 */