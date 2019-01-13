/* verification s'il a introduit xml ou json aprés le -i*/
#include<stdio.h>
#include<string.h>
#include "fonction.h"
int verif(char* argument[] ,int tail)
{
	if (tail==7 || tail==8)
	{
		if((strcmp(argument[2],"xml")==0) || (strcmp(argument[2],"json")==0) )
		{
			return 0;
		}
		else
		{
			printf("aprés l'option -i on doit avoir xml ou json\n" );

			return 1;

		}
	}
	else
	{
		printf("Le nombre d'argument saisi est incorrect\n");
		return 1;
	}
}