#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/core.h"
#include "includes/fila.h"

void initMorse (int imprimir) {
    printf("Init program %d\n", imprimir);
}

Arvore *criaNo (Chave *reg) {
    Arvore *nova = (Arvore*) malloc(sizeof(Arvore));
    nova->registro = reg;
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

Arvore *CriaArvore () { 
    Arvore *nova = (Arvore*) malloc(sizeof(Arvore));
    nova->registro->letra = '!';
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

void LiberaArvore (Arvore *a) {
    if(a != NULL) {
        LiberaArvore(a->esq);
        LiberaArvore(a->dir);
        free(a);
    }
}

void imprimeArvore (Arvore *a) {
    if(a != NULL) {
        if(a->registro->letra != '!') {
            printf("%c %s\n", a->registro->letra, a->registro->chave);
        }
        imprimeArvore(a->esq);
        imprimeArvore(a->dir);
    }
}

char pesquisaR (Arvore *a, char *chave, int p) {
    if (a->esq == NULL && a->dir == NULL) {
        if (!strcmp(a->registro->chave, chave)) {
            char letra = a->registro->letra;
            return letra;
        }
        else { return '!'; }
    }

    if (chave[p] == '.') {
        return pesquisaR(a->esq, chave, p + 1);
    } else {
        return pesquisaR(a->dir, chave, p + 1);
    }
}

Arvore *insereR (Arvore *a, Chave *reg, int p) {
    char chave[10];
    strcpy(chave, reg->chave);

    if (strlen(chave) == p) {
        if (a == NULL) { return criaNo(reg); }
        else {
            a->registro = reg;
            return a;
        }
    }
    if (a == NULL) { a = CriaArvore(); }
    if (chave[p] == '.') {
        a->esq = insereR(a->esq, reg, p+1);
    }
    else {
        a->dir = insereR(a->dir, reg, p+1);
    }
    return a;
}


void insere (Arvore **a, Chave *reg) {
    *a = insereR(*a, reg, 0);
}