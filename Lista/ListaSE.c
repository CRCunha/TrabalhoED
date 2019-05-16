#include<stdio.h>
#include<stdlib.h>
#include "ListaSE.h"

void criaLista(ListaSE *lista){
	lista->inicio = NULL;
	printf("Lista Criada\n\n");
}
void exibeLista(ListaSE lista){
	Nodo *pAux;
	int i=1;
	if(estaVazia(lista) == LISTA_VAZIA){
		printf("Lista Vazia\n\n");
	}else{
		pAux = lista.inicio;
		while(pAux != NULL){
			printf("%d - [Nome: %s ] - [Tel: %d]\n", i, pAux->info.nome, pAux->info.num);
			pAux = pAux->prox;
			i++;
		}
	}
}
int estaVazia(ListaSE lista){
	if(lista.inicio == NULL){
		return LISTA_VAZIA;
	}
	return SUCESSO;
}
int incluiAntes(ListaSE *lista, int n, Contato c){
	Nodo *pNodo, *pTemp, *pAux;
	pNodo = (Nodo *) malloc(sizeof(Nodo));
	if(pNodo ==  NULL){
		return FALTOU_MEMORIA;
	}else{
		pNodo->info = c;
		pNodo->prox = NULL;
		if(lista->inicio == NULL){
			lista->inicio = pNodo;
			return SUCESSO;
		}else{
			pAux = lista->inicio;
			while(pAux != NULL){
				if(n == lista->inicio->info.num){
					pNodo->prox = pAux;
					lista->inicio = pNodo;
					return SUCESSO;
				}else{
					if(pAux->prox->info.num == n){
						pTemp = pAux->prox;
						pAux->prox = pNodo;
						pNodo->prox = pTemp;
						return SUCESSO;
					}
				}
				pAux = pAux->prox;
			}
		}
		return CODIGO_INEXISTENTE;
	}
}
int incluiDepois(ListaSE *lista, int n, Contato c){
	Nodo *pNodo, *pTemp, *pAux;
	pNodo = (Nodo *) malloc(sizeof(Nodo));
	if(pNodo ==  NULL){
		return FALTOU_MEMORIA;
	}else{
		pNodo->info = c;
		pNodo->prox = NULL;
		if(lista->inicio == NULL){
			lista->inicio = pNodo;
			return SUCESSO;
		}else{
			pAux = lista->inicio;
			while(pAux != NULL){
				if(pAux->info.num == n){
					pTemp = pAux->prox;
					pAux->prox = pNodo;
					pNodo->prox = pTemp;
					return SUCESSO;
				}
				pAux = pAux->prox;
			}
		}
		return CODIGO_INEXISTENTE;
	}
}
int consultaContato(ListaSE lista, int n, Contato *c){
	Nodo *pNodo;
	if(estaVazia(lista) == LISTA_VAZIA){
		return LISTA_VAZIA;
	}else{
		pNodo = lista.inicio;
		while(pNodo != NULL){
			if(pNodo->info.num == n){
				*c = pNodo->info;
				return SUCESSO;
			}
			pNodo = pNodo->prox;
		}
		return CODIGO_INEXISTENTE;
	}
}
int excluiContato(ListaSE *lista, int n, Contato *c){
	Nodo *pNodo, *pNodoA, *pTemp;
	if(estaVazia(*lista) == LISTA_VAZIA){
		return LISTA_VAZIA;
	}else{
		pNodo = lista->inicio;
		while(pNodo->info.num != n && pNodo->prox != NULL){
			pNodoA = pNodo;
			pNodo = pNodo->prox;
		}
		if(pNodo->info.num == n){
			if(pNodo== lista->inicio){
				*c = pNodo->info;
				pTemp = pNodo->prox; 
				lista->inicio = pTemp;
				free (pNodo);
			}else{
				pTemp = pNodo->prox;
				pNodoA->prox = pTemp;
				*c = pNodo->info;
				free (pNodo);
			}
			return SUCESSO;
		}else{
			return CODIGO_INEXISTENTE;
		}
	}
}
