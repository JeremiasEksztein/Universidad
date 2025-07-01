#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include "comunes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_CAP 10

#define FACTOR_INCR 2

typedef int (*Comparar)(const void*, const void*);
typedef int (*Modificar)(void*, const void*);
typedef void (*Imprimir)(const void*);


typedef struct{
    void* data;
    size_t tamElem;
    size_t cantElem;
    size_t cap;
}Vector;

int vectorCrear(Vector* vec, size_t tamElem);
int vectorDestruir(Vector* vec);

int vectorAgregar(Vector* vec, void* elem);
void* vectorObtener(Vector* vec, int pos);
int vectorModificar(Vector* vec, void* elem, int pos);

int vectorOrdenar(Vector* vec, Comparar cmpFunc);

int vectorBusquedaLineal(Vector* vec, void* clave, Comparar cmpFunc);
int vectorBusquedaBinaria(Vector* vec, void* clave, Comparar cmpFunc);

int vectorRedimensionar(Vector* vec, size_t nuevaCap);

int vectorMostrar(Vector* vec, Imprimir imprFunc, int cant);


#endif // VECTOR_H_INCLUDED
