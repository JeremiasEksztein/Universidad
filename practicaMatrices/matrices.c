#include "matrices.h"

void** crearMatriz(int filas, int columnas, int tamElem)
{
    void** mat = malloc(filas * sizeof(void*));

    if(!mat) return NULL;

    void** i = mat;
    void** ult = mat + filas - 1;

    for(; i < ult; i++){
        *i = malloc(filas * tamElem);

        if(!i){
            destruirMatriz(mat, i - mat);
            return NULL;
        }
    }

    return mat;
}

int destruirMatriz(void** matriz, int filas)
{
    void** ult = matriz + filas - 1;

    for(void** i = matriz; i < ult; i++){
        free(*i);
    }

    free(matriz);

    return 0;
}

int inicializarMatriz(void** matriz, int filas, int columnas, Inicializar initMatFunc)
{
    int i, j;

    for(i = 0; i < filas; i++){
        for(j = 0; j < columnas; j++){
            initMatFunc((matriz[i] + j));
        }
    }

    return  0;
}

void mostrarMatriz(void** matriz, int filas, int columnas, Mostrar imprMatFunc)
{
    int i, j;

    for(i = 0; i < filas; i++){
        for(j = 0; j < columnas; j++){
            imprMatFunc((matriz[i] + j));
        }

        printf("\n");
    }
}
