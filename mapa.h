struct mapa{
    int linhas;
    int colunas;
    char** matriz;
};
typedef struct mapa MAPA; // Dando um apelido para o struct

struct posicao
{
     int x,y;
 
};
typedef struct posicao POSICAO;


void liberaMapa(MAPA* m);
void leMapa(MAPA* m);
void alocaMapa(MAPA* m);
void imprimirMapa(MAPA* m);
 void encontraMapa(MAPA* m, POSICAO* p,char c);