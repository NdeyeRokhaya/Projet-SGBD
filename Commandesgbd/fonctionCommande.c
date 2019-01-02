#include<stdio.h> 
#include<string.h>

//Vérification des paramètres //
int verifiOp(int taille,char*arg[])
 {
	if(taille==8)
	{
		if (strcmp(arg[2],"-i")!=0)
		   {
		   	printf("Vous avez oublie l'option -i\n");
	        return 0;
	       } 
		   
		else if (strcmp(arg[4],"-f")!=0 && strcmp(arg[4],"-h")!=0)
			{
				printf("les options doivent etre -h ou -f\n");
	            return 0;
	        }   
 
		else if(strcmp(arg[6],"-o")!=0) 
		   {
		   	printf("L'option de sortie doit etre -o\n");
		    return 0; 
		   }
		else 
		    return 1;   
	}       
	else if(taille==9) 
	 { 
		if(strcmp(arg[2],"-i")!=0) 
		  { 
		  	printf("Vous avez oublie l'option -i\n");
	        return 0;
	      }
		if(strcmp(arg[4],"-t")!=0)
			{
			 printf("Vous avez oublié l'option -t\n");
			 return 0;
			}    

		else if(strcmp(arg[5],"-h")!=0 && strcmp(arg[5],"-f")!=0)
			{
				printf("les options doivent etre -h ou -f\n");
		        return 0;
            }		   
		else if(strcmp(arg[7],"-o")!=0)
			{
			 printf("L'option de sortie doit etre -o\n");
		     return 0;  
            }
        else
        	return 1;
     }
	else
	   {
	 	 printf("Les options ne sont pas complets\n");
	 	 return 0;
	   }  
 }    
//  verification des valeurs des paramètres et des extensions//
int verifiPar(int taille,char*arg[])
{
  int taillefichier1=strlen(arg[5]);
  int taillefichier2=strlen(arg[6]);	 
  if(taille==8)
   {
	 if(strcmp(arg[3],"xml")!=0 && strcmp(arg[3],"json")!=0)
		 {
		  printf(" Aprés l'option -i ,nous devons avoir xml ou json\n");
	      return 0;
	     } 

	 else if(strcmp(arg[3],"xml")==0 && arg[5][taillefichier1-4] =='.')
	  {
	  		if(arg[5][taillefichier1-3] != 'x' || arg[5][taillefichier1-2]!='m' || arg[5][taillefichier1-1] != 'l')
	  		{
	  			printf("Le fichier d'entrée doit etre au format xml \n");
	  			return 0;
	  		}
	  }
	  else if(strcmp(arg[3],"xml")==0 && arg[5][taillefichier1-4] !='.') 
  		{
  	      printf("le format du fichier d'entrée doit etre xml \n");
  	       return 0;
  	    }  

	 else if(strcmp(arg[3],"json")==0 && arg[5][taillefichier1-5] =='.')
	 
	 	{ 
	 	  if(arg[5][taillefichier1-4] !='j' || arg[5][taillefichier1-3] !='s' || arg[5][taillefichier1-2] !='o' || arg[5][taillefichier1-1] !='n') 
	 		 	{
	 		 	 printf("Le fichier d'entrée doit etre au format json\n");
	  			 return 0;
	  			} 
	 	}	 
	 else if (strcmp(arg[3],"json")==0 && arg[5][taillefichier1-5] !='.') 
	   {
	 	 printf("le format du fichier d'entrée doit etre json\n");
	 	 return 0;
	   }
     else 
      	return 1;
    }
   
   else if(taille==9)
    
    {
    	if(strcmp(arg[3],"xml")!=0 && strcmp(arg[3],"json")!=0)
		 {
		  printf(" Aprés l'option -i ,nous devons avoir xml ou json\n");
	      return 0;
	     } 

	 else if(strcmp(arg[3],"xml")==0 && arg[6][taillefichier2-4] =='.')
	  {
	  		if(arg[6][taillefichier2-3] != 'x' || arg[6][taillefichier2-2]!='m' || arg[6][taillefichier2-1] != 'l')
	  		{
	  			printf("le fichier d'entrée doit etre xml\n");
	  			return 0;
	  		}
	  }
	  else if(strcmp(arg[3],"xml")==0 && arg[6][taillefichier2-4] !='.') 
  		{
  	      printf("le format du fichier d'entrée doit etre xml \n");
  	       return 0;
  	    }  

	 else if(strcmp(arg[3],"json")==0 && arg[6][taillefichier2-5] =='.')
	 
	 	{ 
	 	  if(arg[6][taillefichier2-4] !='j' || arg[6][taillefichier2-3] !='s' || arg[6][taillefichier2-2] !='o' || arg[6][taillefichier2-1] !='n') 
	 		 	{
	 		 	 printf("le fichier d'entrée doit etre json\n");
	  			 return 0;
	  			} 
	 	}	 
	 else if (strcmp(arg[3],"json")==0 && arg[6][taillefichier2-5] !='.') 
	   {
	 	 printf("le format du fichier d'entrée doit etre json\n");
	 	 return 0;
	   }
     else 
      	return 1;
    }
      	
   else
	 {
	 	printf("Les valeurs des paramètres ne sont pas completes\n");
	 	return 0;
	 }
 }

// Vérification de l'extension de sortie svg//

  int verifi_sorti(int taille,char*arg[]){
  /* La fonction strchr() renvoie la chaine qui se situe apres le caractere(ce dernier inclus.) */
   if(taille==8)
   {
     if(strchr(arg[7],'.')!=0)
     {
        if(strcmp(strchr(arg[7],'.'),".svg")!=0)
        {
          printf("Erreur de syntaxe: le format de la sortie doit etre en SVG.\n");
          return 0;
        }
        else
          return 1;  
     }
     else//Cest le cas ou il n'y a pas de '.' dans la chaine.
         {
         	printf("Le point est obligatoire pour définir l'extension de sortie svg\n");
         	 return 0;
         } 
  }
  else if(taille==9)
  {
     if(strchr(arg[8],'.')!=0)
     {
        if(strcmp(strchr(arg[8],'.'),".svg")!=0)
        {
          printf("Erreur de syntaxe: le format de la sortie doit etre en SVG.\n");
          return 0;
        }
        else
          return 1;  
     }
     else      //Cest le cas ou il n'y a pas de '.' dans la chaine.
         return 0;  
   }
   else
      return 0;   
 }
  
 