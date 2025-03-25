#include <stdio.h>

void imprimirBits(unsigned long long num) {
    int i;
    int numBits = sizeof(num) * 8;

    for (i = numBits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

unsigned long long dupMasLargo(unsigned long long x){
    unsigned long long mask1 = ~0ULL >> 32;
    unsigned long long mask2 = ~0ULL << 32;
    for(int i = 32; i > 0; i --) {
        unsigned long long sufijo = x & mask1;
        unsigned long long prefijo = x & mask2;
        prefijo = prefijo >> i;
       if(sufijo == prefijo){
            imprimirBits(prefijo);
            return 0;
        } else {
            mask1 = mask1 >> 1;
            mask2 = mask1 << i-1;
        }
    }
}

int main() {
    unsigned long long num = 0b101100100100100100100;
    dupMasLargo(num);
    return 0;
}
