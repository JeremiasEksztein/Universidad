#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_LINEA 255

#define NOM_ARCH_STOCK "stock.csv"///Leemos de este
#define NOM_ARCH_CAMBIOS "cambios.csv" ///Leemos de este
#define NOM_ARCH_STOCK_TMP "stock.tmp" ///Usamos como auxiliar
#define NOM_ARCH_STOCK_BIN "stock.dat" ///Guardamos finalmente en este

typedef struct{
    int legajo;
    char nom[30];
    int stock;
}RegStock;

typedef struct{
    int legajo;
    int mov;
}RegCambio;

typedef int (*TxtABin)(char* , FILE*);

int unirArchivosStock(char* nomArchStock, char* nomArchCambios, char* nomArchTmp); ///A completar
int procesarProdNuevo(RegCambio* reg, FILE* archCambios, FILE* archTmp);

int trozarRegStock(FILE* arch, char* buffer, void* reg); ///Hecha
int trozarRegCambio(FILE* arch, char* buffer, void* reg); ///Hecha

int convertirTxtABin(char* nomArchTxt, char* nomArchBin, TxtABin convFunc);

int convertirStock(char* reg, FILE* arch);

int mostrarArchivoTxt(char* nomArchTxt);
int mostrarStockBin(char* nomArchBin);

int main()
{
    mostrarArchivoTxt(NOM_ARCH_STOCK);
    unirArchivosStock(NOM_ARCH_STOCK, NOM_ARCH_CAMBIOS, NOM_ARCH_STOCK_TMP);
    mostrarArchivoTxt(NOM_ARCH_STOCK);

    //convertirTxtABin(NOM_ARCH_STOCK, NOM_ARCH_STOCK_BIN, convertirStock);

    //mostrarStockBin(NOM_ARCH_STOCK_BIN);

    return 0;
}

int unirArchivosStock(char* nomArchStock, char* nomArchCambios, char* nomArchTmp)
{
    FILE* archStock = fopen(nomArchStock, "rt");

    if(!archStock) return 1;

    FILE* archCambios = fopen(nomArchCambios, "rt");

    if(!archCambios){
        fclose(archStock);
        return 1;
    }

    FILE* archTmp = fopen(nomArchTmp, "wt");

    if(!archTmp){
        fclose(archStock);
        fclose(archCambios);
        return 1;
    }

    RegStock stockTmp;
    RegCambio cambioTmp;
    char buffer[TAM_LINEA];
    int comp;

    trozarRegStock(archStock, buffer, &stockTmp);
    trozarRegCambio(archCambios, buffer, &cambioTmp);

    while(!feof(archStock) && !feof(archCambios)){

        comp = stockTmp.legajo - cambioTmp.legajo;

        if(comp == 0){ ///Registro de producto con sus registros de movimiento
            stockTmp.stock += cambioTmp.mov;
            trozarRegCambio(archCambios, buffer, &cambioTmp);
        }else if(comp < 0){ ///Cambio sin producto
            fprintf(archTmp, "%d;%s;%d\n", stockTmp.legajo, stockTmp.nom, stockTmp.stock);
            trozarRegStock(archStock, buffer, &stockTmp);
        }else{ ///Producto sin cambio
            procesarProdNuevo(&cambioTmp, archCambios, archTmp);
        }

    }

    if(!feof(archStock)){ ///Productos sin movimiento
        fprintf(archTmp, "%d;%s;%d\n", stockTmp.legajo, stockTmp.nom, stockTmp.stock);
        trozarRegStock(archStock, buffer, &stockTmp);
    }

    if(!feof(archCambios)){ ///Movimientos sin producto
        procesarProdNuevo(&cambioTmp, archCambios, archTmp);
    }

    fclose(archCambios);
    fclose(archStock);
    fclose(archTmp);

    ///Despues voy a poner para que sobreescriba el archivo, quiero ver que este todo bien

    return 0;
}

int trozarRegStock(FILE* arch, char* buffer, void* reg)
{
    RegStock* tmp = (RegStock*) reg;
    char* cursor = buffer;

    fgets(buffer, TAM_LINEA, arch);

    if((cursor = strrchr(buffer, '\n')) == NULL) return 2;

    *cursor = '\0';

    if((cursor = strrchr(buffer, ';')) == NULL) return 3;

    sscanf(cursor + 1, "%d", &tmp->stock);
    *cursor = '\0';

    if((cursor = strrchr(buffer, ';')) == NULL) return 3;

    sscanf(cursor + 1, "%s", tmp->nom);
    *cursor = '\0';

    sscanf(buffer, "%d", &tmp->legajo);

    return 0;
}

int trozarRegCambio(FILE* arch, char* buffer, void* reg)
{
    RegCambio* tmp = (RegCambio*) reg;
    char* cursor = buffer;

    fgets(buffer, TAM_LINEA, arch);

    if((cursor = strrchr(buffer, '\n')) == NULL) return 2;

    *cursor = '\0';

    if((cursor = strrchr(buffer, ';')) == NULL) return 3;

    sscanf(cursor + 1, "%d", &tmp->mov);
    *cursor = '\0';

    sscanf(buffer, "%d", &tmp->legajo);

    return 0;
}

int procesarProdNuevo(RegCambio* reg, FILE* archCambios, FILE* archTmp)
{
    RegStock nuevo;
    nuevo.legajo = reg->legajo;
    strcpy(nuevo.nom, "\0");
    nuevo.stock = reg->mov;
    char buffer[TAM_LINEA];

    trozarRegCambio(archCambios, buffer, reg);

    while(!feof(archCambios) && nuevo.legajo == reg->legajo){
        nuevo.stock += reg->mov;
        trozarRegCambio(archCambios, buffer, reg);
    }

    fprintf(archTmp, "%d;%s;%d\n", nuevo.legajo, nuevo.nom, nuevo.stock);

    return 0;
}

int mostrarArchivoTxt(char* nomArchTxt)
{
    FILE* arch = fopen(nomArchTxt, "rt");

    if(!arch) return 1;

    RegStock reg;

    fscanf(arch, "%d;%[^;];%d\n", &reg.legajo, reg.nom, &reg.stock);

    while(!feof(arch)){
        printf("Legajo: %d  Nombre: %s  Stock: %d\n", reg.legajo, reg.nom, reg.stock);
        fscanf(arch, "%d;%[^;];%d\n", &reg.legajo, reg.nom, &reg.stock);
    }

    fclose(arch);

    return 0;
}
