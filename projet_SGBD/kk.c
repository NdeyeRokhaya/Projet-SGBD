	#include<stdio.h>
	#include<string.h>
	#include "fonction.h"
	#include "valida_du_fi_xml.c"

	#include<stdio.h>
	#include<stdlib.h>
	#include<libxml/parser.h>
	int validation_fic_xml(char const nom_fi_xml)
	{
		xmlDocptr doc;
		xmlNodeptr cur;

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
	
	
	int main(int argc, char const *argv[])
	{
	if (verif_de_xml_json(argc,argv)==0 && verif(argc,argv)==0 && verifsvg(argc,argv)==0 && verif_f_ou_h(argc,argv)==0)
		printf("nous pouvons passer au traitement" );
		validation_fic_xml(fic.xml);	
	} 	

