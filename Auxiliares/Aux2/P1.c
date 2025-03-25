#include <stdio.h>
#include <stdlib.h>

// Funcion bits1 que dado un numero n, retorna el numero de bits en 1 que tiene n

int bits1(unsigned int n) {
    int count = 0;
    while (n) {
        count += n & 1;  
        n >>= 1;         
    }
    return count;
}

int main(int argc, char *argv[]) {
    unsigned int num = (unsigned int) atoi(argv[1]);  
    printf("Bits en 1: %d\n", bits1(num));
    return 0;
}
