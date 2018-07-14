#include <stdio.h>
#include <stdlib.h>
#include "lista_dup_ordenada.h"

typedef struct no{
    struct no* ant;
    int n;
    struct no* prox;
}No;

struct lista{
    No* prim;
};

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        li->prim = NULL;
        return li;
    }
}

Lista* insere_final(Lista* li, int n){
    No* no = (No*) malloc(sizeof(No));
    no->n = n;
    no->prox = NULL;
    if (li->prim == NULL){
        no->ant == NULL;
        li->prim = no;
        return li;
    }
    No* aux = li->prim;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = no;
    no->ant = aux;
    return li;
}

void imprime_lista(Lista* li){
    printf("[");
    for (No * no = li->prim; no!=NULL;no=no->prox){
        printf("%d ",no->n);
    }
    printf("]\n");
}

Lista* insere_ordenado(Lista* li, int n){
    No* no = (No*)malloc(sizeof(No));
    no->n = n;
    if(li->prim == NULL){
        no->prox = NULL;
        no->ant = NULL;
        li->prim = no;
        return li;
    }
    No *anterior, *atual = li->prim;
    while (atual != NULL && atual->n < no->n){
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == li->prim) {
        no->ant = NULL;
        li->prim->ant = no;
        no->prox = li->prim;
        li->prim = no;
        return li;
    }
    no->prox = anterior->prox;
    no->ant = anterior;
    anterior->prox = no;
    if(atual!=NULL){
        atual->ant = no;
    }
    return li;
}

int remove_elemento(Lista* li, int n){
    No *anterior, *atual = li->prim;
    while (atual->n != n && atual->prox != NULL){
        anterior = atual;
        atual = atual->prox;
    }
    if(atual->prox == NULL && atual->n != n){
        printf("Esse elemento nao existe\n");
        return -1;
    }
    if (atual == li->prim){
        No *aux = atual->prox;
        li->prim = aux;
        aux->ant = NULL;
        int x = atual->n;
        free(atual);
        return x;
    }
    if(atual->prox == NULL){
        No *aux = atual->ant;
        aux->prox = NULL;
        int x = atual->n;
        free(atual);
        return x;
    }
    anterior->prox = atual->prox;
    atual->prox->ant = anterior;
    int x = atual->n;
    free(atual);
    return x;
}