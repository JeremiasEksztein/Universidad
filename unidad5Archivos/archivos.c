#include "archivos.h"

bool abrirArchivo(FILE* file, char* dir, char* modo, bool mostrarError)
{
    file = fopen(dir, modo);

    if(mostrarError && !file){
        printf("Error en la apertura de archivo %s\n", dir);
        return false;
    }

    return true;
}
