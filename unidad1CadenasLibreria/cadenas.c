#include "cadenas.h"

//Manejo de memoria

void* memoryChar(const void* ptr, int ch, size_t count)
{
    const char* a = ptr;

    while(count && *a != ch){
        a++;
        count--;
    }

    return (void*)a;
}

int memoryCmp(const void* lhs, const void* rhs, size_t count)
{
    const char* a = lhs;
    const char* b = rhs;

    while(*a == *b && count){
        a++;
        b++;
        count--;
    }

    return *a - *b;
}

void* memorySet(void* ptr, int ch, size_t count)
{
    char* a = ptr;

    while(count){
        *a = ch;
        a++;
        count--;
    }

    return a;
}

void* memoryCopy(void* dest, const void* src, size_t count)
{
    char* tmpDest = dest;
    const char* tmpSrc = src;

    while(count){
        count--;
        *tmpDest = *tmpSrc;
        tmpDest++;
        tmpSrc++;
    }

    return tmpDest;
}

void* memoryMove(void* dest, const void* src, size_t count)
{
    void* tmp = malloc(count);

    memoryCopy(tmp, src, count);
    memoryCopy(dest, src, count);

    free(tmp);

    return dest;
}

void* memoryCharCopy(void* dest, const void* src, int ch, size_t count)
{
    char* a = dest;
    const char* b = src;

    while(count && *b != ch){
        *a = *b;
        a++;
        b++;
        count--;
    }

    return a;
}
