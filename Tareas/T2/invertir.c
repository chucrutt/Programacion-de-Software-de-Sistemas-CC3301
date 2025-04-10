#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "invertir.h"

void invertir_segmento(char* l, char* r) {
    while (l < r) {
        char tmp = *l;
        *l = *r;
        *r = tmp;
        l++;
        r--;
    }
}

//La función invertir altera el mismo string str que recibe como parámetro
void invertir(char* s) {
    // invertimos todo el string
    char* l = s;
    char* r = s + strlen(s) - 1;
    while(l < r){
        char tmp = *l;
        *l = *r;
        *r = tmp;
        l++;
        r--;
    }

    // eliminamos los espacios innecesarios
    char *src = s;
    char *dst = s;

    while (*src == ' ') {
        src++;
    }

    int espacio_anterior = 0;

    while (*src) {
        if (*src == ' ') {
            if (!espacio_anterior) {
                *dst++ = ' ';
                espacio_anterior = 1;
            }
        } else {
            *dst++ = *src;
            espacio_anterior = 0;
        }
        src++;
    }

    if (dst > s && *(dst - 1) == ' ') {
        dst--;
    }

    *dst = '\0';

    // invertir cada palabra
    char* inicio = s;
    char* fin = s;

    while (*fin) {
        while (*fin && *fin != ' ') {
            fin++;
        }

        invertir_segmento(inicio, fin - 1);

        if (*fin == ' ') {
            inicio = fin + 1;
            fin++;
        }
    }
}


//La función invertido retorna un nuevo string resultante sin alterar el parámetro str original
char *invertido(char *s) {
    char *copia = malloc(strlen(s) + 1);
    strcpy(copia, s);
    invertir(copia);
    return copia;
    }

/*int main() {
    char str[] = "  hola   que   tal ";
    //invertir(str);
    printf("%s", invertido(str));
    return 0;
}*/