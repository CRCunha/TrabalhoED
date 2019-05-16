#ifndef Fila_h
#define Fila_h
#define SUCESSO 0
#define FILA_VAZIA 1
#define FALTOU_MEMORIA 2
#define NUMERO_INEXISTENTE 3

typedef struct nodo Nodo;

typedef struct{
	int num;
	char cia[10];
}Voo;

struct nodo{
	Voo v;
	Nodo *prox;
};

typedef struct{
	Nodo *frente;
	Nodo *re;
}FilaSE;

void criaFila(FilaSE *fila);
void exibeFila(FilaSE fila);
int insere(FilaSE *fila, Voo voo);
int retira(FilaSE *fila, Voo *voo);
int estaVazia(FilaSE fila);
int quantidadeDeVoos(FilaSE fila);
int consultaExistencia(FilaSE fila, int n);

#endif
