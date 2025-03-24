#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    int n = 3;
    int mask = (1 << n);
    printf("%b", mask);
    return 0;
}