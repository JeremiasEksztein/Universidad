#ifndef MEMORIA_H_INCLUDED
#define MEMORIA_H_INCLUDED

#include <stddef.h>
#include <stdlib.h>

typedef struct
{
    char* cadena;
    int entero;
    float real;
    char caracter;
}Prueba;

int* crearArregloInt(size_t tam);
Prueba* crearArregloDePrueba(size_t tam);
void inicializarArregloInt(int* arreglo, size_t tam, int (*f)(int));
void inicializarArregloDePrueba(Prueba* arreglo, size_t tam, Prueba (*f)(void));

char* copiaCadena(const char* cadena);
void* copiaCosas(void* cosa, size_t tam_elem);

void* memMove(void* dest, const void* source, size_t tam_elem);

#endif // MEMORIA_H_INCLUDED
