#include <stdio.h>
#include <stdlib.h>

int decimal(int binario) {
    int decimal = 0, base = 1, resto;
    
    while (binario > 0) {
        resto = binario % 10;
        decimal += resto * base;
        binario /= 10;
        base *= 2;
    }
    
    return decimal;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <numero_binario>\n", argv[0]);
        return 1;
    }

    int binario = atoi(argv[1]);
    printf("%d\n", decimal(binario));

    return 0;
}
