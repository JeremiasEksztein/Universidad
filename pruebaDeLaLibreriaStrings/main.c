#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include "..\unidad1CadenasLibreria\cadenas.h"

int esPalindromo(const char* str);

int main()
{
    char a[] = "xanax";

    printf("%d\n", esPalindromo(a));


    return 0;
}

int esPalindromo(const char* str)
{
    char* tmpInicio = (char*)str;
    char* tmpFin = (char*)str + stringLen(str) - 1;

    while(tmpInicio < tmpFin && *tmpInicio == *tmpFin){
        tmpInicio++;
        tmpFin--;
    }

    return (tmpInicio == tmpFin) ? 1 : 0;
}
