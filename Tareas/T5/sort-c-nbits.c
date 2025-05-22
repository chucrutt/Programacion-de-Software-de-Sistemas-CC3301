#include <string.h>

void sort(unsigned int *nums, int n) {
  unsigned int *ult= &nums[n-1];
  unsigned int *p= nums;
  while (p<ult) {
    // No modifique nada arriba de esta linea
    // Inicio de la parte que debe cambiar

    // Contar los bits validos de p[0] y p[1]
    // Deben crearse copias para no modificar los numeros del arreglo

    unsigned int cpy0 = p[0], cpy1 = p[1];
    int count0 = 0, count1 = 0;
    while(cpy0){
      count0 += cpy0 & 1;
      cpy0 >>= 1; 
    }
    while(cpy1){
      count1 += cpy1 & 1;
      cpy1 >>= 1; 
    }

    // Hacer la comparacion de bits en 1 y continuar con Bubble Sort
    int t1= count0>=count1 ? 0 : 1;

    // Fin de la parte que debe cambiar
    // No Cambie nada mas a partir de aca
    if (t1 <= 0)
      p++;
    else {
      unsigned int tmp= p[0];
      p[0]= p[1];
      p[1]= tmp;
      p= nums;
    }
  }
}
