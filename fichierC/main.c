#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functionCommand.c"
#include "validationFichier.c"
#include "extractXml.c"
#include "fonctions_JSON.c"

int main(int argc,char*arg[])
{
  //Declaration des inputs
  char const*fichierXml;
  FILE* fichierJson;
   

    if(argc==7)
      {
        fichierXml=arg[4];
       fichierJson= fopen(arg[4] , "r");
      }  

    if(argc==8)
     {
      fichierXml=arg[5];
      fichierJson= fopen(arg[5] , "r"); 
     }
 
  if(verifiOp(argc,arg)!=0 && verifiPar(argc,arg)!=0 && verifi_sorti(argc,arg)!=0 )
   {
        if(strcmp(arg[2],"xml")==0)
        
           {
             if(validationXml(fichierXml)==1)
              extractionXml(fichierXml);
           }   
           else if(strcmp(arg[2],"json")==0)
        
              if(validationJson(fichierJson)==0) 
               {
                     fichierJson= fopen(arg[4] , "r");
                //Création du pointeur cJSON et récupération des entités et attributs
                   cJSON *ptrJson = extractionJson(fichierJson);
                 if (ptrJson!=NULL)
                  {
                    //Création du fichier svg
                      svg* fichierSVG;
                     fichierSVG = svg_create(1012, 1512);

                      if(fichierSVG == NULL) 
                        puts("LE FICHIER SVG N'A PAS ÉTÉ CRÉÉ.\n");

                      else 
                       svg_rectangle(fichierSVG, 1012, 1512, 0, 0, "white", "white", 0, 0, 0);

                          int i=0;
                         recuperationEntite(ptrJson->child, fichierSVG, i);
                          printf("FIN\n");

                   //Fin et enregistrement du fichier généré
                          svg_finalize(fichierSVG);
                          svg_save(fichierSVG, "SchemaSVG.svg");
                          svg_free(fichierSVG);
                  }
                 else 
                printf("Le pointeur cJSON est null\n");
              }

            fclose(fichierJson);
       }
  //else printf("ERREUR D'OUVERTURE DU FICHIER\n\n");
  //return 0;
  
        
         
            
 else
      return 0;
       

     

   } 
  
