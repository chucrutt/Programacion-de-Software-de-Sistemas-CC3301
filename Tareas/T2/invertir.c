#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "invertir.h"

//La función invertir altera el mismo string str que recibe como parámetro
void invertir(char* s) {
    // Invertimos
    char* l = s;
    char* r = s + strlen(s) - 1;
    while(l < r){
        char tmp = *l;
        *l = *r;
        *r = tmp;
        l++;
        r--;
    }

    // Eliminamos los espacios innecesarios
    char *s2 = s;
    int espacio_anterior = 1;

    while (*s) {
        if (*s == ' ') {
            if (!espacio_anterior) {
                *s2++ = ' ';
                espacio_anterior = 1;
            }
        } else {
            *s2++ = *s;
            espacio_anterior = 0;
        }
        s++;
    }

    if (s2 != s && *(s2 - 1) == ' ') {
        s2--;
    }

    *s2 = '\0';
}


//La función invertido retorna un nuevo string resultante sin alterar el parámetro str original
char *invertido(char *s) {
    /** Programe aqui la funcion invertido */
}

int main() {
	char str[] = "  Esto    es un    ejemplo     ";
    invertir(str);
    printf("->%s<- \n", str);
    return 0;
}