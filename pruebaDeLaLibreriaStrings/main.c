#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <ctype.h>
#include "..\unidad1CadenasLibreria\cadenas.h"

//1.6
int esPalindromo(const char* str);

//1.7
int stringToInt(const char* str);
long exponent(long base, int exp);

//1.8
int contarSubstrings(const char* str, const char* substr);

//1.9
char* normalizarCadena(char* str);

//1.10
char* desofuscar(char* str, char* clave);
int desofuscarAux(int ch, int offset, char* clave);

int main()
{
    //char a[] = "aa";
    //char num[] = "68938";
    //char prueba[] = "holahhhhhhhhhhhhhhhhhhhhhhhhhhhola";
    //char busca[] = "hola";
    //char prueba[] = "chau;chau;chau";
    char frase[] = "Nj qemh v ljs kraenkqbres; lj oqe qemh es oqevorme sgn ellhs --Istqt Asdmgj";
    char clave[] = "abcdghijkoqtuv";

    //printf("%d\n", esPalindromo(a));
    //printf("%d\n", stringToInt(num));
    //printf("%d\n", contarSubstrings(prueba, busca));
    //printf("%s\n", normalizarCadena(prueba));
    printf("%s\n", desofuscar(frase, clave));

    return 0;
}

int esPalindromo(const char* str)
{
    char* tmpInicio = (char*)str;
    char* tmpFin = (char*)str + stringLen(str) - 1;

    while(tmpInicio < tmpFin){
        if(*tmpInicio != *tmpFin){
            return 0;
        }
        tmpInicio++;
        tmpFin--;
    }

    return 1;
}

int stringToInt(const char* str)
{
    int ret = 0;
    int pos = stringLen(str) - 1;
    char* tmpStr = (char*)str;
    char digits[10] = "0123456789";

    if(stringSpan(str, digits) != stringLen(str)) return 0;

    while(*tmpStr){
        ret += (*tmpStr - '0') * exponent(10, pos);
        tmpStr++;
        pos--;
    }

    return ret;
}

long exponent(long base, int exp)
{
    long ret = base;

    if(exp == 0){
        return 1;
    }

    while(exp > 1){
        ret *= base;
        exp--;
    }

    return ret;
}

int contarSubstrings(const char* str, const char* substr)
{
    size_t count = 0;
    char* tmp = (char*)str;

    stringSubstring(tmp, substr);

    while(tmp != NULL){
        if((tmp = stringSubstring(tmp, substr))){
            tmp += stringLen(substr) - 1;
            count++;
        }
    }

    return count;
}

char* normalizarCadena(char* str)
{
    size_t trim = 0;
    char* tmp = str;
    char abecedario[26] = "abcdefghiklmnopqrstuvwxyzz";

    tmp += stringCSpan(stringToLower(str), abecedario);
    *tmp += 'A' - 'a';
    tmp++;

    while(*tmp){
        if(stringCSpan(tmp, abecedario) > 1){
            stringCopy(tmp, tmp + (trim = stringCSpan(tmp, abecedario)));
            tmp += stringLen(tmp) - trim;
            *tmp = '\0';
            tmp += -stringLen(tmp) + trim + 1;
        }

        tmp += stringSpan(tmp, abecedario) + 1;
    }

    printf("%ld\n", (long int)stringLen(str));

    return str;
}

char* desofuscar(char* str, char* clave)
{
    size_t count = 0;
    char* tmpClave = clave;
    char* tmpStr = str;

    while(*tmpStr != '\0'){

        while(isalpha(*tmpStr) && *tmpStr){
            tmpClave = clave;
            count++;
            while(*tmpClave != *tmpStr && *tmpStr && *tmpClave){
                tmpClave++;
            }

            if(*tmpClave != '\0'){
                *tmpStr = desofuscarAux(*tmpStr, count, clave);
            }

            tmpStr++;
        }

        count = 0;
        tmpStr++;

        printf("%c\n", *tmpStr);
    }

    return str;
}

int desofuscarAux(int ch, int offset, char* clave)
{
    char* ret = stringChar(clave, ch);

    if((stringLen(ret) - 1) >= offset){
        ret += offset;
    }else{
        offset -= stringLen(ret);
        ret = clave + offset;
    }

    return *ret;
}
