#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void criarPilha(PilhaSE *pilha){
    pilha->topo = NULL;
}

void exibePilha(PilhaSE pilha){
    if(pilha.topo != NULL){
        Nodo *nodoTemp = pilha.topo;
        do{
            printf("Dado: %d\n", nodoTemp->info);
            nodoTemp = nodoTemp->prox;
        } while (nodoTemp->prox != NULL);

        printf("Dado: %d\n", nodoTemp->info);
    }
    
}

int estaVazia(PilhaSE *pilha){
    if(pilha->topo = NULL){
        return(1);
    }
    else{
        return(0);
    }
}

int empilha(PilhaSE *pilha, Nodo nodo){
    Nodo *pNodo = (Nodo *) malloc (sizeof (Nodo));
    pNodo->func = nodo.func;

    if(pilha->topo == NULL){
        pNodo->prox = NULL;
        return(FALTOU_MEMORIA);
    }
    else
    {
        pNodo->prox = pilha->topo;
    }
    
    pilha->topo = pNodo;

    return (SUCESSO);
}

// DESEMPILHA INCOMPLETO
int desempilha(PilhaSE *pilha){
    if( pNodo->prox = NULL){
        return(PILHA_VAZIA);
    }
    // USAR o free();
}

int consultaExistencia (Pilha *pilha, int codigo){
    int flag = 0;
    if( pNodo->prox = NULL){
        return(PILHA_VAZIA);
    }
    do{
        nodoTemp = nodoTemp->prox;
        if(funcionario->cod == codigo){
            flag = 1;
        }
        if(flag == 1){
            return(SUCESSO);
        }
        else{
            return(CODIGO_INEXISTENTE);
        }

    } while (nodoTemp->prox != NULL);
}