#include <stdio.h>
#include <stdlib.h>
#include "Declarações.h"

int calcular_media_massa(corpo *ptr, int num_corpos)
{
	double soma=0, media;
	for(int i=0; i < num_corpos; i++) 
	{
		soma += ptr[i].massa;
	}                                       
	media = soma / num_corpos;

	return media;
}

void mostrar_mapa(corpo *ptr, int num_corpos, int *centro_massa)
{
	int i=0, j=0;
	char suporte[NUM];    
	char mapa[X_MAPA][Y_MAPA];
	double mediaT;
	
	mediaT = calcular_media_massa(ptr, num_corpos);


	for(int linha=0;linha<X_MAPA;linha++) //inicializa o mapa com ' '
		for(int coluna=0;coluna<Y_MAPA;coluna++)
			mapa[linha][coluna] = ' ';
	
	while(i < num_corpos) // para que o laço continue enquanto n tenha chegado na qtd de corpos cadastrados
	{                
		
		for(int linha=0;linha<X_MAPA;linha++) 
		{
      		for(int coluna=0; coluna<Y_MAPA;coluna++)
       		{
    	   		if(ptr[i].x == linha && ptr[i].y == coluna) //se as coordenadas baterem...
			    {	
					if(mediaT < ptr[i].massa)
					{
						mapa[linha][coluna] = 'X';  // atribuir x para este endereço 
					}
					else
					{
						mapa[linha][coluna] = 'x';  // atribuir x para este endereço 
					}
			    }
				if(centro_massa[0] == linha && centro_massa[1] == coluna)// impressão de c_m
					mapa[linha][coluna] = '@';		
        	}        	
   		}  
		i++;                                     
	}

	printf("███████████████████████████████████████████████\n");
	for(int linha=0;linha<X_MAPA;linha++)  
	{
		printf("█ ");
		for(int coluna=0;coluna<Y_MAPA;coluna++)
		{
			printf("%c ", mapa[linha][coluna]);
			
		}
		printf("█");
		putchar('\n');		
	}
	printf("███████████████████████████████████████████████\n");	
}
