#include<stdio.h>
#include<stdlib.h>
#include "Fila.h"
void criaFila(FilaSE *fila){
	fila->frente = NULL;
	fila->re = NULL;
}
int insere(FilaSE *fila, Voo voo){
	Nodo *pNodo, *pAux;
	pNodo = malloc(sizeof(Nodo));
	if(pNodo == NULL){
		return FALTOU_MEMORIA;
	}else{
		pNodo->v = voo;
		if(estaVazia(*fila)==FILA_VAZIA){
			fila->frente = pNodo;
			fila->re = pNodo;
		}else{
			pAux = fila->re;
			pAux->prox = pNodo;
			fila->re = pNodo;
		}
		return SUCESSO;
	}
}
int retira(FilaSE *fila, Voo *voo){
	Nodo *pAux;
	if(estaVazia(*fila)==FILA_VAZIA){
		return FILA_VAZIA;
	}else{
		*voo = fila->frente->v;
		pAux = fila->frente->prox;
		free(fila->frente);
		if(fila->frente == fila->re){
			fila->frente = NULL;
			fila->re = NULL;
		}else{
			fila->frente = pAux;
		}
	}
	return SUCESSO;
}
int estaVazia(FilaSE fila){
	if(fila.frente == NULL && fila.re == NULL){
		return FILA_VAZIA;
	}else{
		return SUCESSO;
	}
}
void exibeFila(FilaSE fila){
	Nodo *pNodo;
	if(estaVazia(fila)==FILA_VAZIA){
		printf("Fila vazia\n\n");
	}else{
		if(fila.frente == fila.re){
			printf("Num: %d\tCIA: %s\n", fila.frente->v.num, fila.frente->v.cia);
		}else{
			for(pNodo=fila.frente; pNodo!=NULL; pNodo = pNodo->prox){
				printf("Num: %d\tCIA: %s\n", pNodo->v.num, pNodo->v.cia);
			}
		}
	}
}
int quantidadeDeVoos(FilaSE fila){
	int i=0;
	Nodo *pNodo;
	if(estaVazia(fila)==FILA_VAZIA){
		return FILA_VAZIA;
	}else{
		i++;
		for(pNodo=fila.frente; pNodo!=fila.re; pNodo = pNodo->prox){
			i++;
		}
	}
	return i;
}
int consultaExistencia(FilaSE fila, int n){
	Nodo *pNodo;
	if(estaVazia(fila) == FILA_VAZIA){
		return FILA_VAZIA;
	}else{
		for(pNodo=fila.frente; pNodo->prox != NULL; pNodo = pNodo->prox){
			if(pNodo->v.num == n || fila.re->v.num == n){
				return SUCESSO;
			}
		}
		return NUMERO_INEXISTENTE;
	}
}
