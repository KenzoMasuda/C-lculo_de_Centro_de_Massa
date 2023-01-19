#include <stdio.h>
#include <stdlib.h>
#include "Declarações.h"

int calcular_xy_cm(corpo *ptr, int num_corpos, int qtd_vezes)
{
	int cm_x, cm_y, soma_x=0, soma_y=0, div=0, centro=0;

	for(int i = 0; i < num_corpos; i++)  
	{
		soma_x += (ptr[i].massa * ptr[i].x);  
		soma_y += (ptr[i].massa * ptr[i].y);                                        
		div += ptr[i].massa;                
	}
	cm_x = soma_x/div;
	cm_y = soma_y/div;
	// na primeira vez, retorna coordenada x, já na segunda a coordenada y, devido à variável qtd_vezes, que dita que a captação do centro de massa deve ser realizado 2x, e qual coordenada será mandada em cada uma dessas vezes
	centro = cm_x;   
	if(qtd_vezes == 1)   
	{                    
		centro = cm_y;    
	}		
	return centro;
	
}