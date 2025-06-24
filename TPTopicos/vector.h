#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXITO 0
#define ERROR 1

#define DEFAULT_CAP 10
#define FACTOR_INCR 2
#define FACTOR_INCR_FILE 1.2

typedef int  (*Accion)(void*);
typedef void (*Imprimir)(const void*);
typedef int  (*Comparar)(const void*, const void*);
typedef int  (*FileRead)(FILE*, void*);
typedef int  (*FileWrite)(FILE*, void*);

typedef struct{
    void* data;
    size_t tamElem;
    size_t cantElem;
    size_t cap;
}Vector;

Vector* vectorCrear(Vector* vec, size_t tamElem);
int vectorDestruir(Vector* vec);

int vectorGuardarBinario(Vector* vec, const char* path);
int vectorCargarBinario(Vector* vec, const char* path);

int vectorGuardarTexto(Vector* vec, const char* path, FileRead fReadFunc);
int vectorCargarTexto(Vector* vec, const char* path, FileWrite fWriteFunc);

int vectorConcatenar(Vector* vecA, Vector* vecB);
int vectorBarajar(Vector* vecA, Vector* vecB);

int vectorAgregar(Vector* vec, void* elem);
int vectorEliminarUlt(Vector* vec);
void* vectorObtener(Vector* vec, size_t pos);
int vectorModificar(Vector* vec, void* elem, size_t pos);
int vectorVaciar(Vector* vec);

int vectorRedimensionar(Vector* vec, size_t nuevoCap);

int vectorOrdenar(Vector* vec, Comparar cmpFunc);
int vectorBuscar(Vector* vec, Comparar cmpFunc);
int intercambiar(void* a, void* b, size_t tamElem);

int vectorMostrar(Vector* vec, Imprimir imprFunc);
int vectorRecorrer(Vector* vec, Accion actFunc);

size_t vectorTam(Vector* vec);
size_t vectorCapacidad(Vector* vec);
int vectorVacio(Vector* vec);

#endif // VECTOR_H_INCLUDED
