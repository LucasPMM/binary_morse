struct item {
	char morse[150];
	struct item *prox;
};
typedef struct item Item;


struct fila {
	Item *inicio;
	Item *fim;
};
typedef struct fila Fila;

// #1:
void FFVazia (Fila *f);
// #2:
int Vazia (Fila *f);
// #3:
void InsereFila (Fila *f, char morse[]);
// #4:
void LiberaFile (Fila *q);
// #5:
void ImprimeFila (Fila *f);