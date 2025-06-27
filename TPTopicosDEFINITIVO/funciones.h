#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "secuenciaPalabras.h"
#include "vector.h"
#include "comunesYErrores.h"

#define BUFFER_TAM 256

#define PERIODO_TAM 25
#define NIVEL_TAM 25
#define INDICE_TAM 25
#define CLASIF_TAM 25
#define VAR_INDICE_TAM 25

typedef struct{
    char periodo[PERIODO_TAM];
    char nivel[NIVEL_TAM];
    char indice[INDICE_TAM];
    char clasif[CLASIF_TAM];
    char var_indice[VAR_INDICE_TAM];
}Registro;

int cargarRegistroGeneral(FILE* arch, void* buf);
int cargarRegistroItems(FILE* arch, void* buf);



#endif // FUNCIONES_H_INCLUDED
