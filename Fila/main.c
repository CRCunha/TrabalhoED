#include<stdio.h>
#include<stdlib.h>
#include "Fila.h"
#include "Fila.c"

int main(){
	int escolha; 
	int n; 
	int resposta;
	Voo voo;
	FilaSE fila;

	criaFila(&fila);

	do{
		printf("0 - [FIM]");
		printf("\n1 - [Inserir voo]");
		printf("\n2 - [Retirar voo]");
		printf("\n3 - [Consultar a exitencia de um voo]");
		printf("\n4 - [Quantidade de voos]");
		printf("\n5 - [Exibe todos os voos]");
		printf("\n\n: ");
		scanf("%d", &escolha);
		fflush(stdin);
		switch (escolha){
			case 1:
				printf("Num: ");
				scanf("%d", &voo.num);
				fflush(stdin);
				printf("CIA: ");
				scanf("%s", &voo.cia);
				fflush(stdin);
				if(insere(&fila, voo)==FALTOU_MEMORIA){
					printf("ERRO: Faltou memoria\n\n");
				}else{
					printf("SUCESSO\n\n");
				}
				break;
			case 2:
				if(retira(&fila, &voo)==FILA_VAZIA){
					printf("ERRO: Fila vazia\n\n");
				}else{
					printf("\nDado retirado\nNum: %d\tCIA: %s\n\n", voo.num, voo.cia);
					printf("SUCESSO\n\n");
				}
				break;
			case 3:
				printf("Digite o numero do voo: ");
				scanf("%d", &n);
				resposta = consultaExistencia(fila, n);
				if(resposta == FILA_VAZIA){
					printf("ERRO: Fila vazia\n\n");
				}else{
					if(resposta == SUCESSO){
						printf("\nEsse voo existe\n\n");
						printf("SUCESSO\n\n");
					}else{
						printf("\nERRO: Codigo inexistente\n\n");
					}
				}
				break;
			case 4:
				resposta = quantidadeDeVoos(fila);
				if(resposta == FILA_VAZIA){
					printf("ERRO: Fila vazia\n\n");
				}else{
					printf("\nNumero de voos: %d\nSUCESSO\n\n", resposta);
				}
				break;
			case 5:
				exibeFila(fila);
				break;
			case 0:
				break;
		}
	}while(escolha != 0);

	return 0;
}
