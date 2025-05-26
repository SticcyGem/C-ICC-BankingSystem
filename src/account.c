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

void initializeAccBackupFromAccount(const Account *acc, Account *accb) {
    LOGGER();
    accb->accountNumber = acc->accountNumber;

    strncpy(accb->firstname, acc->firstname, sizeof(accb->firstname));
    accb->firstname[sizeof(accb->firstname) - 1] = '\0';

    strncpy(accb->password, acc->password, sizeof(accb->password));
    accb->password[sizeof(accb->password) - 1] = '\0';

    strncpy(accb->lastname, acc->lastname, sizeof(accb->lastname));
    accb->lastname[sizeof(accb->lastname) - 1] = '\0';

    strncpy(accb->midname, acc->midname, sizeof(accb->midname));
    accb->midname[sizeof(accb->midname) - 1] = '\0';

    strncpy(accb->street, acc->street, sizeof(accb->street));
    accb->street[sizeof(accb->street) - 1] = '\0';

    strncpy(accb->barangay, acc->barangay, sizeof(accb->barangay));
    accb->barangay[sizeof(accb->barangay) - 1] = '\0';

    strncpy(accb->city, acc->city, sizeof(accb->city));
    accb->city[sizeof(accb->city) - 1] = '\0';

    strncpy(accb->region, acc->region, sizeof(accb->region));
    accb->region[sizeof(accb->region) - 1] = '\0';

    strncpy(accb->postalCode, acc->postalCode, sizeof(accb->postalCode));
    accb->postalCode[sizeof(accb->postalCode) - 1] = '\0';

    accb->balance = acc->balance;

    accb->toDelete = acc->toDelete;
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

int accLogin(Account *acc, Account*accb) {
    LOGGER();

    return 1;
}

int accSignup(Account *acc, Account *accb) {
    LOGGER();
    guiAccSignup();
    if (!guiStringInput(acc, accb, GUI_INPUT_ACCOUNTNUMBER_LOGIN)) {
        LOG("Operation canceled by user.\n");
        return 0;
    }
    guiStringInput(acc, accb, GUI_INPUT_PASSWORD_SIGNUP);
    return 1;
}

void accLogout(Account *acc, Account *accb) {
    LOGGER();
    initializeAcc(acc);
    initializeAccBackupFromAccount(acc, accb);
    LOG("Account logged out successfully.");
}

void accDelete(Account *acc, Account *accb) {
    acc->toDelete = 1;
    LOG_STRUCT_CHANGE_VAL("toDelete", accb->toDelete, acc->toDelete);
    saveOrUpdateAccount(acc, accb, "data/Account.txt");
    accLogout(acc, accb);
    LOGGER();
}

void accEditName(Account *acc, Account *accb) {
    LOGGER();
    guiAccEditName();

    guiStringInput(acc, accb, GUI_INPUT_FIRSTNAME);
    guiStringInput(acc, accb, GUI_INPUT_LASTNAME);
    guiStringInput(acc, accb, GUI_INPUT_MIDNAME);
    
    initializeAccBackupFromAccount(acc, accb);
    saveOrUpdateAccount(acc, accb, "data/Account.txt");
}

void accEditAddress(Account *acc, Account *accb) {
    LOGGER();
    guiAccEditAddress();

    guiStringInput(acc, accb, GUI_INPUT_STREET);
    guiStringInput(acc, accb, GUI_INPUT_BARANGAY);
    guiStringInput(acc, accb, GUI_INPUT_CITY);
    guiStringInput(acc, accb, GUI_INPUT_REGION);
    guiStringInput(acc, accb, GUI_INPUT_POSTALCODE);

    initializeAccBackupFromAccount(acc, accb);
}
    
void accEditPassword(Account *acc, Account *accb) {
    LOGGER();
}

void accDisplay(const Account *acc) {
    LOGGER();
}

void transDisplay(const Transaction *trans) {
    LOGGER();
}