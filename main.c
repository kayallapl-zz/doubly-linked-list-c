#include <stdio.h>
#include "lista_dup_ordenada.h"

int main() {
    Lista* li = cria_lista();
    li = insere_ordenado(li, 3);
    imprime_lista(li);
    li = insere_ordenado(li, 1);
    imprime_lista(li);
    li = insere_ordenado(li, 4);
    imprime_lista(li);
    li = insere_ordenado(li, 2);
    imprime_lista(li);
    li = insere_ordenado(li, 5);
    imprime_lista(li);
    li = insere_ordenado(li, 0);
    imprime_lista(li);
    printf("Removendo...\n");

    int x = remove_elemento(li, 0);
    printf("%d: ", x);
    imprime_lista(li);

    int y = remove_elemento(li, 6);
    printf("%d: ", y);
    imprime_lista(li);

    int z= remove_elemento(li, 1);
    printf("%d: ", z);
    imprime_lista(li);

    int w= remove_elemento(li, 5);
    printf("%d: ", w);
    imprime_lista(li);

    return 0;
}