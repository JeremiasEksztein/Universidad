#include "vector.h"

int bubbleSort(Vector* vec, Comparar cmpFunc);
int selectionSort(Vector* vec, Comparar cmpFunc);
int insertionSort(Vector* vec, Comparar cmpFunc);

int linearSearch(Vector* vec, void* clave, Comparar cmpFunc);
int binarySearch(Vector* vec, void* clave, Comparar cmpFunc);

//Probado
int bubbleSort(Vector* vec, Comparar cmpFunc)
{
    char* i = vec->data;
    char* j;
    char* ult = vec->data + (vec->cantElem - 1) * vec->tamElem;
    char* limJ = ult;

    for(; i < ult; i += vec->tamElem, limJ -= vec->tamElem){
        for(j = vec->data; j < limJ; j+=vec->tamElem){
            if(cmpFunc(j, j + vec->tamElem) > 0){
                intercambiar(j, j + vec->tamElem, vec->tamElem);
            }
        }
    }

    return EXITO;
}

int selectionSort(Vector* vec, Comparar cmpFunc)
{
    char* i = vec->data;
    char* j = i;
    char* ult = vec->data + (vec->cantElem - 1) * vec->tamElem;
    char* min = NULL;

    for(; i < ult; i += vec->tamElem){
        min = i;

        for(j = i + vec->tamElem; j < (ult + vec->tamElem); j += vec->tamElem){
            if(cmpFunc(j, min) > 0){
                min = j;
            }
        }

        intercambiar(i, min, vec->tamElem);
    }

    return EXITO;
}


/*
int selectionSort(Vector* vec, Comparar cmpFunc)
{
    char* tmpI = vec->data;
    char* tmpJ = tmpI;
    char* tmpUlt = vec->data + (vec->cantElem - 1) * vec->tamElem;
    char* tmpMin = tmpI;

    for(; tmpI < tmpUlt; tmpI += vec->tamElem){
        tmpMin = tmpI;
        for(tmpJ = tmpI + vec->tamElem; tmpJ < (tmpUlt + vec->tamElem); tmpJ += vec->tamElem){
            if(cmpFunc(tmpJ, tmpMin) < 0){
                tmpMin = tmpJ;
            }
        }

        intercambiar(tmpI, tmpMin, vec->tamElem);
    }

    return EXITO;
}*/

//Probado
int insertionSort(Vector* vec, Comparar cmpFunc)
{
    char* ori = vec->data;
    char* i = vec->data;
    char* ult = vec->data + (vec->cantElem) * vec->tamElem;
    char* j;

    while(i < ult){
        j = i;
        while(j > ori && cmpFunc(j - vec->tamElem, j) > 0){
            intercambiar(j, j - vec->tamElem, vec->tamElem);
            j -= vec->tamElem;
        }

        i += vec->tamElem;
    }

    /*


    char* tmpUlt = vec->data + (vec->cantElem - 1) * vec->tamElem;

    char* tmpI, *tmpJ, *tmpElem;

    tmpElem = malloc(vec->tamElem);

    if(!tmpElem) return ERROR;

    for(tmpI = vec->data + vec->tamElem; tmpI < tmpUlt; tmpI += vec->tamElem){
        memcpy(tmpElem, tmpI, vec->tamElem);
        tmpJ = tmpI - vec->tamElem;

        while(tmpJ >= (char*) vec->data && cmpFunc(tmpJ, tmpElem) > 0){
            tmpJ -= vec->tamElem;
        }

        memmove(tmpJ + vec->tamElem * 2, tmpJ + vec->tamElem, tmpI - (tmpJ - vec->tamElem));
        memcpy(tmpJ + vec->tamElem, tmpElem, vec->tamElem);
    }

    free(tmpElem);
    */

    return EXITO;
}

//Probado
int linearSearch(Vector* vec, void* clave, Comparar cmpFunc)
{
    int pos = -1, i = 0;
    char* tmpData = vec->data;
    char* tmpUlt = vec->data + (vec->cantElem - 1) * vec->tamElem;

    while(tmpData < tmpUlt && pos == -1){
        if(!cmpFunc(tmpData, clave)){
            pos = i;
        }
        i++;
        tmpData += vec->tamElem;
    }

    return pos;
}

int binarySearch(Vector* vec, void* clave, Comparar cmpFunc)
{
    /*
    char* ori = vec->data;
    char* li = vec->data;
    char* ls = vec->data - (vec->cantElem) * vec->tamElem;

    while(li <= ls){
        char* m = li + ((ls - li) / (2 * vec->tamElem));

        if(cmpFunc(m, clave) < 0){
            li = m + vec->tamElem;
        }else if(cmpFunc(m, clave) > 0){
            ls = m - vec->tamElem;
        }else{
            return (m - ori);
        }
    }

    return -1;
*/


    if(vec->cantElem == 0) return ERROR;

    char* tmpLI = vec->data;
    char* tmpLS = vec->data + (vec->cantElem) * vec->tamElem;
    char* tmpMed = tmpLI +  ((tmpLS - tmpLI) / (2 * vec->tamElem)) + vec->tamElem;
    char* tmpOri = vec->data;

    while(tmpLI <= tmpLS && cmpFunc(clave, tmpMed) != 0){
        if(cmpFunc(clave, tmpMed) > 0){
            tmpLI = tmpMed + vec->tamElem;
        }else{
            tmpLS = tmpMed - vec->tamElem;
        }

        tmpMed = tmpLI + ((tmpLS - tmpLI) / (2 * vec->tamElem)) + vec->tamElem;
    }

    if(tmpLI > tmpLS){
        return ERROR;
    }

    return (tmpMed - tmpOri);
}

/*Probado*/
Vector* crearVector(Vector* vec, size_t tamElem)
{
    vec = malloc(sizeof(Vector));

    if(!vec) return NULL;

    vec->data = malloc(tamElem * DEFAULT_CAP);

    if(!(vec->data)){
        free(vec);
        return NULL;
    }

    vec->cursor = 0;
    vec->tamElem = tamElem;
    vec->cantElem = 0;
    vec->cap = DEFAULT_CAP;

    return vec;
}

/*Probado*/
int destruirVector(Vector* vec)
{
    free(vec->data);
    free(vec);

    return EXITO;
}

int vectorGuardarTexto(Vector* vec, const char* path, FileRead fReadFunc)
{
    FILE* arch = fopen(path, "rt");

    if(!arch) return ERROR;

    void* tmp = malloc(vec->tamElem);

    fReadFunc(arch, tmp);
    vectorAgregar(vec, tmp);

    while(!feof(arch)){
        fReadFunc(arch, tmp);
        vectorAgregar(vec, tmp);
    }

    fclose(arch);
    free(tmp);

    return EXITO;
}

int vectorCargarTexto(Vector* vec, const char* path, FileWrite fWriteFunc)
{
    FILE* arch = fopen(path, "wb");

    if(!arch) return ERROR;

    char* tmpData = NULL;
    char* tmpUlt = vec->data + (vec->cantElem - 1) * vec->tamElem;

    for(tmpData = vec->data; tmpData < tmpUlt; tmpData += vec->tamElem){
        fWriteFunc(arch, tmpData);
    }

    fclose(arch);

    return EXITO;
}

int vectorGuardarBinario(Vector* vec, const char* path)
{
    FILE* arch = fopen(path, "rb");

    if(!arch) return ERROR;

    fseek(arch, 0, SEEK_END);
    size_t archTam = ftell(arch) / vec->tamElem;

    if(vec->cap <= archTam){
        vectorRedimensionar(vec, archTam * FACTOR_INCR_FILE);
    }

    fread(vec->data, vec->tamElem, archTam, arch);

    fclose(arch);

    return EXITO;
}

int vectorCargarBinario(Vector* vec, const char* path)
{
    FILE* arch = fopen(path, "wb");

    if(!arch) return ERROR;

    fwrite(vec->data, vec->tamElem, vec->cantElem, arch);

    fclose(arch);

    return EXITO;
}

/*Probado*/
int vectorReiniciarCursor(Vector* vec)
{
    vec->cursor = 0;
    return EXITO;
}

/*Probado*/
int vectorLeer(Vector* vec, void* dest)
{
    if(vectorCursorAlFinal(vec)) return ERROR;

    char* tmpData = vec->data;

    tmpData += vec->cursor * vec->tamElem;

    memcpy(dest, tmpData, vec->tamElem);

    vec->cursor++;

    return EXITO;
}

/*Probado*/
int vectorEscribir(Vector* vec, void* src)
{
    if(vectorCursorAlFinal(vec)) return ERROR;

    char* tmpData = vec->data;

    tmpData += vec->cursor * vec->tamElem;

    memcpy(tmpData, src, vec->tamElem);

    vec->cursor++;

    return EXITO;
}

/*Probado*/
int vectorMover(Vector* vec, size_t pos)
{
    if(pos < 0 || pos > vec->cantElem) return ERROR;

    vec->cursor = pos;

    return EXITO;
}

/*Probado*/
size_t vectorPosCursor(Vector* vec)
{
    return vec->cursor;
}

int vectorCursorAlFinal(Vector* vec)
{
    if(vec->cursor == vec->cantElem) return 1;

    return 0;
}

/*Probado*/
int vectorAgregar(Vector* vec, void* elem)
{
    if(vec->cantElem == vec->cap){
        if(vectorRedimensionar(vec, vec->cap * FACTOR_INCR)) return ERROR;
    }

    char* tmpData = vec->data;
    char* tmpElem = elem;

    tmpData += vec->cantElem * vec->tamElem;

    memcpy(tmpData, tmpElem, vec->tamElem);

    vec->cantElem++;

    return EXITO;
}

/*Probado*/
int vectorEliminarUltimo(Vector* vec)
{
    char* tmpData = vec->data;

    tmpData += (vec->cantElem - 1) * vec->tamElem;

    /*memset(tmpData, 0, vec->tamElem);*/

    vec->cantElem--;

    return EXITO;
}

/*Probado*/
void* vectorObtener(Vector* vec, size_t pos)
{
    if(pos < 0 || pos > vec->cantElem) return NULL;

    char* tmpData = vec->data;

    tmpData += pos * vec->tamElem;

    return tmpData;
}

/*Probado*/
int vectorModificar(Vector* vec, void* elem, size_t pos)
{
    if(pos < 0 || pos > vec->cantElem) return ERROR;

    char* tmpData = vec->data;

    tmpData += pos * vec->tamElem;

    memcpy(tmpData, elem, vec->tamElem);

    return EXITO;
}

/*Probado*/
int vectorVaciar(Vector* vec)
{
    vec->cantElem = 0;

    return EXITO;
}

/*Probado*/
int vectorRedimensionar(Vector* vec, size_t nuevaCap)
{
    if(nuevaCap < 0 || nuevaCap > MAXIMUM_CAP) return ERROR;

    void* tmp = realloc(vec->data, nuevaCap * vec->tamElem);

    if(!tmp) return ERROR;

    vec->data = tmp;
    vec->cap = nuevaCap;

    return EXITO;
}

/*Probado*/
int vectorBuscar(Vector* vec, void* clave, Comparar cmpFunc, int metodo)
{
    switch(metodo){
        case BINARY_SEARCH:
            return binarySearch(vec, clave, cmpFunc);
            break;
        case LINEAR_SEARCH:
            return linearSearch(vec, clave, cmpFunc);
            break;
        default:
            return ERROR;
    }
/*
    int pos = -1, i = 0;
    char* tmpData = vec->data;
    char* tmpUlt = vec->data + (vec->cantElem - 1) * vec->tamElem;

    while(tmpData < tmpUlt && pos == -1){
        if(!cmpFunc(tmpData, clave)){
            pos = i;
        }
        i++;
        tmpData += vec->tamElem;
    }

    return pos;

*/
}

/*Probado*/
int vectorOrdenar(Vector* vec, Comparar cmpFunc, int metodo)
{
    switch(metodo){
        case INSERTION_SORT:
            insertionSort(vec, cmpFunc);
            break;
        case SELECTION_SORT:
            selectionSort(vec, cmpFunc);
            break;
        case BUBBLE_SORT:
            bubbleSort(vec, cmpFunc);
            printf("ORDENADO\n");
            break;
        default:
            return ERROR;
    }

/*
    char* tmpI = NULL;
    char* tmpJ = NULL;
    char* tmpUlt = vec->data + (vec->cantElem - 1) * vec->tamElem;
    char* tmpLimJ = tmpUlt;

    for(tmpI = vec->data; tmpI < tmpUlt; tmpI += vec->tamElem, tmpLimJ -= vec->tamElem){
        for(tmpJ = vec->data; tmpJ < tmpLimJ; tmpJ += vec->tamElem){
            if(cmpFunc(tmpJ, tmpJ + vec->tamElem) > 0){
                intercambiar(tmpJ, tmpJ + vec->tamElem, vec->tamElem);
            }
        }
    }

    return EXITO;
    */

    return EXITO;
}

/*Probado*/
int intercambiar(void* a, void* b, size_t tamElem)
{
    char* tmp = malloc(tamElem);

    memcpy(tmp, a, tamElem);
    memcpy(a, b, tamElem);
    memcpy(b, tmp, tamElem);

    free(tmp);

    return EXITO;
}

/*Probado*/
int vectorRecorrer(Vector* vec, Accion actFunc)
{
    char* tmpData = NULL;
    char* tmpUlt = vec->data + (vec->cantElem - 1) * vec->tamElem;

    for(tmpData = vec->data; tmpData < tmpUlt; tmpData += vec->tamElem){
        actFunc(tmpData);
    }

    return EXITO;
}

/*Probado*/
int mostrarVector(Vector* vec, Imprimir imprFunc)
{
    if(vec->cantElem == 0) return ERROR;

    char* tmpData = NULL;
    char* tmpUlt = vec->data + vec->cantElem * vec->tamElem;

    for(tmpData = vec->data; tmpData < tmpUlt; tmpData += vec->tamElem){
        imprFunc(tmpData);
    }

    return EXITO;
}

/*Probado*/
size_t vectorTam(Vector* vec)
{
    return vec->cantElem;
}

/*Probado*/
size_t vectorCapacidad(Vector* vec)
{
    return vec->cap;
}

/*Probado*/
int vectorVacio(Vector* vec)
{
    return (vec->cantElem) ? 0 : 1;
}

