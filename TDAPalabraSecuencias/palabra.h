#ifndef PALABRA_H_INCLUDED
#define PALABRA_H_INCLUDED

#include <stdio.h>

#define DEFAULT_PAL_TAM 50

typedef struct{
    char pal[DEFAULT_PAL_TAM];
}Palabra;

typedef void (*Modificar)(Palabra*);

void mostrarPalabra(const Palabra* pal);
void palabraModificar(Palabra* pal, Modificar modFunc);
void palabraATitulo(Palabra* pal);
int esLetra(int c);

#endif // PALABRA_H_INCLUDED
