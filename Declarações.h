#include <stdio.h>
#include <stdlib.h>

#define NUM 20
#define X_MAPA 20
#define Y_MAPA 22

typedef struct _corpo{
	int x,y;
	float massa;
	char nome[NUM]; 
} corpo;

int calcular_xy_cm(corpo *ptr, int num_corpos, int qtd_vezes);

void deletar_corpo(corpo *ptr, int *num_corpos);

void modificar_corpo(corpo *ptr, int num_corpos);

int calcular_media_massa(corpo *ptr, int num_corpos);

void mostrar_mapa(corpo *ptr, int num_corpos, int *centro_massa);
