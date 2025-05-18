#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "memoria.h"

int suma(int i);
int resta(int i);
int random(int i);

Prueba goodbye(void);

int main()
{
    int *arr, tam, i;
    Prueba* prueba;

    srand(time(NULL));

    puts("Ingrese cant de elementos para el array");
    scanf("%d", &tam);

    arr = crearArregloInt(tam);
    //inicializarArregloInt(arr, tam, suma);
    inicializarArregloInt(arr, tam, random);

    for(i = 0; i < tam; i++)
    {
        printf("%d ", *(arr + i));
    }

    prueba = crearArregloDePrueba(5);
    inicializarArregloDePrueba(prueba, 5, goodbye);

    puts("");
    for(i = 0; i < 5; i++)
    {
        printf("Cadena: %s\nEntero = %d\nReal = %0.2f\nCaracter: %c\n", (prueba + i)->cadena, (prueba + i)->entero, (prueba + i)->real, (prueba + i)->caracter);
    }

    free(arr);
    free(prueba);

    char* cadena = "Hello, World";

    char* copia = copiaCadena(cadena);

    printf("%s\n%s\n", cadena, copia);

    free(copia);

    return 0;
}

int suma(int i)
{
    return i + 1;
}

int resta(int i)
{
    return i - 2 * i;
}

int random(int i)
{
    return rand() % 100;
}

Prueba goodbye(void)
{
    Prueba prueba;
    char* cadena = "Goodbye, World";

    prueba.cadena = cadena;
    prueba.entero = 10;
    prueba.real = 0.75;
    prueba.caracter = 'B';

    return prueba;
}
