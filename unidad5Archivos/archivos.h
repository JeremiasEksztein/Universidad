#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ABRIR_ARCHIVO(file, dir, modo, error)   \
        (file) = fopen((dir), (modo));\
        if((error) && !(file)){\
        printf("Error al abrir archivo %s\n", (dir));\
        return false;\
        }\
        return true;

bool abrirArchivo(FILE* file, char* dir, char* modo, bool mostrarError);

#endif // ARCHIVOS_H_INCLUDED
