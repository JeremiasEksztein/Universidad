#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "archivos.h"
#include "secuenciaPalabras.h"

//5.2
int resolverEjercicio(char* str);

int main()
{
    char cadena[] = "uno.dos.tres.cuatro.cinco.uno.uno.ocho.nueve.diez,octubre";

    //5.2
    resolverEjercicio(cadena);

    return 0;
}

int resolverEjercicio(char* str)
{
    SecuenciaPalabras sec;
    Palabra pal;

    char primerPal[PALABRA_TAM];
    size_t contPal = 0;
    size_t contPrimPal = 0;
    size_t maxPal = 0;

    secuenciaPalabrasCrear(&sec, str);
    secuenciaPalabrasLeer(&sec, &pal);
    maxPal = strlen(pal.palabra);
    strcpy(primerPal, pal.palabra);
    contPrimPal++;

    while(!secuenciaPalabrasFin(&sec)){
        contPal++;
        palabraMostrar(&pal);

        if(maxPal < strlen(pal.palabra)){
            maxPal = strlen(pal.palabra);
        }

        secuenciaPalabrasLeer(&sec, &pal);

        if(strcmp(pal.palabra, primerPal) == 0){
            contPrimPal++;
        }

    }

    printf("La cadena mas larga mide %d\n", (int)maxPal);
    printf("Hay %d palabras\n", (int)contPal);
    printf("La palabra primera \"%s\" se repite %d veces\n", primerPal, (int)contPrimPal);

    return 0;
}
