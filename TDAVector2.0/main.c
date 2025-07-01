#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

typedef struct{
    char nom[25];
    char ape[25];
    int legajo;
    double sueldo;
}Empleado;

void imprimirEmpleados(const void* empl);
int compararSueldos(const void* emplA, const void* emplB);
void accionEmpleados(void* empl);

int main()
{
    Vector* vec = NULL;

    Empleado empleados[] = {
        {"Alan",      "Martinez",   1001, 50000.0},
        {"Ana",      "Lopez",      1002, 51000.0},
        {"Ana",      "Gomez",      1003, 51500.0},
        {"Andres",    "Ramirez",    1004, 52000.0},
        {"Beatriz",   "Lopez",      1005, 52000.0},
        {"Carlos",    "Gomez",      1006, 48000.0},
        {"Cecilia",   "Ortiz",      1007, 49000.0},
        {"Daniela",   "Perez",      1008, 53000.0},
        {"David",     "Herrera",    1009, 54000.0},
        {"Eduardo",   "Fernandez",  1010, 51000.0},
        {"Elena",     "Suarez",     1011, 55000.0},
        {"Emilia",    "Torres",     1012, 54500.0},
        {"Esteban",   "Rojas",      1013, 50000.0},
        {"Felipe",    "Castro",     1014, 49000.0},
        {"Fernando",  "Silva",      1015, 47500.0},
        {"Francisco", "Mendez",     1016, 47000.0},
        {"Gabriel",   "Vega",       1017, 46000.0},
        {"Gonzalo",   "Mora",       1018, 48000.0},
        {"Guillermo", "Ibarra",     1019, 52000.0},
        {"Hector",    "Sosa",       1020, 50000.0},
        {"Hugo",      "Luna",       1021, 49000.0},
        {"Ignacio",   "Salas",      1022, 50500.0},
        {"Ines",      "Campos",     1023, 49500.0},
    };

    vec = crearVector(vec, sizeof(Empleado));

    for(int i = 0; i < 23; i++){
        vectorAgregar(vec, empleados + i);
    }

    Empleado* empl = NULL;

    Empleado a = {"Jeremias", "Eksztein", 00, 50000};

    empl = &a;

    puts("Original");

    mostrarVector(vec, imprimirEmpleados);
    printf("%d\n", (int)vectorBuscar(vec, empl, compararSueldos, LINEAR_SEARCH));
    puts("COPIA");
    vectorOrdenar(vec, compararSueldos, SELECTION_SORT);
    printf("%d\n", vectorBuscar(vec, empl, compararSueldos, BINARY_SEARCH));
    mostrarVector(vec, imprimirEmpleados);
    /*

    puts("Copia");

    vectorReiniciarCursor(vec);

    while(!vectorCursorAlFinal(vec)){
        vectorLeer(vec, empl);
        imprimirEmpleados(empl);
    }
    */


    destruirVector(vec);

    return 0;
}

void imprimirEmpleados(const void* empl)
{
    const Empleado* tmp = empl;

    printf("%s - %s - %d - %0.2lf\n", tmp->nom, tmp->ape, tmp->legajo, tmp->sueldo);
}

int compararSueldos(const void* emplA, const void* emplB)
{
    const Empleado* tmpA = emplA;
    const Empleado* tmpB = emplB;

    int dif = tmpA->sueldo - tmpB->sueldo;

    return dif;
}

void accionEmpleados(void* empl)
{
    Empleado* tmp = empl;

    tmp->sueldo *= 1.1;
}
