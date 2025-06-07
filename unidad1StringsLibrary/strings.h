#ifndef STRINGS_H_INCLUDED
#define STRINGS_H_INCLUDED

//Deben estar las funciones de strings, memory, y chars

//Strings

//String manipulation
//Returns a pointer to the beginning of dest, after having copied all the contents of src unto dest
char* stringCopy(char* dest, const char* src);
//Returns a pointer to the beginning of dest, after having copied up to count bytes from src unto dest
char* stringNCopy(char* dest, const char* src, size_t count);
//Return a pointer to the beginning of dest, after having concatenated src unto dest
char* stringCat(char* dest, const char* src);
//Returns a pointer to the beginning of dest, after having concatenated up to count bytes from src unto dest
char* stringNCat(char* dest, constr char* src, size_t count);
//Returns a pointer to the duplicate string of src
char* stringDup(const char* src);
//Returns a pointer to the duplicate string of src up to size bytes
char* stringNDup(const char* src, size_t size);
//size_t stringTransform(); Specific function to ease comparison between locale-specific strings

//String examination
//Returns the lenght of str
size_t stringLen(const char* str);
//Returns the lexicographical comparison between leftString and rightString
int stringCmp(const char* leftString, const char* rightString);
//Returns the lexicographical comparison between leftString and rightString up to count bytes
int stringNCmp(const char* leftString, const char* rightString, size_t count);
//int stringCmpLocale(); Specific function to compare between locale-specific strings
//Returns the first instance of the char ch within str, NULL if not found
char* stringChar(const char* str, int ch);
//Returns the last instance of the char ch within str, NULL if not found
char* stringRChar(const char* str, int ch);
//Returns the initial lenght of dest composed solely of characters from src
size_t stringSpan(const char* dest, const char* src);
//Returns the initial lenght of dest composed solely of characters not from src
size_t stringCSpan(const char* dest, const char* src);
//Returns pointer to the first instance in which a char from dest belongs to breakset
char* stringPBreak(const char* dest, const char* breakset);
//Returns pointer to the first instance of the string substr within dest
char* stringSubstring(const char* dest, const char* substr);
//char* stringTokenize(); Returns the next token to be scanned from a NULL terminated string

//Character-array manipulation tienen sentido estas?
void* memoryChar();
int memoryCmp();
void* memorySet();
void* memoryCopy();
void* memoryMove();
void* memoryCharCopy(); //POSIX implentation

//Characters

//Character classification tiene sentido esto?

int isAlphaNum(); //Retu
int isAlpha();
int isLower();
int isUpper();
int isDigit();
int isHexDigit();
int isControl();
int isGraph();
int isSpace();
int isBlank();
int isPrint(); //Problematic depends on the locale
int isPunct();

//Character manipulation
int toLower();
int toUpper();

//

#endif
