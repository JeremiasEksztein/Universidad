#ifndef VECTORITERADOR_H_INCLUDED
#define VECTORITERADOR_H_INCLUDED

#include "vector.h"

typedef struct{
    void* cursor;
    void* ini;
    void* fin;
    int esFin;
}VectorIterador;

int vectorIteradorCrear(VectorIterador* iter, Vector* vec);
void vectorIteradorDestruir(VectorIterador* iter);

int vectorIteradorMover(VectorIterador* iter, size_t nuevaPos);
void* vectorIteradorLeer(VectorIterador* iter);
int VectorIteradorEscribir(VectorIterador* iter, void* elem);
int VectorIteradorReiniciar(VectorIterador* iter);

size_t vectorIteradorPosCursor(VectorIterador* iter);
int VectorIteradorFin(VectorIterador* iter);

#endif // VECTORITERADOR_H_INCLUDED
