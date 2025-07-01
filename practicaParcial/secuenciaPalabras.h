#ifndef SECUENCIAPALABRAS_H_INCLUDED
#define SECUENCIAPALABRAS_H_INCLUDED

#include <stdio.h>
#include "comunes.h"

#define PALABRA_TAM 50

typedef struct{
    char* cursor;
    int esFin;
}SecuenciaPalabras;

typedef struct{
    char palabra[PALABRA_TAM];
}Palabra;

int secuenciaPalabrasCrear(SecuenciaPalabras* sec, char* str);
int secuenciaPalabrasLeer(SecuenciaPalabras* sec, Palabra* pal);
int secuenciaPalabrasEsFin(SecuenciaPalabras* sec);
int secuenciaPalabrasCerrar(SecuenciaPalabras* sec);

int charValido(int ch);

int palabraMostrar(Palabra* pal);

#endif // SECUENCIAPALABRAS_H_INCLUDED
