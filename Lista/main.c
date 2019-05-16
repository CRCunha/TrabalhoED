#include<stdio.h>
#include<stdlib.h>
#include "ListaSE.h"
#include "ListaSE.c"

int main(){
	int escolha;
	int n;
	int resposta;
	ListaSE lista;
	Contato c;
	criaLista(&lista);

	do{
		printf("0 - [Fim]");
		printf("\n1 - [Criar Lista]");
		printf("\n2 - [Incluir Contato Anter]");
		printf("\n3 - [Incluir Contato Depois]");
		printf("\n4 - [Consultar Contato]");
		printf("\n5 - [Excluir Contato]");
		printf("\n6 - [Exibir Lista]\n\n");
		printf(":");
		scanf("%d", &escolha);
		fflush(stdin);
		switch (escolha){
			case 1:
				system("cls");
				criaLista(&lista);
				break;
			case 2:
				system("cls");
				if(estaVazia(lista)!=LISTA_VAZIA){
					printf("Numero do contato EXISTENTE: ");
					scanf("%d", &n);
					fflush(stdin);
				}else{
					n = 1;
				}
				printf("Nome do NOVO contato: ");
				scanf("%s", &c.nome);
				fflush(stdin);
				printf("Numero: ");
				scanf("%d", &c.num);
				fflush(stdin);
				resposta = incluiAntes(&lista, n, c);
				if(resposta == FALTOU_MEMORIA){
					printf("ERRO: Faltou memoria\n\n");
				}else{
					if(resposta == CODIGO_INEXISTENTE){
						printf("ERRO: Codigo nao encontrado\n\n");
					}else{
						printf("SUCESSO\n\n");
					}
				}
				break;
			case 3:
				system("cls");
				if(estaVazia(lista)!=LISTA_VAZIA){
					printf("Numero do contato EXISTENTE: ");
					scanf("%d", &n);
					fflush(stdin);
				}else{
					n = 1;
				}
				printf("Nome do NOVO contato: ");
				scanf("%s", &c.nome);
				fflush(stdin);
				printf("Numero: ");
				scanf("%d", &c.num);
				fflush(stdin);
				resposta = incluiDepois(&lista, n, c);
				if(resposta == FALTOU_MEMORIA){
					printf("ERRO: Faltou memoria\n\n");
				}else{
					if(resposta == CODIGO_INEXISTENTE){
						printf("ERRO: Codigo nao encontrado\n\n");
					}else{
						printf("SUCESSO\n\n");
					}
				}
				break;
			case 4:
				system("cls");
				printf("Digite o numero do contato: ");
				scanf("%d", &n);
				fflush(stdin);
				resposta = consultaContato(lista, n, &c);
				if(resposta == CODIGO_INEXISTENTE){
					printf("ERRO: Codigo nao encontrado\n\n");
				}else{
					if(resposta == LISTA_VAZIA){
						printf("ERRO: Lista vazia\n\n");
					}else{
						printf("\n[Nome: %s ] - [Tel: %d]\n", c.nome, c.num);
						printf("SUCESSO\n\n");
					}
				}
				break;
			case 5:
				system("cls");
				printf("Digite o numero do contato: ");
				scanf("%d", &n);
				fflush(stdin);
				resposta = excluiContato(&lista, n, &c);
				if(resposta==LISTA_VAZIA){
					printf("ERRO: Lista Vazia\n\n");
				}else{
					if(resposta == CODIGO_INEXISTENTE){
						printf("ERRO: Codigo nao encontrado\n\n");
					}else{
						printf("\nNome: %s\tTel: %d\n", c.nome, c.num);
						printf("SUCESSO\n\n");
					}
				}
				break;
			case 6:
				system("cls");
				exibeLista(lista);
				break;
			case 0:
				return(0);
				break;
		
		}
	}while(escolha != 0);

	return 0;
}
