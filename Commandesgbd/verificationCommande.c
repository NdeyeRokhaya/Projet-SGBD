#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fonctionCommande.c"

int main(int argc,char*arg[])
{

   
    if( strcmp(arg[1],"XJ_Convertor")!=0)
    {
       printf("Erreur nom commande invalide : %s\n",arg[1]);
       printf("La commande est : XJ_Convertor.\n");
       
    }
     else
     { 
        if(argc<8 || argc>9)
         printf("La commande doit avoir au minimum 8 chaines.\n");
        else
        {   
         if(verifiOp(argc,arg)==0)
          exit(0);
         else 
         if(verifiPar(argc,arg)==0)
          exit(0);
         else 
           if(verifi_sorti(argc,arg)==0)
             exit(0);
        }       
     }                     
  

     if(verifiOp(argc,arg)!=0 && verifiPar(argc,arg)!=0 && verifi_sorti(argc,arg)!=0 )
         {
          printf("La commande saisie est bonne\n");   
          return 1;
         } 
       
  }
  