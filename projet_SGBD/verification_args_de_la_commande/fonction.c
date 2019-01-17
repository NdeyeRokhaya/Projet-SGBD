#include <stdio.h>
#include <string.h>
#include <libxml/parser.h>

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

int verif_de_xml_json(char* argument[] ,int tail)

{
if (tail==7 )
{
	int tail_N_de_fi;

	tail_N_de_fi=strlen(argument[4]);
	if (((argument[4][tail_N_de_fi-4]=='.') && (argument[4][tail_N_de_fi-3]=='x') && (argument[4][tail_N_de_fi-2]=='m') 
		&& (argument[4][tail_N_de_fi-1]=='l')) ||  ((argument[4][tail_N_de_fi-5]=='.') 
		&& (argument[4][tail_N_de_fi-4]=='j') && (argument[4][tail_N_de_fi-3]=='s') && (argument[4][tail_N_de_fi-2]=='o')
		 && (argument[4][tail_N_de_fi-1]=='n')))
	
		return 0;
	
	else {

		printf("le fichier d'entree n'est pas au bon format\n");
		return 1;
	}
}
else{
	printf("le nombre d'argument est incorrecte \n");
	return 1;

}
}


int verif_de_i(char* argument[] ,int tail)
{
	if (tail==7 || tail==8)
	{
		if(strcmp(argument[1],"-i")==0) 
		{
			
			return 0;
		}
		else{
			printf("veuiller saisir l'option -i\n" );

			return 1;
		}
	}

	else
			printf("Le nombre d'argument saisi est incorrect\n");
	return 0;

}

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

int verifsvg(char* argument[] ,int tail)
{
if (tail==7 || tail==8){
		int tail_Fi_sor;
		tail_Fi_sor=strlen(argument[6]);
		if ((argument[6][tail_Fi_sor-4]=='.') && (argument[6][tail_Fi_sor-3]=='s') && (argument[6][tail_Fi_sor-2]=='v') && (argument[6][tail_Fi_sor-1]=='g'))

			return 0;
		else
		{
		printf("l'extension svg du fichier de sortie est .svg\n");
		return 1;
		}
}
else
	{
		printf("Le nombre d'argument saisi est incorrect\n");
		return 1;
	}				
}

int validation_fic_xml(char const *nom_fi_xml)
{
	xmlDocPtr doc;
	xmlNodePtr cur;

	doc=xmlParseFile (nom_fi_xml);
	if (doc==NULL)
	{
		fprintf(stderr, "erreur sur la validité du document\n" );
		return 1;
	}
	else{
		fprintf(stderr, "l'input est valide.\n" );
		return 0;
	}
}


int extractionxml(char* argument[],char const * FichierXml)
{
    xmlDoc         *document;
    xmlNode        *racine, *first_child, *node;
    //char           *FichierXml;

    
    
    FichierXml = argument[4];

    document = xmlReadFile(FichierXml,NULL, 0);
    racine = xmlDocGetRootElement(document);
    fprintf(stdout, "Racine: <%s> (%s)\n", racine->name, racine->content);
    first_child = racine->children;
    for (node = first_child; node; node = node->next) {
        fprintf(stdout, "\t  <%s> (%s)\n", node->name, node->content);
    }
    fprintf(stdout, "...\n");
    return 0;

}

