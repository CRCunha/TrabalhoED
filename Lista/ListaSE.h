#ifndef listaSE_h
#define listaSE_h
#define SUCESSO 0
#define LISTA_VAZIA 1
#define FALTOU_MEMORIA 2
#define CODIGO_INEXISTENTE 3

typedef struct{
	int num;
	char nome[10];
}Contato;

typedef struct nodo Nodo;

struct nodo{
	Contato info;
	Nodo *prox;
};

typedef struct{
	Nodo *inicio;
}ListaSE;

void criaLista(ListaSE *lista);
int incluiAntes(ListaSE *lista, int n, Contato c);
int incluiDepois(ListaSE *lista, int n, Contato c);
void exibeLista(ListaSE lista);
int consultaContato(ListaSE lista, int n, Contato *c);
int excluiContato(ListaSE *lista, int n, Contato *c);
int estaVazia(ListaSE lista);
#endif
