#ifndef SECUENCIAPALABRAS_H_INCLUDED
#define SECUENCIAPALABRAS_H_INCLUDED

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define PALABRA_TAM 50

typedef int (*Modificar)(char*);

typedef struct{
    char* cursor;
    int esFin;
}SecuenciaPalabras;

typedef struct{
    char palabra[PALABRA_TAM];
}Palabra;

int secuenciaPalabrasCrear(SecuenciaPalabras* sec, char* str);
int secuenciaPalabrasCerrar(SecuenciaPalabras* sec);
int secuenciaPalabrasFin(SecuenciaPalabras* sec);

int secuenciaPalabrasLeer(SecuenciaPalabras* sec, Palabra* pal);
int secuenciaPalabrasEscribir(SecuenciaPalabras* sec, Palabra* pal);
int secuenciaPalabrasEscribirChar(SecuenciaPalabras* sec, int ch);

int palabraModificar(Palabra* pal, Modificar modFunc);
int palabraMostrar(Palabra* pal);

#endif // SECUENCIAPALABRAS_H_INCLUDED
