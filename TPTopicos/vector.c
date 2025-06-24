#include "vector.h"

Vector* vectorCrear(Vector* vec, size_t tamElem)
{
    vec->data = malloc(tamElem * DEFAULT_CAP);

    if(!(vec->data)) return NULL;

    vec->tamElem = tamElem;
    vec->cantElem = 0;
    vec->cap = DEFAULT_CAP;

    return vec;
}

int vectorDestruir(Vector* vec)
{
    free(vec->data);

    vec->tamElem = 0;
    vec->cantElem = 0;
    vec->cap = 0;

    return EXITO;
}

int vectorGuardarBinario(Vector* vec, const char* path)
{
    FILE* arch = fopen(path, "rb");

    if(!arch) return ERROR;

    fseek(arch, 0, SEEK_END);
    size_t archTam = ftell(arch) / vec->tamElem;

    if(vec->cap < archTam){
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

int vectorGuardarTexto(Vector *vec, const char *path, FileRead fReadFunc)
{
	FILE *arch = fopen(path, "rt");

	if (!arch) return ERROR;

	void *tmp = malloc(vec->tamElem);

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
    FILE* arch = fopen(path, "wt");

    if(!arch) return ERROR;

    char* tmpData = NULL;
    char* tmpUlt = vec->data + (vec->cantElem * vec->tamElem);

    for(tmpData = vec->data; tmpData < tmpUlt; tmpData += vec->tamElem){
        fWriteFunc(arch, tmpData);
    }

    fclose(arch);

    return EXITO;
}

int vectorConcatenar(Vector* vecA, Vector* vecB)
{
    if(vecA->tamElem != vecB->tamElem) return ERROR;

    if(vecA->cap <= vecB->cantElem){
        if(vectorRedimensionar(vecA, (vecA->cap + vecB->cantElem) * FACTOR_INCR_FILE)) return ERROR;
    }

    char* tmpUltA = vecA->data + (vecA->cantElem + 1) * vecA->tamElem;

    memcpy(tmpUltA, vecB->data, vecB->tamElem * vecB->cantElem);

    return EXITO;
}

/*Es hacer trampa esto
int vectorBarajar(Vector* vecA, Vector* vecB)
{
    if(vecA->tamElem != vecB->tamElem) return ERROR;

    if(vecA->cap <= vecB->cantElem){
        if(vectorRedimensionar(vecA, (vecA->cap + vecB->cantElem) * FACTOR_INCR_FILE)) return ERROR;
    }

    Vector tmpVec = vectorCrear(&tmpVec, vecA->tamElem);

    char* tmpA = vecA->data;
    char* tmpUltA = vecA->data + vecA->cantElem * vecA->tamElem;
    char* tmpB = vecB->data;
    char* tmpUltB = vecB->data + vecB->cantElem * vecB->tamElem;

    while(tmpA < tmpUltA && tmpB < tmpUltB){

    }

}
*/

int vectorAgregar(Vector* vec, void* elem)
{
    if(vec->cantElem + 1 <= vec->cap){
        if(vectorRedimensionar(vec, vec->cap * FACTOR_INCR)) return ERROR;
    }

    char* tmpData = vec->data + vec->cantElem * vec->tamElem;

    memcpy(tmpData, elem, vec->tamElem);

    vec->cantElem++;

    return EXITO;
}

int vectorEliminarUlt(Vector* vec)
{
    vec->cantElem--;

    return EXITO;
}

void* vectorObtener(Vector* vec, size_t pos)
{
    if(pos < 1 || pos > vec->cantElem) return NULL;

    char* tmpData = vec->data + pos * vec->tamElem;

    return tmpData;
}

int vectorModificar(Vector* vec, void* elem, size_t pos)
{
    if(pos < 1 || pos > vec->cantElem) return ERROR;

    char* tmpData = vec->data + pos * vec->tamElem;

    memcpy(tmpData, elem, vec->tamElem);

    return EXITO;
}

int vectorVaciar(Vector* vec)
{
    vec->cantElem = 0;

    return EXITO;
}

int vectorRedimensionar(Vector* vec, size_t nuevoCap)
{
    void* tmpRealloc = realloc(vec->data, nuevoCap * vec->tamElem);

    if(!tmpRealloc) return ERROR;

    vec->data = tmpRealloc;
    vec->cap = nuevoCap;

    return EXITO;
}

int vectorOrdenar(Vector* vec, Comparar cmpFunc)
{
    /*Insertion sort*/

    return EXITO;
}

int vectorBuscar(Vector* vec, Comparar cmpFunc)
{
    /*Binary search*/

    return EXITO;
}

int intercambiar(void* a, void* b, size_t tamElem)
{
    void* tmp = malloc(tamElem);

    memcpy(tmp, a, tamElem);
    memcpy(a, b, tamElem);
    memcpy(b, tmp, tamElem);

    free(tmp);

    return EXITO;
}

int vectorMostrar(Vector* vec, Imprimir imprFunc)
{
    char* tmpData = NULL;
    char* tmpUlt = vec->data + vec->cantElem * vec->tamElem;

    for(tmpData = vec->data; tmpData < tmpUlt; tmpData += vec->tamElem){
        imprFunc(tmpData);
    }

    return EXITO;
}

int vectorRecorrer(Vector* vec, Accion actFunc)
{
    char* tmpData = NULL;
    char* tmpUlt = vec->data + vec->cantElem * vec->tamElem;

    for(tmpData = vec->data; tmpData < tmpUlt; tmpData += vec->tamElem){
        actFunc(tmpData);
    }

    return EXITO;
}
