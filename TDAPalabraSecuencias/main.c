#include <stdio.h>
#include <stdlib.h>
#include "secuenciaPalabras.h"

void normalizarString(char* ori, char* dest);

int main()
{
    char cadenaPrueba[] = "uno.dos.tres.cuatro.cinco.seis.siete.ocho.nueve.diez";
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
    size_t contPal = 0;

    secuenciaPalabrasCrear(&secOri, tmpOri);
    secuenciaPalabrasCrear(&secDest, tmpDest);
    secuenciaPalabrasLeer(&secOri, &pal);

    while(!secuenciaPalabrasFin(&secOri)){
        palabraATitulo(&pal);
        mostrarPalabra(&pal);
        secuenciaPalabrasEscribir(&secDest, &pal);
        contPal++;

        if(!secuenciaPalabrasLeer(&secOri, &pal)){
            secuenciaPalabrasEscribirChar(&secDest, ' ');
        }
    }

    printf("%ld\n", (long)contPal);

    secuenciaPalabrasCerrar(&secDest);
}
