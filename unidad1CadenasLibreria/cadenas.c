#include "cadenas.h"

//Manejo de cadenas

char* stringCopy(char* dest, const char* src)
{
    return memoryCopy(dest, src, stringLen(src));
}

char* stringNCopy(char* dest, const char* src, size_t n)
{
    size_t tmp = stringLen(src);
    return memoryCopy(dest, src, tmp > n ? n : tmp);
}

char* stringCat(char* dest, const char* src)
{
    char* tmp = dest + stringLen(dest);

    return memoryCopy(tmp, src, stringLen(src));
}

char* stringNCat(char* dest, const char* src, size_t n)
{
    size_t tmpLen = stringLen(src);
    char*  tmp = dest + stringLen(dest);

    return memoryCopy(tmp, src, tmpLen > n ? n : tmpLen);
}

char* stringDup(const char* str)
{
    return memoryDup(str, stringLen(str));
}

char* stringNDup(const char* str, size_t n)
{
    size_t tmpLen = stringLen(str);
    return memoryDup(str, (tmpLen > n) ? n : tmpLen);
}

char* stringCharDup(const char* str, int ch)
{
    size_t count = 0;
    char* tmp = (char*)str;

    while(*tmp && *tmp != ch){
        tmp++;
        count++;
    }

    return stringNDup(str, count);
}

/*
char* stringRCharDup(const char* str, int ch)
{
    size_t count = stringLen(str);
    char* tmp = (char*)str + stringLen(str);
    char* ret = NULL;

    while(count && ret == NULL){
        if(*tmp == ch){
            ret = tmp;
        }

        tmp--;
        count--;
    }

    return stringNDup(ret, stringLen(ret));
}
*/

char* stringToUpper(char* str)
{
    char* a = str;

    while(*a){
        *a = toupper(*a);
        a++;
    }

    return str;
}

char* stringToLower(char* str)
{
    char* a = str;

    while(*a){
        *a = tolower(*a);
        a++;
    }

    return str;
}

char* stringReverse(char* str)
{
    //HACER

    return NULL;

}

size_t stringLen(const char* str)
{
    size_t count = 0;
    char* tmp = (char*)str;

    while(*tmp){
        tmp++;
        count++;
    }

    return count;
}

int stringCmp(const char* lhs, const char* rhs)
{
    return stringLen(lhs) == stringLen(rhs) ? memoryCmp(lhs, rhs, stringLen(lhs)) : stringLen(lhs) - stringLen(rhs);
}

int stringCmpI(const char* lhs, const char* rhs)
{
    //Podria ser que estas funciones capitalicen las strings que le son pasadas

    stringToUpper((char*)lhs);
    stringToUpper((char*)rhs);

    return stringCmp(lhs, rhs);
}

int stringNCmp(const char* lhs, const char* rhs, size_t n)
{
    size_t tmpLen = stringLen(lhs);

    return (tmpLen > n) ? memoryCmp(lhs, rhs, n) : memoryCmp(lhs, rhs, tmpLen);

    /*
    if(stringLen(lhs) == stringLen(rhs)){

    }
    else{
        return tmpLen - stringLen(rhs);
    }*/
}

int stringNCmpI(const char* lhs, const char* rhs, size_t n)
{
    stringToUpper((char*)lhs);
    stringToUpper((char*)rhs);

    return stringNCmp(lhs, rhs, n);
}

char* stringChar(const char* str, int ch)
{
    char* tmp = (char*)str;
    char* ret = NULL;

    while(*tmp && ret == NULL){
        if(*tmp == ch){
            ret = tmp;
        }
        tmp++;
    }

    return ret;
}

char* stringRChar(const char* str, int ch)
{
    size_t count = stringLen(str);
    char* tmp = (char*)str + stringLen(str);
    char* ret = NULL;

    while(count && ret == NULL){
        if(*tmp == ch){
            ret = tmp;
        }
        tmp--;
        count--;
    }

    return ret;
}

size_t stringSpan(const char* dest, const char* src)
{
    size_t count = 0;
    char* tmpDest = (char*)dest;
    char* tmpSrc = (char*)src;

    while(*tmpDest && *tmpSrc){
        while(*tmpSrc && *tmpDest != *tmpSrc){
            tmpSrc++;
        }

        if(*tmpSrc){
            tmpDest++;
            count++;
            tmpSrc = (char*)src;
        }
    }

    return count;
}

size_t stringCSpan(const char* dest, const char* src)
{
    size_t count = 0;
    char* tmpDest = (char*)dest;
    char* tmpSrc = (char*)src;

    while(*tmpDest && *tmpDest != *tmpSrc){
        while(*tmpSrc && *tmpDest != *tmpSrc){
            tmpSrc++;
        }

        if(!(*tmpSrc)){
            tmpDest++;
            count++;
            tmpSrc = (char*)src;
        }
    }

    return count;
}

char* stringPBreak(const char* str, const char* breakset)
{
    char* tmpStr = (char*)str;
    char* tmpBreak = (char*)breakset;

    while(*tmpStr){
        while(*tmpBreak){
            if(*tmpBreak == *tmpStr){
                return tmpStr;
            }

            tmpBreak++;
        }

        tmpStr++;
        tmpBreak = (char*)breakset;
    }

    return NULL;
}

char* stringTokenize(const char* str, const char* delim, char* memory, char* token)
{
    if(delim == NULL) return NULL;

    char* tmpData = NULL;
    char* tmpOrig = NULL;
    char* aux = NULL;
    char* tmpDelim = (char*)delim;

    if(str == NULL){
        tmpData = memory;
    }else{
        tmpData = (char*)str;
    }

    tmpOrig = tmpData;

    while(*tmpData){
        while(*tmpDelim){
            if(*tmpData == *tmpDelim){
                memoryCopy(token, tmpOrig, stringLen(tmpOrig) - stringLen(tmpData + 1));
                aux = memoryChar(token, *tmpDelim, stringLen(token));
                *aux = '\0';

                memoryCopy(memory, tmpData + 1, stringLen(tmpData));

                return token;
            }

            tmpDelim++;
        }

        tmpData++;
        tmpDelim = (char*)delim;
    }

    token = NULL;

    return token;
}

//SACADO DE GLIBC
char* stringTokenizeS(char* str, const char* delim, char** memory)
{
    char* end;

    if(str == NULL){
        str = *memory;
    }

    if(*str == '\0'){
        *memory = str;
    }

    str += stringSpan(str, delim);

    if(*str == '\0'){
        *memory = str;
        return NULL;
    }

    end = str + stringCSpan(str, delim);

    if(*end == '\0'){
        *memory = end;
        return str;
    }

    *end = '\0';
    *memory = end + 1;

    return str;
}

char* stringSubstring(const char* str, const char* substr)
{
    if(substr == NULL) return NULL;

    char* tmpStr = (char*)str;
    char* tmpAux = tmpStr;
    char* tmpSubstr = (char*)substr;

    while(*tmpStr){
        while(*tmpAux == *tmpSubstr){
            tmpAux++;
            tmpSubstr++;
        }

        if(*tmpSubstr == '\0'){
            return tmpStr;
        }

        tmpStr++;
        tmpAux = tmpStr;
        tmpSubstr = (char*)substr;
    }

    return NULL;
}

char* stringSubstringI(const char* str, const char* substr)
{
    stringToUpper((char*)str);
    stringToUpper((char*)substr);

    return stringSubstring(str, substr);
}

//Manejo de memoria

void* memoryDup(const void* ptr, size_t count)
{
    void* a = malloc(count);

    if(!a) return NULL;

    memoryCopy(a, ptr, count);

    return a;
}

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

    return dest;
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
