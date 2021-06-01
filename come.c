#include <stdio.h>
#include <stdlib.h>
#include "come.h"
#include "mapa.h"

MAPA m;
POSICAO palyer;


int acabou(){
    return 0;
}
void move(char direcao) {
  
    
    m.matriz[palyer.x][palyer.y] ='.';
    switch(direcao) {
        case 'a':
            m.matriz[palyer.x][palyer.y-1] = '@';
            palyer.y--;
            break;
        case 'w':
            m.matriz[palyer.x-1][palyer.y] = '@';
            palyer.x--;
            break;
        case 's':
            m.matriz[palyer.x+1][palyer.y] = '@';
            palyer.x++;
            break;
        case 'd':
            m.matriz[palyer.x][palyer.y+1] = '@';
            palyer.y++;
            break;
    }

}
int main(){
    
    leMapa(&m);
    encontraMapa(&m,&palyer,'@');
    do{
       imprimirMapa(&m);
        char comando;
        scanf(" %c",&comando);
        move(comando);
        
    }while(!acabou());
    liberaMapa(&m);
}