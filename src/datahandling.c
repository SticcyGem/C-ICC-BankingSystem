/**
 * @file datahandling.c
 * @brief Provides low-level file handling and database manipulation utilities.
 * 
 * Contains helper functions for reading, writing, searching, and modifying
 * text-based databases (Account.txt, StatementOfAccount.txt). Supports 
 * algorithms like line-by-line scanning, appending, and overwriting.
 * 
 * @author 
 * BALANTAC, Neil Justine R.
 * 
 * @date 
 * May 2025
 */

#include "lib/bankinglib.h"

long getline(char **lineptr, size_t *n, FILE *stream) {
    if (!lineptr || !n || !stream) return -1;

    size_t pos = 0;
    int c;

    if (*lineptr == NULL || *n == 0) {
        *n = 128;
        *lineptr = malloc(*n);
        if (*lineptr == NULL) return -1;
    }

    while ((c = fgetc(stream)) != EOF) {
        if (pos + 1 >= *n) {
            *n *= 2;
            char *new_ptr = realloc(*lineptr, *n);
            if (!new_ptr) return -1;
            *lineptr = new_ptr;
        }
        (*lineptr)[pos++] = (char)c;
        if (c == '\n') break;
    }

    if (pos == 0 && c == EOF) return -1;

    (*lineptr)[pos] = '\0';
    return pos;
}

int loadAccountByNumber(int accountNumber, Account *acc, const char *filename){
    LOGGER();
    return 1;
}

int saveOrUpdateAccount(Account *acc, const char *filename){
    LOGGER();
    return 1;
}

int getTransactionsByAcc(int accountNumber, Transaction *list, const char *filename){
    LOGGER();
    return 1;
}

int logTransaction(int accountNumber, Transaction *trans, const char *filename){
    LOGGER();
    return 1;
}