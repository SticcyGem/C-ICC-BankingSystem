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

int loadAccountByNumber(Account *acc, Account *accb, int accountNumber, const char *filename){
    LOGGER();
    FILE *file = fopen(filename, "rb");
    if (!file) {
        LOG_ERROR("Failed to open file to load: %s", filename);
        return 0;
    }
    Account temp;
    int found = 0;
    while (fread(&temp, sizeof(Account), 1, file) == 1) {
        if (temp.accountNumber == accountNumber) {

            if (accb->accountNumber != temp.accountNumber) {
                LOG_FILE_RETRIEVED_VAL("accountNumber", accb->accountNumber, temp.accountNumber);
            }
            if (strcmp(accb->password, temp.password) != 0) {
                LOG_FILE_RETRIEVED_STR("password", accb->password, temp.password);
            }
            if (strcmp(accb->firstname, temp.firstname) != 0) {
                LOG_FILE_RETRIEVED_STR("firstname", accb->firstname, temp.firstname);
            }
            if (strcmp(accb->lastname, temp.lastname) != 0) {
                LOG_FILE_RETRIEVED_STR("lastname", accb->lastname, temp.lastname);
            }
            if (strcmp(accb->midname, temp.midname) != 0) {
                LOG_FILE_RETRIEVED_STR("midname", accb->midname, temp.midname);
            }
            if (strcmp(accb->street, temp.street) != 0) {
                LOG_FILE_RETRIEVED_STR("street", accb->street, temp.street);
            }
            if (strcmp(accb->barangay, temp.barangay) != 0) {
                LOG_FILE_RETRIEVED_STR("barangay", accb->barangay, temp.barangay);
            }
            if (strcmp(accb->city, temp.city) != 0) {
                LOG_FILE_RETRIEVED_STR("city", accb->city, temp.city);
            }
            if (strcmp(accb->region, temp.region) != 0) {
                LOG_FILE_RETRIEVED_STR("region", accb->region, temp.region);
            }
            if (strcmp(accb->postalCode, temp.postalCode) != 0) {
                LOG_FILE_RETRIEVED_STR("postalCode", accb->postalCode, temp.postalCode);
            }
            if (accb->balance != temp.balance) {
                LOG_FILE_RETRIEVED_VAL("balance", accb->balance, temp.balance);
            }
            if (accb->toDelete != temp.toDelete) {
                LOG_FILE_RETRIEVED_VAL("toDelete", accb->toDelete, temp.toDelete);
            }

            *acc = temp;
            found = 1;
            LOG("Loaded account %d from file.", accountNumber);
            break;
        }
    }
    fclose(file);

    if (!found) {
        LOG_WARN("Account number %d not found in file.", accountNumber);
        printf("Account number %d not found in file.\n", accountNumber);
        return 0;
    } else {
        return 1;
    }
}

int saveOrUpdateAccount(Account *acc, Account *accb, const char *filename) {
    LOGGER();
    FILE *file = fopen(filename, "rb");
    if (!file) {
        LOG_WARN("Account file not found, creating new one: %s", filename);
        file = fopen(filename, "wb");
        if (!file) {
            LOG_ERROR("Failed to create file: %s", filename);
            return 0;
        }
        fclose(file);
        file = fopen(filename, "rb");
    }

    FILE *temp = fopen("data/temp.dat", "wb");
    if (!temp) {
        fclose(file);
        LOG_ERROR("Failed to open temp file for update.");
        return 0;
    }

    int found = 0;
    while (fread(accb, sizeof(Account), 1, file) == 1) {
        if (accb->toDelete == 1) {
            LOG("Skipping account %d marked for deletion.", accb->accountNumber);
            continue;
        }

        if (accb->accountNumber == acc->accountNumber && !found) {
            if (acc->toDelete == 1) {
                LOG("Skipping updated account %d marked for deletion.", acc->accountNumber);
                found = 1;
                continue;
            }

            LOG_FILE_CHANGE_VAL("accountNumber", accb->accountNumber, acc->accountNumber);
            LOG_FILE_CHANGE_STR("password", accb->password, acc->password);
            LOG_FILE_CHANGE_STR("firstname", accb->firstname, acc->firstname);
            LOG_FILE_CHANGE_STR("lastname", accb->lastname, acc->lastname);
            LOG_FILE_CHANGE_STR("midname", accb->midname, acc->midname);
            LOG_FILE_CHANGE_STR("street", accb->street, acc->street);
            LOG_FILE_CHANGE_STR("barangay", accb->barangay, acc->barangay);
            LOG_FILE_CHANGE_STR("city", accb->city, acc->city);
            LOG_FILE_CHANGE_STR("region", accb->region, acc->region);
            LOG_FILE_CHANGE_STR("postalCode", accb->postalCode, acc->postalCode);
            LOG_FILE_CHANGE_VAL("balance", accb->balance, acc->balance);
            LOG_FILE_CHANGE_VAL("toDelete", accb->toDelete, acc->toDelete);

            size_t written = fwrite(acc, sizeof(Account), 1, temp);
            if (written != 1) {
                LOG_ERROR("Failed to write updated account %d to temp file.", acc->accountNumber);
            } else {
                LOG("Updated account %d in temp file.", acc->accountNumber);
            }
            found = 1;
        } else {
            fwrite(accb, sizeof(Account), 1, temp);
        }
    }

    fclose(file);
    fclose(temp);

    if (!found && acc->toDelete != 1) {
        temp = fopen("data/temp.dat", "ab");
        if (temp) {
            size_t written = fwrite(acc, sizeof(Account), 1, temp);
            if (written != 1) {
                LOG_ERROR("Failed to append new account %d to temp file.", acc->accountNumber);
            } else {
                LOG("Added new account %d to temp file (append).", acc->accountNumber);
            }
            fclose(temp);
        } else {
            LOG_ERROR("Failed to open temp file for appending new account.");
        }
    } else if (!found && acc->toDelete == 1) {
        LOG("Skipping new account %d marked for deletion.", acc->accountNumber);
    }

    if (remove(filename) != 0) {
        LOG_ERROR("Failed to remove old file: %s", filename);
    } else {
        LOG("Removed old file: %s", filename);
    }

    if (rename("data/temp.dat", filename) != 0) {
        LOG_ERROR("Failed to rename temp file to: %s", filename);
    } else {
        LOG("Renamed temp file to: %s", filename);
    }

    return 1;
}

int getTransactionsByAcc(Transaction *list, int accountNumber, const char *filename){
    LOGGER();
    return 1;
}

int logTransaction(Transaction *trans, int accountNumber, const char *filename){
    LOGGER();
    return 1;
}