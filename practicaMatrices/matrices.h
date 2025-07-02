#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef int (*Inicializar)(void*);
typedef void (*Mostrar)(const void*);

void** crearMatriz(int filas, int columnas, int tamElem);
int destruirMatriz(void** matriz, int filas);
int inicializarMatriz(void** matriz, int filas, int columnas, Inicializar initMatFunc);
void mostrarMatriz(void** matriz, int filas, int columnas, Mostrar imprMatFunc);

#endif // MATRICES_H_INCLUDED
