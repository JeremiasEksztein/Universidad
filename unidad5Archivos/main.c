#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "archivos.h"
#include "../TDAPalabraSecuencias/secuenciaPalabras.h"
#include "../unidad1CadenasLibreria/cadenas.h"

//5.2
int resolverEjercicio(char* str);

int main()
{
    char cadena[] = "uno.dos.tres.cuatro.cinco.seis.siete.ocho.nueve.diez";

    resolverEjercicio(cadena);

    return 0;
}

int resolverEjercicio(char* str)
{
    SecuenciaPalabras sec;
    Palabra pal;

    char* first = NULL;
    char* maxString = NULL;
    size_t max = 0;
    size_t count = 0;
    size_t firstCount = 0;

    secuenciaPalabrasCrear(&sec, str);
    secuenciaPalabrasLeer(&sec, &pal);
    printf("La primer palabra es %s\n", pal.pal);
    strcpy(first, pal.pal);
    max = strlen(first);
    maxString = first;
    firstCount++;
    count++;

    while(!secuenciaPalabrasFin(&sec)){

        count++;

        secuenciaPalabrasLeer(&sec, &pal);

        if(strcmp(first, pal.pal) == 0){
            firstCount++;
        }

        if(max < strlen(pal.pal)){
            max = strlen(pal.pal);
            maxString = pal.pal;
        }
    }

    printf("La primer palabra %s y se repite %d veces\n", first, (int)firstCount);
    printf("La palabra mas larga es %s y tiene longitud %d\n", maxString, (int)max);

    return 1;
}
