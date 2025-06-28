#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comunesYErrores.h"
#include "cadenas.h"

#define CHECK_RANGO(x, min, max) ((x < min || x > max) ? 1 : 0)

#define BURBUJEO 0
#define SELECCION 1
#define INSERCION 2

#define BUSQUEDA_LINEAL 0
#define BUSQUEDA_BINARIA 1

#define DEFAULT_SIZE 10
#define FACTOR_INCR 2

typedef int (*FileReadText)(FILE*, void*);
typedef int (*FileWriteText)(FILE*, void*);
typedef void (*Imprimir)(const void*);
typedef void (*Accion)(void*);
typedef int (*Comparar)(const void*, const void*);

typedef struct{
    void* data;
    size_t tamElem;
    size_t cantElem;
    size_t cap;
}Vector;

int vectorCrear(Vector* vec, size_t tamElem);
void vectorDestruir(Vector* vec);

int vectorGuardarTexto(Vector* vec, const char* path, FileReadText fReadFunc);
int vectorCargarTexto(Vector* vec, const char* path, FileWriteText fWriteFunc);
int vectorGuardarBinario(Vector* vec, const char* path);
int vectorCargarBinario(Vector* vec, const char* path);

void* vectorObtener(Vector* vec, size_t pos);
int vectorAgregar(Vector* vec, void* elem);
int vectorModificar(Vector* vec, void* newElem, size_t pos);
int vectorEliminarUlt(Vector* vec);
int vectorEliminarPrimero(Vector* vec);
int vectorConcatenar(Vector* vecA, Vector* vecB);
int vectorVaciar(Vector* vec);

int vectorRedimensionar(Vector* vec, size_t nuevaCap);

int vectorOrdenar(Vector* vec, Comparar cmpFunc, int metodo);
int vectorBuscar(Vector* vec, void* clave, Comparar cmpFunc, int metodo);

int vectorMostrar(Vector* vec, Imprimir imprFunc);
int vectorRecorrer(Vector* vec, Accion accFunc);

size_t vectorTam(Vector* vec);
size_t vectorCapacidad(Vector* vec);
int vectorVacio(Vector* vec);

#endif // VECTOR_H_INCLUDED
