#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_ListaEncadeada.h"

Lista *lista_criar()
{
    Lista *nova_lista = (Lista *)malloc(sizeof(Lista));

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

Lista *lista_uniao(Lista *lista1, Lista *lista2)
{ // ant primeiro lista e depois do ultimo da lista 2

    if (lista1->qtde == 0 && lista2->qtde == 0)
        return lista1;
    if (lista1->qtde == 0 && lista2->qtde > 0)
        return lista1;
    if (lista2->qtde == 0 && lista1->qtde > 0)
        return lista1;

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

    if (strlen(elemento) < 1)
        return;
    No *novo = (No *)malloc(sizeof(No));

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

/* Tipo lista_remover(Lista *l, int posicao)
{

    if (posicao < 0 || posicao > l->qtde - 1)
        return NULL;

    No *onde = l->primeiro;

    for (int i = 0; i < posicao; i++)
    {
        onde = onde->prox;
    }

    if (posicao == 0)
    {
        l->primeiro = onde->prox;
    }
    else if (posicao == l->qtde - 1)
    {
        onde->ant->prox = NULL;
    }
    else
    {
        onde->ant->prox = onde->prox;
        onde->prox->ant = onde->ant;
    }

    Tipo *dado = (Tipo *)malloc(sizeof(Tipo));

    *dado = onde->dado;

    free(onde);
    l->qtde--;

    return dado;
}
 */
/* 
No* buscarPosicaoFim(Lista* l, int pos){
    No* aux = l->primeiro;
    for(int i = 0; i < pos; i++) {
        aux = aux->prox;
    }
    return aux;
}
 */
/*FUNCAO QUE RETORNA ENDEREÇO ONDE SERA INSERIDO VALOR
/*TAL FUNÇÃO COMEÇA SUA PROCURA PELO FIM DA LISTA
*@param: l = lista onde sera procurada posicao
*@return endereço dessa posição
*/
No* buscarPosicaoFim(Lista* l, int pos){
    No* aux = l->ultimo;
    for(int i = l->qtde-1; i > pos; i--) {
        aux = aux->ant;
    }
    return aux;
}


No* buscarPosicao(Lista* l, int posicao){
    No* pos;

    int posicaoMeio = l->qtde / 2;
    if( posicaoMeio == posicao || posicaoMeio >= posicao ) pos = buscarPosicaoFim(l, posicao);
    if( posicaoMeio <= posicao ) pos = buscarPosicaoFim(l, posicao);

    return pos;
}

Tipo lista_remover(Lista* l, int posicao){
    if(l == NULL) return NULL;
    if(l->qtde == 0) return NULL;
    if(posicao < 0 || posicao >= l->qtde) return NULL;

    No* pos = buscarPosicao(l, posicao);
    
    if(posicao != 0 && posicao < l->qtde-1) pos->ant->prox = pos->prox;
    if(posicao != l->qtde-1) pos->prox->ant = pos->ant;
    if(posicao == l->qtde-1) pos->ant->prox = NULL;
    if(posicao == 0) l->primeiro = pos->prox;

    l->qtde--;
    return pos->dado;
}


void destruir_no(No *no)
{
    if (no == NULL)
    {
        printf("no null\n");
        return;
    }
    printf("dado: %s\n", no->dado);
    destruir_no(no->prox);
    //free(no->dado);
    free(no);
}

void lista_destruir(Lista *lista)
{
    if (lista == NULL)
        return;
    if (lista->qtde <= 0)
        return;

    destruir_no(lista->ultimo);

    free(lista);
    printf("aq\n");
}
