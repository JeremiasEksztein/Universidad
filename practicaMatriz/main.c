#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void** crearMatriz(size_t tamElem, int filas, int columnas);
int destruirMatriz(void** matriz, int filas);
int inicializarMatrizAlea(int** matriz, int filas, int columnas);
int mostrarMatriz(int ** matriz, int filas, int columnas);

int sumaDiagonal(int** matriz, int filas, int columnas);

int main()
{
    srand(time(NULL));

    int** matriz = (int**)crearMatriz(sizeof(int), 4, 4);

    inicializarMatrizAlea(matriz, 4, 4);
    mostrarMatriz(matriz, 4, 4);

    printf("%d\n", sumaDiagonal(matriz, 4, 4));

    destruirMatriz((void**)matriz, 4);

    return 0;
}

void** crearMatriz(size_t tamElem, int filas, int columnas)
{
    void** mat = malloc(filas * sizeof(void*));

    if(!mat) return NULL;

    void** i;
    void** ult = mat + filas - 1;

    for(i = mat; i <= ult; i++){
        *i = malloc(columnas * tamElem);

        if(!*i){
            destruirMatriz(mat, i - mat);
            return NULL;
        }
    }

    return mat;
}

int destruirMatriz(void** matriz, int filas)
{
    void** ult = matriz + filas - 1;
    void** i = matriz;

    for(;i <= ult; i++){
        free(*i);
    }

    free(matriz);

    return 0;
}

int inicializarMatrizAlea(int** matriz, int filas, int columnas)
{
    int i, j;

    for(i = 0; i < filas; i++){
        for(j = 0; j < columnas; j++){
            matriz[i][j] = rand() % 10;
        }
    }

    return 0;
}

int mostrarMatriz(int** matriz, int filas, int columnas)
{
    int i, j;

    for(i = 0; i < filas; i++){
        for(j = 0; j < filas; j++){
            printf("%3d\t", matriz[i][j]);
        }

        puts("");
    }

    return 0;
}

int sumaDiagonal(int** matriz, int filas, int columnas)
{
    int i, suma = 0;

    for(i = 0; i < filas; i++){
        suma += matriz[i][i];
    }

    return suma;
}

int sumaTriSup(int** matriz, int filas, int columnas)
{
    int i, limI, j, suma = 0;

    for(i = filas - 1; )


    return suma;
}


