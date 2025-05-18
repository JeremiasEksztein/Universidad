#ifndef ARREGLOS_H_INCLUDED
#define ARREGLOS_H_INCLUDED

#include <stddef.h>

int insertarEnArregloInt(int arreglo[], int elem, int pos, int largo);
int insertarEnArregloAscInt(int arreglo[], int elem, int largo);
int eliminarPosicionEnArregloInt(int arreglo[], int pos, int largo);
int eliminarElementoEnArregloInt(int arreglo[], int elem, int largo);
int eliminarElementosEnArregloInt(int arreglo[], int elem, int largo);

int bubbleSort(int arreglo[], int largo);

int insertarEnArregloVoid(void* arreglo, void* elem, int largo, size_t tam_elem);
int insertarEnArregloAscVoid(void* arreglo, void* elem, int largo, size_t tam_elem);
int eliminarEnArregloVoid(void* arreglo, size_t pos, int largo, size_t tam_elem);
int eliminarElementoEnArregloVoid(void* arreglo, void* elem, int largo, size_t tam_elem);
int eliminarElementosEnArregloVoid(void* arreglo, void* elem, int largo, size_t tam_elem);

#endif // ARREGLOS_H_INCLUDED
