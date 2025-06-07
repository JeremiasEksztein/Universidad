#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char* fechaAFormatear = "12/12/12034";
    char* numeroAFormatear = "1029,299";
    char* textoANormalizar = "6_instalaciones_dE_yeso_";

    printf("%s - %s - %s\n", fechaAFormatear, numeroAFormatear, textoANormalizar);

    cambiarFormatoDeFecha(fechaAFormatear);
    cambiarFormatoDecimal(numeroAFormatear);
    normalizarCadenaSinGuiones(textoANormalizar);

    printf("%s - %s - %s\n", fechaAFormatear, numeroAFormatear, textoANormalizar);
    printf("VALOR ESPERADO\n");
    printf("12-2-12034 - 1029.299 - Instalaciones de yeso\n");

    return 0;
}
