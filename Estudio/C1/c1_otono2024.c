#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// P1
typedef unsigned long long uint64;

uint64 suma(uint64 x) {
    uint64 suma = 0;
    uint64 nmask = ~0ULL;
    uint64 lmask = 0b1111;
    uint64 largo = x & lmask;
    while(largo != 0){
        x = x >> 4;
        nmask = nmask >> 64 - largo;
        suma += (x & nmask);
        x = x >> largo;
        nmask = ~0ULL;
        largo = x & lmask;
    }
    return suma;
}

// P2
char *reemplazo(char *s, char c, char *pal){
    int pal_len = strlen(pal);
    char *start1 = s;
    int contador = 0;
    while(*s != '\0') {
        if(*s == c) {
            contador++;
            s++;
        }else s++; 
    }
    s = start1;
    char *res = malloc(strlen(s) - contador + pal_len*contador + 1);
    char *str = res;
    while(*s != '\0') {
        if(*s == c) {
            char *start2 = pal;
            for(int i = 0; i < pal_len; i++){
                *res = *pal;
                res++;
                pal++;
            }
            pal = start2;
            s++;
        } else {
            *res = *s;
            res++;
            s++;
        }
    }
    *res = '\0';
    return str;
}

// P3
typedef struct nodo {
    int x;
    struct nodo *prox;
} Nodo;

// imprime una cadena de nodos para comprobar los resultados
void printList(Nodo *L) {
    while(L -> prox != NULL) {
        printf("%d, ", L -> x);
        L = L -> prox;
    }
    printf("%d \n", L -> x);
}

void elimDup(Nodo *L){
    if (L -> prox == NULL) {
        return;
    }
    while (L -> prox != NULL) {
        if(((L -> prox) -> x) == L -> x) {
            L -> prox = (L -> prox) -> prox;
        } else {
            L = L -> prox;
        }
    }
}

int main() {
    // ej. P1
    //printf("%llu \n", suma(0b00001001101011100011010010));
    // ej. P2
    //char s[] = "hola que tal";
    //char c = 'a';
    //char pal[] = "xyz";
    //printf("%s \n", reemplazo(s, c, pal));
    // ej. P3
    //Nodo g = {.x = 7, .prox = NULL};
    //Nodo f = {.x = 3, .prox = &g};
    //Nodo e = {.x = 3, .prox = &f};
    //Nodo d = {.x = 3, .prox = &e};
    //Nodo c = {.x = 9, .prox = &d};
    //Nodo b = {.x = 7, .prox = &c};
    //Nodo a = {.x = 7, .prox = &b};
    //Nodo *L = &a;
    //elimDup(L);
    //printList(L);
    return 0;
}