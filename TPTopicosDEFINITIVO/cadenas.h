#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "comunesYErrores.h"

int esLetra(int ch);

char* cadenaCopiar(char* dest, const char* src);
char* cadenaConcatenar(char* dest, const char* src);
char* cadenaDuplicar(const char* str);
char* cadenaInvertir(char* str);
char* cadenaCapitalizar(char* str);
char* cadenaAMinuscula(char* str);
char* cadenaRemoverCaract(char* str, int ch);

int cadenaComparar(const char* lhs, const char* rhs);
//int cadenaCompararI(const char* lhs, const char* rhs);
size_t cadenaLongitud(const char* str);
char* cadenaCaracter(const char* str, int ch);
char* cadenaCaracterReverso(const char* str, int ch);

int memoryIntercambiar(void* a, void* b, size_t tamElem);

#endif // CADENAS_H_INCLUDED
