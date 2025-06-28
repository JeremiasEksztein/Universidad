#include "vector.h"

void bubbleSort(Vector* vec, Comparar cmpFunc);
void selectionSort(Vector* vec, Comparar cmpFunc);
void insertionSort(Vector* vec, Comparar cmpFunc);

int busquedaLineal(Vector* vec, void* clave, Comparar cmpFunc);
int busquedaBinaria(Vector* vec, void* clave, Comparar cmpFunc);

void bubbleSort(Vector* vec, Comparar cmpFunc)
{
    char* i = vec->data;
    char* j;
    char* ult = vec->data + (vec->cantElem - 1) * vec->tamElem;
    char* limJ = ult;

    for(; i < ult; i += vec->tamElem){
        for(j = vec->data; j < limJ; j += vec->tamElem, limJ -= vec->tamElem){
            if(cmpFunc(j, j + vec->tamElem) > 0){
                memoryIntercambiar(j, j + vec->tamElem, vec->tamElem);
            }
        }
    }
}

void selectionSort(Vector* vec, Comparar cmpFunc)
{


}

void insertionSort(Vector* vec, Comparar cmpFunc)
{


}

int busquedaLineal(Vector* vec, void* clave, Comparar cmpFunc)
{
    char* i = vec->data;
    char* ult = vec->data + (vec->cantElem) * vec->tamElem;
    int pos = -1;

    while(i < ult && pos == -1){
        if(cmpFunc(i, clave) == 0){
            pos = (i - (char*)vec->data) / vec->tamElem;
        }

        i++;
    }

    return pos;
}

int busquedaBinaria(Vector* vec, void* clave, Comparar cmpFunc)
{
    char* ori = vec->data;
    char* li = vec->data;
    char* ls = vec->data + (vec->cantElem) * vec->tamElem;
    char* med = li + ((ls - li) / (2 * vec->tamElem)) + vec->tamElem;

    while(li <= ls && cmpFunc(med, clave) != 0){
        if(cmpFunc(med, clave) > 0){
            li = med - vec->tamElem;
        }else if(cmpFunc(med, clave) < 0){
            ls = med + vec->tamElem;
        }

        med = li + ((ls - li) / (2 * vec->tamElem)) + vec->tamElem;
    }

    if(li > ls){
        return -1;
    }

    return (med - ori) / vec->tamElem;
}


int vectorCrear(Vector* vec, size_t tamElem)
{
    vec->data = malloc(DEFAULT_SIZE * tamElem);

    if(!(vec->data)) return ERR_MEMORIA;

    vec->cantElem = 0;
    vec->tamElem = tamElem;
    vec->cap = DEFAULT_SIZE;

    return EXITO;
}

int vectorGuardarTexto(Vector* vec, const char* path, FileReadText fReadFunc)
{
    FILE* arch = fopen(path, "rt");

    if(!arch) return ERR_ARCHIVO;

    char* tmpBuf = malloc(vec->tamElem);

    if(!tmpBuf) return ERR_MEMORIA;

    while(!feof(arch)){
        fReadFunc(arch, tmpBuf);
        vectorAgregar(vec, tmpBuf);
    }

    fclose(arch);
    free(tmpBuf);

    return EXITO;
}

int vectorCargarTexto(Vector* vec, const char* path, FileWriteText fWriteFunc)
{
    FILE* arch = fopen(path, "wt");

    if(!arch) return ERR_ARCHIVO;

    char* i = vec->data;
    char* ult = vec->data + (vec->cantElem - 1) * vec->tamElem;

    for(; i < ult; i += vec->tamElem){
        fWriteFunc(arch, i);
    }

    fclose(arch);

    return EXITO;
}

int vectorGuardarBinario(Vector* vec, const char* path)
{
    FILE* arch = fopen(path, "rb");

    if(!arch) return ERR_ARCHIVO;

    fseek(arch, 0, SEEK_END);

    size_t cantRegistros = ftell(arch) / vec->tamElem;
    if(cantRegistros > vec->cap){
        if(!vectorRedimensionar(vec, vec->cap * FACTOR_INCR)) return ERR_MEMORIA;
    }

    fread(vec->data, vec->tamElem, cantRegistros, arch);

    fclose(arch);

    return EXITO;
}

int vectorCargarBinario(Vector* vec, const char* path)
{
    FILE* arch = fopen(path, "wb");

    if(!arch) return ERR_ARCHIVO;

    fwrite(vec->data, vec->tamElem, vec->cantElem, arch);

    fclose(arch);

    return EXITO;
}

void* vectorObtener(Vector* vec, size_t pos)
{
    if(CHECK_RANGO(pos, 0, vec->cantElem)) return NULL;

    char* tmpData = vec->data;

    tmpData += pos * vec->tamElem;

    return tmpData;
}

int vectorAgregar(Vector* vec, void* elem)
{
    if(vec->cantElem == vec->cap){
        if(vectorRedimensionar(vec, vec->cap * FACTOR_INCR)) return ERR_MEMORIA;
    }

    char* tmpData = vec->data;

    tmpData += vec->cantElem * vec->tamElem;

    memcpy(tmpData, elem, vec->tamElem);

    vec->cantElem++;

    return EXITO;
}

int vectorModificar(Vector* vec, void* newElem, size_t pos)
{
    if(CHECK_RANGO(pos, 0, vec->cantElem)) return ERR_MAL_INGRESO;

    char* tmpData = vec->data;

    tmpData += pos * vec->tamElem;

    memoryIntercambiar(tmpData, newElem, vec->tamElem);

    return EXITO;
}

int vectorEliminarUlt(Vector* vec)
{
    if(vec->cantElem == 0) return ERR_MAL_INGRESO;

    vec->cantElem--;

    return EXITO;
}

int vectorConcatenar(Vector* vecA, Vector* vecB)
{
    if(vecA->tamElem != vecB->tamElem) return ERR_MAL_INGRESO;

    if(vecA->cap <= (vecA->cantElem + vecB->cantElem)){
        if(vectorRedimensionar(vecA, (vecA->cap + vecB->cap) * FACTOR_INCR)) return ERR_MEMORIA;
    }

    char* tmpUltA = vecA->data + (vecA->cantElem) * vecA->tamElem;
    char* tmpPriB = vecB->data;

    memcpy(tmpUltA, tmpPriB, vecB->cantElem * vecB->tamElem);

    return EXITO;
}

int vectorVaciar(Vector* vec)
{
    if(vec->cantElem == 0) return ERR_MAL_INGRESO;

    vec->cantElem = 0;

    return EXITO;
}

int vectorRedimensionar(Vector* vec, size_t nuevaCap)
{
    void* tmpNew = realloc(vec->data, nuevaCap * vec->tamElem);

    if(!tmpNew) return ERR_MEMORIA;

    vec->data = tmpNew;
    vec->cap = nuevaCap;

    return EXITO;
}

int vectorOrdenar(Vector* vec, Comparar cmpFunc, int metodo)
{
    switch(metodo){
    case BURBUJEO:
        bubbleSort(vec, cmpFunc);
        break;
    case SELECCION:
        selectionSort(vec, cmpFunc);
        break;
    case INSERCION:
        insertionSort(vec, cmpFunc);
        break;
    default:
        return ERR_MAL_INGRESO;
    }

    return EXITO;
}

int vectorBuscar(Vector* vec, void* clave, Comparar cmpFunc, int metodo)
{
    size_t pos = -1;

    switch(metodo){
    case BUSQUEDA_LINEAL:
        pos = busquedaLineal(vec, clave, cmpFunc);
        break;
    case BUSQUEDA_BINARIA:
        pos = busquedaBinaria(vec, clave, cmpFunc);
        break;
    default:
        return ERR_MAL_INGRESO;
    }

    return pos;
}

int vectorMostrar(Vector* vec, Imprimir imprFunc)
{
    char* i = vec->data;
    char* ult = vec->data + (vec->cantElem) * vec->tamElem;

    for(; i < ult; i++){
        imprFunc(i);
    }

    return EXITO;
}

int vectorRecorrer(Vector* vec, Accion accFunc)
{
    char* i = vec->data;
    char* ult = vec->data + (vec->cantElem) * vec->tamElem;

    for(; i < ult; i += vec->tamElem){
        accFunc(i);
    }

    return EXITO;
}

size_t vectorTam(Vector* vec)
{
    return vec->cantElem;
}

size_t vectorCapacidad(Vector* vec)
{
    return vec->cap;
}

int vectorVacio(Vector* vec)
{
    return (!(vec->cantElem));
}

void vectorDestruir(Vector* vec)
{
    free(vec->data);

    vec->tamElem = 0;
    vec->cantElem = 0;
    vec->cap = 0;
}
