#include "mapa.h"
#include <stdio.h>
#include <stdlib.h>

void liberaMapa(MAPA* m){
    for(int i =0;i<m->linhas;i++){ // (*m). é a mesma coisa que m->  
        free((*m).matriz[i]);
    }
    free(m->matriz);
}

void alocaMapa(MAPA* m){
    m->matriz = malloc(sizeof(char*)*m->linhas);
    for(int i =0;i<m->linhas;i++){
      m->matriz[i] = malloc(sizeof(char)*(m->colunas+1)); 
    }
}

void leMapa(MAPA* m){
    FILE * f;
    f = fopen("mapa.txt","r");
    if (f==0){
        printf("Erro ao buscar o dado tente novamente ");
        exit(1);
    }

    fscanf(f,"%d %d",&m->linhas,&m->colunas);
    alocaMapa(m);
    for(int i =0; i < 5;i++ ){
        fscanf(f,"%s",m->matriz[i]);
    }
   
    fclose(f);

}
void imprimirMapa(MAPA* m){
    for(int i =0; i < 5;i++ ){
        printf("%s \n",m->matriz[i]);
    }
}

void encontraMapa(MAPA* m, POSICAO* p,char c){
    for(int i = 0; i < m->linhas; i++) {
        for(int j = 0; j < m->colunas; j++) {
            if(m->matriz[i][j] == c) {
                p->x = i;
                p->y = j;
                break;
            }
        }
    } 
}