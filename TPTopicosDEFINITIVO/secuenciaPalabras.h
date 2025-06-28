#ifndef SECUENCIAPALABRAS_H_INCLUDED
#define SECUENCIAPALABRAS_H_INCLUDED

#include "cadenas.h"
#include "comunesYErrores.h"

#define DEFAULT_PAL_TAM 50

typedef char* (*ModificarPal)(char*);

typedef struct{
    char* cursor;
    int esFin;
}SecuenciaPalabra;

typedef struct{
    char palabra[DEFAULT_PAL_TAM];
}Palabra;

/*SecuenciaPalabra*/

int secuenciaPalabraCrear(SecuenciaPalabra* sec, char* str);
int secuenciaPalabraCerrar(SecuenciaPalabra* sec);

int secuenciaPalabraLeer(SecuenciaPalabra* sec, Palabra* pal);
int secuenciaPalabraEscribir(SecuenciaPalabra* sec, Palabra* pal);
int secuenciaPalabraEscribirCaract(SecuenciaPalabra* sec, int ch);

int secuenciaPalabraEsFin(SecuenciaPalabra* sec);

/*Palabra*/

int palabraMostrar(Palabra* pal);
int palabraModificar(Palabra* pal, ModificarPal modPalFunc);

#endif // SECUENCIAPALABRAS_H_INCLUDED
