#include "palabra.h"
#include <ctype.h>

void mostrarPalabra(const Palabra* pal)
{
    printf("%s\n", pal->pal);
}

void palabraModificar(Palabra* pal, Modificar modFunc)
{
    modFunc(pal);
}

void palabraATitulo(Palabra* pal)
{
    char* i = pal->pal;

    *i = toupper(*i);
    i++;

    while(*i){
        *i = tolower(*i);
        i++;
    }
}

int esLetra(int c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
