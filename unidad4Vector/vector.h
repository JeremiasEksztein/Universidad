#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CREACION 10

typedef struct{
    void* vec;
    size_t cap;
    size_t tamElem;
    size_t ce;
}Vector;

bool crearVector(Vector* vec, size_t tamElem);
void destruirVector(Vector* vec);

#endif // VECTOR_H_INCLUDED
