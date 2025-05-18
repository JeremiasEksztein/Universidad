#include "cadenas.h"

bool esLetra(char c)
{
    c = toupper(c);
    return (c >= 'A' && c <= 'Z');
}

char* normalizar(char* dest, const char* orig)
{
    register int i = 0, j = 0;

    dest = (char*)calloc(MAX_STRING_BUFFER, 1);

    while(*(orig + i) != '\0')
    {
        while(esLetra(*(orig + i)) == false && *(orig + i) != '\0')
        {
            ++i;
        }
        while(esLetra(*(orig + i)) == true && *(orig + i) != '\0')
        {
            *(dest + j) = *(orig + i);
            ++i;
            ++j;
        }

        *(dest + j) = 32;
        ++j;
    }

    *(dest + j - 1) = '\0';

    return palabraAMayusc(dest);
}

char* palabraAMayusc(char* buffer)
{
    register int i = 0, j = 0;

    while(*(buffer + i + 1) != '\0')
    {
        while(*(buffer + i) != 32 && *(buffer + i) != '\0')
        {
            if(j == 0 && *(buffer + j + i) > 'Z')
            {
                *(buffer + i) = toupper(*(buffer + i));
            }
            else if(j != 0)
            {
                *(buffer + i) = tolower(*(buffer + i));
            }

            ++i;
            ++j;
        }

        ++i;
        j = 0;
    }

    return buffer;
}
