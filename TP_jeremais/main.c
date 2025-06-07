#include <stdio.h>
#include <stdlib.h>

#define HEADER "%[^;];%[^;];%[^\n]"
#define FORMATO "%[^;];%[^;];%4lf\n"
#define MAX_LINE_SIZE 256

typedef struct
{
    char* fecha;
    char* nombre;
    double indice;
}Entrada;

int main()
{
    char buffer[MAX_LINE_SIZE] = {""};

    FILE* iccGeneral = fopen("indices_icc_general_capitulos.csv", "r+t");

    if(iccGeneral == NULL) return -1;

    Entrada nuevaEntrada;

    nuevaEntrada.fecha = (char*)malloc(15);
    nuevaEntrada.nombre = (char*)malloc(40);

    if(nuevaEntrada.fecha == NULL || nuevaEntrada.nombre == NULL) return -1;

    fgets(buffer, MAX_LINE_SIZE, iccGeneral);

    fgets(buffer, MAX_LINE_SIZE, iccGeneral);

    while(!feof(iccGeneral))
    {
        sscanf(buffer, FORMATO, nuevaEntrada.fecha, nuevaEntrada.nombre, &nuevaEntrada.indice);
        printf("Fecha: %s Nombre: %s Indice: %lf\n", nuevaEntrada.fecha, nuevaEntrada.nombre, nuevaEntrada.indice);
        fgets(buffer, MAX_LINE_SIZE, iccGeneral);
    }

    fclose(iccGeneral);

    return 0;
}
