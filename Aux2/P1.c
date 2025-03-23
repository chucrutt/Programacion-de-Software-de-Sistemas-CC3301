#include <stdio.h>
#include <stdlib.h>  // Para usar atoi()

int bits1(unsigned int n) {
    int count = 0;
    while (n) {
        count += n & 1;  
        n >>= 1;         
    }
    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {  
        printf("Uso: %s <numero>\n", argv[0]);
        return 1;
    }

    unsigned int num = (unsigned int) atoi(argv[1]);  
    printf("Bits en 1: %d\n", bits1(num));
    return 0;
}
