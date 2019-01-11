	#include <stdio.h>
	#include <string.h>
	#include "fonction.h"
	#include "extra.c"
	#include "verif.c"
	#include "verif_de_ex_xml_json.c"
	#include "verif_de_o.c"
	#include "verif_de_i.c"
	#include "verif_f_ou_h.c"
	#include "verifsvg.c"
	#include "valida_du_fi_xml.c"

	int main(int argc, char *argv[])
	{
		char const*fic; 
		if (argc==7)
			fic=argv[4];
		if (argc==8)
			fic=argv[5];
		if (verif_de_o(argv,argc)==0 && verif_de_i(argv,argc)==0 && verif_de_xml_json(argv,argc)==0 && verif(argv,argc)==0 && verifsvg(argv,argc)==0 && verif_f_ou_h(argv,argc)==0)
			validation_fic_xml(fic);
		if (validation_fic_xml(fic)==0)	{
			if (argc < 2) {
    	     fprintf(stderr, " veuiller renseigner le fichier.xml a extraire\n");
    	     return 1;
    	 }
			extraction(argv[1]);
		}
	} 	
