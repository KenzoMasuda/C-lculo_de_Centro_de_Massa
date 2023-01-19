#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Declarações.h"

int main()
{   
	int num_corpos=1, opcao=0, i=0, centro_massa[2], qtd_vezes=0, num_corpos_sup=0;
	corpo *ptr = (corpo *)malloc(sizeof(corpo) * num_corpos);
	
   if(ptr!=NULL)
	do
	{   
		
		printf("⠀SIMULADOR DE CENTRO DE MASSA - MENU DE OPÇÕES\n");
  		printf("████████████████████████████████████████████████\n");
  		printf("█                                              █\n");
  		printf("█ Digite 1 --- Para criar um corpo.            █\n");
  		printf("█ Digite 2 --- Para deletar um corpo.          █\n");
  		printf("█ Digite 3 --- Para modificar um corpo.        █\n");
  		printf("█ Digite 4 --- Para sair.                      █\n");
		printf("█                                              █\n");  
	    printf("█ *OBS: Qualquer outro valor é inválido...*    █\n");
  		printf("█                                              █\n");
  		printf("████████████████████████████████████████████████\n");
  		printf("Código: ");
  		scanf("%d", &opcao);
		
  		printf("\e[H\e[2J");//comando para limpar a tela.
    //  // system("clear");

		switch(opcao)
		{
			case 1:
			qtd_vezes = 0;
			ptr = (corpo *)realloc(ptr, sizeof(corpo)*num_corpos);

            fflush(stdin);
            printf("\nDigite o nome do corpo: "); scanf("%s", ptr[i].nome);
			fflush(stdin);
		    printf("Digite a massa do corpo: "); scanf("%f", &ptr[i].massa);
			fflush(stdin);
            printf("Digite a coordenada em x (0 <= x < 20): "); scanf("%d", &ptr[i].x);
			fflush(stdin);
			printf("Digite a coordenada em y (0 <= y < 22): "); scanf("%d", &ptr[i].y);
			fflush(stdin);

			printf("\e[H\e[2J");
			printf("\nCorpo adicionado com sucesso...");
            putchar('\n');
			putchar('\n'); 

			sleep(2);// o comando sleep, funciona pra dar um delay...
			printf("\e[H\e[2J");
                
			for(int i = 0; i<2; i++)
			{
				centro_massa[i] = calcular_xy_cm(ptr, num_corpos, qtd_vezes);
				qtd_vezes = 1;
			}

			printf("  Mapa do Sistema\n \n");
			mostrar_mapa(ptr, num_corpos, centro_massa);
			putchar('\n');

            i++; // incrementa para poder passar para o próximo endereço do ponteiro
	        num_corpos++;
			break;

			case 2: 
			if(num_corpos==1)
			{
				printf("Não há corpos a serem deletados...\n\n");
				sleep(2);
				printf("\e[H\e[2J");
				break;
			}
			qtd_vezes = 0;
			deletar_corpo(ptr, &num_corpos); 
            num_corpos_sup = num_corpos-1; //deixar intacto o num_corpos, e utilizar a quantidade de corpos existentes de fato nas funções
            
			if(num_corpos!=1) //Só calcula se houver 1 ou mais corpos
			{
				for(int i = 0; i<2; i++)
				{
					centro_massa[i] = calcular_xy_cm(ptr, num_corpos_sup, qtd_vezes);	
					qtd_vezes = 1;
				}
			}

			printf("  Mapa do Sistema\n");
			mostrar_mapa(ptr, num_corpos_sup, centro_massa);
			putchar('\n');
			i--;     

			ptr = (corpo *)realloc(ptr, sizeof(corpo) * num_corpos);
			break;

			case 3:
			if(num_corpos==1)
			{
				printf("Não há corpos a serem modificados...\n\n");
				sleep(2);
				printf("\e[H\e[2J");
				break;
			}
			qtd_vezes=0;
			modificar_corpo(ptr, num_corpos);

			for(int i = 0; i<2; i++)
			{
				centro_massa[i] = calcular_xy_cm(ptr, num_corpos, qtd_vezes);	
				qtd_vezes = 1;
			}

			printf("  Mapa do Sistema\n");
			mostrar_mapa(ptr, num_corpos-1, centro_massa);
			putchar('\n');
			break;

			case 4:
			puts("Encerrando...");
			break;
			default:
			puts("Opção inválida\n");
		}
	}while(opcao!=4);
	free(ptr);
	ptr=NULL;
	
return 0;
}

