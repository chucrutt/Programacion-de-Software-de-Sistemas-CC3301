#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {
    // (i) leer secuencialmente todos los elementos de la cola, buscando el texto con mejor prioridad
    FILE *f = fopen(argv[1], "r+");
    
    // archivo no existe
    if(f == NULL) {
        perror("fopen");
        return 1;
    }
    // cola vacia
    if(fgetc(f) == '0') {
        fprintf(stderr, "error: cola.txt esta vacia\n");
        return 1;
    } else {
        fseek(f, 0, SEEK_SET);
    }
    
    char s[6];
    fgets(s, sizeof(s), f);
    int n = atoi(s);

    // desde la segunda fila recorrer nombre y prioridad
    char res[11];
    int maxPrio = -1;
    long int filaPrio = 0;
    for(int i = 0; i < n; i++) {
        // obtener nombre
        char nombre[11];
        fgets(nombre, sizeof(nombre), f);
        // obtener prioridad de nombre
        char prio[8];
        fgets(prio, sizeof(prio), f);
        int intPrio = atoi(prio);
        // si la prioridad es mayor, actualizar nombre y maxima prioridad encontrada
        if(intPrio < maxPrio || maxPrio == -1) {
            filaPrio = i * 17 + 5;
            maxPrio = intPrio;
            strcpy(res, nombre);
        }    
    }
    // (ii) mostrarlo en pantalla
    printf("%s\n", res);
    // (iii) usar  fseek para actualizar el tamaño de la cola
    fseek(f, 0L, SEEK_SET);
    fprintf(f, "%-4d\n", n - 1);
    // (iv) usar fseek para mover el último elemento de la cola a la línea que queda libre
    fseek(f, (17 * (n-1) + 5), SEEK_SET);
    char ultimo[17];
    fgets(ultimo, sizeof(ultimo), f);
    fseek(f, filaPrio, SEEK_SET);
    fprintf(f, "%-16s\n", ultimo);
    return 0;
}