#include <stdio.h>
#include "suma-dec.h"
// typedef unsigned long long Decimal
Decimal sumaDecimal(Decimal x, Decimal y) {
    Decimal sum, digX, digY, mask = ~0ULL, res = 0ULL;
    int resto = 0;
    mask = mask >> 60;
    for (int i = 0; i < 16; i++) {
        digX = x & mask;
        digY = y & mask;
        digX = digX >> (i*4);
        digY = digY >> (i*4);
        sum = digX + digY;
        if(resto) {
            sum += 1;
            resto = 0;
        }
        if(sum >= 10) {
            resto = 1;
            sum = sum - 10;
        }
        res = (sum << i*4)|res;
        mask = mask << 4;
    }
    return res;
}