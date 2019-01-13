#include<stdio.h>
#include<math.h>
#include<time.h>
#include "cJSON.h"
#include"Extraction.h"
#include <unistd.h>
#include"svg.h"

//--------------------------------------------------------
// FUNCTION PROTOTYPES
//--------------------------------------------------------
void drawrectangles(void);
void drawallshapes(void);
void iwanttobelieve(void);
void mondrian(void);


void handleAttribute(cJSON *child,svg* psvg,int i){
    //printf("Entrée dans handle: i=%d\n", i);
    if(!(cJSON_IsArray(child) || cJSON_IsObject(child)) && child!=NULL){
        if(i%2==1){
            printf("%d--> %s\n", i,child->string);
            createAttribute(psvg, child->string, 256, 300, 58, 58 + 550*((i-1)/2));
            
        }
        else{
            printf("%d--> %s\n", i,child->string);
            createAttribute(psvg, child->string, 256, 300, 700, 58 + 550*((i-1)/2));

        }
    }

    while(child->next!=NULL)
    {
        int k=1;
        child = child->next;
        printf("%s\n", child->string );
        if(!(cJSON_IsArray(child) || cJSON_IsObject(child))){
            if(i%2==1){
                createAttribute(psvg, child->string, 256, 300, 58, k*40 +58 +  550*((i-1)/2) );
                k++;
            }
            else{
                createAttribute(psvg, child->string, 256, 300, 700, k*40 + 58 + 550*((i-1)/2));
                k++;
            }
        }
    }
}


void handleEntity(cJSON *child,svg* psvg,int i){
    
    //printf("Entrée dans handle: i=%d\n", i);
    if(cJSON_IsArray(child) || cJSON_IsObject(child)){
        printf("if\n");
        if(i%2==1){
            createEntite(psvg, child->string, 256, 300, 58, 58 + 550*((i-1)/2));
            i++;
        }
        else{
            createEntite(psvg, child->string, 256, 300, 700, 58 + 550*((i-1)/2));
            i++;
        }
    }
    printf("before while\n");
    while(child->next!=NULL)
    {
        printf("WHILE\n");
        child = child->next;
        if((cJSON_IsArray(child) || cJSON_IsObject(child)) && child!=NULL)
        {
            if(i%2==1)
            {
                printf("num%d--> %s\n", i,child->string);
                createEntite(psvg, child->string, 256, 300, 58, 58 + 550*((i-1)/2));
            }
            else
            {
                printf("num2%d--> %s\n", i,child->string);
                createEntite(psvg, child->string, 256, 300, 700, 58 + 550*((i-1)/2));
            }     
            i++;
            
            if(cJSON_IsObject(child))
            {  
                printf("cJSON_IsObject\n");
                //printf("%d--> %s\n", i,child->string);
                handleEntity(child->child,psvg,i);
                sleep(1);
                handleAttribute(child->child,psvg,i-1);

            }
            /*if(cJSON_IsArray(child))
            {  
                printf("cJSON_IsArray\n");
                handleEntity(child->child,psvg,i);
                child=cJSON_GetArrayItem(child, 0);
                sleep(1);
                handleAttribute(child->child,psvg,i-1);

            }*/
        }
    }
}

void drawrectanglesJSON(cJSON *json, svg* psvg)
{
    //svg* psvg;
    //psvg = svg_create(1012, 1512);

    if(psvg == NULL)
    {
        puts("psvg is NULL");
    }
    else
    {
        svg_rectangle(psvg, 1012, 1512, 0, 0, "white", "white", 0, 0, 0);

        int i = 1;
        
        printf("%d\n", i);
        createEntite(psvg, "Fichier", 256, 300, 58, 58 + 550*(i-1)/2);
        i++;
        cJSON *child = json->child;
        printf("%s\n", json->child->string);
        handleEntity(child,psvg,i);

        sleep(1);

        handleAttribute(child,psvg,i-1);

        /*createEntite(psvg, "Etudiant", NULL, 4, 256, 300, 58, 58);
        createEntite(psvg, "Professeur", professeurAtt, 3, 256, 300, 58, 600);
        createEntite(psvg, "Departement", departementAtt, 2, 256, 300, 700, 58);*/
        /*sleep(2);
        svg_finalize(psvg);
        svg_save(psvg, "rectangles.svg");
        svg_free(psvg);*/
    }
} 



//--------------------------------------------------------
// FUNCTION main
//--------------------------------------------------------
int main()
{
    svg* psvg;
    psvg = svg_create(1012, 1512);
    printf("sfdd\n");
    puts("Code in C - SVG\n---------------\n");
    FILE * f = fopen("fichier.json","r");
    if(f!=NULL){
        cJSON *json = ExtractionJSON(f);
        drawrectanglesJSON(json, psvg);
        
        svg_finalize(psvg);
        svg_save(psvg, "rectangles.svg");
        svg_free(psvg);

    }
    else{
        printf("Erreur d'ouverture du fichier\n");
    }

    //drawallshapes();

    //iwanttobelieve();

    //mondrian();

    return EXIT_SUCCESS;
}

// --------------------------------------------------------
// FUNCTION drawrectangles
// --------------------------------------------------------
/*void drawrectangles(void)
{
    svg* psvg;
    psvg = svg_create(1012, 1512);

    if(psvg == NULL)
    {
        puts("psvg is NULL");
    }
    else
    {

        svg_rectangle(psvg, 1012, 1512, 0, 0, "white", "white", 0, 0, 0);
        createEntite(psvg, "Etudiant", NULL, 4, 256, 300, 58, 58);
        createEntite(psvg, "Professeur", NULL, 3, 256, 300, 58, 600);
        createEntite(psvg, "Departement", NULL, 2, 256, 300, 700, 58);
        svg_finalize(psvg);
        svg_save(psvg, "rectangles.svg");
        svg_free(psvg);
    }
} */