typedef struct {
    char chave[10];
    char letra;
} Chave;

typedef struct no *Apontador;

typedef struct no {
    Apontador esq;
    Apontador dir;
    Chave registro;
} No;

typedef Apontador Arvore;

// #1:
void InitMorse (int imprimir);
// #2:
Apontador CriaNo (Chave reg);
// #3:
Apontador CriaArvore ();
// #4:
void LiberaArvore (Apontador a);
// #5:
void ImprimeArvore (Apontador a);
// #6:
Apontador PesquisaR (Apontador a, char *chave, int p);
// #7:
Apontador InsereR (Apontador a, Chave reg, int p);
// #8:
void Insere (Apontador *a, Chave reg);
// #9:
Apontador Pesquisa (Apontador a, char *chave);