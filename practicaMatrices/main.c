#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

int initElem(void* a);
void imprElem(const void* a);

int main()
{
    int** mat = (int**) crearMatriz(4, 4, sizeof(int));

    inicializarMatriz((void**) mat, 4, 4, initElem);

    mostrarMatriz((void**) mat, 4, 4, imprElem);

    destruirMatriz((void**) mat, 4);

    return 0;
}

int initElem(void* a)
{
    int* tmp = (int*) a;

    *tmp = 1;

    return 0;
}

void imprElem(const void* a)
{
    int* tmp = (int*) a;

    printf("%d\n", *tmp);
}
