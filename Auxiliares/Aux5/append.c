#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct nodo {
    int x;
    struct nodo *sgte;
} Nodo;

void append(Nodo **pa, Nodo *b);

Nodo *createNodeList(int *a, int size){
    Nodo *n = malloc(sizeof(Nodo));
    if(size > 1){

    }
}

int main(){

    return 0;
}