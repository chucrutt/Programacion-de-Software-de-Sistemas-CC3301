#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

// P1
typedef unsigned int uint32_t;

uint32_t elimDup(uint32_t x) {
    uint32_t mask = ~0U;
    uint32_t sufijo;
    uint32_t prefijo;
    uint32_t res = 0U;
    int repetidos = 0;
    mask = mask >> 28;
    for(int i = 0; i < 8; i ++) {
        sufijo = x & mask;
        sufijo = sufijo >> (i*4);
        mask = mask << 4;
        prefijo = x & mask;
        prefijo = prefijo >> (i*4 + 4);
        if(sufijo != prefijo) {
            res = (sufijo << 28) | (res >> 4);
        } else {
            repetidos ++;
        }
    }
    while(repetidos != 0) {
        res = res >> 4;
        repetidos --;
    }
    return res;
}

// P2
void comprimir(char *s) {
    char *read = s;
    char *write = s;
    while (*read != '\0') {
        char actual = *read;
        int count = 1;
        while (*(read + 1) == actual) {
            count++;
            read++;
        }
        if (count > 1) {
            *write = '0' + count;
            write ++;
        }
        *write = actual;
        write++;
        read++;
    }
    *write = '\0';
}

// P3
typedef struct nodo {
    int x;
    struct nodo *izq, *der;
} Nodo;

Nodo *balancear(Nodo **pa, int h) {
    if(*pa == NULL && h == 0) {
        return *pa;
    }
}

int main() {
    // ej. P1
    //printf("%x", elimDup(0x5ccc005c));
    // ej. P2
    //char s[]= "CCGGAAATCAAAA";
    //comprimir(s);
    //printf("%s \n", s); // 2C2G3ATC4A
    // ej P3

    return 0;
}
