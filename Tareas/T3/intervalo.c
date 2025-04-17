#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "intervalo.h"

Nodo *extractMax(Nodo **pa) {
    if (*pa == NULL) {
        return NULL;
    }
    if ((*pa)->der == NULL) {
        
        Nodo *res = (*pa);
        *pa = (*pa)->izq;
        return res;
    } else {
        return extractMax(&(*pa)->der);
    }
}

Nodo *mezclar(Nodo **izq, Nodo **der) {
    if (*izq == NULL) {
        return *der;
    }
    if (*der == NULL) {
        return *izq;
    }
    Nodo* res = extractMax(izq);
    res->izq = *izq;
    res->der = *der;
    return res;
}

void elimIntervalo(Nodo **pa, int inf, int sup) {
    if (*pa == NULL) return;
    if (inf <= (*pa)->id && (*pa)->id <= sup) {
        elimIntervalo(&(*pa)->izq, inf, sup);
        elimIntervalo(&(*pa)->der, inf, sup);
        Nodo *nuevo = mezclar(&(*pa)->izq, &(*pa)->der);
        free(*pa);
        *pa = nuevo;
        elimIntervalo(&(*pa), inf, sup);
    } else {
        elimIntervalo(&(*pa)->izq, inf, sup);
        elimIntervalo(&(*pa)->der, inf, sup);
    }
}
