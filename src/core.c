#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/core.h"

// Função 'cabeça' do programa:
void initMorse () {
    printf("Init program \n");
}

Arvore *criaNo(Chave *reg) {
    Arvore *nova = (Arvore*) malloc(sizeof(Arvore));
    nova->registro = reg;
    //setting left and right Arvores to NULL to prevent errors
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

Arvore *CriaArvore() { 
    Arvore *nova = (Arvore*) malloc(sizeof(Arvore));
    nova->registro->letra = '!';
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

void LiberaArvore(Arvore *a) {
    if(a != NULL) {
        LiberaArvore(a->esq);
        LiberaArvore(a->dir);
        free(a);
    }
}

void imprimeArvore(Arvore *a) {
    if(a != NULL) {
        if(a->registro->letra != '!') {
            printf("%c %s\n", a->registro->letra, a->registro->chave);
        }
        imprimeArvore(a->esq);
        imprimeArvore(a->dir);
    }
}

char pesquisaR(Arvore *a, char *chave, int p) {
    if (p == NULL) { return NULL; }
    
    if (a->esq == NULL && a->dir == NULL) {
        if (!strcmp(a->registro->chave, chave)) {
            char letra = a->registro->letra;
            return letra;
        }
        else { return NULL; }
    }

    if (!strcmp(chave[p], '.')) {
        return pesquisaR(a->esq, chave, p + 1);
    } else {
        return pesquisaR(a->dir, chave, p + 1);
    }
}

Arvore *insereR (Arvore *a, Chave *reg, int p) {
    char chave[10];
    strcopy(chave, reg->chave);

    if (strlen(chave) == p) {
        if (a == NULL) { return criaNo(reg); }
        else {
            a->registro = reg;
            return a;
        }
    }
    if (a == NULL) { a = criaArvore(); }
    if (!strcmp(chave[p], '.')) {
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