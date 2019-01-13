#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functionCommand.c"
#include "validationFichier.c"
#include "extractXml.c"

int main(int argc,char*arg[])
{
  //Declaration des inputs
  char const*fichierXml;
  // File* fichierJson;
   
    if(argc==7)
      {
        fichierXml=arg[4];
       //fichierJson=fopen(arg[4] , "r");
      }  

    if(argc==8)
     {
      fichierXml=arg[5];
      // fichierJson=fopen(arg[5] , "r"); 
     }
 
  if(verifiOp(argc,arg)!=0 && verifiPar(argc,arg)!=0 && verifi_sorti(argc,arg)!=0 )
   {
     
     if(strcmp(arg[2],"xml")==0)
        {validationXml(fichierXml);

     //if(strcmp(arg[2],"json")==0)
       // validationJson(fichierJson);
  
     // if(validationXml(argc,arg)==1)
        extractionXml(fichierXml);}
   } 
   else
      return 0;
       

  
}