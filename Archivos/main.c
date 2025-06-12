#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR_ARCHIVO 1
#define TODO_OK 0

#define CANT_ARG 5
#define ERR_CANT_ARG 1

#define NOM_ARCHIVO 1
#define NOM_INDICE 2
#define PORCENTAJE 3
#define CODIGO 4

typedef struct{
    char codigo[11];
    size_t pos;
}Indice;

typedef struct{
    char codigo[11];
    char descripcion[51];
    float precio;
    int stock;
}Producto;

int generarProductosBin(const char* nomArchProds);
int generarArchivoIndice(const char* nomArchProds, const char* nomArchIndice);
int mostrarProductos(const char* nomArchProds);
int mostrarIndices(const char* nomArchIndice);
int actualizarPrecioProds(const char* nomArchProds, float porc);
int actualizarPrecioProd(const char* nomArchProds, const char* nomArchIndice, float porc, const char* cod);
size_t buscarPos(FILE* archIndice, const char* cod);

//Archivos.exe Productos.dat Indices.idx 10 UVA

int main(int argc, char* argv[]){

    if(argc != CANT_ARG) return ERR_CANT_ARG;

    //generarProductosBin(argv[1]);

    generarArchivoIndice(argv[NOM_ARCHIVO], argv[NOM_INDICE]);
    mostrarIndices(argv[NOM_INDICE]);

    puts("Antes: ");
    mostrarProductos(argv[NOM_ARCHIVO]);

    float porc = atof(argv[PORCENTAJE]);

    actualizarPrecioProds(argv[NOM_ARCHIVO], porc);

    puts("Despues: ");
    mostrarProductos(argv[NOM_ARCHIVO]);

    actualizarPrecioProd(argv[NOM_ARCHIVO], argv[NOM_INDICE], porc ,argv[CODIGO]);

    puts("Despues...........");
    mostrarProductos(argv[NOM_ARCHIVO]);

    return 0;
}

int generarProductosBin(const char* nomArchProds){

    Producto vProds[10]  = {
        {"PERA", "Pera Williams", 1500.50, 100},
        {"MANZANA", "Manzana Roja", 1200.00, 200},
        {"BANANA", "Banana Cavendish", 800.00, 300},
        {"NARANJA", "Naranja Valencia", 900.00, 150},
        {"KIWI", "Kiwi Hayward", 2000.00, 50},
        {"UVA", "Uva Concord", 2500.00, 80},
        {"FRESA", "Fresa Fragaria", 3000.00, 60},
        {"MANGO", "Mango Tommy Atkins", 4000.00, 30},
        {"PINIA", "Pinia Cayena Lisa", 5000.00, 20},
        {"SANDIA", "Sandía Crimson Sweet", 6000.00, 10}
    };

    FILE* arch = fopen(nomArchProds, "wb");

    if(!arch) return ERR_ARCHIVO;

    fwrite(vProds, sizeof(Producto), 10, arch);

    fclose(arch);

    return TODO_OK;
}

int generarArchivoIndice(const char* nomArchProds, const char* nomArchIndice){

    FILE* archIndice = fopen(nomArchIndice, "wb");

    if(!archIndice) return ERR_ARCHIVO;

    FILE* archProds = fopen(nomArchProds, "rb");

    if(!archProds) return ERR_ARCHIVO;

    Producto prod;

    Indice indice;

    while(fread(&prod, sizeof(Producto), 1, archProds)){

        strcpy(indice.codigo, prod.codigo);
        indice.pos = ftell(archProds) / sizeof(Producto) - 1;

        fwrite(&indice, sizeof(Indice), 1, archIndice);
    }

    fclose(archProds);
    fclose(archIndice);

    return TODO_OK;
}

int mostrarProductos(const char* nomArchProds){

    FILE* arch = fopen(nomArchProds, "rb");

    if(!arch) return ERR_ARCHIVO;

    Producto prod;

    while(fread(&prod, sizeof(Producto), 1, arch)){
        printf("%-10s%-20s%8.2f%4d\n", prod.codigo, prod.descripcion, prod.precio, prod.stock);
    }

    fclose(arch);

    return TODO_OK;
}

int mostrarIndices(const char* nomArchIndice){

    FILE* arch = fopen(nomArchIndice, "rb");

    if(!arch) return ERR_ARCHIVO;

    Indice ind;

    while(fread(&ind, sizeof(Indice), 1, arch)){
        printf("%s %d\n", ind.codigo, (int)ind.pos);
    }

    fclose(arch);

    return TODO_OK;
}

int actualizarPrecioProds(const char* nomArchProds, float porc){

    FILE* arch = fopen(nomArchProds, "r+b");

    if(!arch) return ERR_ARCHIVO;

    Producto prod;
    float factorIncr = 1 + porc / 100;

    while(fread(&prod, sizeof(Producto), 1, arch)){
        prod.precio *= factorIncr;

        fseek(arch, -(long)sizeof(Producto), SEEK_CUR);
        fwrite(&prod, sizeof(Producto), 1, arch);
        fflush(arch);
    }

    fclose(arch);

    return TODO_OK;
}

int actualizarPrecioProd(const char* nomArchProds, const char* nomArchIndice, float porc, const char* cod){

    FILE* archProds = fopen(nomArchProds, "r+b");

    if(!archProds) return ERR_ARCHIVO;

    FILE* archIndice = fopen(nomArchIndice, "rb");

    if(!archIndice) return ERR_ARCHIVO;

    Producto prod;

    size_t pos = buscarPos(archIndice, cod);
    float factorIncr = 1 + porc / 100;

    fseek(archProds, sizeof(Producto) * pos, SEEK_SET);
    fread(&prod, sizeof(Producto), 1, archProds);

    prod.precio *= factorIncr;

    printf("%f \n", prod.precio);

    fseek(archProds, -(long)sizeof(Producto), SEEK_CUR);
    fwrite(&prod, sizeof(Producto), 1, archProds);

    fclose(archProds);
    fclose(archIndice);

    return TODO_OK;
}

size_t buscarPos(FILE* ArchIndice, const char* cod){

    Indice ind;
    size_t posFinal = 0;

    while(fread(&ind, sizeof(Indice), 1, ArchIndice) && !posFinal){
        if(strcmp(ind.codigo, cod) == 0) posFinal = ind.pos;
    }

    return posFinal;
}
