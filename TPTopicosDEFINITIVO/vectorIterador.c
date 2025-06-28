#include "vectorIterador.h"

int vectorIteradorCrear(VectorIterador* iter, Vector* vec)
{
    if(vec->cantElem == 0) return ERR_MAL_INGRESO;

    iter->cursor = vec->data;
    iter->vec = vec;
    iter->fin = vec->data + vec->cantElem * vec->tamElem;
    iter->esFin = 0;

    return EXITO;
}

void vectorIteradorDestruir(VectorIterador* iter)
{
    iter->cursor = NULL;
    iter->vec = NULL;
    iter->fin = NULL;
    iter->esFin = 0;
}

int vectorIteradorMover(VectorIterador* iter, size_t nuevaPos)
{
    if(CHECK_RANGO(nuevaPos, 0, (iter->fin - iter->vec->data) * iter->vec->tamElem)){
        return ERR_MAL_INGRESO;
    }

    char* tmpCur = iter->cursor;

    tmpCur = iter->vec->data + nuevaPos * iter->vec->tamElem;

    if(tmpCur == iter->fin){
        iter->esFin = 1;
    }

    return EXITO;
}

void* vectorIteradorLeer(VectorIterador* iter)
{
    if(iter->esFin) return NULL;

    char* tmpRet = iter->cursor;
    char* tmpCur = iter->cursor;

    tmpCur += iter->vec->cantElem * iter->vec->tamElem;

    return tmpRet;
}

int vectorIteradorEscribir(VectorIterador* iter, void* elem)
{
    if(iter->esFin) return ERR_MAL_INGRESO;

    char* tmpCur = iter->cursor;

    memoryIntercambiar(tmpCur, elem, iter->vec->tamElem);

    iter->cursor += iter->vec->tamElem;

    return EXITO;
}

int vectorIteradorReiniciar(VectorIterador* iter)
{
    if(iter == NULL) return ERR_MAL_INGRESO;

    iter->cursor = iter->vec->data;
    iter->esFin = 0;

    return EXITO;
}

size_t vectorIteradorPosCursor(VectorIterador* iter)
{
    return ((iter->cursor - iter->vec->data) * iter->vec->tamElem);
}

int vectorIteradorFin(VectorIterador* iter)
{
    return iter->esFin;
}

