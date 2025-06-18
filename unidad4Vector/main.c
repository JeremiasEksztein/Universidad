#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

#pragma GCC diagnostic ignored "-Wuninitialized"
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"

void imprimirAux(const void* a);

int main()
{
    Vector* vec = NULL;

    int a = 90;

    void* b = &a;

    a++;
    void* c = &a;


    puts("A");

    vec = crearVector(10, sizeof(int));

    puts("C");

    pop(vec, c, b, 0);

    puts("B");

    if(inicializarVector(vec, (void*)b)) return ERROR;

    puts("C");

    mostrarVector(vec, imprimirAux);

    printf("D");

    return 0;
}

void imprimirAux(const void* a){
    const int* tmp = (int*) a;
    printf("%d\n", *tmp);
}
