#include <stdio.h>
#include <stdlib.h>
#include "TAD_ListaEncadeada.h"

Lista* lista_criar(){
  Lista* novaL = (Lista*) malloc(sizeof(Lista));
  novaL->qtde = 0;
  return novaL;
}

void lista_inserir(Lista* l, Tipo elemento, int posicao){
    posicao -= 1;
    if(posicao >= l->qtde + 1 || posicao < 0 || l == NULL) return;

    No* noInsere = (No*) malloc(sizeof(No));
    noInsere->dado = elemento;

    if(l->qtde == 0){
        l->primeiro = noInsere;
        l->ultimo = noInsere;
        noInsere->prox = NULL;
        noInsere->ant = NULL;
    }else{
        if(posicao == l->qtde){
            noInsere->ant = l->ultimo;
            l->ultimo->prox = noInsere;
            noInsere->prox = NULL;
            l->ultimo = noInsere;
        }else if(posicao == 0){
            noInsere->ant = NULL;
            noInsere->prox = l->primeiro;
            l->primeiro = noInsere;
        }else{
            No* aux = getNo(l, posicao);
            noInsere->ant = aux->ant->prox = noInsere;
            noInsere->prox = aux;
            aux->ant = noInsere;
        }
      }
      l->qtde++;
}

void lista_imprimir(Lista* l){

    int i=0;
    No* aux = l->primeiro;

    printf("[");
    while(i < l->qtde){
        printf("%d", aux->dado);
        if(i < l->qtde - 1) printf(", ");
        aux = aux->prox;
        i++;
    }
    printf("]\n\n");
}

void lista_inserir_fim(Lista* l, Tipo elemento){
    if(l == NULL) return;

    No* noInsere = (No*) malloc(sizeof(No));
    noInsere->dado = elemento;
    noInsere->ant = l->ultimo;
    l->ultimo->prox = noInsere;
    noInsere->prox = NULL;
    l->ultimo = noInsere;
    l->qtde++;
}

Tipo* lista_remover1(Lista* l, int posicao){
    if((posicao - 1) > l->qtde-1 || (posicao - 1) < 0 || l == NULL || l->qtde == 0) return false;
    posicao = posicao - 1;

    int* removido = malloc(sizeof(int));

    if(posicao == l->qtde - 1 && l->qtde != 1){
        *removido = l->ultimo->dado;
        l->ultimo->ant->prox = NULL;
        l->ultimo = l->ultimo->ant;
    }else if(posicao == 0 && l->qtde != 1){
         *removido = l->primeiro->dado;
        l->primeiro->prox->ant = NULL;
        l->primeiro = l->primeiro->prox;
    }else if(l->qtde == 1){
        *removido = l->primeiro->dado;
        l->primeiro = NULL;
        l->ultimo = NULL;
    }else{
        No* aux = getNo(l, posicao);
        aux->prox->ant = aux->ant;
        aux->ant->prox = aux->prox;
        *removido = aux->dado;
    }

    l->qtde--;

    return removido;
}

No* getNo(Lista* l, int posicao){

    int i;
    No* aux;

    if(posicao <= l->qtde/2){
        i=0;
        aux = l->primeiro;
        while(i != posicao){
            aux = aux->prox;
            i++;
        }
    }else{
        i = l->qtde;
        aux = l->ultimo;
        while(i != posicao){
            aux = aux->prox;
            i--;
        }
    }

    return aux;
}

Boolean lista_buscar(Lista* l, int posicao, int* endereco){

    No* aux = getNo(l, posicao);
    *endereco = aux->dado;

    return true;
}

Boolean lista_remover_elemento(Lista* l, Tipo elemento){
    if(l == NULL) return false;

    No* aux = l->primeiro;
    int posicao = 0;

    while(posicao < l->qtde){
        if(aux->dado != elemento){
            aux = aux->prox;
            posicao++;
        }else{
            lista_remover1(l, posicao + 1);
            return true;
        }
    }
    return false;
}

Boolean lista_contem(Lista* l, Tipo elemento){
    if(l == NULL || l->qtde == 0) return false;

    No* aux = l->primeiro;

    while(aux != NULL){
        if(aux->dado == elemento) return true;
        aux = aux->prox;
    }
    return false;
}

Boolean lista_remover2(Lista* l, int posicao, Tipo* endereco){
    if(l == NULL || l->qtde == 0 || endereco == NULL) return false;

    No* aux = getNo(l, posicao);

    if(posicao == l->qtde - 1 && l->qtde != 1){
        l->ultimo->ant->prox = NULL;
        l->ultimo = l->ultimo->ant;
    }else if(posicao == 0 && l->qtde != 1){
        l->primeiro->prox->ant = NULL;
        l->primeiro = l->primeiro->prox;
    }else if(l->qtde == 1){
        l->primeiro = NULL;
        l->ultimo = NULL;
    }else{
        int endereco;
        lista_buscar(l, posicao, &endereco);
        aux->prox->ant = aux->ant;
        aux->ant->prox = aux->prox;
        endereco = aux->dado;
        free(aux);
    }

    l->qtde--;

    return true;
}

int lista_posicao(Lista* l, Tipo elemento){
    if(l == NULL) return -1;
    
    int i = 1;
    No* aux = l->primeiro;

    while(aux != NULL){
        if(aux->dado == elemento) return i;
        i++;
        aux = aux->prox;
    }

    return -1;
}

int lista_tamanho(Lista* l){
    if(l == NULL) return -1;
    return l->qtde;
}

void lista_destruir(Lista* l){

    Tipo* removidoFree;
    while(l->qtde != 0) removidoFree = lista_remover1(l, l->qtde);

    free(l->primeiro);
    free(l->ultimo);
    free(l);
}