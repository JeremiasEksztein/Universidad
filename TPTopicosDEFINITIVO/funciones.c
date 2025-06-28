#include "funciones.h"

int cargarRegistroIndGeneral(FILE* arch, void* buf)
{
    Registro* reg = buf;
    char buffer[256];
    char* cur = buffer;

    if (!fgets(buffer, sizeof(buffer), arch)) {
        return ERR_REGISTRO;
    }
    cadenaRemoverCaract(buffer, '\"');

    if(!(cur = cadenaCaracterReverso(buffer, '\n'))){
        return ERR_REGISTRO;
    }

    *cur = '\0';

    if(!(cur = cadenaCaracterReverso(buffer, ';'))){
        return ERR_REGISTRO;
    }

    sscanf(cur + 1, "%s", reg->indice);
    *cur = '\0';

    if(!(cur = cadenaCaracterReverso(buffer, ';'))){
        return ERR_REGISTRO;
    }

    sscanf(cur + 1, "%s", reg->nivel);
    *cur = '\0';

    sscanf(buffer, "%s", reg->periodo);

    return EXITO;
}

int cargarRegistroIndItems(FILE* arch, void* buf)
{
    Registro* reg = buf;
    char buffer[256];
    char* cur = buffer;

    if(fgets(buffer, sizeof(buffer), arch)){
        return ERR_REGISTRO;
    }
    cadenaRemoverCaract(buffer, '\"');

    if(!(cur = cadenaCaracterReverso(buffer, '\n'))){
        return ERR_REGISTRO;
    }

    *cur = '\0';

    if(!(cur = cadenaCaracterReverso(buffer, ';'))){
        return ERR_REGISTRO;
    }

    sscanf(cur + 1, "%s", reg->indice);
    *cur = '\0';

    if(!(cur = cadenaCaracterReverso(buffer, ';'))){
        return ERR_REGISTRO;
    }

    sscanf(cur + 1, "%s", reg->nivel);
    *cur = '\0';

    sscanf(buffer, "%s", reg->periodo);

    return EXITO;
}

int corregirRegistros(Vector* vec, Corrector crtFunc)
{
    VectorIterador iter;
    void* elem = NULL;

    vectorEliminarPrimero(vec);

    vectorIteradorCrear(&iter, vec);

    while(!vectorIteradorFin(&iter)){
        elem = vectorIteradorSiguiente(&iter);
        crtFunc(elem);
    }

    return EXITO;
}

int corregirRegistroGeneral(void* buf)
{
    Registro* reg = (Registro*)buf;

    corregirFecha(reg->periodo);
    corregirIndice(reg->indice);
    desencriptarNivelGeneral(reg->nivel);
    normalizarNivel(reg->nivel);

    if(cadenaComparar(reg->nivel, "Nivel General") == 0){
        cadenaCopiar(reg->clasif, "Clasificador");
    }else{
        cadenaCopiar(reg->clasif, "Capitulos");
    }

    return EXITO;
}

int corregirFecha(char* buf)
{
    int d, m, a;

    sscanf(buf, "%d/%d/%d", &d, &m, &a);
    sprintf(buf, "%4d-%02d-%02d", a, m, d);

    return EXITO;
}

int corregirIndice(char* buf)
{
    char* tmp = cadenaCaracter(buf, ',');

    if(tmp){
        *tmp = '.';
    }

    return EXITO;
}

int desencriptarNivelGeneral(char* buf)
{
    char* i = buf;
    size_t count = 0;

    while(*i){
        if(esLetra(*i)){
            if(count % 2 == 0){
                *i += 4;
            }else{
                *i += 2;
            }

            if(*i > 'z'){
                *i -= ('z' - 'a' + 1);
            }
        }

        count++;
        i++;
    }

    return EXITO;
}

int normalizarNivel(char* buf)
{
    SecuenciaPalabra secOri, secNorm;
    Palabra pal;
    char salida[NIVEL_TAM];

    secuenciaPalabraCrear(&secOri, buf);
    secuenciaPalabraCrear(&secNorm, salida);
    secuenciaPalabraLeer(&secOri, &pal);

    palabraModificar(&pal, cadenaCapitalizar);

    secuenciaPalabraEscribir(&secNorm, &pal);
    secuenciaPalabraEscribirCaract(&secNorm, ' ');

    while(!secuenciaPalabraEsFin(&secOri)){
        secuenciaPalabraEscribirCaract(&secNorm, ' ');
        secuenciaPalabraLeer(&secOri, &pal);
        palabraModificar(&pal, cadenaAMinuscula);
        secuenciaPalabraEscribir(&secNorm, &pal);
    }

    secuenciaPalabraCerrar(&secNorm);
    puts(salida);
    cadenaCopiar(buf, salida);

    return EXITO;
}

int corregirRegistroItems(void* buf)
{
    Registro* reg = (Registro*) buf;

    corregirFecha(reg->periodo);
    corregirIndice(reg->indice);
    desencriptarNivelItems(reg->nivel);
    normalizarNivel(reg->nivel);

    cadenaCopiar(reg->clasif, "Items");

    return EXITO;
}

int desencriptarNivelItems(char* buf)
{
    char* i = buf;
    char* pos = NULL;

    char clave[] = "@8310$7|59";
    char valor[] = "abeiostlmn";

    while(*i){
        if((pos = cadenaCaracter(clave, *i))){
            *i = *(valor + (pos - clave));
        }

        i++;
    }

    return EXITO;
}

int compararFechas(const void* a, const void* b)
{
    Registro* regA = (Registro*) a;
    Registro* regB = (Registro*) b;

    int d, m, anio, suma = 0;

    sscanf(regA->periodo, "%d-%d-%d", &anio, &m, &d);

    suma += anio * 10000 + m * 1000 + d * 10;

    sscanf(regB->periodo, "%d-%d-%d", &anio, &m, &d);

    suma -= anio * 10000 + m * 1000 + d * 10;

    return suma;
}

int calcularVariaciones(Vector* vec, char* nomVar, int rango)
{
    VectorIterador iter;
    vectorIteradorCrear(&iter, vec);
    Registro* reg = (Registro*)vectorIteradorPrimero(&iter);
    Registro* regAnterior = NULL;

    size_t cantRegistros = cantidadDeMeses(vec) * rango;
    int i;
    double variacion;

    for(i = 0; i < cantRegistros; i++){
        sprintf(reg->var_indice, "%s", nomVar);
        sprintf(reg->indice, "%s", "NA");
        reg = (Registro*) vectorIteradorSiguiente(&iter);
    }

    while(!vectorIteradorFin(&iter)){
        regAnterior = (Registro*) vectorIteradorMover(&iter, -cantRegistros);
        vectorIteradorMover(&iter, cantRegistros);

        variacion = (((atof(reg->indice)) / (atof(regAnterior->indice) - 1)) - 1) * 100;
        sprintf(reg->indice, "%.02f\n", variacion);

        reg = (Registro*) vectorIteradorSiguiente(&iter);
    }

    return EXITO;
}

int cantidadDeMeses(Vector* vec)
{
    VectorIterador iter;
    vectorIteradorCrear(&iter, vec);

    size_t count = 0;
    Registro* reg = vectorIteradorPrimero(&iter);
    Registro* regActual = vectorIteradorSiguiente(&iter);

    while(cadenaComparar(reg->nivel, regActual->nivel) != 0){
        count++;
        regActual = (Registro*) vectorIteradorSiguiente(&iter);
    }

    return count;
}
