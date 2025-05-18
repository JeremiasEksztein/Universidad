#include <stdio.h>
#include <stdlib.h>
#include "arreglos.h"

void mostrarArregloInt(int* arreglo, size_t tam);

int main()
{
    int arreglo[10] = {1, 2, 2, 2, 5, 6, 7, 8, 9, 10};
    //float reales[5] = {5.6, 12.3, 34.24, 39.39, 20.12};

    mostrarArregloInt(arreglo, 10);

    int* elem = NULL;
    *elem = 12;

    insertarEnArregloVoid((void*)arreglo, (void*)elem, 0, 10, sizeof(int));
    mostrarArregloInt(arreglo, 10);









    /*
    printf("original\n");
    mostrarArregloInt(arreglo, 10);

    //leftShiftArray(arreglo, 10, 10);
    //leftShiftArrayVoid((void*)arreglo, 2, 10, sizeof(int));

    mostrarArregloInt(arreglo, 10);

    */

    /*
    insertarEnArregloInt(arreglo, 11, 4, 10);

    printf("insertar en arreglo\n");
    mostrarArregloInt(arreglo, 10);

    insertarEnArregloAscInt(arreglo, 15, 10);

    printf("insertar en arreglo asc\n");
    mostrarArregloInt(arreglo, 10);

    eliminarPosicionEnArregloInt(arreglo, 0, 10);

    printf("eliminar posicion en arreglo\n");
    mostrarArregloInt(arreglo, 10);

    eliminarElementoEnArregloInt(arreglo, 2, 10);

    printf("eliminar elemento en arreglo\n");
    mostrarArregloInt(arreglo, 10);

    eliminarElementosEnArregloInt(arreglo, 2, 10);

    printf("eliminar elementos en arreglo\n");
    mostrarArregloInt(arreglo, 10);

    */
    return 0;
}

void mostrarArregloInt(int* arreglo, size_t tam)
{
    int i;

    for(i = 0; i < tam; i++)
    {
        printf("%d\t", *(arreglo + i));
    }

    puts("");
}
