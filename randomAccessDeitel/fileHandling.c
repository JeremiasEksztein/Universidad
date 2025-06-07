#include "fileHandling.h"

int updateAccount(FILE* accounts, Account updatedAccount)
{
    Account aux;

    FILE *temporary = fopen(TEMP_NAME, "wb");

    if(temporary == NULL) return -1;

    fread(&aux, sizeof(Account), 1, accounts);

    while(!feof(accounts)){
        if(aux.accountNumber == updatedAccount.accountNumber){
            fwrite(&updatedAccount, sizeof(Account), 1, temporary);
        }

        fwrite(&aux, sizeof(Account), 1, temporary);
        fread(&aux, sizeof(Account), 1, temporary);
    }

    fclose(accounts);
    fclose(temporary);

    rename(TEMP_NAME, FILE_NAME);
    remove(TEMP_NAME);

    return 0;
}

int insertAccount(FILE* accounts, Account newAccount)
{
    Account aux;

    int duplicate = 0;

    fread(&aux, sizeof(Account), 1, accounts);

    while(!feof(accounts)&& !duplicate){
        if(aux.accountNumber == newAccount.accountNumber) duplicate = 1;

        fread(&aux, sizeof(Account), 1, accounts);
    }

    fwrite()

    fclose(accounts);

    return 0;
}
