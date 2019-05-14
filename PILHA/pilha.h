#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0
#define PILHA_VAZIA 1
#define FALTOU_MEMORIA 2
#define CODIGO_INEXISTENTE 3

typedef struct {
    int cod;
    float salario;
} Funcionario;

struct nodo {
    Funcionario func;
    Nodo *prox;
};

typedef struct nodo Nodo;

typedef struct {
    Nodo *topo;
} PilhaSE;

void criarPilha(PilhaSE *pilha);
void exibePilha(PilhaSE pilha);
int estaVazia(PilhaSE *pilha);
int empilha(PilhaSE *pilha, Nodo nodo);