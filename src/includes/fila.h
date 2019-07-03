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
int vazia (Fila *f);
// #3:
void insereFila (Fila *f, char morse[]);
// #4:
void liberaFile (Fila *q);
// #5:
void imprimeFila (Fila *f);