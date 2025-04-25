#include <stdio.h>
#include <string.h>

#include "sumar-str.h"
// c - '0' (char c ASCII a decimal int)
// d + '0' (int d decimal a char ASCII)
char sumarStr(char *a, char *b) {
    int resto = 0;
    int aLen = strlen(a);
    int bLen = strlen(b);
    a += aLen;
    b += bLen;
    for(int i = 0; i < aLen; i++) {
        a --;
        b --;
        int sum = (*a - '0') + (*b - '0');
        if(resto) {
            sum += 1;
            resto = 0;
        }
        if(sum >= 10) {
            resto = 1;
            sum -= 10;
        }
        *a = sum + '0';
    }
    if(resto) {
        return '1';
    }
    return '0';
}
