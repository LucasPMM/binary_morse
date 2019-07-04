#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/core.h"

#define MORSE_TAM 10
#define LINHA_TAM 200
#define VAZIO '!'

void InitMorse (int imprimir) {
    int i = 0;
    char letra, *entrada, morse[MORSE_TAM], linhaMorse[LINHA_TAM], linhaAlfanumerica[LINHA_TAM], *codigoMorse;
    
    Arvore arvore = CriaArvore();
    Chave chave;

    FILE *morseTxt = fopen("morse.txt", "r");;
    while(fscanf(morseTxt, " %c %s", &letra, morse) != EOF) {
        strcpy(chave.chave, morse);
        chave.letra = letra;
        Insere(&arvore, chave);
    }
    fclose(morseTxt);

    while (fgets(linhaMorse, LINHA_TAM, stdin) != NULL) {
        if(linhaMorse[strlen(linhaMorse)-1] == '\n') {
            linhaMorse[strlen(linhaMorse)-1] = '\0';
        }
        codigoMorse = strtok(linhaMorse, " ");
        while (codigoMorse != NULL) {
            if(!strcmp(codigoMorse, "/")) {
                linhaAlfanumerica[i] = ' ';
            }
            else {
                linhaAlfanumerica[i] = Pesquisa(arvore, codigoMorse)->registro.letra;
            }
            codigoMorse = strtok(NULL, " ");
            i++;
        }
        linhaAlfanumerica[i] = '\0';
        printf("%s\n", linhaAlfanumerica);
        // Seria possível armazenar todas as linhas em um vetor para printar somente no final
    }

    if (imprimir) {
        ImprimeArvore(arvore);
    }

    LiberaArvore(arvore);
}

Apontador CriaNo (Chave reg) {
    Apontador nova = (Apontador) malloc(sizeof(No));
    nova->registro = reg;
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

Apontador CriaArvore () { 
    Apontador nova = (Apontador) malloc(sizeof(No));
    nova->registro.letra = VAZIO;
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

void LiberaArvore (Apontador a) {
    if(a != NULL) {
        LiberaArvore(a->esq);
        LiberaArvore(a->dir);
        free(a);
    }
}

void ImprimeArvore (Apontador a) {
    if(a != NULL) {
        if(a->registro.letra != VAZIO) {
            printf("%c %s\n", a->registro.letra, a->registro.chave);
        }
        ImprimeArvore(a->esq);
        ImprimeArvore(a->dir);
    }
}

Apontador PesquisaR (Apontador a, char *chave, int p) {
    if (a == NULL) { return NULL; }
    if (strlen(chave) == p) {
        if (!strcmp(a->registro.chave, chave)) { return a; }
        else { return NULL; }
    }

    if (chave[p] == '.') {
        return PesquisaR(a->esq, chave, p + 1);
    } else {
        return PesquisaR(a->dir, chave, p + 1);
    }
}

Apontador Pesquisa (Apontador a, char *chave) {
    return PesquisaR(a, chave, 0);
}

Arvore InsereR (Arvore a, Chave reg, int p) {
    char chave[MORSE_TAM];
    strcpy(chave, reg.chave);

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


void Insere (Arvore *a, Chave reg) {
    *a = InsereR(*a, reg, 0);
}