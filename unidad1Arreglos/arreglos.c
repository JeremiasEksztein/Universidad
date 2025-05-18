#include "arreglos.h"
#include <stdio.h>

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
    int i, bytes = largo * tam_elem, cont;
    char aux;
    char* dir = arreglo;

    for(i = bytes - 2 * tam_elem; i > indice * tam_elem; i--)
    {
        for(cont = 0; cont < tam_elem; cont++)
        {
            aux = *(dir + i + cont);
            *(dir + i + cont + tam_elem) = aux;
        }
    }

    return arreglo;
}

void* leftShiftArrayVoid(void* arreglo, int indice, size_t largo, size_t tam_elem)
{
    int i, bytes = largo * tam_elem, cont;
    char aux;
    char* dir = arreglo;

    for(i = indice * tam_elem; i < bytes - tam_elem; i++)
    {
        for(cont = 0; cont < tam_elem; cont++)
        {
            aux = *(dir + i + cont + tam_elem);
            *(dir + i + cont) = aux;
        }
    }

    return arreglo;
}

int insertarEnArregloVoid(void* arreglo, void* elem, int pos, size_t largo, size_t tam_elem)
{
    int bytes;
    char aux;
    char* dir = arreglo;
    char* dir_elem = elem;

    if(pos >= largo) return -1;

    rightShiftArrayVoid(arreglo, pos, largo, tam_elem);

    for(bytes = 0; bytes < tam_elem; bytes++)
    {
        aux = *(dir_elem + bytes);
        *(dir + pos * tam_elem + bytes) = aux;
    }

    return 0;
}

int insertarEnArregloAscVoid(void* arreglo, void* elem, size_t largo, size_t tam_elem)
{
    int i = 0, maximo = 0, bytes;

    char aux;
    char** arregloBytes = arreglo;
    char* dir = arreglo;
    char* dir_elem = elem;

    for(i = 1; i < largo; i++)
    {
        *(arregloBytes + i) = (arreglo + i * tam_elem);
    }

    printf("1\n");

    bubbleSortVoid(arregloBytes, largo, tam_elem);

    printf("2\n");

    while(i < largo && memcmp(elem, *(arregloBytes + i), tam_elem) > 0)
    {
        i++;
    }

    printf("3\n");

    if(i == largo) maximo = 1;

    rightShiftArrayVoid(arreglo, i - maximo, largo, tam_elem);

    printf("4\n");

    for(bytes = 0; bytes < tam_elem; bytes++)
    {
        aux = *(dir_elem + bytes);
        *(dir + i - maximo + bytes) = aux;
    }

    printf("5\n");

    return 0;
}


int bubbleSortVoid(char** arreglo, size_t largo, size_t tam_elem)
{
    int i, j;
    char* aux;

    for(i = 0; i < largo - 1; i++)
    {
        for(j = 0; j < largo - 1 - i; j++)
        {
            if(memcmp(*(arreglo + j), *(arreglo + j + 1), tam_elem) > 0)
            {
                aux = *(arreglo + j);
                *(arreglo + j) = *(arreglo + j + 1);
                *(arreglo + j + 1) = aux;
            }
        }

    }

    return 0;
}
