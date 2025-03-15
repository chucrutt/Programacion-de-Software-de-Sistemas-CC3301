#include <stdio.h>
#include <stdlib.h>

void factoresPrimos(int n) {
    while (n % 2 == 0) {
        printf("2 ");
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            printf("%d ", i);
            n /= i;
        }
    }

    if (n > 1) {
        printf("%d", n);
    }
    
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <numero>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    factoresPrimos(n);

    return 0;
}
