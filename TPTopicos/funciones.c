#include "funciones.h"

int esLetra(int c);
int esPar(int a);
int aMayus(int c);

int esLetra(int c)
{
    return (c < 'A' || c > 'Z' && c < 'a' || c > 'z');
}

int esPar(int a)
{
    return (a % 2 == 0);
}

int aMayus(int c)
{
    return c -= 32;
}

int corregirIndicesGeneral(FILE* arch, void* buffer)
{
    char* tmpBuf = buffer;
    char *tmpFecha, *tmpNivel, *tmpIndice, *tmpClasificador;

    fgets(tmpBuf, BUFFER_TAM, arch);
    if(parsearRegistro(tmpBuf, tmpFecha, tmpNivel, tmpIndice)) return ERROR;
    
    corregirFormatoDeFecha(tmpFecha);
    corregirFormatoDecimal(tmpIndice);
    desencriptarCampo1(tmpNivel);
    normalizarCampo1(tmpNivel);
    agregarCampo1(tmpClasificador, tmpNivel);

    sprintf(tmpBuf, "%s;%s;%s;%s\n", tmpFecha, tmpNivel, tmpIndice, tmpClasificador);

    return EXITO;
}

int parsearRegistro(char* buffer, char* periodo, char* nivel, char* indice)
{
    char* tmp = buffer;

    tmp = strrchr(tmp, '\n');

    if(!tmp) return ERROR;

    *tmp = '\0';

    tmp = strrchr(tmp, ';');
    tmp = indice;

    *tmp = '\0';

    tmp = strrchr(tmp, ';');
    tmp = nivel;

    *tmp = '\0';

    tmp = strrchr(tmp, ';');
    tmp = periodo;

    return EXITO;
}

void corregirFormatoDeFecha(char* buffer)
{
    int d, m, a;

    sscanf(buffer, "%d/%d/%d", &d, &m, &a);

    sprintf(buffer, "%4d-%02d-%02d", &a, &m, &d);
}

void corregirFormatoDecimal(char* buffer)
{
    while(!buffer){
        if(*buffer == ','){
            *buffer = '.';
        }

        buffer++;
    }
}

void desencriptarCampo1(char* buffer)
{
    size_t contador = 0;
    
    while(*buffer){
        if(esLetra(buffer)){
            if(esPar(contador)){
                *buffer += 2;
            }
            else{
                *buffer += 4;
            }

            if(*buffer > 'z'){
                *buffer = 'a' + (*buffer - 'z' - 1);
            }
        }
        
        contador++;
        buffer++;
    }
}

void normalizarCampo1(char* buffer)
{ 
    buffer++;

    *buffer = aMayus(buffer);
    
    while(*buffer){
        if(*buffer == '_'){
            *buffer = ' ';
        }

        buffer++;
    }
}

void agregarCampo1(char* clasificador, char* nivel)
{
    if(strcmp(nivel, "Nivel General")){ /*Esto va a generar problemas seguro*/
        strcpy(clasificador, "Nivel General");
    }else{
        strcat(clasificador, "Capitulos");
    }
}

int corregirIndicesItems(FILE* arch, void* buffer)
{
    char* tmpBuf = buffer;
    char *tmpPeriodo, *tmpNivel, *tmpIndice;

    fgets(tmpBuf, BUFFER_TAM, arch);
    if(parsearRegistro(tmpBuf, tmpPeriodo, tmpNivel, tmpIndice)) return ERROR;

    corregirFormatoDeFecha(tmpPeriodo);
    corregirFormatoDecimal(tmpIndice);
    desencriptarCampo2(tmpNivel);
    normalizarCampo2(tmpNivel);

    sprintf(tmpBuf, "%s;%s;%s;%s\n", tmpPeriodo, tmpNivel, tmpIndice, "Items");

    return EXITO;
}

void desencriptarCampo2(char* buffer)
{
    char encrip[11] = "@8310$7|59";
    char desencrip[11] = "abeiostlmn";

    while(*buffer){
        if(){
            
        }
    }

}

void normalizarCampo2(char* buffer)
{

}
