#include "cadenas.h"

int esPalindromo(const char* str)
{
    char* tmpIni = (char*)str;
    char* tmpFin = (char*)str + stringLen(str) - 1;

    while(tmpIni < tmpFin && *tmpIni == *tmpFin){
        tmpIni++;
        tmpFin--;
    }

    return (tmpIni == tmpFin ? 1 : 0);
}
