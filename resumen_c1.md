# Resumen Control 1 - Programación de Software de Sistemas (CC3301)

## Compilación
Compilar es el proceso en el cuál el código fuente se traduce a un código máquina que puede ser entendido y ejecutado por el computador.

Luego de escribir el código fuente en un archivo .c, llamamos desde la terminal al compilador que estemos usando (gcc) y ejecutamos el comando correspondiente para compilarlo.

- Para producir un ejecutable con fuente de un solo archivo: $ gcc -o nombre_ejecutable codigo_fuente.c

Cuando trabajamos con proyectos más grandes o con multiples archivos fuente, en lugar de compilar todo directamente podemos crear módulos objeto (archivo que contiene código máquina pero no puede ejecutarse por si solo), asi podemos dividir y compilar nuestro programa en archivos en módulos más pequeños y manejables para luego enlazarlos y ejecutarlos en conjunto. 

- Para producir un módulo objeto: $ gcc -c -o nombre_modulo_objeto.o codigo_fuente.c
- Para enlazar módulos: $ gcc -o nombre_ejecutable modulo1.o modulo2.o
- Para ejecutar un programa: $ ./nombre_ejecutable

## Debugging

## Conceptos Básicos del lenguaje C
Obtener inputs desde la terminal
```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Número de argumentos: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("Argumento %d: %s\n", i, argv[i]);
    }
    return 0;
}
/*
$ ./programa hola mundo 123
Número de argumentos: 4
Argumento 0: ./argumentos
Argumento 1: hola
Argumento 2: mundo
Argumento 3: 123
*/
```

Uso de printf()
```c
#include <stdio.h>

int main(){
    int a; float b; char c; int* d; long long e; double f; char str[];
    printf("%d", a); // int
    printf("%u", a); // unsigned int
    printf("%f", b); // float
    printf("%c", c); // character
    printf("%p", d); // pointer (direccion de memoria)
    printf("%lld", e); // long long (int de 64 bits)
    printf("%lf", f); // double (float de 64 bits)
    printf("%s", g); // string
    return 0;
}
```

Definir funciones
```c
#include <stdio.h>
// tipo de variable que retorna, nombre de la funcion y luego argumentos
// siempre definir cada variable con su respectivo tipo
void funcion(int i){
    return;
}

int main(){
    int i;
    funcion(i);
    return 0;
}
```

## Bits
Operadores de bits
```c
#include <stdio.h>

int main(){
    // para bits usamos unsigned para aprovechar de mejor manera los bits de memoria
    // traduccion de bits (potencias de 2) a decimal: 1100 = 2^3 * 1 + 2^2 * 1 + 2^1 * 0 + 2^0 * 0 = 12
    unsigned int a = 12; // 00001100
    unsigned int b = 5;  // 00000101
    printf("a & b = %u\n", a & b);   // & (AND) 00000100
    printf("a | b = %u\n", a | b);   // | (OR) 00001101
    printf("a ^ b = %u\n", a ^ b);   // ^ (XOR) 00001001
    printf("~a = %u\n", ~a);         // ~ (negacion)
    printf("a << 1 = %u\n", a << 1); // << (desplaza a la izquierda) 00011000
    printf("a >> 1 = %u\n", a >> 1); // >> (desplaza a la derecha) 00000110
    // recordar que todas estas variables son de 32 bits sizeof(int)
    // ~a = 1111 1111 1111 1111 1111 1111 1111 0011
    return 0;
}
```

Uso de Masks
```c
#include <stdio.h>
// Usamos una máscara de bits (bitmask) para extraer, modificar o verificar ciertos bits dentro de un número.
int main() {
    // ej. extraemos los 5 bits menos significativos
    unsigned int valor = 0b11011010;
    unsigned int mask = 0b11111;
    unsigned int resultado = valor & mask;
    return 0;
}
```

## Arreglos y Punteros
Punteros
```c
#include <stdio.h>

int main() {
    int a = 5; int b = 5;
    int* p = &a; int* q = &b; // declaramos y asignamos
    // int* indica que el puntero apunta a la direccion de memoria de un numero entero
    // &a es la direccion de memoria de la variable a 
    if (*p == *q) // *p==*q compara los valores a los cuales apuntan, p==q compara las direcciones de memoria
        printf("p y q apuntan a valores iguales\n");
    return 0;
}
```

Arreglos y Aritmetica
```c
#include <stdio.h>

int main(){
    // los arreglos son conjuntos de variables de un mismo tipo donde cada una esta numerada (indices)
    int a[10]; // arreglo de numeros enteros de tamaño 10 (a priori los tamaños de los arreglos son estaticos)
    a[2] = 3; // accede al tercer elemento del arreglo y le asigna el valor 3 (indices del 0 al 9)
    // Como los arreglos son direcciones CONTINUAS de memoria, podemos usar punteros para "navegarlos"
    int* p = &a[4]; // apunta al 5to elemento del arreglo
    p += 1; // ahora apunta al 6to elemento
    // IMPORTANTE: como los arreglos son estaticos es importante no salirse del rango
    printf("%d\n", a[10]); // ERROR
    return 0;
}
```

Strings
```c
#include <stdio.h>
int main() {
    // los strings no son mas que arreglos de caracteres que terminan en '\0'
    char saludo[5] = {'H', 'O', 'l', 'a', '\0'};
    char str[] = "Hola"; // ambos son maneras equivalentes de inicializar el string
    // como tambien son arreglos podemos acceder a sus elementos con aritmetica de punteros
    char *r = str;
    printf("%c", *(r+3)); // imprime 'a'
    // podemos definir strings mutables e inmutables (solo lectura)
    char str_m[] = "Hola"; // mutable
    char* str_im = "Hola"; // inmutable
    

    strlen(str); // retorna un entero con el largo real del string (sin '\0')
    strcpy(b, a); // copia el string a en el arreglo b
    return 0;
}
```

## Estructuras
Malloc y Free
```c
#include <stdio.h>
#include <stdlib.h> // requisito

int main() {
    // malloc() reserva un bloque de memoria de un tamaño especifico y retorna un puntero a esta direccion
    // su principal uso es poder trabajar con memoria de manera dinamica
    int *p = malloc(sizeof(int)*10); // reservamos memoria para 10 enteros y obtenemos un puntero p que apunta al primer elemento de ese bloque
    p[3] = 1; // podemos trabajar con este espacio de memoria, es equivalente a hacer *(p + 3) = 1;
    free(p); // es importante liberar esa memoria al terminar de usarla o puede generar fugas de memoria
    return 0;
}
```

Estructuras
```c
#include <stdio.h>
#include <stdlib.h>

// las estructuras nos permiten agrupar distintos tipos de datos en una sola variable
typedef struct punto {
    int x;
    int y;
} Punto;

int main () {
    Punto v; // tambien puede inicializarse como (struct punto v;)
    v.x = 5; // para acceder a los campos de la estructura
    v.y = 10;

    // podemos tener punteros a estructuras
    Punto* pv = &v;
    // Como tambien podemos tener punteros a punteros
    Punto** ppv = &pv;

    // si tenemos un puntero a una estructura y queremos acceder a uno de los campos podemos hacer:
    printf("%d", (*pv).x); // pv es el puntero que apunta al punto v, luego imprimimos su componente x
    // o de manera equivalente
    printf("%d", pv -> x);

    return 0;
}
```

Como usar punteros a punteros
```c
#include <stdio.h>

void cambiarPuntero(int** ppx) {
    static int y = 2;
    *ppx = &y;
}

int main() {
    // su principal uso es reasignar punteros en una funcion, pues por el contrario solo estamos reasignando una copia del puntero
    // de esta forma estamos cambiando la direccion de memoria en la que se encuentra el puntero original
    int x = 1;
    int* px = &x;
    int** ppx = &px;
    cambiarPuntero(ppx);

    printf("%d\n", *px);
    return 0;
}
```
