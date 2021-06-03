#include <stdio.h>
#include <stdlib.h>
#include "come.h"
#include "mapa.h"
#include <time.h>


MAPA m;
POSICAO player;

int praOndeOFantasmaVai(int xatual, int yatual,int* xdestino,int* ydestino){
    int opcoes[4][2]={{xatual,yatual +1},{xatual+1,yatual},{xatual,yatual-1},{xatual -1, yatual}};
    srand(time(0));
    for(int i=0; i <10;i++){
        int posicao = rand()%4;
        if(podeAndar(&m,FANTASMA, opcoes[posicao][0], opcoes[posicao][1])){
            *xdestino = opcoes[posicao][0];
            *ydestino =opcoes[posicao][1];
            return 1;
        }
    }
    return 0;
}
    

void fantasma(){
    MAPA copia;
    copiaMapa(&copia,&m);
    for(int i =0; i < copia.linhas; i++){
        for(int j =0; j <copia.colunas; j++){
            if(copia.matriz[i][j] == FANTASMA){
                int xdestino;
                int ydestino;
                int encontrou = praOndeOFantasmaVai(i,j,&xdestino,&ydestino);
                if(encontrou){
                    andanomapa(&m,i,j,xdestino,ydestino);
                }
            }
        }
    }
    liberaMapa(&copia);
}

int acabou(){
    POSICAO pos;
    int encontrouHeroi =encontraMapa(&m,&pos,PLAYER);
    return !encontrouHeroi;
}
int ehDirecao(char direcao){
    return direcao == 'a' || direcao == 'w' || direcao == 's' || direcao == 'd';
}
void move(char direcao) {
  
      if(!ehDirecao(direcao)) {
          return;
        } 

    int proximox = player.x;
    int proximoy = player.y;
    switch(direcao) {
        case ESQUERDA:
            proximoy--;
            break;
        case CIMA:
            proximox--;
            break;
        case BAIXO:
            proximox++;
            break;
        case DIREITA:
            proximoy++;
            break;
    }
    if(!podeAndar(&m,PLAYER,proximox,proximoy)){
        return;
    }
    andanomapa(&m,player.x,player.y,proximox,proximoy);
    player.x = proximox;
    player.y = proximoy;
    

}
int main(){
    
    leMapa(&m);
    encontraMapa(&m,&player,PLAYER);
    do{
       imprimirMapa(&m);
        char comando;
        scanf(" %c",&comando);
        move(comando);
        fantasma();
        
    }while(!acabou());
    liberaMapa(&m);
}