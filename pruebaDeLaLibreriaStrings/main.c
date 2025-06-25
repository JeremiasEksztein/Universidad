#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include "..\unidad1CadenasLibreria\cadenas.h"

int main()
{
    char a[20] = "24-6-2025";
    char* s = NULL;
    char b[20] = "-";
    char* c;

    stringTokenizeS(a, b, &c);
    printf("%s\n", a);
    stringTokenizeS(s, b, &c);
    printf("%s\n", s);

    return 0;
}
