#include<stdio.h>
#include<stdlib.h>
#include<libxml/parser.h>//Librairie xml
#include"JSON_checker.h"
#include"validationFichier.h"
 //Validation du fichier XML
int validationXml (char const *filenameXml)
{
	xmlDocPtr docXml;
	docXml= xmlParseFile(filenameXml);
	if (docXml== NULL)
	{
		fprintf(stderr, "LE DOCUMENT XML EST INVALIDE\n");
		return EXIT_FAILURE;
	}

	xmlFreeDoc(docXml);

	return EXIT_SUCCESS;
}
 //Validation du fichier JSON
int validationJson (FILE * filenameJson)
{
	int caract;
	JSON_checker jc = new_JSON_checker(30);
 	if(filenameJson!=NULL)
 	{
 		while (1)
	 	{
	 		caract= fgetc(filenameJson); // Permet de parcourir le fichier caractere par caractere
	 		if(feof(filenameJson)) break; // verifier la fin fichier

        	if (caract<= 0) break;
       		if (!JSON_checker_char(jc, caract)) 
       		{
	            fprintf(stderr, "JSON_checker_char: ERREUR SYNTAXIQUE \n");
	            exit(1);
        	}
    	}

    	if (!JSON_checker_done(jc)) 
    	{
	        fprintf(stderr, "JSON_checker_end: ERREUR SYNTAXIQUE \n");
	       exit(1);
	 	}

	 	fclose(filenameJson);
 	}

 	else printf("FICHIER NON OUVERT\n");

}