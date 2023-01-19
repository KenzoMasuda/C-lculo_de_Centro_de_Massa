#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Declarações.h"

void deletar_corpo(corpo *ptr, int *num_corpos)
{   
	char corpo_deletado[NUM];
	int i_i=0; //indice de interesse
                    
	puts("Lista de corpos cadastrados:\n\n");
	for(int i=0; i<*num_corpos-1;i++)
		printf("%dº - %s (%d, %d)\n", i+1, ptr[i].nome, ptr[i].x, ptr[i].y);
	printf("\n");
	
	puts("Digite o nome do corpo a ser deletado: ");
	scanf("%s", corpo_deletado);
		
	for(int i=0;i<*num_corpos-1;i++) //localização do indice do corpo deletado
	{ 
		if(strcmp(ptr[i].nome,corpo_deletado) == 0) // talvez mudar para 1
		{   
			i_i = i;
		}
	}
    
	for(int i = i_i; i < *num_corpos-1; i++) //delete do corpo
	{
		strcpy(ptr[i].nome, ptr[i+1].nome);  
		ptr[i].massa = ptr[i+1].massa;    
		ptr[i].x = ptr[i+1].x;                     
		ptr[i].y = ptr[i+1].y;
		                   
	} 	
	*num_corpos = *num_corpos - 1;
}