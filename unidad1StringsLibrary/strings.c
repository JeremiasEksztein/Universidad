#include "strings.h"

/* Falta simplificar un monton de estas cosas, algunas funciones glibc literalmente usan solo memmove, strdup de C11*/

//String manipulation

char* stringCopy(char* dest, const char* src){

    char* a = dest;
    const char* b = src;

    while(*b){
        *a = *b;
        a++;
        b++;
    }

    return dest;
}

char* stringNCopy(char* dest, const char* src, size_t count){

    char* a = dest;
    const char* b = src;

    while(*b && count){
        *a = *b;
        a++;
        b++;
        count--;
    }

    return dest;
}

char* stringCat(char* dest, const char* src){

    char* a = dest;
    const char* b = src;

    while(*a) a++;

    while(*b){
        *a = *b;
        a++;
        b++;
    }

    return dest;
}

char* stringNCat(char* dest, const char* src, size_t count){

    char* a = dest;
    const char* b = src;

    while(*a) a++;

    while(*b && count){
        *a = *b;
        a++;
        b++;
        count--;
    }

    return dest;
}

char* stringDup(const char* src){

    size_t count = 0;
    char* a = src;

    while(*a){
        a++;
        count++;
    }

    char* dup = malloc(count);

    if(dup) return NULL;

    a -= count;

    while(*a){
        *dup = *a;
        a++;
        dup++;
    }

    return dup;
}

//Falta completar
char* stringNDup(const char* src, size_t size){

    size_t count = 0;
    char* a = src;

    while(*a){
        a++;
        count++;
    }

    char* dup = malloc(count);

    if(dup) return NULL;

    a -= count;

    while(*a){

    }

}

//String examination

size_t stringLen(const char* str){
    size_t count = 0;
    const char* a = str;

    while(*a){
        count++;
        a++;
    }

    return count;
}

int stringCmp(const char* leftString, const char* rightString){

    const char* a = leftString;
    const char* b = rightString;

    while(*a == *b){
        a++;
        b++;
    }

    return (*a - *b);
}

int stringNCmp(const char* leftString, const char* rightString, size_t count){

    const char* a = leftString;
    const char* b = rightString;

    while((*a == *b) and count){
        a++;
        b++;
        count--;
    }

    return (*a - *b);
}

char* stringChar(const char* str, int ch){

    const char* a = str;

    while(*a != ch){
        a++;
    }

    return a;
}

char* stringRChar(const char* str, int ch){

    const char* a = str;
    const char* last = NULL;

    while(*a){
        if(*a == ch){
            last = a;
        }
    }

    return last;
}

//Puede tener problemas con los limites de iteracion de b, en particular, el caracter \0
size_t stringSpan(const char* dest, const char* src){

    size_t bLen = stringLen(src);
    size_t count = 0;

    const char* a = dest;
    const char* b = src;

    while(*a && *b){

        b -= bLen;
        count++;

        while(*b != *a){
            b++;
        }

        a++;
    }

    return count;
}

//Tengo que fijarme como hacer aca, es el complemento de stringSpan
size_t stringCSpan(const char* dest, const char* src){

    size_t bLen = stringLen(src);
    size_t count = 0;

    const char* a = dest;
    const char* b = src;

    return count;
}

//Me tengo que fijar esta funcion tambien, como definir los limites de iteracion
char* stringPBreak(const char* dest, const char* breakset){

    size_t breakLen = stringLen(breakset);
    int breakFound = 0;

    const char* a = dest;
    const char* b = breakset;

    while(*a && *b){

        while(*a != *b){
            b++;
        }

        a++;
    }

    return a;
}

char* stringSubstring(const char* dest, const char* substr){

    int found = 0;

    const char* a = dest;
    const char* b = substr;

    while(*a && !found){

        a++;

        while(*a == *b){
            a++;
            b++;
        }

        found = *b ? 1 : 0;
    }

    return a;
}

//Character-array manipulation

void* memoryChar(const void* ptr, int ch, size_t count){

    const char* a = ptr;

    while(*a)

}

int isAlphaNum(int ch){
    return ()
}
