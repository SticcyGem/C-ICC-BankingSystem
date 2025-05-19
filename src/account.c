/**
 * @file account.c
 * @brief Handles account creation, update, and deletion functionalities.
 * 
 * This module is responsible for manipulating account-related data, such as
 * registering new accounts, editing existing records, and deleting accounts
 * from the database. It interacts with the Accounts database stored in
 * "Account.txt" to perform these operations.
 * 
 * @authors
 * ANUTA, Vhien H.
 * LUMAKIN, Luke Gabriel C.
 * 
 * @date 
 * May 2025
 */

#include "lib/bankinglib.h"

void initializeAcc(Account *acc) {
    LOGGER();

    Account oldAcc = *acc;

    acc->accountNumber = 0;
    if (oldAcc.accountNumber != 0) {
        LOG_STRUCT_CHANGE_VAL("accountNumber", oldAcc.accountNumber, 0);
    }

    if (strcmp(oldAcc.password, "") != 0) {
        LOG_STRUCT_CHANGE_STR("password", oldAcc.password, "");
    }

    if (strcmp(oldAcc.firstname, "") != 0) {
        LOG_STRUCT_CHANGE_STR("firstname", oldAcc.firstname, "");
    }

    if (strcmp(oldAcc.lastname, "") != 0) {
        LOG_STRUCT_CHANGE_STR("lastname", oldAcc.lastname, "");
    }

    if (strcmp(oldAcc.midname, "") != 0) {
        LOG_STRUCT_CHANGE_STR("midname", oldAcc.midname, "");
    }

    if (strcmp(oldAcc.street, "") != 0) {
        LOG_STRUCT_CHANGE_STR("street", oldAcc.street, "");
    }

    if (strcmp(oldAcc.barangay, "") != 0) {
        LOG_STRUCT_CHANGE_STR("barangay", oldAcc.barangay, "");
    }

    if (strcmp(oldAcc.city, "") != 0) {
        LOG_STRUCT_CHANGE_STR("city", oldAcc.city, "");
    }

    if (strcmp(oldAcc.region, "") != 0) {
        LOG_STRUCT_CHANGE_STR("region", oldAcc.region, "");
    }

    if (strcmp(oldAcc.postalCode, "") != 0) {
        LOG_STRUCT_CHANGE_STR("postalCode", oldAcc.postalCode, "");
    }

    if (oldAcc.balance != 0.0f) {
        LOG_STRUCT_CHANGE_VAL("balance", oldAcc.balance, 0.0f);
    }

    if (oldAcc.toDelete != 0) {
        LOG_STRUCT_CHANGE_VAL("toDelete", oldAcc.toDelete, 0);
    }

    strcpy(acc->password, "");
    strcpy(acc->firstname, "");
    strcpy(acc->lastname, "");
    strcpy(acc->midname, "");
    strcpy(acc->street, "");
    strcpy(acc->barangay, "");
    strcpy(acc->city, "");
    strcpy(acc->region, "");
    strcpy(acc->postalCode, "");
    acc->balance = 0.0f;
    acc->toDelete = 0;
}

void initializeAccBackupFromAccount(AccountBackup *backup, const Account *acc) {
    LOGGER();
    backup->accountNumber = acc->accountNumber;

    strncpy(backup->firstname, acc->firstname, sizeof(backup->firstname));
    backup->firstname[sizeof(backup->firstname) - 1] = '\0';

    strncpy(backup->password, acc->password, sizeof(backup->password));
    backup->password[sizeof(backup->password) - 1] = '\0';

    strncpy(backup->lastname, acc->lastname, sizeof(backup->lastname));
    backup->lastname[sizeof(backup->lastname) - 1] = '\0';

    strncpy(backup->midname, acc->midname, sizeof(backup->midname));
    backup->midname[sizeof(backup->midname) - 1] = '\0';

    strncpy(backup->street, acc->street, sizeof(backup->street));
    backup->street[sizeof(backup->street) - 1] = '\0';

    strncpy(backup->barangay, acc->barangay, sizeof(backup->barangay));
    backup->barangay[sizeof(backup->barangay) - 1] = '\0';

    strncpy(backup->city, acc->city, sizeof(backup->city));
    backup->city[sizeof(backup->city) - 1] = '\0';

    strncpy(backup->region, acc->region, sizeof(backup->region));
    backup->region[sizeof(backup->region) - 1] = '\0';

    strncpy(backup->postalCode, acc->postalCode, sizeof(backup->postalCode));
    backup->postalCode[sizeof(backup->postalCode) - 1] = '\0';

    backup->balance = acc->balance;

    backup->toDelete = acc->toDelete;
}


void initializeTrans(Transaction* tran){
    LOGGER();
    tran->accountNumber = 0;
    tran->transactionType = 0;
    strcpy(tran->date, "");
    tran->amount = 0.0f;
}

int getNextAccountNumber(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return 100000;

    Account acc;
    int maxAccNum = 100000;
    while (fread(&acc, sizeof(Account), 1, file) == 1) {
        if (acc.accountNumber > maxAccNum) {
            maxAccNum = acc.accountNumber;
        }
    }
    fclose(file);
    return maxAccNum + 1;
}

int accLogin(Account *acc, AccountBackup*accb){
    LOGGER();
    printf("Account Number: ");
    userInput("%d", &acc->accountNumber);
    LOG_STRUCT_CHANGE_VAL("Account Number:", accb->accountNumber, acc->accountNumber);
    return 1;
}

int accSignup(Account *acc, AccountBackup*accb){
    LOGGER();
    printf("Account Number: ");
    userInput("%d", &acc->accountNumber);
    LOG_STRUCT_CHANGE_VAL("Account Number:", accb->accountNumber, acc->accountNumber);
    return 1;
}

void accLogout(Account *acc, AccountBackup*accb) {
    LOGGER();
    initializeAcc(acc);
    initializeAccBackupFromAccount(accb, acc);
}

void accDelete(Account *acc, AccountBackup*accb) {
    LOGGER();
    acc->toDelete = 1;
    LOG_STRUCT_CHANGE_VAL("Deletion:", accb->toDelete, acc->balance);
}

void accEditName(Account *acc) {
    LOGGER();
}

void accEditAddress(Account *acc) {
    LOGGER();
}

void accEditPassword(Account *acc) {
    LOGGER();
}

void accDisplay(const Account *acc) {
    LOGGER();
    guiAccDisplay(acc);
}

void transDisplay(const Transaction *trans) {
    LOGGER();
}