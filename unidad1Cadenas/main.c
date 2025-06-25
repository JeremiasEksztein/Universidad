#include <stdio.h>
#include <stdlib.h>
#include "cadenas.h"
#include "../uni

int esPalindromo(const char* str);

int main()
{
    char a[] = "aa";

    printf("%d\n", esPalindromo(a));

    return 0;
}
