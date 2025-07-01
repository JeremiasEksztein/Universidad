#include "funciones.h"

int procesarManuscrito(Vector* vec, char* path)
{
    FILE* arch = fopen(path, "rt");

    if(!arch) return ERR_ARCHIVO;

    char* buffer = malloc(BUFFER_TAM);

    if(!buffer) return ERR_MEMORIA;

    Entrada nuevasEntradas;
    Entrada* viejasEntradas;
    SecuenciaPalabras sec;
    Palabra pal;
    int posAux;
    size_t count = 0;

    fgets(buffer, BUFFER_TAM, arch);
    secuenciaPalabrasCrear(&sec, buffer);

    while(!feof(arch)){
        while(!secuenciaPalabrasLeer(&sec, &pal)){

            count++;

            if(!strchr(pal.palabra, '?')){
                if((posAux = vectorBusquedaLineal(vec, pal.palabra, compararEntradasStr)) == -1){ //DUDOSO
                    strcpy(nuevasEntradas.str, pal.palabra);
                    nuevasEntradas.cont = 1;
                    vectorAgregar(vec, &nuevasEntradas);
                }else{
                    viejasEntradas = (Entrada*)vectorObtener(vec, posAux);//No tienen por que ser genericos, solo utiles para el problema
                    viejasEntradas->cont++;
                    printf("%s - %s,%d\n",pal.palabra, viejasEntradas->str, (int)viejasEntradas->cont);
                    vectorModificar(vec, viejasEntradas, posAux);
                }
            }
        }

        fgets(buffer, BUFFER_TAM, arch);
        secuenciaPalabrasCrear(&sec, buffer);
    }

    printf("CANT DE PALABRAS%d\n", (int) count);

    fclose(arch);
    free(buffer);

    return 0;
}

int compararEntradasStr(const void* lhs, const void* rhs)
{
    Palabra* a = (Palabra*)lhs;
    Entrada* b = (Entrada*)rhs;

    return (strcmpi(a->palabra, b->str));
}

int compararEntradasCont(const void* lhs, const void* rhs)
{
    Entrada* a = (Entrada*)lhs;
    Entrada* b = (Entrada*)rhs;

    return (- a->cont + b->cont);
}

void imprimirEntradas(const void* elem)
{
    Entrada* a = (Entrada*) elem;

    printf("Palabra: %s\tFrecuencia:%4d\n", a->str, (int)a->cont);
}

