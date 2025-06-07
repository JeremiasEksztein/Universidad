#ifndef FILEHANDLING_H_INCLUDED
#define FILEHANDLING_H_INCLUDED

#include <stdio.h>

#define FILE_NAME "accounts.dat"
#define TEMP_NAME "auxiliary.temp"

typedef struct{
    int accountNumber;
    char firstName[15];
    char lastName[20];
    double balance;
}Account;

int updateAccount(FILE* accounts, Account updatedAccount);
int insertAccount(FILE* accounts, Account newAccount);
int deleteAccount(FILE* accounts, Account accountToDelete);
FILE* formatForPrint(FILE* accounts);

#endif // FILEHANDLING_H_INCLUDED
