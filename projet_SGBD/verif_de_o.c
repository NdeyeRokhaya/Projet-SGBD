/* verification de l'option -i*/
#include<stdio.h>
#include<string.h>
#include "fonction.h"
int verif_de_o(char* argument[] ,int tail)
{
	if (tail==7)
	{
		if(strcmp(argument[5],"-o")==0) 
			return 0;
		else
		{
			printf("veuiller saisir l'option -o\n" );

			return 1;
		}
	}
	else
	{

		if (tail==8)
		{
			if(strcmp(argument[6],"-o")==0) 
				return 0;
			else
			{
				printf("veuiller saisir l'option -o\n" );

				return 1;
			}
		}

		else
			printf("Le nombre d'argument saisi est incorrect\n");
	}
		
}