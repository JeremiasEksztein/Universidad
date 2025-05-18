#include "memoria.h"
#include <string.h>


int* crearArregloInt(size_t tam)
{
    int i;
    int* arr = (int*)malloc(sizeof(int) * tam);

    if(arr == NULL) return NULL;

    for(i = 0; i < tam; i++)
    {
        *(arr + i) = 0;
    }

    return arr;
}

Prueba* crearArregloDePrueba(size_t tam)
{
    int i;
    Prueba *pruebaNueva = (Prueba*)malloc(sizeof(Prueba) * tam);
    char* cadena = "Hello, World";

    if(pruebaNueva == NULL) return NULL;

    for(i = 0; i < tam; i++)
    {
        (pruebaNueva + i)->cadena = cadena;
        (pruebaNueva + i)->entero = 5;
        (pruebaNueva + i)->real = 0.5;
        (pruebaNueva + i)->caracter = 'A';
    }

    return pruebaNueva;
}

void inicializarArregloInt(int* arreglo, size_t tam, int (*f)(int))
{
    int i;

    for(i = 0; i < tam; i++)
    {
        *(arreglo + i) = f(i);
    }
}

void inicializarArregloDePrueba(Prueba* arreglo,  size_t tam, Prueba (*f)(void))
{
    int i;

    for(i = 0; i < tam; i++)
    {
        *(arreglo + i) = f();
    }
}

char* copiaCadena(const char* cadena)
{
    size_t tam = *(&cadena + 1) - cadena;
    int i;
    char* copia = malloc(sizeof(char) * tam);

    for(i = 0; i < tam; i++)
    {
        *(copia + i) = *(cadena + i);
    }

    return copia;
}

void* copiaCosas(void* elemento, size_t tam)
{
    char* copia = (char*)malloc(tam);

    if(copia == NULL) return NULL;

    char* o = (char*)elemento;

    while(tam)
    {
        *copia = *o;
        copia++;
        o++;
        tam--;
    }

    return (void*)copia;
}

void* memMove(void* dest, const void* source, size_t tam_elem)
{
    if(dest == source) return dest;

    void* aux = malloc(tam_elem);

    if(aux == NULL) return NULL;

    aux = copiaCosas((void*)source, tam_elem);

    dest = copiaCosas(aux, tam_elem);

    free(aux);

    return (void*)dest;
}
