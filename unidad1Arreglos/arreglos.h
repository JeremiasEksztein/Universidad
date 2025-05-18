#ifndef ARREGLOS_H_INCLUDED
#define ARREGLOS_H_INCLUDED

#include <stddef.h>

int* rightShiftArray(int* arreglo, int indice, size_t tam);
int* leftShifhtArray(int* arreglo, int indice, size_t tam);

int insertarEnArregloInt(int arreglo[], int elem, int pos, size_t largo);
int insertarEnArregloAscInt(int arreglo[], int elem, size_t largo);
int eliminarPosicionEnArregloInt(int arreglo[], int pos, size_t largo);
int eliminarElementoEnArregloInt(int arreglo[], int elem, size_t largo);
int eliminarElementosEnArregloInt(int arreglo[], int elem, size_t largo);

int bubbleSort(int arreglo[], size_t largo);

//Gracias Pujia
void* rightShiftArrayVoid(void* arreglo, int indice, size_t largo, size_t tam_elem);
void* leftShifhtArrayVoid(void* arreglo, int indice, size_t largo, size_t tam_elem);

int insertarEnArregloVoid(void* arreglo, void* elem, size_t largo, size_t tam_elem);
int insertarEnArregloAscVoid(void* arreglo, void* elem, size_t largo, size_t tam_elem);
int eliminarEnArregloVoid(void* arreglo, int pos, size_t largo, size_t tam_elem);
int eliminarElementoEnArregloVoid(void* arreglo, void* elem, size_t largo, size_t tam_elem);
int eliminarElementosEnArregloVoid(void* arreglo, void* elem, size_t largo, size_t tam_elem);

#endif // ARREGLOS_H_INCLUDED
