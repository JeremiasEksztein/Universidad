#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

//Manejo de strings
char* stringCopy(char* dest, const char* src);
char* stringNCopy(char* dest, const char*, size_t n);
char* stringCat(char* dest, const char* src);
char* stringNCat(char* dest, const char* src, size_t n);
char* stringDup(const char* str);
char* stringNDup(const char* str, size_t n);

size_t stringLen(const char* str);
int stringCmp(const char* lhs, const char* rhs);
int stringCmpI(const char* lhs, const char* rhs);
int stringNCmp(const char* lhs, const char* rhs, size_t n);
int stringNCmpI(const char* lhs, const char* rhs, size_t n);
char* stringChar(const char* str, char ch);
char* stringRChar(const char* str, char ch);
size_t stringSpan(const char* dest, const char* src);
size_t stringCSpan(const char* dest, const char* breakset);
char* stringPBreak(const char* str, const char* delim);
char* stringTokenize(const char* str, const char* delim, char* memory);

//Manejo de memoria

void* memoryChar(const void* ptr, int ch, size_t count);
int memoryCmp(const void* lhs, const void* rhs, size_t count);
void* memorySet(void* ptr, int ch, size_t count);
void* memoryCopy(void* dest, const void* src, size_t count);
void* memoryMove(void* dest, const void* src, size_t count);
void* memoryCharCopy(void* dest, const void* src, int ch, size_t count);

#endif // CADENAS_H_INCLUDED
