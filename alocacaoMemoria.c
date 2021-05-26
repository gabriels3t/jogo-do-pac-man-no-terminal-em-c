#include <stdio.h>
#include <stdlib.h>
int main(){
    //////////////// alocando memoria dinamicamente
    /*
    int* v = malloc(sizeof(int));
    *v = 10;
    printf(" memoria alocada %d",*v);
    free(v);
    */
    ///////////// Para array 
    /*
    int* v = malloc(sizeof(int)*50);
    v[0] = 10;
    v[1] = 45;
    v[2] = 7;
    printf(" memoria alocada %d %d %d \n",v[0],v[1],v[2]);
    free(v);
    */
    //////////////// 
    ///////////// Para matrix 
   /*
    int** v = malloc(sizeof(int*)*5);
    for (int i =0; i < 5; i++){
        v[i] = malloc(sizeof(int)*10);

    }
    v[0][0] = 10;
    v[1][1] = 45;
    v[2][1] = 7;
    printf(" memoria alocada %d %d %d \n",v[0][0],v[1][1],v[2][1]);
    for(int i =0;i<5;i++){
        free(v[i]);
    }
    free(v);
    
    */
    ////////////////
}