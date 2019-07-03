#include <stdio.h>
#include <string.h>
#include "includes/fila.h"
#include <stdlib.h>

/*
Implementação de filas baseada nos slides da materia.
 */

void FFVazia (Fila *f) {
	f->inicio = (Item*) malloc(sizeof(Item));
	f->fim = f->inicio;
    f->inicio->prox = NULL;
}

int Vazia (Fila *f) { return (f->inicio == f->fim); }

void InsereFila (Fila *f, char morse[]) {
	f->fim->prox = (Item*) malloc(sizeof(Item));
	f->fim = f->fim->prox;
	strcpy(f->fim->morse, morse);
	f->fim->prox = NULL;
}

void LiberaFile (Fila *q) {
    Item *p = q->inicio;
    while (p != NULL) {
        q->inicio = p->prox;
        free(p);
        p = q->inicio;
    }
}

void ImprimeFila (Fila *f) {
    Item *p = f->inicio->prox;
    while (p != NULL) {
        printf("%s\n", p->morse);
        p = p->prox;
    }
}