#include "funciones.h"

char* cambiarFormatoDeFecha(char* fecha)
{
    size_t i;

    while(*(fecha + i) != '\0'){
        if(*(fecha + i) == '/'){
            *(fecha + i) = '-';
        }

        i++;
    }

    return fecha;
}

char* cambiarFormatoDecimal(char* numero)
{
    size_t i;

    while(*(numero + i) != '\0'){
        if(*(numero + i) == ','){
            *(numero + i) = '.';
        }

        i++;
    }

    return numero;
}

char* normalizarCadenaSinGuiones(char* cadena)
{
    size_t i = 0, j = 0;

    char* dest = NULL;

    while(*(cadena + i) != '\0'){
        while(*(cadena + i) != '_'){


        }

    }

}
