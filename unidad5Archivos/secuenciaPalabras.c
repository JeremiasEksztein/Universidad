#include "secuenciaPalabras.h"

int secuenciaPalabrasCrear(SecuenciaPalabras* sec, char* str)
{
    sec->cursor = str;
    sec->esFin = 0;

    return 0;
}

int secuenciaPalabrasCerrar(SecuenciaPalabras* sec)
{
    *(sec->cursor) = '\0';

    return 0;
}

int secuenciaPalabrasFin(SecuenciaPalabras* sec)
{
    return sec->esFin;
}

int secuenciaPalabrasLeer(SecuenciaPalabras* sec, Palabra* pal)
{
    while(*(sec->cursor) && !isalpha(*(sec->cursor))){
        sec->cursor++;
    }

    if(*(sec->cursor) == '\0'){
        sec->esFin = 1;
        return 1;
    }

    char* i = pal->palabra;

    do{
        *i = *(sec->cursor);
        sec->cursor++;
        i++;
    }while(*(sec->cursor) && isalpha(*(sec->cursor)));

    *i = '\0';

    return 0;
}

int secuenciaPalabrasEscribir(SecuenciaPalabras* sec, Palabra* pal)
{
    char* i = pal->palabra;

    while(*i){
        *(sec->cursor) = *i;
        sec->cursor++;
        i++;
    }

    return 0;
}

int secuenciaPalabrasEscribirChar(SecuenciaPalabras* sec, int ch)
{
    *(sec->cursor) = ch;

    return 0;
}

int palabraModificar(Palabra* pal, Modificar modFunc)
{
    modFunc(pal->palabra);

    return 0;
}

int palabraMostrar(Palabra* pal)
{
    puts(pal->palabra);

    return 0;
}
