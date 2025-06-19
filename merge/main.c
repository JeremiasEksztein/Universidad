#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

#define ERR_ARCHIVO -1
#define EXITO 0

typedef struct{
    char codigo[10];
    char nombre[50];
    int stock;
}Producto;

typedef struct{
    char codigo[10];
    int cantidad;
}Movimientos;

int generarProductos(const char* path);
int generarMovimientos(const char* path);
int mostrarProductos(const char* aFile, const char* bFile);
int actualizarProductos(const char* aFile, const char* bFile);

// merge.c
// Este programa genera dos archivos binarios: uno con productos y otro con movimientos.
// Compilar: gcc -o merge.exe main.c vector.c
// Ejecutar:
//merge.exe Productos.dat Movimientos.dat

int main(int argc, char* argv[])
{
    //Cambia la pagina del sistema para aceptar caracteres castellanos
    system("chcp 65001 > nul");

    const char* a = argv[1];
    const char* b = argv[2];

    generarProductos(a);
    generarMovimientos(b);

    mostrarProductos(a, b);

    actualizarProductos(a, b);

    return 0;
}

int generarProductos(const char* path)
{
    Producto producto[20] = {{"A001", "Leche entera", 159},
        {"A002", "Pan integral", 125},
        {"A003", "Café molido", 749},
        {"A004", "Azúcar común", 89},
        {"A005", "Harina 000", 110},
        {"A006", "Aceite girasol", 419},
        {"A007", "Yerba mate", 899},
        {"A008", "Galletitas dulces", 239},
        {"A009", "Arroz largo fino", 175},
        {"A010", "Fideos spaghetti", 139},
        {"A011", "Sal fina", 75},
        {"A012", "Jugo en polvo", 59},
        {"A013", "Mermelada frutilla", 299},
        {"A014", "Queso rallado", 589},
        {"A015", "Manteca", 449},
        {"A016", "Huevos x12", 799},
        {"A017", "Tomate triturado", 199},
        {"A018", "Gaseosa cola 2.25L", 649},
        {"A019", "Agua sin gas 2L", 299},
        {"A020", "Cerveza lata", 340}
    };

    FILE* file = fopen(path, "wb");

    if(!file){
        perror("Error al abrir el archivo de productos");
        return(ERR_ARCHIVO);
    }

    for(int i = 0; i < 20; i++) {
        fwrite(&producto[i], sizeof(Producto), 1, file);
    }

    fclose(file);
    // Implementación de la función para generar productos

    return 0;
}

int generarMovimientos(const char* path)
{
    Movimientos movimientos[20] = {
        {"A001",  5},
        {"A002", -3},
        {"A003", 10},
        {"A004",  2},
        {"A005", -1},
        {"A006",  8},
        {"A007", -4},
        {"A008",  3},
        {"A009",  6},
        {"A010", -2},
        {"A011",  1},
        {"A012",  7},
        {"A013", -3},
        {"A014",  4},
        {"A015",  9},
        {"A016", -5},
        {"A017",  2},
        {"A018",  6},
        {"A019", -2},
        {"A020",  0}
    };

    FILE* file = fopen(path, "wb");

    if(!file){
        perror("Error al abrir el archivo de movimientos");
        return(ERR_ARCHIVO);
    }

    for(int i = 0; i < 10; i++) {
        fwrite(&movimientos[i], sizeof(Movimientos), 1, file);
    }

    fclose(file);
    // Implementación de la función para generar movimientos

    return EXITO;
}

int mostrarProductos(const char* aFile, const char* bFile)
{
    FILE* fileA = fopen(aFile, "rb");
    FILE* fileB = fopen(bFile, "rb");

    if(!fileA || !fileB) {
        perror("Error al abrir los archivos");
        return(ERR_ARCHIVO);
    }

    Producto producto;
    Movimientos movimiento;

    printf("Productos:\n");
    while(fread(&producto, sizeof(Producto), 1, fileA)) {
        printf("Código: %s, Nombre: %s, Stock: %d\n", producto.codigo, producto.nombre, producto.stock);
    }

    printf("\nMovimientos:\n");
    while(fread(&movimiento, sizeof(Movimientos), 1, fileB)) {
        printf("Código: %s, Cantidad: %d\n", movimiento.codigo, movimiento.cantidad);
    }

    fclose(fileA);
    fclose(fileB);

    return EXITO;
}

int actualizarProductos(const char* aFile, const char* bFile)
{
    FILE* archProds = fopen(aFile, "rb");

    if(!archProds) {
        perror("Error al abrir el archivo de productos para actualizar");
        return(ERR_ARCHIVO);
    }

    FILE* archMovs = fopen(bFile, "rb");

    if(!archMovs) {
        perror("Error al abrir el archivo de movimientos para actualizar");
        fclose(archProds);
        return(ERR_ARCHIVO);
    }

    FILE* archProdsTemp = fopen("temp.dat", "wb");

    if(!archProdsTemp) {
        perror("Error al crear el archivo temporal para actualizar productos");
        fclose(archProds);
        fclose(archMovs);
        return(ERR_ARCHIVO);
    }

    Producto prod, prodNuevo;
    Movimientos mov;
    int comp;

    fread(&prod, sizeof(Producto), 1, archProds);
    fread(&mov, sizeof(Movimientos), 1, archMovs);

    while(!feof(archProds) && !feof(archMovs)){
        comp = strcmp(prod.codigo, mov.codigo);

        if(comp == 0){ //Prod con mov
            prod.stock += mov.cantidad;
            fread(&mov, sizeof(Movimientos), 1, archMovs);
        } else if(comp < 0){ //Prod sin mov
            fwrite(&prod, sizeof(Producto), 1, archProdsTemp);
            fread(&prod, sizeof(Producto), 1, archProds);
        } else { //Prod nuevo
            strcpy(prodNuevo.codigo, mov.codigo);
            prodNuevo.stock = mov.cantidad;
            prodNuevo.nombre[0] = '\0'; // Nombre vacío
            fwrite(&prodNuevo, sizeof(Producto), 1, archProdsTemp);
            fread(&mov, sizeof(Movimientos), 1, archMovs);

            while(strcmp(prodNuevo.codigo, mov.codigo) == 0 && !feof(archMovs)){
                prodNuevo.stock += mov.cantidad;
                fread(&mov, sizeof(Movimientos), 1, archMovs);
            }

            fwrite(&prodNuevo, sizeof(Producto), 1, archProdsTemp);
        }
    }

    while(!feof(archProds)){ //Prods sin mov
        fwrite(&prod, sizeof(Producto), 1, archProdsTemp);
        fread(&prod, sizeof(Producto), 1, archProds);
    }

    while(!feof(archMovs)){ //Prods nuevos
        strcpy(prodNuevo.codigo, mov.codigo);
        prodNuevo.stock = mov.cantidad;
        prodNuevo.nombre[0] = '\0'; // Nombre vacío

        while(strcmp(prodNuevo.codigo, mov.codigo) == 0 && !feof(archMovs)){
            prodNuevo.stock += mov.cantidad;
            fread(&mov, sizeof(Movimientos), 1, archMovs);
        }

        fwrite(&prodNuevo, sizeof(Producto), 1, archProdsTemp);
    }

    fclose(archProds);
    fclose(archMovs);
    fclose(archProdsTemp);

    remove(aFile);
    rename("tmp.dat", aFile);

    return EXITO;
}
