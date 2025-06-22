#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "integral.h"

double integral_par(Funcion f, void *ptr, double xi, double xf, int n, int p) {
    int fd[p][2];
    double h = (xf - xi) / p;
    int trapecios_por_proceso = n / p;

    for (int i = 0; i < p; i++) {
        pipe(fd[i]);

        pid_t pid = fork();
        if (pid == 0) {
            close(fd[i][0]);

            double sub_xi = xi + i * h;
            double sub_xf = sub_xi + h;

            int trapecios = (i == p - 1) ? (n - trapecios_por_proceso * (p - 1)) : trapecios_por_proceso;

            double resultado = integral(f, ptr, sub_xi, sub_xf, trapecios);
            write(fd[i][1], &resultado, sizeof(double));

            close(fd[i][1]);
            exit(0);
        }

        close(fd[i][1]);
    }

    double resultado_total = 0.0;
    for (int i = 0; i < p; i++) {
        double parcial = 0.0;
        read(fd[i][0], &parcial, sizeof(double));
        resultado_total += parcial;
        close(fd[i][0]);
    }

    for (int i = 0; i < p; i++) {
        wait(NULL);
    }

    return resultado_total;
}
