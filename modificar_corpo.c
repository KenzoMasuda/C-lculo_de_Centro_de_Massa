#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Declarações.h"

void modificar_corpo(corpo *ptr, int num_corpos)
{
	char nome_corpo[NUM];
	int i_i = 0; // indice do corpo escolhido
	int op = 0;  // opção de modificação

	puts("Lista de corpos cadastrados:\n");
	for(int i=0; i<num_corpos-1;i++)
		printf("%dº - %s (%d, %d)\n", i+1, ptr[i].nome, ptr[i].x, ptr[i].y);
    printf("\n");

	printf("Digite o nome do corpo que deseja alterar:");
    scanf("%s", nome_corpo);
	
	for(int i = 0; i < num_corpos-1; i++) //localização do indice do corpo 
	{ 
		if(strcmp(ptr[i].nome, nome_corpo) == 0) 
		{   
			i_i = i;		
		}
	}
			
	printf(" 	  O que deseja alterar do corpo %s?\n", nome_corpo);
	printf("████████████████████████████████████████████████\n");			
	printf("█ Digite 1 --- Para modificar o nome           █\n");
  	printf("█ Digite 2 --- Para modificar a massa          █\n");
  	printf("█ Digite 3 --- Para modificar a coordenada x   █\n");
  	printf("█ Digite 4 --- Para modificar a coordenada y   █\n");
	printf("█ Digite 5 --- Para retornar ao menu           █\n");
	printf("████████████████████████████████████████████████\n");
	scanf("%d", &op);

	switch(op)
	{
		case 1:
		printf("digite o novo nome:");
		scanf("%s", ptr[i_i].nome);			
		break;

		case 2:
		printf("digite a nova massa:");
		scanf("%f", &ptr[i_i].massa);
		break;

		case 3:
		printf("digite o novo valor para X:");
		scanf("%d", &ptr[i_i].x);
		break;

		case 4:
		printf("digite o novo valor para Y:");
		scanf("%d", &ptr[i_i].y);

		case 5:
		break;

		default:
		printf("Opção inválida\n");
   }
}