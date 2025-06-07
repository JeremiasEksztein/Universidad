#include "vector.h"

bool crearVector(Vector* vector, size_t tamElem)
{
    vector->vec = malloc(tamElem * CREACION);

    if(vector->vec == NULL) return false;

    vector->cap = CREACION;
    vector->tamElem = tamElem;
    vector->ce = 0;

    return true;
}

void destruirVector(Vector* vector)
{
    free(vector->vec);

    vector->vec = NULL;
    vector->cap = 0;
    vector->ce = 0;
    vector->tamElem = 0;
}
