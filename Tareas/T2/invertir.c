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
    // Invertimos todo el string
    char* l = s;
    char* r = s + strlen(s);
    r--;

    while (l < r) {
        char tmp = *l;
        *l = *r;
        *r = tmp;
        l++;
        r--;
    }

    // Eliminamos los espacios innecesarios
    char *src = s;
    char *dst = s;
    char *ultimo = NULL;

    while (*src == ' ') {
        src++;
    }

    int espacio_anterior = 0;

    while (*src) {
        if (*src == ' ') {
            if (!espacio_anterior) {
                *dst = ' ';
                ultimo = dst;
                dst++;
                espacio_anterior = 1;
            }
        } else {
            *dst = *src;
            ultimo = dst;
            dst++;
            espacio_anterior = 0;
        }
        src++;
    }

    if (ultimo && *ultimo == ' ') {
        dst = ultimo;
    }

    *dst = '\0';

    // Invertir cada palabra
    char* inicio = s;
    char* fin = s;

    while (*inicio) {
        fin = inicio;
        while (*fin && *fin != ' ') {
            fin++;
        }

        char* r = fin;
        r--;

        invertir_segmento(inicio, r);

        if (*fin == ' ') {
            inicio = fin + 1;
        } else {
            inicio = fin;
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