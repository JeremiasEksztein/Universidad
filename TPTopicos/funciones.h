#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

#define EXITO 0
#define ERROR 1

#define NOM_ARCH_INDICES_GENERAL "indices_icc_general_capitulos.csv"
#define NOM_ARCH_INDICES_ITEMS "Indices_items_obra.csv"
#define NOM_ARCH_UNIFICADO "indices_unificados.dat"

#define BUFFER_TAM 256

int corregirIndicesGeneral(FILE* arch, void* buffer);
int parsearRegistro(char* buffer, char* periodo, char* nivel, char* indice);

void corregirFormatoDeFecha(char* buffer); /*Tambien se usa en el 2*/
void corregirFormatoDecimal(char* buffer); /*Tambien se usa en el 2*/
void desencriptarCampo1(char* buffer);
void normalizarCampo1(char* buffer);
void agregarCampo1(char* clasificador, char* nivel);

int corregirIndicesItems(FILE* arch, void* buffer);

void desencriptarCampo2(char* buffer);
void normalizarCampo2(char* buffer);

int compararFechas(const void* a, const void* b);

void calcularVariacionesMensual(Vector* indices);
void calcularVariacionesInteranuales(Vector* indices);

#endif // FUNCIONES_H_INCLUDED
