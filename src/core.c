#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/core.h"

// Uma possível melhora seria implementar o realloc para evitar esses valores não dinâmicos
#define MORSE_TAM 10
#define LINHA_TAM 500
#define MORSE_FILE "morse.txt"
#define VAZIO '!'

void InitMorse (int imprimir) {
    int i = 0;
    char letra, *entrada, morse[MORSE_TAM], linhaMorse[LINHA_TAM], linhaAlfanumerica[LINHA_TAM], *codigoMorse;
    
    Arvore arvore = CriaArvore();
    Chave chave;

    // Montar a árvore com os dados do arquivo
    FILE *morseTxt = fopen(MORSE_FILE, "r");;
    while(fscanf(morseTxt, " %c %s", &letra, morse) != EOF) {
        strcpy(chave.chave, morse);
        chave.letra = letra;
        Insere(&arvore, chave);
    }
    fclose(morseTxt);

    // Traduzir cada codigo morse em uma letra até o final do arquivo
    while (fgets(linhaMorse, LINHA_TAM, stdin) != NULL) {
        // Remover o '\n' no final da string e marcar como o final
        if(linhaMorse[strlen(linhaMorse)-1] == '\n') {
            linhaMorse[strlen(linhaMorse)-1] = '\0';
        }
        // Similar ao split do javascript: separar em uma string até a ocorrência de um caracter
        codigoMorse = strtok(linhaMorse, " ");
        while (codigoMorse != NULL) {
            if(!strcmp(codigoMorse, "/")) { // Caso o caracter for '/' adicionar um espaço
                linhaAlfanumerica[i] = ' ';
            } else { // Caso contrário pesquisar na árvore
                linhaAlfanumerica[i] = Pesquisa(arvore, codigoMorse)->registro.letra;
            }
            codigoMorse = strtok(NULL, " ");
            i++;
        }
        // Marcar o fim da string
        linhaAlfanumerica[i] = '\0';
        i = 0;
        printf("%s\n", linhaAlfanumerica);
        // Seria possível armazenar todas as linhas em um vetor para printar somente no final
    }

    // Imprimir a árvore caso o parâmetro '-a' seja inserido
    if (imprimir) { ImprimeArvore(arvore); }

    LiberaArvore(arvore);
}

Apontador CriaNo (Chave reg) {
    Apontador nova = (Apontador) malloc(sizeof(No));
    nova->registro = reg;
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
    // Implementação baseada nos slides da matéria;
}

Apontador CriaArvore () { 
    Apontador nova = (Apontador) malloc(sizeof(No));
    nova->registro.letra = VAZIO;
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
    // Implementação baseada nos slides da matéria;
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

    if (chave[p] == '.') { // caso o caracter seja '.' inserir na sub-árvore da esquerda
        return PesquisaR(a->esq, chave, p + 1);
    } else { // caso o caracter seja '-' inserir na sub-árvore da direita
        return PesquisaR(a->dir, chave, p + 1);
    }
    // Implementação baseada nos slides da matéria;
}

Apontador Pesquisa (Apontador a, char *chave) {
    return PesquisaR(a, chave, 0);
    // Implementação baseada nos slides da matéria;
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
    // Implementação baseada nos slides da matéria;
}


void Insere (Arvore *a, Chave reg) {
    *a = InsereR(*a, reg, 0);
    // Implementação baseada nos slides da matéria;
}