#include "vector.h"

int vectorCrear(Vector* vec, size_t tamElem)
{
    vec->data = malloc(tamElem * DEFAULT_CAP);

    if(!(vec->data)) return ERR_MEMORIA;

    vec->tamElem = tamElem;
    vec->cantElem = 0;
    vec->cap = DEFAULT_CAP;

    return 0;
}

int vectorDestruir(Vector* vec)
{
    free(vec->data);
    vec->tamElem = 0;
    vec->cantElem = 0;
    vec->cap = 0;

    return 0;
}

int vectorAgregar(Vector* vec, void* elem)
{
    if(!elem) return ERR_MEMORIA;

    if(vec->cantElem >= vec->cap){
        if(!vectorRedimensionar(vec, vec->cap * FACTOR_INCR)) return ERR_MEMORIA;
    }

    char* i = vec->data + vec->cantElem * vec->tamElem;

    memcpy(i, elem, vec->tamElem);

    vec->cantElem++;

    return 0;
}

void* vectorObtener(Vector* vec, int pos)
{
    char* i = vec->data + pos * vec->tamElem;

    return i;
}

int vectorModificar(Vector* vec, void* elem, int pos)
{
    char* i = vec->data + pos * vec->tamElem;
    memcpy(i, elem, vec->tamElem);

    return 0;
}

int vectorOrdenar(Vector* vec, Comparar cmpFunc)
{
    qsort(vec->data, vec->cantElem, vec->tamElem, cmpFunc);

    return 0;
}

int vectorBusquedaLineal(Vector* vec, void* clave, Comparar cmpFunc)
{
    char* tmpDat = vec->data;
    char* tmpUlt = vec->data + vec->cantElem * vec->tamElem;
    char* tmpOri = vec->data;
    int pos = -1;

    while(tmpDat < tmpUlt && pos == -1){
        if(cmpFunc(tmpDat, clave) == 0){
            pos = (tmpDat - tmpOri) / vec->tamElem;
        }

        tmpDat += vec->tamElem;
    }

    return pos;
}

int vectorBusquedaBinaria(Vector* vec, void* clave, Comparar cmpFunc)
{
    char* ori = vec->data;
    char* li = vec->data;
    char* ls = vec->data + vec->cantElem * vec->tamElem;
    char* med = li + ((ls - li) / (2 * vec->tamElem)) * vec->tamElem;

    while(li <= ls && cmpFunc(med, clave) != 0){
        if(cmpFunc(med, clave) > 0){
            ls = med + vec->tamElem;
        }else{
            li = med + vec->tamElem;
        }

        med = li + ((ls - li) / (2 * vec->tamElem)) * vec->tamElem;
    }

    if(li == ls){
        return -1;
    }

    return ((med - ori) / vec->tamElem);
}

int vectorRedimensionar(Vector* vec, size_t nuevaCap)
{
    void* nuevoDat = realloc(vec->data, nuevaCap * vec->tamElem);

    if(!nuevoDat) return ERR_MEMORIA;

    vec->data = nuevoDat;
    vec->cap = nuevaCap;

    return 0;
}

int vectorMostrar(Vector* vec, Imprimir imprFunc, int cant)
{
    char* i = vec->data;
    char* ult = vec->data + cant * vec->tamElem;

    for(; i < ult; i += vec->tamElem){
        imprFunc(i);
    }

    return 0;
}
