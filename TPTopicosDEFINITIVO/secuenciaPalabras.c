#include "secuenciaPalabras.h"

int secuenciaPalabraCrear(SecuenciaPalabra* sec, char* str)
{
    sec->cursor = str;
    sec->esFin = 0;

    return EXITO;
}

int secuenciaPalabraCerrar(SecuenciaPalabra* sec)
{
    sec->cursor = '\0';
    return EXITO;
}

int secuenciaPalabraLeer(SecuenciaPalabra* sec, Palabra* pal)
{
    while(*(sec->cursor) && !esLetra(*(sec->cursor))){
        sec->cursor++;
    }

    if(!*(sec->cursor)){
        sec->esFin = 1;
        return 1;
    }

    char* tmpPal = pal->palabra;

    do{
        *tmpPal = *(sec->cursor);
        tmpPal++;
        sec->cursor++;
    }while(*(sec->cursor) && esLetra(*(sec->cursor)));

    *tmpPal = '\0';

    return EXITO;
}

int secuenciaPalabraEscribir(SecuenciaPalabra* sec, Palabra* pal)
{
    char* i = pal->palabra;

    while(*i){
        *(sec->cursor) = *i;
        i++;
        sec->cursor++;
    }

    return EXITO;
}

int secuenciaPalabraEscribirCaract(SecuenciaPalabra* sec, int ch)
{
    *(sec->cursor) = ch;
    sec->cursor++;
    return EXITO;
}

int secuenciaPalabraEsFin(SecuenciaPalabra* sec)
{
    return sec->esFin;
}

int palabraMostrar(Palabra* pal)
{
    puts(pal->palabra);
    return EXITO;
}

int palabraModificar(Palabra* pal, ModificarPal modPalFunc)
{
    modPalFunc(pal->palabra);

    return EXITO;
}

