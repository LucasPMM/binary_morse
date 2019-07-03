struct registro {
    char chave[10];
    char letra;
};

typedef struct registro Chave;

struct no {
    struct no *esq;
    struct no *dir;
    Chave *registro;
};

typedef struct no Arvore;

// #1:
void initMorse (int imprimir);
// #2:
Arvore *criaNo (Chave *reg);
// #3:
Arvore *CriaArvore ();
// #4:
void LiberaArvore (Arvore *a);
// #5:
void imprimeArvore (Arvore *a);
// #6:
char pesquisaR (Arvore *a, char *chave, int p);
// #7:
Arvore *insereR (Arvore *a, Chave *reg, int p);
// #8:
void insere (Arvore **a, Chave *reg);