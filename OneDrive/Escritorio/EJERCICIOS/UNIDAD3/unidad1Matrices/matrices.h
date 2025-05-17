#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

void** crearMatriz(size_t tam_elem, int filas, int columnas);
void inicializarMatriz(double** matriz, int filas, int columnas, double (*f)(int, int));
void mostrarMatriz(double** matriz, int filas, int columnas);
void destruirMatriz(void** matriz, int filas);

double sumarDiagonalPrincipal(double** matriz, int filas, int columnas); //Traza de la matriz
double sumarDiagonalSecundaria(double** matriz, int filas, int columnas);
double sumarMatrizTriangularSuperiorDP(double** matriz, int filas, int columnas);
double sumarMatrizTriangularInferiorDP(double** matriz, int filas, int columnas);
double sumarMatrizTriangularSuperiorDS(double** matriz, int filas, int columnas);
double sumarMatrizTriangularInferiorDS(double** matriz, int filas, int columnas);

int esMatrizDiagonal(double** matriz, int filas, int columnas);
int esMatrizIdentidad(double** matriz, int filas, int columnas);

int esMatrizSimetrica(double** matriz, int filas, int columnas);
void transponerMatrizCuadrada(double** matriz, int filas, int columnas);
double** transponerYCopiarMatriz(double** matriz, int filas, int columnas);

double** matrizProducto(double** matriz_a, double** matriz_b, int filas_a, int columnas_a, int filas_b, int columnas_b);

void inicializarMatrizPartido(int** matriz, int orden);
void mostrarMatrizPartido(int** matriz, int orden);
int matrizDePartidosCorrecta(int** matriz, int orden);
int* generarTablaDePuntuacion(int** matriz, int orden);

#endif // MATRICES_H_INCLUDED
