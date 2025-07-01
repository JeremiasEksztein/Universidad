#include "secuenciaPalabras.h"

int secuenciaPalabrasCrear(SecuenciaPalabras* sec, char* str)
{
    sec->cursor = str;
    sec->esFin = 0;

    return 0;
}

int secuenciaPalabrasLeer(SecuenciaPalabras* sec, Palabra* pal)
{
    while(*(sec->cursor) != '\n' && !charValido(*(sec->cursor))){
        sec->cursor++;
    }

    if(*(sec->cursor) == '\n'){
        sec->esFin = 1;
        return FIN_DE_SECUENCIA;
    }

    char* iPal = pal->palabra;

    do
    {
        *iPal = *(sec->cursor);
        iPal++;
        sec->cursor++;
    }while(*(sec->cursor) != '\0' && charValido(*(sec->cursor)));

    *iPal = '\0';

    return 0;
}

int secuenciaPalabrasEsFin(SecuenciaPalabras* sec)
{
    return sec->esFin;
}

int secuenciaPalabrasCerrar(SecuenciaPalabras* sec)
{
    *(sec->cursor) = '\0';

    return 0;
}

int charValido(int ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch == '?') || (ch >= '0' && ch <= '9'));
}

int palabraMostrar(Palabra* pal)
{
    puts(pal->palabra);

    return 0;
}
