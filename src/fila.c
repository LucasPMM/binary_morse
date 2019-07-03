#include <stdio.h>
#include <string.h>
#include "includes/fila.h"
#include <stdlib.h>

/*
Implementação de filas baseada nos slides da materia.
 */

void FFVazia (Fila *f) {
	f->inicio = (Fila*) malloc(sizeof(Fila));
	f->fim = f->inicio;
    f->inicio->prox = NULL;
}

int vazia (Fila *f) { return (f->inicio == f->fim); }

void insere (Fila *f, char morse[]) {
	f->fim->prox = (Fila*) malloc(sizeof(Fila));
	f->fim = f->fim->prox;
	strcpy(f->fim->morse, morse);
	f->fim->prox = NULL;
}

void liberaFile (Fila *q) {
    Item *p = q->inicio;
    while (p != NULL) {
        q->inicio = p->prox;
        free(p);
        p = q->inicio;
    }
}

void imprimeFila (Fila *f) {
    Item *p = f->inicio->prox;
    while (p != NULL) {
        printf("%s\n", p->morse);
        p = p->prox;
    }
}