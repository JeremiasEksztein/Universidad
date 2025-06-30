#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "comunesYErrores.h"

void imprimirRegistro(const void* reg);

int main(int argc, char* argv[])
{
    system("chcp 65001 > nul");

    if(argc != 4){
        return ERR_MAL_INGRESO;
    }

    Vector vecIndGen, vecIndItems;

    TRY(vectorCrear(&vecIndGen, sizeof(Registro)));

    TRY(vectorCrear(&vecIndItems, sizeof(Registro)));

    TRY(vectorGuardarTexto(&vecIndGen, argv[NOM_ARCH_INDICES_GENERAL], cargarRegistroIndGeneral));

    TRY(vectorGuardarTexto(&vecIndItems, argv[NOM_ARCH_INDICES_ITEMS], cargarRegistroIndGeneral));

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
    printf("%s;%s;%s;%s;%s\n", i->periodo, i->nivel, i->indice, i->clasif, i->var_indice);
}
