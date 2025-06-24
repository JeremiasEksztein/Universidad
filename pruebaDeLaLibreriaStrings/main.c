#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\unidad1CadenasLibreria\cadenas.h"

int main()
{
    char a[] = "Hello, World";
    char b[20];

    //memoryChar(a, ' ', 20);

    //printf("%d\n", memoryCmp(a, b, 20));

    //memorySet(a, 'A', strlen(a));
    //printf("%s\n", a);

    memoryCharCopy(b, a, ' ',strlen(a));
    printf("%s\n", b);



    return 0;
}
