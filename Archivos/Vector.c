#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Vector.h"


bool redimensionarVector(Vector* vector, int operacion);
void ordenarBurbujeo(Vector* vector);
void ordenarSeleccion(Vector* vector, Cmp cmp);
void ordenarInsercion(Vector* vector);
void intercambiar(void* a, void* b, size_t tamElem);
void* buscarMenor(void* ini, void* fin, Cmp cmp, size_t tamElem);


bool vectorCrear(Vector* vector, size_t tamElem)
{
    vector->ce = 0;
    vector->vec = malloc(CAP_INI * tamElem);

    if(vector->vec == NULL)
    {
        vector->cap = 0;
        vector->tamElem = 0;
        return false;
    }

    vector->cap = CAP_INI;
    vector->tamElem = tamElem;

    return true;
}


int vectorCrearDeArchivo(Vector* vector, size_t tamElem, const char* nomArch)
{
    FILE* arch = fopen(nomArch, "rb");

    if(!arch){
        return ERR_ARCHIVO;
    }

    fseek(arch, 0L, SEEK_END);
    size_t tamArchivo = ftell(arch);

    vector->vec = malloc(tamArchivo);

    if(!vector->vec) return ERR_ARCHIVO;

    fread(vec, sizeof(tamElem), tamArchivo / tamElem, arch);

    fclose(arch);

    return TODO_OK;
}


int vectorGrabar(Vector* vector, const char* nomArch)
{

}


int vectorOrdInsertar(Vector* vector, const void* elem, Cmp cmp)
{
    if(vector->ce == vector->cap)
    {
        if(!redimensionarVector(vector, AUMENTAR))
        {
            return SIN_MEM;
        }
    }

    void* i = vector->vec;
    void* ult = vector->vec + (vector->ce - 1) * vector->tamElem;

    while(i <= ult && cmp(elem, i) > 0)
    {
        i += vector->tamElem;
    }

    if(i <= ult && cmp(elem, i) == 0) // Duplicado
    {
        return DUPLICADO;
    }

    void* posIns = i;

    for(i = ult; i >= posIns; i -= vector->tamElem) // Resolver con memmove.
    {
        memcpy(i + vector->tamElem, i, vector->tamElem);
    }

    memcpy(posIns, elem, vector->tamElem);

    vector->ce++;

    return TODO_OK;
}


int vectorInsertarAlFinal(Vector* vector, const void* elem)
{
    if(vector->ce == vector->cap)
    {
        if(!redimensionarVector(vector, AUMENTAR))
        {
            return SIN_MEM;
        }
    }

    void* posIns = vector->vec + vector->ce * vector->tamElem;
    memcpy(posIns, elem, vector->tamElem); // memmove cuando hay solapamiento.
    vector->ce++;

    return TODO_OK;
}


int vectorOrdBuscar(const Vector* vector, void* elem, Cmp cmp)
{
    if(vector->ce == 0)
    {
        return -1;
    }

    void* li = vector->vec;
    void* ls = vector->vec + (vector->ce - 1) * vector->tamElem;
    void* m = li + ((ls - li) / vector->tamElem / 2) * vector->tamElem;
    int comp;

    while(li <= ls && (comp = cmp(elem, m)) != 0)
    {
        if(comp < 0)
        {
            ls = m - vector->tamElem;
        }
        else // > 0
        {
            li = m + vector->tamElem;
        }

        m = li + ((ls - li) / vector->tamElem / 2) * vector->tamElem;
    }

    if(li > ls)
    {
        return -1;
    }

    memcpy(elem, m, vector->tamElem);

    return (m - vector->vec) / vector->tamElem;
}


void vectorOrdenar(Vector* vector, int metodo, Cmp cmp)
{
    switch(metodo)
    {
        case BURBUJEO:
            // ordenarBurbujeo(vector);
            break;

        case SELECCION:
            ordenarSeleccion(vector, cmp);
            break;

        case INSERCION:
            // ordenarInsercion(vector);
            break;

        case QSORT:
            qsort(vector->vec, vector->ce, vector->tamElem, cmp);
            break;
    }
}


// bool vectorOrdEliminar(Vector* vector, int elem)
// {
//     int posElim = vectorOrdBuscar(vector, elem);

//     if(posElim == -1)
//     {
//         return false;
//     }

//     vectorEliminarDePos(vector, posElim);

//     return true;
// }


// bool vectorEliminarDePos(Vector* vector, int pos)
// {
//     if(pos >= vector->ce)
//     {
//         return false;
//     }

//     int* ult = vector->vec + vector->ce - 1;

//     for(int* i = vector->vec + pos; i < ult; i++)
//     {
//         *i = *(i + 1);
//     }

//     vector->ce--;

//     if((float)vector->ce / vector->cap <= FACTOR_OCUP)
//     {
//         redimensionarVector(vector, DISMINUIR);
//     }

//     return true;
// }


void vectorDestruir(Vector* vector)
{
    free(vector->vec);
    vector->vec = NULL;
    vector->ce = 0;
    vector->cap = 0;
    vector->tamElem = 0;
}


bool redimensionarVector(Vector* vector, int operacion)
{
    size_t nuevaCap = operacion == AUMENTAR? vector->cap * FACTOR_INCR : max(vector->cap * FACTOR_DECR, CAP_INI);

    int* nVec = realloc(vector->vec, nuevaCap * vector->tamElem);

    if(!nVec)
    {
        return false;
    }

    printf("Redimensión de %lu, a %lu\n", vector->cap, nuevaCap);

    vector->vec = nVec;
    vector->cap = nuevaCap;

    return true;
}


size_t max(size_t a, size_t b)
{
    return a >= b? a : b;
}


void vectorMostrar(const Vector* vector, Imprimir imprimir)
{
    void* ult = vector->vec + (vector->ce - 1) * vector->tamElem;

    for(void* i = vector->vec; i <= ult; i += vector->tamElem)
    {
        imprimir(i);
    }

    putchar('\n');
}


// void ordenarBurbujeo(Vector* vector)
// {
//     int* ult = vector->vec + vector->ce - 1;
//     for(int i = 1, *limJ = ult - 1; i < vector->ce; i++, limJ--)
//     {
//         for(int* j = vector->vec; j <= limJ; j++)
//         {
//             if(*j > *(j + 1))
//             {
//                 intercambiar(j, j + 1);
//             }
//         }
//     }
// }


void ordenarSeleccion(Vector* vector, Cmp cmp)
{
    void* ult = vector->vec + (vector->ce - 1) * vector->tamElem;
    void* m;
    for(void* i = vector->vec; i < ult; i += vector->tamElem)
    {
        m = buscarMenor(i, ult, cmp, vector->tamElem);
        intercambiar(i, m, vector->tamElem);
    }
}


void* buscarMenor(void* ini, void* fin, Cmp cmp, size_t tamElem)
{
    void* m = ini;
    for(void* j = ini + tamElem; j <= fin; j += tamElem)
    {
        if(cmp(j, m) < 0)
        {
            m = j;
        }
    }

    return m;
}


// void ordenarInsercion(Vector* vector)
// {
//     int* ult = vector->vec + vector->ce - 1;
//     int elemAIns;
//     for(int* i = vector->vec + 1; i <= ult; i++)
//     {
//         elemAIns = *i;
//         int* j = i - 1;
//         while(j >= vector->vec && elemAIns < *j)
//         {
//             *(j + 1) = *j;
//             j--;
//         }

//         *(j + 1) = elemAIns;
//     }
// }


void intercambiar(void* a, void* b, size_t tamElem)
{
    void* aTemp = malloc(tamElem);
    memcpy(aTemp, a, tamElem);
    memcpy(a, b, tamElem);
    memcpy(b, aTemp, tamElem);
    free(aTemp);
}
