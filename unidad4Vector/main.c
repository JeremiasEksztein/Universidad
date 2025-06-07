#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

typedef struct{
    int legajo;
    char nomape[25];
}Empleado;

int main()
{
    Vector* vec = NULL;

    puts("C");

    crearVector(vec, 4 + 25);

    puts("A");

    destruirVector(vec);

    puts("B");

    return 0;
}
