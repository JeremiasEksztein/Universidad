#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parametros.h"

#define OPCIONES 3

int cuadrado(int i)
{
    return i * i;
}

int menorADiez(int i)
{
    return (i < 10 ? 1 : 0);
}

int main()
{

    size_t n;
    int opcion = 0;

    float (*operaciones[3])(float*, size_t) = {buscarMinimoFloat, promedioParesFloat, mostrarInversoFloat};
    float* arreglo = NULL;

    char** opciones = (char**)malloc(3 * sizeof(char*));

    opciones[0] = (char*)malloc(strlen("Buscar el minimo elemento"));
    opciones[0] = "Buscar el minimo elemento";

    opciones[1] = (char*)malloc(strlen("Calcular el promedio de las posiciones pares"));
    opciones[1] = "Calcular el promedio de las posiciones pares";

    opciones[2] = (char*)malloc(strlen("Mostrarlo en orden inverso"));
    opciones[2] = "Mostrarlo en orden inverso";

    n = cargarArregloDeFloat(arreglo, 10, cuadrado, menorADiez);

    printf("Se cargaron %d elementos al arreglo\n", (int)n);

    do
    {
        opcion = menuGenerico(opciones, OPCIONES);

        operaciones[opcion](arreglo, n);

    }while(opcion != OPCIONES + 1);

    return 0;
}
