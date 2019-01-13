/* verification de l'option -h  ou -f*/
#include<stdio.h>
#include<string.h>
#include "fonction.h"
int verif_f_ou_h(char* argument[] ,int tail)

{
	if (tail==8)
	{
		if((strcmp(argument[4],"-h")==0) || (strcmp(argument[4],"-f")==0) )
			return 0;
		
		else
		{
			printf("saississez l'option -h oubien l'option -f\n" );

			return 1;
		}
	}
	else
	{
		if (tail==7)
		{
			if((strcmp(argument[3],"-h")==0) || (strcmp(argument[3],"-f")==0) )
				return 0;
			
			else
			{
				printf("saississez l'option -h oubien l'option -f\n" );

				return 1;
			}
		}
		else
		{
			printf("Le nombre d'argument saisi est incorrect\n");
			return 1;
		}
	}
}