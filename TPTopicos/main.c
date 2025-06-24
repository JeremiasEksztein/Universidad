#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "vector.h"

/*
    1- Corregir indices capitulos
    2- Corregir indices items
    3- Unificar y ordenar las estructuras
    4- Calcular las variaciones mensuales
    5- Exportar a binario
*/

int main()
{
    Vector indicesGeneral, indicesItems;

    vectorCrear(&indicesGeneral, BUFFER_TAM);
    vectorCrear(&indicesItems, BUFFER_TAM);

    vectorGuardarTexto(&indicesGeneral, NOM_ARCH_INDICES_GENERAL, corregirIndicesGeneral); /*1*/
    vectorGuardarTexto(&indicesItems, NOM_ARCH_INDICES_ITEMS, corregirIndicesItems); /*2*/

    vectorConcatenar(&indicesGeneral, &indicesItems);
    vectorDestruir(&indicesItems);

    /*Como dijo Luis, solo es necesario ordenar por fecha aca*/
    vectorOrdenar(&indicesGeneral, compararFechas); /*3*/

    calcularVariacionesMensual(&indicesGeneral); /*4*/
    calcularVariacionesInteranuales(&indicesGeneral);

    vectorCargarBinario(&indicesGeneral, NOM_ARCH_UNIFICADO); /*5*/

    vectorDestruir(&indicesGeneral);

    return 0;
}
