#include <stdio.h>
#include <stdlib.h>
#include "come.h"
#include "mapa.h"

MAPA m;
POSICAO player;

void fantasma(){
    MAPA copia;
    copiaMapa(&copia,&m);
    for(int i =0; i < copia.linhas; i++){
        for(int j =0; j <copia.colunas; j++){
            if(copia.matriz[i][j] == FANTASMA){
                if(ehValido(&m,i,j+1) && ehVazia(&m,i,j+1)){
                    andanomapa(&m,i,j,i,j+1);
                    
                }
            }
        }
    }
    liberaMapa(&copia);
}

int acabou(){
    return 0;
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
    if(!ehValido(&m,proximox,proximoy)){
        return;
    }
    if(!ehVazia(&m,proximox,proximoy)){
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