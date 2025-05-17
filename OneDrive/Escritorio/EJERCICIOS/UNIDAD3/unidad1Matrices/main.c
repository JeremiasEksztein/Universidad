#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "matrices.h"

double sumaIJ(int i, int j);
double restaIJ(int i, int j);
double productoIJ(int i, int j);
double identidad(int i, int j);
double diagonal(int i, int j);
double numeroAleatorio(int i, int j);
double cero(int i, int j);

void printPrueba(char* nomPrueba, char* valorEsperado, double valorCalculado);
int testOne();
int testTwo();
int testThree();
int testFour();

int main()
{
    srand(time(NULL));

    //testOne();
    //testTwo();
    //testThree();
    //testFour();

    int** matriz = (int**)crearMatriz(sizeof(int), 10, 10);
   // int** basura = (int**)crearMatriz(sizeof(int), 10, 10);

    inicializarMatrizPartido(matriz, 10);
    //inicializarMatriz((double**)basura, 10, 10, numeroAleatorio);

    mostrarMatrizPartido(matriz, 10);
    //mostrarMatriz((double**)basura, 10, 10);

    int* puntuacion = generarTablaDePuntuacion(matriz, 10);

    for(int i = 0; i < 10; i++)
    {
        printf("\n%d", *(puntuacion + i));
    }

    printf("\n");

    //printf("%d\n", matrizDePartidosCorrecta(basura, 10));

    destruirMatriz((void**)matriz, 10);
    //destruirMatriz((void**)basura, 10);

    free(puntuacion);

    return 0;
}

double sumaIJ(int i, int j)
{
    return (double)(i + j);
}

double restaIJ(int i, int j)
{
    return (double)(i - j);
}

double productoIJ(int i, int j)
{
    return (double)(i * j);
}

double identidad(int i, int j)
{
    return (double)(i == j ? 1 : 0);
}

double diagonal(int i, int j)
{
    return (double)((i == j ? 1 : 0) * rand() % 100);
}

double numeroAleatorio(int i, int j)
{
    return (double)(rand() % 100);
}

double cero(int i, int j)
{
    return 0;
}

void printPrueba(char* nomPrueba, char* valorEsperado, double valorCalculado)
{
    printf("Prueba %s: Valor esperado = %s, Valor calculado = %0.2lf --", nomPrueba, valorEsperado, valorCalculado);
}

int testOne()
{
    double** matriz = (double**)crearMatriz(sizeof(double), 4, 4);
    double result;

    if(matriz == NULL)
    {
        free(matriz);
        return -1;
    }

    inicializarMatriz(matriz, 4, 4, sumaIJ);

    printf("Matriz\n");
    mostrarMatriz(matriz, 4, 4);

    printPrueba("Diagonal principal", "12.00", result = sumarDiagonalPrincipal(matriz, 4, 4));

    result != 12 ? printf("FALLO\n") : printf("PASO\n");

    printPrueba("Diagonal secundaria", "12.00", result = sumarDiagonalSecundaria(matriz, 4, 4));
    result != 12 ? printf("FALLO\n") : printf("PASO\n");

    printPrueba("Triangular superior DP", "30.00", result = sumarMatrizTriangularSuperiorDP(matriz, 4, 4));
    result != 30.00 ? printf("FALLO\n") : printf("PASO\n");

    printPrueba("Triangular inferior DP", "30.00", result = sumarMatrizTriangularInferiorDP(matriz, 4, 4));
    result != 30.00 ? printf("FALLO\n") : printf("PASO\n");

    printPrueba("Triangular superior DS", "30.00", result = sumarMatrizTriangularSuperiorDS(matriz, 4, 4));
    result != 20.00 ? printf("FALLO\n") : printf("PASO\n");

    printPrueba("Triangular inferior DS", "40.00", result = sumarMatrizTriangularInferiorDS(matriz, 4, 4));
    result != 40.00 ? printf("FALLO\n") : printf("PASO\n");

    destruirMatriz((void**)matriz, 4);

    return 0;
}

int testTwo()
{
    double** diag = (double**)crearMatriz(sizeof(double), 4, 4);
    double** iden = (double**)crearMatriz(sizeof(double), 4, 4);
    double** basura = (double**)crearMatriz(sizeof(double), 4, 4);

    double result;

    if(diag == NULL || iden == NULL || basura == NULL)
    {
        free(diag);
        free(iden);
        free(basura);
        return -1;
    }

    inicializarMatriz(diag, 4, 4, diagonal);
    inicializarMatriz(iden, 4, 4, identidad);
    inicializarMatriz(basura, 4, 4, numeroAleatorio);

    printf("Diagonal\n");
    mostrarMatriz(diag, 4, 4);

    printf("Identidad\n");
    mostrarMatriz(iden, 4, 4);

    printf("Basura\n");
    mostrarMatriz(basura, 4, 4);

    printPrueba("Es Matriz Diagonal - Diagonal", "1", result = esMatrizDiagonal(diag, 4, 4));
    result != 1 ? printf("FALLO\n") : printf("PASO\n");

    printPrueba("Es Matriz Diagonal - Identidad", "1", result = esMatrizDiagonal(iden, 4, 4));
    result != 1 ? printf("FALLO\n") : printf("PASO\n");

    printPrueba("Es Matriz Diagonal - Basura", "0", result = esMatrizDiagonal(basura, 4, 4));
    result == 1 ? printf("FALLO\n") : printf("PASO\n");


    printPrueba("Es Matriz Identidad - Diagonal", "0", result = esMatrizIdentidad(diag, 4, 4));
    result == 1 ? printf("FALLO\n") : printf("PASO\n");

    printPrueba("Es Matriz Identidad - Identidad", "1", result = esMatrizIdentidad(iden, 4, 4));
    result != 1 ? printf("FALLO\n") : printf("PASO\n");

    printPrueba("Es Matriz Identidad - Basura", "0", result = esMatrizIdentidad(basura, 4, 4));
    result == 1 ? printf("FALLO\n") : printf("PASO\n");


    return 0;
}

int testThree()
{
    double** matriz = (double**)crearMatriz(sizeof(double), 4, 4);
    double** basura = (double**)crearMatriz(sizeof(double), 4, 4);
    double result;

    if(matriz == NULL || basura == NULL)
    {
        free(matriz);
        free(basura);
        return -1;
    }

    inicializarMatriz(matriz, 4, 4, sumaIJ);
    inicializarMatriz(basura, 4, 4, numeroAleatorio);

    printf("Matriz simetrica\n");
    mostrarMatriz(matriz, 4, 4);

    printf("Basura\n");
    mostrarMatriz(basura, 4, 4);

    printPrueba("Es Matriz simetrica - Simetrica", "1", result = esMatrizSimetrica(matriz, 4, 4));
    result != 1 ? printf("FALLO\n") : printf("PASO\n");

    printPrueba("Es Matriz simetrica - Basura", "0", result = esMatrizSimetrica(basura, 4, 4));
    result == 1 ? printf("FALLO\n") : printf("PASO\n");

    printPrueba("Transponer matriz cuadrada - Simetrica", "IGUAL", 0.0);
    printf("\n");

    transponerMatrizCuadrada(matriz, 4, 4);
    mostrarMatriz(matriz, 4, 4);

    printf("\n");

    transponerMatrizCuadrada(basura, 4, 4);
    mostrarMatriz(basura, 4, 4);

    puts("");


    return 0;
}

int testFour()
{
    double** matriz_a = (double**)crearMatriz(sizeof(double), 4, 2);
    double** matriz_b = (double**)crearMatriz(sizeof(double), 2, 4);
    double** producto = NULL;

    if(matriz_a == NULL || matriz_b == NULL)
    {
        free(matriz_a);
        free(matriz_b);
        return -1;
    }

    inicializarMatriz(matriz_a, 4, 2, sumaIJ);
    inicializarMatriz(matriz_b, 2, 4, sumaIJ);

    mostrarMatriz(matriz_a, 4, 2);
    puts("");
    mostrarMatriz(matriz_b, 2, 4);

    producto = matrizProducto(matriz_a, matriz_b, 4, 2, 2, 4);

    puts("");
    mostrarMatriz(producto, 4, 4);

    return 0;
}
