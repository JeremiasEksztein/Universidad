#ifndef SECUENCIAPALABRAS_H_INCLUDED
#define SECUENCIAPALABRAS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "palabra.h"

#define EXITO 0
#define ERROR 1
#define FIN_DE_CADENA 2

typedef struct{
    char* cursor;
    int esFin;
}SecuenciaPalabras;

int secuenciaPalabrasCrear(SecuenciaPalabras* sec, char* str);
int secuenciaPalabrasLeer(SecuenciaPalabras* sec, Palabra* pal);
void secuenciaPalabrasEscribir(SecuenciaPalabras* sec, Palabra* pal);
void secuenciaPalabrasAtras(SecuenciaPalabras* sec);
void secuenciaPalabrasAdelante(SecuenciaPalabras* sec);
void secuenciaPalabrasEscribirChar(SecuenciaPalabras* sec, char c);
int secuenciaPalabrasFin(SecuenciaPalabras* sec);
void secuenciaPalabrasCerrar(SecuenciaPalabras* sec);

#endif // SECUENCIAPALABRAS_H_INCLUDED
