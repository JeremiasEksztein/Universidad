#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "funciones.h"
#include "cadenas.h"
#include "secuenciaPalabras.h"
#include "comunesYErrores.h"
#include "vector.h"
#include "vectorIterador.h"

typedef struct{
    char nom[10];
    int num;
    double decimal;
}Aux;

int pruebaVector()
{
    Vector vec;

    TRY(vectorCrear(&vec, sizeof(Aux)));

    return 0;
}
