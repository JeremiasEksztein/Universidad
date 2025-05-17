#include "matrices.h"

//GENERAL

void** crearMatriz(size_t tam_elem, int filas, int columnas)
{
    int i;

    void** matriz = malloc(filas * sizeof(void*));

    if(matriz == NULL)
    {
        free(matriz);
        return NULL;
    }

    for(i = 0; i < filas; i++)
    {
        *(matriz + i) = malloc(columnas * tam_elem);

        if(*(matriz + i) == NULL)
        {
            destruirMatriz(matriz, filas);
            return NULL;
        }

    }

    return matriz;
}

void inicializarMatriz(double** matriz, int filas, int columnas, double (*f)(int, int))
{
    int i, j;

    for(i = 0; i < filas; i++)
    {
        for(j = 0; j < columnas; j++)
        {
            matriz[i][j] = f(i,j);
        }
    }
}

void mostrarMatriz(double** matriz, int filas, int columnas)
{
    int i, j;

    for(i = 0; i < filas; i++)
    {
        for(j = 0; j < columnas; j++)
        {
            printf("%5.1f", matriz[i][j]);
        }

        printf("\n");
    }
}

void destruirMatriz(void** matriz, int filas)
{
    int i;

    for(i = 0; i < filas; i++)
    {
        free(*(matriz + i));
    }

    free(matriz);
}


//1.12, 1.13


double sumarDiagonalPrincipal(double** matriz, int filas, int columnas)
{
    int i;
    double sum = 0;

    for(i = 0; i < filas; i++)
    {
        sum += matriz[i][i];
    }

    return sum;
}

double sumarDiagonalSecundaria(double** matriz, int filas, int columnas)
{
    int i, j;
    double sum = 0;

    for(i = 0, j = filas - 1; i < filas; i++, j--)
    {
        sum += matriz[i][j];
    }

    return sum;
}

double sumarMatrizTriangularSuperiorDP(double** matriz, int filas, int columnas)
{
    int i, j, j_lim;
    double sum = 0;

    for(i = 0, j_lim = -1; i < filas; i++, j_lim++)
    {
        for(j = filas - 1; j > j_lim; j--)
        {
            sum += matriz[i][j];
        }

    }

    /*
    for(i = 0; i < filas; i++)
    {
        for(j = 0; j < filas; j++)
        {
            if(i < j) cont += matriz[i][j];
        }
    }*/

    return sum;
}

double sumarMatrizTriangularInferiorDP(double** matriz, int filas, int columnas)
{
    int i, j, j_lim;
    double sum = 0;

    for(i = 0, j_lim = 1; i < filas; i++, j_lim++)
    {
        for(j = 0; j < j_lim; j++)
        {
            sum += matriz[i][j];
        }
    }

    return sum;
}

double sumarMatrizTriangularSuperiorDS(double** matriz, int filas, int columnas)
{
    int i, j, j_lim;
    double sum = 0;

    for(i = 0, j_lim = filas; i < filas; i++, j_lim--)
    {
        for(j = 0; j < j_lim; j++)
        {
            sum += matriz[i][j];
        }
    }

    return sum;
}

double sumarMatrizTriangularInferiorDS(double** matriz, int filas, int columnas)
{
    int i, j, j_lim;
    double sum = 0;

    for(i = 0, j_lim = filas - 2; i < filas; i++, j_lim--)
    {
        for(j = filas - 1; j > j_lim; j--)
        {
            sum += matriz[i][j];
        }
    }

    return sum;
}


//1.13, 1.14

int esMatrizDiagonal(double** matriz, int filas, int columnas)
{
    int i = 0, j = 0, fallo = 0, diagonal = 0;

    while(fallo == 0 && i < filas)
    {
        while(fallo == 0 && j < filas)
        {
            if(i != j)
            {
                fallo = matriz[i][j] ? 1 : 0;
            }
            else
            {
                diagonal += matriz[i][j] ? 1 : 0;
            }

            j++;
        }

        i++;
        j = 0;
    }

    return (!fallo && !(diagonal % filas));
}

int esMatrizIdentidad(double** matriz, int filas, int columnas)
{
    int i = 0, j = 0, fallo = 0, diagonal = 0;

    while(fallo == 0 && diagonal <= filas && i < filas)
    {
        while(fallo == 0 && diagonal <= filas && j < filas)
        {
            if(i != j)
            {
                fallo = matriz[i][j] ? 1 : 0;
            }
            else
            {
                diagonal += matriz[i][j];
            }

            j++;
        }

        i++;
        j = 0;
    }

    if(diagonal != filas || fallo != 0) return 0;

    return 1;
}

int esMatrizSimetrica(double** matriz, int filas, int columnas)
{
    int i = 0, j;

    while(i < (filas / 2))
    {
        while(j < (filas / 2))
        {
            if(matriz[i][j] != matriz[j][i]) return 0;

            j++;
        }

        i++;
        j = 0;
    }

    return 1;
}

void transponerMatrizCuadrada(double** matriz, int filas, int columnas)
{
    int i, j, j_lim;
    double aux;


    for(i = 0, j_lim = -1; i < filas; i++, j_lim++)
    {
        for(j = filas - 1; j > j_lim; j--)
        {
            aux = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = aux;
        }

    }

/*
    for(i = 0; i < filas; i++)
    {
        for(j = 0; j < filas; j++)
        {
            if(i != j)
            {
                aux = matriz[i][j];
                matriz[i][j] = matriz[j][i]; //Creo que esto no hace nada
                matriz[j][i] = aux;
            }

        }

    }*/
}

/*double** transponerYCopiarMatriz(double** matriz, int filas, int columnas)
{
    int i, j;
    double aux;

    double** transpuesta = (double**)crearMatriz(sizeof(double), columnas, filas);

    if(transpuesta == NULL)
    {
        free(transpuesta);
        return NULL;
    }








}*/

//1.19

double suma(int i, int j)
{
    return 0;
}

double** matrizProducto(double** matriz_a, double** matriz_b, int filas_a, int columnas_a, int filas_b, int columnas_b)
{
    int i, j, k;

    double** producto = (double**)crearMatriz(sizeof(double), filas_a, columnas_b);

    inicializarMatriz(producto, filas_a, columnas_b, suma);

    if(producto == NULL)
    {
        free(producto);
        return NULL;
    }

    for(i = 0; i < filas_a; i++)
    {
        for(j = 0; j < columnas_b; j++)
        {
            for(k = 0; k < columnas_a; k++)
            {
                producto[i][j] += matriz_a[i][k] * matriz_b[k][j];
            }
        }
    }

    //mostrarMatriz(producto, filas_a, columnas_b);

    return producto;
}

//1.20

void inicializarMatrizPartido(int** matriz, int orden)
{
    int i, j, aux;

    for(i = 0; i < orden; i++)
    {
        for(j = orden - 1; j >= i; j--)
        {
            if(i != j)
            {
                aux = rand() % 3;

                //printf("%d\n", aux);

                if(aux == 0)
                {
                    matriz[i][j] = 0;
                    matriz[j][i] = 3;
                }
                else if(aux == 1)
                {
                    matriz[i][j] = 3;
                    matriz[j][i] = 0;
                }
                else
                {
                    matriz[i][j] = 1;
                    matriz[j][i] = 1;
                }
            }
            if(i == j)
            {
                matriz[i][j] = 0;
            }
        }
    }
}

void mostrarMatrizPartido(int** matriz, int orden)
{
    int i, j;

    for(i = 0; i < orden; i++)
    {
        for(j = 0; j < orden; j++)
        {
            printf("%3d", matriz[i][j]);
        }

        printf("\n");
    }
}

int matrizDePartidosCorrecta(int** matriz, int orden)
{
    int i = 0, j, fallo = 0;

    while(i < orden && !fallo)
    {

        j = orden - 1;
        while(j >= i && !fallo)
        {
            if(matriz[i][i] != 0) fallo = 1;

            if(matriz[i][j] == 0 && matriz[j][i] != 3) fallo = 1;

            if(matriz[i][j] == 1 && matriz[j][i] != 1) fallo = 1;

            if(matriz[i][j] == 3 && matriz[j][i] != 0) fallo = 1;

            j--;
        }

        i++;
    }

    return !fallo;
}

int* generarTablaDePuntuacion(int** matriz, int orden)
{
    int i, j, sum;

    int* puntuacion = (int*)malloc(sizeof(int) * orden);

    if(puntuacion == NULL) return NULL;

    for(i = 0; i < orden; i++)
    {
        sum = 0;

        for(j = 0; j < orden; j++)
        {
            sum += matriz[i][j];
        }

        //puntuacion[i] = sum;
        //printf("%3d", puntuacion[i]);
        *(puntuacion + i) = sum;
        //printf("%3d", *(puntuacion + i));
    }

    return puntuacion;
}
