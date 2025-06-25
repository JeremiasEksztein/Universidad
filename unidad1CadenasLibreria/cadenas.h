#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

//Manejo de strings
char* stringCopy(char* dest, const char* src); //Probado
char* stringNCopy(char* dest, const char*, size_t n); //Probado
char* stringCat(char* dest, const char* src); //Probado
char* stringNCat(char* dest, const char* src, size_t n); //Probado
char* stringDup(const char* str); //Probado
char* stringNDup(const char* str, size_t n); //Probado
char* stringCharDup(const char* str, int ch); //Probado
//char* stringRCharDup(const char* str, int ch); NO FUNCIONA
char* stringToUpper(char* str); //Probado
char* stringToLower(char* str); //Probado
char* stringReverse(char* str); //A HACER

size_t stringLen(const char* str); //Probado
int stringCmp(const char* lhs, const char* rhs); //Probado
int stringCmpI(const char* lhs, const char* rhs); //Probado
int stringNCmp(const char* lhs, const char* rhs, size_t n); //Probado
int stringNCmpI(const char* lhs, const char* rhs, size_t n); //Probado
char* stringChar(const char* str, int ch); //Probado
char* stringRChar(const char* str, int ch); //Probado
size_t stringSpan(const char* dest, const char* src); //Probado
size_t stringCSpan(const char* dest, const char* src); //Probado
char* stringPBreak(const char* str, const char* breakset); //Probado
/*char* stringTokenize(const char* str, const char* delim, char* memory, char* token); // A HACER*/
char* stringTokenize(char* str, const char* delim, char** savePtr); // INSPIRADO EN GLIBC y OTROS
char* stringSubstring(const char* str, const char* substr); // Probado
char* stringSubstringI(const char* str, const char* substr); // Probado, mas o menos

//Manejo de memoria

void* memoryDup(const void* ptr, size_t count);
void* memoryChar(const void* ptr, int ch, size_t count);
int memoryCmp(const void* lhs, const void* rhs, size_t count);
void* memorySet(void* ptr, int ch, size_t count);
void* memoryCopy(void* dest, const void* src, size_t count);
void* memoryMove(void* dest, const void* src, size_t count);
void* memoryCharCopy(void* dest, const void* src, int ch, size_t count);
void* memoryInterchange(void* dest, void* src, size_t count);

//Manejo de caracteres


#endif // CADENAS_H_INCLUDED
