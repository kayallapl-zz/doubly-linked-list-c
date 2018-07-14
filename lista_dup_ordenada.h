#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

Lista* cria_lista();
Lista* insere_final(Lista* li, int n);
Lista* insere_ordenado(Lista* li, int n);
int remove_elemento(Lista* li, int n);
void imprime_lista(Lista* li);