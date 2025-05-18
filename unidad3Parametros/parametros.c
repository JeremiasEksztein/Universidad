#include "parametros.h"

//3.1

int menuGenerico(char** opciones, size_t n)
{
    int i, opcion = 0;

    printf("MENU\n");

    do
    {
        printf("Ingrese opcion a elegir");

        for(i = 0; i < n; i++)
        {
            printf("%d - %s\n", i + 1, *(opciones + i));
        }

        printf("%d - Salir\n", (int)(n + 1));

        scanf("%d", &opcion);

        if(opcion != n + 2)
        {
            return opcion;
        }

    }while(opcion != n + 2);

    return n + 2;
}

size_t cargarArregloDeFloat(float* arreglo, size_t tam, int(*operacion)(int), int(*condicion)(int))
{
    size_t i = 0;

    while(condicion(i) && i < tam)
    {
        *(arreglo + i) = operacion(i);
        i++;
    }

    return i;
}

float buscarMinimoFloat(float* arreglo, size_t tam)
{
    int i;
    float min = *(arreglo);

    for(i = 1; i < tam; i++)
    {
        if(*(arreglo + i) < min)
        {
            min = *(arreglo + i);
        }
    }

    return min;
}

float promedioParesFloat(float *arreglo, size_t tam)
{
    int i;
    float sum = 0, mean = 1;

    for(i = 0; i < tam; i++)
    {
        if(i % 2 == 0)
        {
            sum += *(arreglo + i);
        }
    }

    mean = sum / tam;

    return mean;
}

float mostrarInversoFloat(float* arreglo, size_t tam)
{
    int i;

    for(i = tam - 1; i >= 0; i--)
    {
        printf("%0.3f\n", *(arreglo + i));
    }

    return 0;
}

char* guardarFloatEnTexto(float* arreglo, size_t tam)
{
    int i;

    FILE* floats = fopen("floats.txt", "wt");

    if(floats == NULL) return NULL;

    for(i = 0; i < tam; i++)
    {
        fwrite((arreglo + i), sizeof(float), 1, floats);
    }

    fclose(floats);

    return "floats.txt";
}
