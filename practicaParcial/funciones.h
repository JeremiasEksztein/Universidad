#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "secuenciaPalabras.h"
#include "comunes.h"

#define BUFFER_TAM 256

typedef struct{
    char str[PALABRA_TAM];
    size_t cont;
}Entrada;

int procesarManuscrito(Vector* vec, char* path);

int compararEntradasStr(const void* lhs, const void* rhs);
int compararEntradasCont(const void* lhs, const void* rhs);
void imprimirEntradas(const void* elem);

#endif // FUNCIONES_H_INCLUDED
