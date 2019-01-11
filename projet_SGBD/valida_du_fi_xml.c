#include<stdio.h>
#include<stdlib.h>
#include<libxml/parser.h>
// #include "valida_du_fi_xml.h"
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