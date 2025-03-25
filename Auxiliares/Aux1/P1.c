#include <stdio.h>
#include <stdlib.h>

float celcius_to_fahrenheit(float c) {
    return (c * (9.0 / 5.0)) + 32.0;
}

int factorial(int n) {
    if(n <= 1){
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num;
    printf("23°C = %f°F\n", celcius_to_fahrenheit(23.0));
    printf("9! = %d\n", factorial(9));
    printf("Ingrese un número para calcular su factorial: ");
    scanf("%d", &num);
    printf("%d! = %d\n", num, factorial(num));
    return 0;
}
