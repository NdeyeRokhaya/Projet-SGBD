#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functionCommand.c"


int main(int argc,char*arg[])
{

   
         if(verifiOp(argc,arg)==0)
          exit(0);
         else 
         if(verifiPar(argc,arg)==0)
          exit(0);
         else 
           if(verifi_sorti(argc,arg)==0)
             exit(0);
     

     if(verifiOp(argc,arg)!=0 && verifiPar(argc,arg)!=0 && verifi_sorti(argc,arg)!=0 )
         {
          printf("La commande saisie est bonne\n");   
          return 1;
         } 
       
  }
  