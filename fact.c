#include <stdio.h>

// Función recursiva para calcular el factorial
double factorial(int n) {
    if (n == 0 || n == 1) {
        return 1.0;  // Caso base: 0! = 1! = 1
    }
    return n * factorial(n - 1);  // Llamada recursiva
}

int main() {
    int n;

    scanf("%d", &n);

    if (n < 0) {
        printf("El factorial no está definido para números negativos.\n");
    } else {
        double result = factorial(n);
        printf("El factorial de %d es: %.0f\n", n, result);
    }

    return 0;
}
