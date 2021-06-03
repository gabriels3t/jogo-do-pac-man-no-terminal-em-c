#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'

int acabou();
void move(char direcao);
int ehDirecao(char direcao);
void fantasma();
int praOndeOFantasmaVai(int xatual, int yatual,int * xdestino,int* ydestino);