#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/core.h"
#include "includes/fila.h"

void InitMorse (int imprimir) {
    int i;
    char letra, *entrada, morse[10], linhaMorse[1000], linhaAlfanumerica[1000];
    Fila *f; FFVazia(f);
    Arvore *arvore = CriaArvore();
    FILE *morseTxt = fopen("morse.txt", "r");;

    while(fscanf(morseTxt, " %c %s", &letra, morse) != EOF) {  
        Chave *chave;
        strcpy(chave->chave, morse);
        chave->letra = letra;
        Insere(&arvore, chave);
    }
    fclose(morseTxt);

    while (fgets(linhaMorse, 500, stdin) != NULL) {
        char *codigoMorse;
        i = 0;
        if(linhaMorse[strlen(linhaMorse)-1] == '\n') {
            linhaMorse[strlen(linhaMorse)-1] = '\0';
        }
        codigoMorse = strtok(linhaMorse, " ");    //getting the first morse codigoMorse
        while (codigoMorse != NULL) {
            //if it's an '/' just put a blank space on message
            if(strcmp(codigoMorse, "/") == 0) {
                linhaAlfanumerica[i] = ' ';
            }
            else {
                linhaAlfanumerica[i] = PesquisaR(arvore, codigoMorse, 0);
            }
            codigoMorse = strtok(NULL, " ");
            i++;
        }
        linhaAlfanumerica[i] = '\0';
        InsereFila(f, linhaAlfanumerica);
    }

    ImprimeFila(f);

    if(imprimir)
        ImprimeArvore(arvore);

    LiberaFile(f);
    LiberaArvore(arvore);
}

Arvore *CriaNo (Chave *reg) {
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

void ImprimeArvore (Arvore *a) {
    if(a != NULL) {
        if(a->registro->letra != '!') {
            printf("%c %s\n", a->registro->letra, a->registro->chave);
        }
        ImprimeArvore(a->esq);
        ImprimeArvore(a->dir);
    }
}

char PesquisaR (Arvore *a, char *chave, int p) {
    if (a->esq == NULL && a->dir == NULL) {
        if (!strcmp(a->registro->chave, chave)) {
            char letra = a->registro->letra;
            return letra;
        }
        else { return '!'; }
    }

    if (chave[p] == '.') {
        return PesquisaR(a->esq, chave, p + 1);
    } else {
        return PesquisaR(a->dir, chave, p + 1);
    }
}

Arvore *InsereR (Arvore *a, Chave *reg, int p) {
    char chave[10];
    strcpy(chave, reg->chave);

    if (strlen(chave) == p) {
        if (a == NULL) { return CriaNo(reg); }
        else {
            a->registro = reg;
            return a;
        }
    }
    if (a == NULL) { a = CriaArvore(); }
    if (chave[p] == '.') {
        a->esq = InsereR(a->esq, reg, p+1);
    }
    else {
        a->dir = InsereR(a->dir, reg, p+1);
    }
    return a;
}


void Insere (Arvore **a, Chave *reg) {
    *a = InsereR(*a, reg, 0);
}