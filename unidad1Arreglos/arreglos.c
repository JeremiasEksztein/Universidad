#include "arreglos.h"

int* rightShiftArray(int* arreglo, int indice, size_t tam)
{
    int i, aux;

    aux = *(arreglo + tam - 2);
    *(arreglo + tam - 1) = aux;

    for(i = tam - 2; i > indice; i--)
    {
        aux = *(arreglo + i - 1);
        *(arreglo + i) = aux;
    }

    return arreglo;
}

int* leftShiftArray(int* arreglo, int indice, size_t tam)
{
    int i, aux;

    for(i = indice; i < tam - 1; i++)
    {
        aux = *(arreglo + i + 1);
        *(arreglo + i) = aux;
    }

    return arreglo;
}

int insertarEnArregloInt(int arreglo[], int elem, int pos, size_t largo)
{
    if(pos >= largo) return -1;

    rightShiftArray(arreglo, pos, largo);

    arreglo[pos] = elem;

    return 0;
}

int insertarEnArregloAscInt(int arreglo[], int elem, size_t largo)
{
    int i = 0, maximo = 0;

    bubbleSort(arreglo, largo);

    while(i < largo && elem > arreglo[i])
    {
        i++;
    }

    if(i == largo) maximo = 1;

    rightShiftArray(arreglo, i - maximo, largo);

    arreglo[i - maximo] = elem;

    return 0;
}

int eliminarPosicionEnArregloInt(int arreglo[], int pos, size_t largo)
{
    if(pos >= largo) return -1;

    leftShiftArray(arreglo, pos, largo);

    return 0;
}

int eliminarElementoEnArregloInt(int arreglo[], int elem, size_t largo)
{
    int i = 0, encontrado = 0;

    while(!encontrado && i < largo)
    {
        if(arreglo[i] == elem)
        {
            encontrado = 1;
        }

        i++;
    }

    if(!encontrado) return -1;

    leftShiftArray(arreglo, i - 1, largo);

    return 0;
}

int eliminarElementosEnArregloInt(int arreglo[], int elem, size_t largo)
{
    int i = 0;

    while(i < largo)
    {
        if(arreglo[i] == elem)
        {
            leftShiftArray(arreglo, i, largo);
            i--;
        }

        i++;
    }

    return 0;
}

int bubbleSort(int arreglo[], size_t largo)
{
    int i, j, aux;

    for(i = 0; i < largo - 1; i++)
    {
        for(j = 0; j < largo - 1 - i; j++)
        {
            if(arreglo[j] > arreglo[j + 1])
            {
                aux = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = aux;
            }
        }
    }

    return 0;
}

void* rightShiftArrayVoid(void* arreglo, int indice, size_t largo, size_t tam_elem)
{
    int i, aux_bytes, bytes = largo * tam_elem;
    char aux;

    char* dir = arreglo;

    aux_bytes = 0;

    while(aux_bytes < tam_elem)
    {
        aux = *(dir + (bytes) - 2 * tam_elem + aux_bytes);
        *(dir + (bytes) - tam_elem + aux_bytes) = aux;
        aux_bytes++;
    }



    /*

    char* dir = arreglo;

    aux = *(dir + (tam * tam_elem) - 2);
    *(dir + (tam * tam_elem) - 1) = aux;

    for(i = (tam * tam_elem) - 2; i > (indice * tam_elem); i--)
    {
        aux = *(dir + i - 1);
        *(dir + i) = aux;
    }*/

    return arreglo;
}

void* leftShiftArrayVoid(void* arreglo, int indice, size_t bytes)
{


}
