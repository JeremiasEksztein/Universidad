#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "comunesYErrores.h"

int main(int argc, char* argv[])
{
    if(argc != 4){
        return ERR_MAL_INGRESO;
    }

    Vector vecIndGen, vecIndItems;

    TRY(vectorCrear(&vecIndGen, sizeof(Registro)));

    TRY(vectorCrear(&vecIndGen, sizeof(Registro)));

    TRY(vectorCargarTexto(&vecIndGen, argv[NOM_ARCH_INDICES_GENERAL], cargarRegistroIndGeneral));

    TRY(vectorCargarTexto(&vecIndItems, argv[NOM_ARCH_INDICES_ITEMS], cargarRegistroIndItems));

    TRY(corregirRegistros(&vecIndGen, corregirRegistroGeneral));

    TRY(corregirRegistros(&vecIndItems, corregirRegistroItems));

    TRY(vectorConcatenar(&vecIndGen, &vecIndItems));

    vectorDestruir(&vecIndItems);

    vectorOrdenar(&vecIndGen, compararFechas, INSERCION);

    TRY(calcularVariaciones(&vecIndGen, "var_mensual", 1));

    TRY(calcularVariaciones(&vecIndGen, "var_anual", 12));

    TRY(vectorCargarBinario(&vecIndGen, argv[NOM_ARCH_INDICES_UNIF]));

    vectorDestruir(&vecIndGen);

    return 0;
}
