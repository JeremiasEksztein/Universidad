#include "secuenciaPalabras.h"

int secuenciaPalabrasCrear(SecuenciaPalabras* sec, char* str)
{
    sec->cursor = str;
    sec->esFin = 0;

    return EXITO;
}

int secuenciaPalabrasLeer(SecuenciaPalabras* sec, Palabra* pal)
{
    while(*(sec->cursor) != '\0' && !esLetra(*(sec->cursor))){
        sec->cursor++;
    }

    if(*sec->cursor == '\0'){
        sec->esFin = 1;
        return FIN_DE_CADENA;
    }

    char* iPal = pal->pal;

    do{
        *iPal = *(sec->cursor);
        sec->cursor++;
        iPal++;
    }while(*(sec->cursor) != '\0' && esLetra(*(sec->cursor)));

    *iPal = '\0';

    return EXITO;
}

void secuenciaPalabrasEscribir(SecuenciaPalabras* sec, Palabra* pal)
{
    char* i = pal->pal;

    while(*i != '\0'){
        *(sec->cursor) = *i;
        i++;
        sec->cursor++;
    }

}

void secuenciaPalabrasEscribirChar(SecuenciaPalabras* sec, char c)
{
    *(sec->cursor) = c;
    sec->cursor++;
}

int secuenciaPalabrasFin(SecuenciaPalabras* sec)
{
    return sec->esFin;
}

void secuenciaPalabrasCerrar(SecuenciaPalabras* sec)
{
    *(sec->cursor) = '\0';
}
