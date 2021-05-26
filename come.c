#include <stdio.h>
#include <stdlib.h>
#include "come.h"

int linhas;
int colunas;
char** mapa;

void alocaMapa(){
    mapa = malloc(sizeof(char*)*linhas);
    for(int i =0;i<linhas;i++){
        mapa[i] = malloc(sizeof(char)*(colunas+1)); 
    }
}
void liberaMapa(){
   

    for(int i =0;i<linhas;i++){
        free(mapa[i]);
    }
    free(mapa);
}
void leMapa(){
    FILE * f;
    f = fopen("mapa.txt","r");
    if (f==0){
        printf("Erro ao buscar o dado tente novamente ");
        exit(1);
    }

    fscanf(f,"%d %d",&linhas,&colunas);
    alocaMapa();
    for(int i =0; i < 5;i++ ){
        fscanf(f,"%s",mapa[i]);
    }
   
    fclose(f);

}

int main(){
    
    leMapa();
     for(int i =0; i < 5;i++ ){
        printf("%s \n",mapa[i]);
    }
    liberaMapa();
}