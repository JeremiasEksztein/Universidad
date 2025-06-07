#include <stdio.h>
#include <stdlib.h>
#include "fileHandling.h"

int main()
{
    Account account = {0, "", "", 0.0};

    FILE* accountsFile = fopen(FILE_NAME, "wb");

    if(accountsFile == NULL) return -1;

    int i;

    for(i = 0; i < 100; i++){
        fwrite(&account, sizeof(Account), 1, accountsFile);
    }

    fclose(accountsFile);



    return 0;
}
