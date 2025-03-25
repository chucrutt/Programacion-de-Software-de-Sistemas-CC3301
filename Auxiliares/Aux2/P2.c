#include <stdio.h>
#include <stdlib.h>

//busca en x el patron p de n bits, entregando su posicion expresada como la posicion del bit menos significativo de p en x, o −1 si no se encuentra.

int posicionBits(int x, int p, int n) {
    int mask = (1 << n) - 1;
    for (int i = 0; i <= (sizeof(int) * 8 - n); i++) { 
        if (((x >> i) & mask) == p) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char *argv[]){
    unsigned int x = atoi(argv[1]);
    int p = atoi(argv[2]);
    int n = atoi(argv[3]);
    posicionBits(x, p, n);
    return 0;
}