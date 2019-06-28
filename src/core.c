#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/core.h"

// Função 'cabeça' do programa:
void initMorse () {
    printf("Init program \n");
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

// A ..-.
// B -...
// C -.-.
// D -
// E .
// F .-
// G --
// H ....
// I ..-
// J .---
// K -.-
// L .-..
// M -.
// N --.
// O ---
// P .--.
// Q --.-
// R .-.
// S ...
// T -..
// U ..
// V ...-
// W .--
// X -..-
// Y -.--
// Z --..
// 0 -----
// 1 .----
// 2 ..---
// 3 ...--
// 4 ....-
// 5 .....
// 6 -....
// 7 --...
// 8 ---..
// 9 ----.