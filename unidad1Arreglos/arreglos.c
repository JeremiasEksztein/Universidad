#include "arreglos.h"

int insertarEnArregloInt(int arreglo[], int elem, int pos, int largo)
{
    if(pos >= largo) return -1;

    arreglo[pos] = elem;

    return 0;
}

int insertarEnArregloAscInt(int arreglo[], int elem, int largo)
{
    int i, aux;

    bubbleSort(arreglo, largo);

    while(i < largo && elem > arreglo[i])
    {
        i++;
    }

    for(; i < largo - 1; i++)
    {
        aux = arreglo[i];
        arreglo[i] = aux;
        arreglo[i + 1] = aux;
    }

    return 0;
}

int eliminarElementoEnArregloInt(int arreglo[], int elem, int largo)
{
    int i, aux;



}

int bubbleSort(int arreglo[], int largo)
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
