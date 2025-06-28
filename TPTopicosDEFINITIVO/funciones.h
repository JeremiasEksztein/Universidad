#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "secuenciaPalabras.h"
#include "vector.h"
#include "vectorIterador.h"
#include "comunesYErrores.h"

#define PERIODO_TAM 12
#define NIVEL_TAM 41
#define INDICE_TAM 17
#define CLASIF_TAM 14
#define VAR_INDICE_TAM 13

typedef int (*Corrector)(void*);

typedef struct{
    char periodo[PERIODO_TAM];
    char nivel[NIVEL_TAM];
    char indice[INDICE_TAM];
    char clasif[CLASIF_TAM];
    char var_indice[VAR_INDICE_TAM];
}Registro;

int cargarRegistroIndGeneral(FILE* arch, void* buf);
int cargarRegistroIndItems(FILE* arch, void* buf);

int corregirRegistros(Vector* vec, Corrector crtFunc);

int corregirRegistroGeneral(void* buf);

int corregirFecha(char* buf);
int corregirIndice(char* buf);
int desencriptarNivelGeneral(char* buf);
int normalizarNivel(char* buf);

int corregirRegistroItems(void* buf);
int desencriptarNivelItems(char* buf);

int compararFechas(const void* a, const void* b);

int calcularVariaciones(Vector* vec, char* nomVar, int rango);
int cantidadDeMeses(Vector* vec);

#endif // FUNCIONES_H_INCLUDED
