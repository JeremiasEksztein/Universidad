#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Para memcpy y memmove
#include "secuenciaPalabras.h"
#include "vector.h"
#include "funciones.h"

/*
*   Mostrar en consola las 10 palabras mas frecuentes
*   en el manuscrito de Voynich, en orden descendente.
*   No considerar aquellas palabras que posean el caracter
*   '?'
*/

//2 - voynich.txt

#define VOYNICH 1

int main(int argc, char* argv[])
{
    Vector conteo;

    vectorCrear(&conteo, sizeof(Entrada));

    procesarManuscrito(&conteo, argv[VOYNICH]);

    vectorOrdenar(&conteo, compararEntradasCont);

    vectorMostrar(&conteo, imprimirEntradas, 10);

    vectorDestruir(&conteo);

    return 0;
}
