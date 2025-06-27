#include <stdio.h>
#include <stdlib.h>
#include "secuenciaPalabras.h"

void normalizarString(char* ori, char* dest);

int main()
{
    char cadenaPrueba[] = "¡Hola! ...esto123 es$una++cadena@de@@#prueba---con%%palabras&y##basura.";
    char dest[50];

    printf("%s\n", cadenaPrueba);

    normalizarString(cadenaPrueba, dest);

    printf("%s\n", dest);

    return 0;
}

void normalizarString(char* ori, char* dest)
{
    SecuenciaPalabras secOri, secDest;
    Palabra pal;

    char* tmpOri = ori;
    char* tmpDest = dest;

    secuenciaPalabrasCrear(&secOri, tmpOri);
    secuenciaPalabrasCrear(&secDest, tmpDest);
    secuenciaPalabrasLeer(&secOri, &pal);

    while(!secuenciaPalabrasFin(&secOri)){
        palabraATitulo(&pal);
        mostrarPalabra(&pal);
        secuenciaPalabrasEscribir(&secDest, &pal);

        if(!secuenciaPalabrasLeer(&secOri, &pal)){
            secuenciaPalabrasEscribirChar(&secDest, ' ');
        }
    }

    secuenciaPalabrasCerrar(&secDest);
}
