#include <stdio.h>

unsigned long long dupMasLargo(unsigned long long x){
    unsigned long long mask1 = ~0ULL >> 32;
    unsigned long long mask2 = ~0ULL << 32;
    for(int i = 32; i > 0; i--) {
        unsigned long long sufijo = x & mask1;
        unsigned long long prefijo = x & mask2;
        prefijo = prefijo >> i;
        if(sufijo == prefijo){
            return i;
        } else {
            mask1 = mask1 >> 1;
            mask2 = mask1 << (i-1);
        }
    }
    return 0;
}

int main() {
    printf("%lld", dupMasLargo(0b0));
    return 0;
}
