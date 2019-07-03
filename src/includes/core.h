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
void InitMorse (int imprimir);
// #2:
Arvore *CriaNo (Chave *reg);
// #3:
Arvore *CriaArvore ();
// #4:
void LiberaArvore (Arvore *a);
// #5:
void ImprimeArvore (Arvore *a);
// #6:
char PesquisaR (Arvore *a, char *chave, int p);
// #7:
Arvore *InsereR (Arvore *a, Chave *reg, int p);
// #8:
void Insere (Arvore **a, Chave *reg);