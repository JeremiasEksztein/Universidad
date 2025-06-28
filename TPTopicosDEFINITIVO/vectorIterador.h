#ifndef VECTORITERADOR_H_INCLUDED
#define VECTORITERADOR_H_INCLUDED

#include "vector.h"

typedef struct{
    void* cursor;
    Vector* vec;
    void* fin;
    int esFin;
}VectorIterador;

int vectorIteradorCrear(VectorIterador* iter, Vector* vec);
void* vectorIteradorPrimero(VectorIterador* iter);
void* vectorIteradorSiguiente(VectorIterador* iter);
void* vectorIteradorMover(VectorIterador* iter, int offset);
int vectorIteradorFin(VectorIterador* iter);

/* Confuso
int vectorIteradorCrear(VectorIterador* iter, Vector* vec);
void vectorIteradorDestruir(VectorIterador* iter);

int vectorIteradorMover(VectorIterador* iter, size_t nuevaPos);
void* vectorIteradorLeer(VectorIterador* iter);
int vectorIteradorEscribir(VectorIterador* iter, void* elem);
int vectorIteradorReiniciar(VectorIterador* iter);

size_t vectorIteradorPosCursor(VectorIterador* iter);
int vectorIteradorFin(VectorIterador* iter);
*/

#endif // VECTORITERADOR_H_INCLUDED
