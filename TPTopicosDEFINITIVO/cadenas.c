#include "cadenas.h"

int esLetra(int ch)
{
    return ((ch >= 'a' && ch <= 'z') && (ch >= 'A' || ch <= 'Z'));
}

char* cadenaCopiar(char* dest, const char* src)
{
    char* d = dest;
    char* s = (char*)src;

    while(*s){
        *d = *s;
        d++;
        s++;
    }

    return dest;
}

char* cadenaConcatenar(char* dest, const char* src)
{
    char* d = dest + cadenaLongitud(dest) - 1;
    char* s = (char*)src;

    while(*s){
        *d = *s;
        d++;
        s++;
    }

    return dest;
}

char* cadenaDuplicar(const char* str)
{
    char* dup = malloc(cadenaLongitud(str));

    if(!dup) return NULL;

    memcpy(dup, str, cadenaLongitud(str));

    return dup;
}

char* cadenaInvertir(char* str)
{
    char* i = str;
    char* f = str + cadenaLongitud(str) - 1;
    char tmp;

    while(i < f){
        tmp = *i;
        *i = *f;
        *f = tmp;
        i++;
        f--;
    }

    return str;
}

char* cadenaCapitalizar(char* str)
{
    char* i = str;

    *i = toupper(*i);
    i++;

    while(*i){
        *i = tolower(*i);
        i++;
    }

    return str;
}

char* cadenaAMinuscula(char* s)
{
    char* i = s;

    while(*i){
        *i = tolower(*i);
        i++;
    }

    return s;
}

int cadenaComparar(const char* lhs, const char* rhs)
{
    char* l = (char*)lhs;
    char* r = (char*)rhs;

    if(cadenaLongitud(l) > cadenaLongitud(r)){
        return 1;
    }else{
        return -1;
    }

    while(*l == *r){
        l++;
        r++;
    }

    return (*l - *r);
}

size_t cadenaLongitud(const char* str)
{
    char* ori = (char*)str;
    char* i = (char*)str;

    while(*i){
        i++;
    }

    return (i - ori);
}

char* cadenaCaracter(const char* str, int ch)
{
    char* i = (char*)str;

    while(*i && *i != ch){
        i++;
    }

    return i;
}

char* cadenaCaracterReverso(const char* str, int ch)
{
    char* ori = (char*)str;
    char* i = (char*)str + cadenaLongitud(str);

    while(i != ori && *i != ch){
        i--;
    }

    return i;
}

int memoryIntercambiar(void* a, void* b, size_t tamElem)
{
    void* tmp = malloc(tamElem);

    memcpy(tmp, a, tamElem);
    memcpy(a, b, tamElem);
    memcpy(b, tmp, tamElem);

    return EXITO;
}
