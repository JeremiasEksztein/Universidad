#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "comunesYErrores.h"

void imprimirRegistro(const void* reg);

int main(int argc, char* argv[])
{
    if(argc != 4){
        return ERR_MAL_INGRESO;
    }

    Vector vecIndGen, vecIndItems;

    puts(argv[NOM_ARCH_INDICES_ITEMS]);

    TRY(vectorCrear(&vecIndGen, sizeof(Registro))); //FUNCIONA

    TRY(vectorCrear(&vecIndItems, sizeof(Registro))); //FUNCIONA

    TRY(vectorGuardarTexto(&vecIndGen, argv[NOM_ARCH_INDICES_GENERAL], cargarRegistroIndGeneral));

    vectorMostrar(&vecIndGen, imprimirRegistro);

    TRY(vectorGuardarTexto(&vecIndItems, argv[NOM_ARCH_INDICES_ITEMS], cargarRegistroIndGeneral));

    vectorMostrar(&vecIndItems, imprimirRegistro);

    //Hasta aca funciona todo bien

    TRY(corregirRegistros(&vecIndGen, corregirRegistroGeneral));

    TRY(corregirRegistros(&vecIndItems, corregirRegistroItems));

    TRY(vectorConcatenar(&vecIndGen, &vecIndItems));

    vectorDestruir(&vecIndItems);

    vectorOrdenar(&vecIndGen, compararFechas, BURBUJEO);

    TRY(calcularVariaciones(&vecIndGen, "var_mensual", 1));

    TRY(calcularVariaciones(&vecIndGen, "var_anual", 12));

    TRY(vectorCargarBinario(&vecIndGen, argv[NOM_ARCH_INDICES_UNIF]));

    vectorDestruir(&vecIndGen);

    return 0;
}

void imprimirRegistro(const void* reg)
{
    Registro* i = (Registro*)reg;

    // Asegúrate de que los campos sean cadenas y estén correctamente inicializados
    printf("%s;%s;%s\n", i->periodo, i->nivel, i->indice);
}
