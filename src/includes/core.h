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

// Função que inicia o programa
// #1:
void initMorse ();