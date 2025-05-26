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

void initializeAcc(Account *acc, Account *accb) {
    LOGGER();

    if (accb->accountNumber != 0) {
        LOG_STRUCT_CHANGE_VAL("accountNumber", accb->accountNumber, 0);
    }
    acc->accountNumber = 0;

    if (strcmp(accb->firstname, "") != 0) {
        LOG_STRUCT_CHANGE_STR("firstname", accb->firstname, "");
    }
    strcpy(acc->firstname, "");

    if (strcmp(accb->lastname, "") != 0) {
        LOG_STRUCT_CHANGE_STR("lastname", accb->lastname, "");
    }
    strcpy(acc->lastname, "");

    if (strcmp(accb->midname, "") != 0) {
        LOG_STRUCT_CHANGE_STR("midname", accb->midname, "");
    }
    strcpy(acc->midname, "");

    if (strcmp(accb->street, "") != 0) {
        LOG_STRUCT_CHANGE_STR("street", accb->street, "");
    }
    strcpy(acc->street, "");

    if (strcmp(accb->barangay, "") != 0) {
        LOG_STRUCT_CHANGE_STR("barangay", accb->barangay, "");
    }
    strcpy(acc->barangay, "");

    if (strcmp(accb->city, "") != 0) {
        LOG_STRUCT_CHANGE_STR("city", accb->city, "");
    }
    strcpy(acc->city, "");

    if (strcmp(accb->region, "") != 0) {
        LOG_STRUCT_CHANGE_STR("region", accb->region, "");
    }
    strcpy(acc->region, "");

    if (strcmp(accb->postalCode, "") != 0) {
        LOG_STRUCT_CHANGE_STR("postalCode", accb->postalCode, "");
    }
    strcpy(acc->postalCode, "");

    if (accb->balance != 0.0f) {
        LOG_STRUCT_CHANGE_VAL("balance", accb->balance, 0.0f);
    }
    acc->balance = 0.0f;

    if (accb->toDelete != 0) {
        LOG_STRUCT_CHANGE_VAL("toDelete", accb->toDelete, 0);
    }
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

int accLogin(Account *acc, Account *accb, int *isAuth) {
    LOGGER();
    guiAccLogin();

    if (!guiStringInput(acc, accb, GUI_INPUT_ACCOUNTNUMBER_LOGIN, isAuth)) {
        LOG("Operation canceled by user. [Account Number Log In]");
        guiAccLoginFailed();
        return 0;
    }

    if (!loadAccountByNumber(acc, accb, accb->accountNumber, "data/Account.txt")) {
        LOG("Invalid credentials.");
        guiAccLoginFailed();
        return 0;
    }

    initializeAccBackupFromAccount(acc, accb);
    return 1;
}

int accSignup(Account *acc, Account *accb, int *isAuth) {
    LOGGER();
    guiAccSignup();
    if (!guiStringInput(acc, accb, GUI_INPUT_ACCOUNTNUMBER_SIGNUP, isAuth)) {
        LOG("Operation canceled by user. [Account Number Sign Up\n");
        return 0;
    }
    if (!guiStringInput(acc, accb, GUI_INPUT_PASSWORD_SIGNUP, isAuth)) {
        LOG("Operation canceled by user. [Password Sign Up]\n");
        return 0;
    }
    if (!guiStringInput(acc, accb, GUI_INPUT_FIRSTNAME, isAuth)) {
        LOG("Operation canceled by user. [First Name Sign Up]\n");
        return 0;
    }
    if (!guiStringInput(acc, accb, GUI_INPUT_LASTNAME, isAuth)) {
        LOG("Operation canceled by user. [Last Name Sign Up]\n");
        return 0;
    }
    if (!guiStringInput(acc, accb, GUI_INPUT_MIDNAME, isAuth)) {
        LOG("Operation canceled by user. [Middle Name Sign Up]\n");
        return 0;
    }
    if (!guiStringInput(acc, accb, GUI_INPUT_STREET, isAuth)) {
        LOG("Operation canceled by user. [Middle Name Sign Up]\n");
        return 0;
    }
    if (!guiStringInput(acc, accb, GUI_INPUT_BARANGAY, isAuth)) {
        LOG("Operation canceled by user. [Middle Name Sign Up]\n");
        return 0;
    }
    if (!guiStringInput(acc, accb, GUI_INPUT_CITY, isAuth)) {
        LOG("Operation canceled by user. [Middle Name Sign Up]\n");
        return 0;
    }
    if (!guiStringInput(acc, accb, GUI_INPUT_REGION, isAuth)) {
        LOG("Operation canceled by user. [Middle Name Sign Up]\n");
        return 0;
    }
    if (!guiStringInput(acc, accb, GUI_INPUT_POSTALCODE, isAuth)) {
        LOG("Operation canceled by user. [Middle Name Sign Up]\n");
        return 0;
    }

    initializeAccBackupFromAccount(acc, accb);
    saveOrUpdateAccount(acc, accb, "data/Account.txt");
    pauseConsole();
    return 1;
}

void accLogout(Account *acc, Account *accb) {
    LOGGER();
    initializeAcc(acc, accb);
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

void accEditName(Account *acc, Account *accb, int *isAuth) {
    LOGGER();
    guiAccEditName();

    guiStringInput(acc, accb, GUI_INPUT_FIRSTNAME, isAuth);
    guiStringInput(acc, accb, GUI_INPUT_LASTNAME, isAuth);
    guiStringInput(acc, accb, GUI_INPUT_MIDNAME, isAuth);

    saveOrUpdateAccount(acc, accb, "data/Account.txt");
    pauseConsole();
}

void accEditAddress(Account *acc, Account *accb, int *isAuth) {
    LOGGER();
    guiAccEditAddress();

    guiStringInput(acc, accb, GUI_INPUT_STREET, isAuth);
    guiStringInput(acc, accb, GUI_INPUT_BARANGAY, isAuth);
    guiStringInput(acc, accb, GUI_INPUT_CITY, isAuth);
    guiStringInput(acc, accb, GUI_INPUT_REGION, isAuth);
    guiStringInput(acc, accb, GUI_INPUT_POSTALCODE, isAuth);

    saveOrUpdateAccount(acc, accb, "data/Account.txt");
    pauseConsole();
}
    
void accEditPassword(Account *acc, Account *accb, int *isAuth) {
    LOGGER();
    guiAccEditPassword();
    guiStringInput(acc, accb, GUI_INPUT_PASSWORD_SIGNUP, isAuth);

    saveOrUpdateAccount(acc, accb, "data/Account.txt");
}

void accDisplay(const Account *acc) {
    LOGGER();
}

void transDisplay(const Transaction *trans) {
    LOGGER();
}