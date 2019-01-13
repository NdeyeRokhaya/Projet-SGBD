#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "cJSON.c"
//#include "Extraction.h"

char* getStrJSON (FILE * fichierJson){
	char *data;
	data = malloc(sizeof(char)*2000);
	char ligne[2000];
	while(getc(fichierJson)!=EOF){
		fscanf(fichierJson,"%s",ligne);
		//strcat(data,"\n");
		strcat(data,ligne);
	}
	//printf("%s\n", data);
	return data;
}

cJSON* ExtractionJSON (FILE * fichierJson)
{
	char *data;
	data = malloc(sizeof(char)*2000);
	data = getStrJSON(fichierJson);
	cJSON *json = cJSON_Parse(data);
	return json;
}

int main(int argc, char const *argv[])
{	
	FILE * f = fopen("fichier.json","r");
	if(f!=NULL){
		cJSON *json = ExtractionJSON(f);
		//exploiterJSON(json);
	}
	else{
		printf("Erreur d'ouverture du fichier\n");
	}
	return 0;
}