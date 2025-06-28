#include "funciones.h"

int cargarRegistroIndGeneral(FILE* arch, void* buf)
{
    Registro reg;
    char* tmpBuf = buf;
    char* cur = buf;

    if(!(cur = cadenaCaracterReverso(tmpBuf, '\n'))){
        return ERR_REGISTRO;
    }

    *cur = '\0';

    if(!(cur = cadenaCaracterReverso(tmpBuf, ';'))){
        return ERR_REGISTRO;
    }

    sscanf(cur, "%s", reg.indice);
    *cur = '\0';

    if(!(cur = cadenaCaracterReverso(tmpBuf, ';'))){
        return ERR_REGISTRO;
    }

    sscanf(cur, "%s", reg.nivel);
    *cur = '\0';

    sscanf(tmpBuf, "%s", reg.periodo);

    return EXITO;
}

int cargarRegistroIndItems(FILE* arch, void* buf)
{
    Registro reg;
    char* tmpBuf = buf;
    char* cur = buf;

    if(!(cur = cadenaCaracterReverso(tmpBuf, '\n'))){
        return ERR_REGISTRO;
    }

    *cur = '\0';

    if(!(cur = cadenaCaracterReverso(tmpBuf, ';'))){
        return ERR_REGISTRO;
    }

    sscanf(cur, "%s", reg.indice);
    *cur = '\0';

    if(!(cur = cadenaCaracterReverso(tmpBuf, ';'))){
        return ERR_REGISTRO;
    }

    sscanf(cur, "%s", reg.nivel);
    *cur = '\0';

    sscanf(tmpBuf, "%s", reg.periodo);

    return EXITO;
}

int corregirRegistros(Vector* vec, Corrector crtFunc)
{
    VectorIterador iter;
    void* elem = NULL;

    TRY(vectorIteradorCrear(&iter, vec));

    while(vectorIteradorFin(&iter)){
        elem = vectorIteradorLeer(&iter);
        vectorIteradorMover(&iter, -1);
        vectorIteradorEscribir(&iter, elem);
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

    sscanf(buf, "\"%d/%d/%d\"", &d, &m, &a);
    sprintf(buf, "%4d-%02d-%02d", a, m, d);

    return EXITO;
}

int corregirIndice(char* buf)
{
    char* tmp = cadenaCaracter(buf, ',');

    *tmp = '.';

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

            if(*i >= 'z'){
                *i = 'a' + (*i + 'z' - 1);
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
    char* salida = NULL;

    secuenciaPalabraCrear(&secOri, buf);
    secuenciaPalabraCrear(&secNorm, buf);

    secuenciaPalabraLeer(&secOri, &pal);
    palabraModificar(&pal, cadenaCapitalizar);
    secuenciaPalabraEscribir(&secNorm, &pal);
    secuenciaPalabraEscribirCaract(&secNorm, ' ');

    while(!secuenciaPalabraEsFin(&secOri)){

        secuenciaPalabraLeer(&secOri, &pal);
        palabraModificar(&pal, cadenaAMinuscula);
        secuenciaPalabraEscribir(&secNorm, &pal);
        secuenciaPalabraEscribir(&secNorm, ' ');
    }

    secuenciaPalabraCerrar(&secNorm);
    cadenaCopiar(buf, salida);

    return EXITO;
}
