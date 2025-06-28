#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "comunesYErrores.h"

int main(int argv, char* argc[])
{
    Vector vecIndGen, vecIndItems;

    TRY(vectorCrear(&vecIndGen, sizeof(Registro)));

    TRY(vectorCrear(&vecIndGen, sizeof(Registro)));

    TRY(vectorCargarTexto(&vecIndGen, argc[NOM_ARCH_INDICES_GENERAL], cargarRegistroIndGeneral));

    TRY(vectorCargarTexto(&vecIndItems, argc[NOM_ARCH_INDICES_ITEMS], cargarRegistroIndItems));

    TRY(corregirRegistros(&vecIndGen, corregirRegistroGeneral));

    TRY(corregirRegistros(&vecIndItems, corregirRegistroItems));

    TRY(vectorConcatenar(&vecIndGen, &vecIndItems));

    vectorDestruir(&vecIndItems);

    vectorOrdenar(&vecIndGen, compararFechas, INSERCION);

    TRY(calcularVariaciones(&vecIndGen, "var_mensual", 1));

    TRY(calcularVariaciones(&vecIndGen, "var_anual", 12));

    TRY(vectorCargarBinario(&vecIndGen, argc[NOM_ARCH_INDICES_UNIF]));

    vectorDestruir(&vecIndGen);

    return 0;
}
