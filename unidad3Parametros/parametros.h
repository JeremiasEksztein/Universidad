#ifndef PARAMETROS_H_INCLUDED
#define PARAMETROS_H_INCLUDED

#include <stddef.h>
#include <stdio.h>

//3.1

int menuGenerico(char** opciones, size_t n);
size_t cargarArregloDeFloat(float* arreglo, size_t tam, int (*operacion)(int), int (*condicion)(int));
float buscarMinimoFloat(float* arreglo, size_t tam);
float promedioParesFloat(float* arreglo, size_t tam);
float mostrarInversoFloat(float* arreglo, size_t tam);
char* guardarFloatEnTexto(float* arreglo, size_t tam);

#endif // PARAMETROS_H_INCLUDED
