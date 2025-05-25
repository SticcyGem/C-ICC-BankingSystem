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
    FILE *file = fopen(filename, "r");
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

int accLogin(Account *acc, AccountBackup*accb) {
    LOGGER();
    if (acc == NULL) {
        printf("\nError: Invalid account data\n");
        return 0;
    }

    printf("Account Number: ");
    if (!userInput("%d", &acc->accountNumber)) {
        printf("\nError: No input received\n");
        return 0;
    }
    LOG_STRUCT_CHANGE_VAL("Account Number", accb->accountNumber, acc->accountNumber);

    if (!loadAccountByNumber(acc->accountNumber, acc, ACC_FILE)) {
        printf("\nError: Account not found\n");
        return 0;
    }

    printf("Password: ");
    char password[100];
    if (!userInput("%s", password)) {
        printf("\nError: No input received\n");
        return 0;
    }

    if (strcmp(password, acc->password) != 0) {
        printf("\nError: Incorrect password\n");
        return 0;
    }
    return 1;
}

int accSignup(Account *acc, AccountBackup*accb) {
    LOGGER();
    if (acc == NULL) {
        printf("\nError: Invalid account data\n");
        return 0;
    }
    system("cls"); 
    printf("\n╔════════════════════════════════════════════════════════════╗\n");
    printf("║                     SIGN UP FORM                            ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    printf("Enter desired account number (6 digits): ");
    if (!userInput("%d", &acc->accountNumber)) {
        printf("\nError: No input received\n");
        pauseConsole();
        return 0;
    }

    if (acc->accountNumber < 100000 || acc->accountNumber > 999999) {
        printf("\nError: Account number must be 6 digits\n");
        pauseConsole();
        return 0;
    }
    LOG_STRUCT_CHANGE_VAL("Account Number", accb->accountNumber, acc->accountNumber);
    printf("\nEnter password (min 6 characters): ");
    if (!userInput("%s", acc->password)) {
        printf("\nError: No input received\n");
        pauseConsole();
        return 0;
    }

    if (strlen(acc->password) < 6) {
        printf("\nError: Password must be at least 6 characters long\n");
        pauseConsole();
        return 0;
    }

    printf("\nEnter first name: ");
    if (!userInput("%s", acc->firstname)) {
        printf("\nError: No input received\n");
        pauseConsole();
        return 0;
    }

    printf("Enter last name: ");
    if (!userInput("%s", acc->lastname)) {
        printf("\nError: No input received\n");
        pauseConsole();
        return 0;
    }

    printf("Enter middle name: ");
    if (!userInput("%s", acc->midname)) {
        printf("\nError: No input received\n");
        pauseConsole();
        return 0;
    }

    printf("\nEnter street: ");
    if (!userInput("%s", acc->street)) {
        printf("\nError: No input received\n");
        pauseConsole();
        return 0;
    }

    printf("Enter barangay: ");
    if (!userInput("%s", acc->barangay)) {
        printf("\nError: No input received\n");
        pauseConsole();
        return 0;
    }

    printf("Enter city: ");
    if (!userInput("%s", acc->city)) {
        printf("\nError: No input received\n");
        pauseConsole();
        return 0;
    }

    printf("Enter region: ");
    if (!userInput("%s", acc->region)) {
        printf("\nError: No input received\n");
        pauseConsole();
        return 0;
    }

    printf("Enter postal code: ");
    if (!userInput("%s", acc->postalCode)) {
        printf("\nError: No input received\n");
        pauseConsole();
        return 0;
    }

    acc->balance = 0.0f;
    acc->toDelete = 0;

    if (!saveOrUpdateAccount(acc, ACC_FILE)) {
        printf("\nError: Failed to create account\n");
        pauseConsole();
        return 0;
    }

    printf("\nAccount created successfully!\n");
    printf("Your account details:\n");
    printf("Account Number: %d\n", acc->accountNumber);
    printf("Name: %s, %s %s\n", acc->lastname, acc->firstname, acc->midname);
    printf("Address: %s, %s, %s, %s %s\n", 
    acc->street, acc->barangay, acc->city, acc->region, acc->postalCode);
    pauseConsole();
    return 1;
}

void accLogout(Account *acc, AccountBackup*accb) {
    LOGGER();
    initializeAcc(acc);
    initializeAccBackupFromAccount(accb, acc);
}

void accDelete(Account *acc, AccountBackup*accb) {
    LOGGER();
    if (acc == NULL) {
        printf("\nError: Invalid account data\n");
        pauseConsole();
        return;
    }

    system("cls");
    printf("\n╔════════════════════════════════════════════════════════════╗\n");
    printf("║                     DELETE ACCOUNT                          ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");

    printf("Are you sure you want to delete this account?\n\n");
    printf("Account Number : %d\n", acc->accountNumber);
    printf("Name          : %s, %s %s\n", acc->lastname, acc->firstname, acc->midname);
    printf("Balance       : ₱%.2f\n\n", acc->balance);
    printf("This action cannot be undone\n");
    printf("[1] No, keep my account\n");
    printf("[2] Yes, delete my account\n");
    printf("\nEnter your choice: ");

    char choice = menuInput();
    if (choice != '2') {
        printf("\nAccount deletion cancelled\n");
        pauseConsole();
        return;
    }

    acc->toDelete = 1;
    LOG_STRUCT_CHANGE_VAL("Deletion:", accb->toDelete, acc->toDelete);

    if (saveOrUpdateAccount(acc, ACC_FILE)) {
        printf("\nAccount successfully marked for deletion\n");
        printf("You will be logged out\n");
        pauseConsole();
        accLogout(acc, accb);
        system("cls"); 
    } else {
        printf("\nError: Failed to delete account\n");
        acc->toDelete = 0;
        pauseConsole();
    }
}

void accEditName(Account *acc, AccountBackup*accb) {
    LOGGER();
    guiAccEditName(acc);

    guiStringInput(acc, accb, GUI_INPUT_FIRSTNAME);
    guiStringInput(acc, accb, GUI_INPUT_LASTNAME);
    guiStringInput(acc, accb, GUI_INPUT_MIDNAME);

    initializeAccBackupFromAccount(accb, acc);
}

void accEditAddress(Account *acc, AccountBackup*accb) {
    LOGGER();
    if (acc == NULL) {
        printf("\nError: Invalid account data\n");
        pauseConsole();
        return;
    }

    system("cls");
    printf("\n╔════════════════════════════════════════════════════════════╗\n");
    printf("║                     EDIT ADDRESS                            ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    printf("Current Address:\n");
    printf("Street    : %s\n", acc->street);
    printf("Barangay  : %s\n", acc->barangay);
    printf("City      : %s\n", acc->city);
    printf("Region    : %s\n", acc->region);
    printf("Postal    : %s\n\n", acc->postalCode);

    printf("Enter new details (press Enter to keep current value):\n\n");
    printf("Street    : ");
    if (!userInput("%s", acc->street)) {
        strcpy(acc->street, accb->street);
    } else {
        LOG_STRUCT_CHANGE_STR("Street", accb->street, acc->street);
    }

    printf("Barangay  : ");
    if (!userInput("%s", acc->barangay)) {
        strcpy(acc->barangay, accb->barangay);
    } else {
        LOG_STRUCT_CHANGE_STR("Barangay", accb->barangay, acc->barangay);
    }

    printf("City      : ");
    if (!userInput("%s", acc->city)) {
        strcpy(acc->city, accb->city);
    } else {
        LOG_STRUCT_CHANGE_STR("City", accb->city, acc->city);
    }

    printf("Region    : ");
    if (!userInput("%s", acc->region)) {
        strcpy(acc->region, accb->region);
    } else {
        LOG_STRUCT_CHANGE_STR("Region", accb->region, acc->region);
    }

    printf("Postal    : ");
    if (!userInput("%s", acc->postalCode)) {
        strcpy(acc->postalCode, accb->postalCode);
    } else {
        LOG_STRUCT_CHANGE_STR("Postal Code", accb->postalCode, acc->postalCode);
    }

    if (saveOrUpdateAccount(acc, ACC_FILE)) {
        printf("\nAddress updated successfully\n");
    } else {
        printf("\nError: Failed to update address\n");
        strcpy(acc->street, accb->street);
        strcpy(acc->barangay, accb->barangay);
        strcpy(acc->city, accb->city);
        strcpy(acc->region, accb->region);
        strcpy(acc->postalCode, accb->postalCode);
    }
    pauseConsole();
}

void accEditPassword(Account *acc, AccountBackup*accb) {
    LOGGER();
    if (acc == NULL) {
        printf("\nError: Invalid account data\n");
        pauseConsole();
        return;
    }

    system("cls");
    printf("\n╔════════════════════════════════════════════════════════════╗\n");
    printf("║                     EDIT PASSWORD                           ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");

    char currentPassword[100];
    char newPassword[100];
    char confirmPassword[100];

    printf("Enter current password: ");
    if (!userInput("%s", currentPassword)) {
        printf("\nError: No input received\n");
        pauseConsole();
        return;
    }

    if (strcmp(currentPassword, acc->password) != 0) {
        printf("\nError: Current password is incorrect\n");
        pauseConsole();
        return;
    }

    printf("Enter new password: ");
    if (!userInput("%s", newPassword)) {
        printf("\nError: No input received\n");
        pauseConsole();
        return;
    }

    if (strlen(newPassword) < 6) {
        printf("\nError: Password must be at least 6 characters long\n");
        pauseConsole();
        return;
    }

    printf("Confirm new password: ");
    if (!userInput("%s", confirmPassword)) {
        printf("\nError: No input received\n");
        pauseConsole();
        return;
    }

    if (strcmp(newPassword, confirmPassword) != 0) {
        printf("\nError: New passwords do not match\n");
        pauseConsole();
        return;
    }

    strcpy(acc->password, newPassword);
    LOG_STRUCT_CHANGE_STR("Password", accb->password, acc->password);

    if (saveOrUpdateAccount(acc, ACC_FILE)) {
        printf("\nPassword updated successfully\n");
    } else {
        printf("\nError: Failed to update password\n");
        strcpy(acc->password, accb->password);
    }
    pauseConsole();
}

void accDisplay(const Account *acc) {
    LOGGER();
    if (acc == NULL) {
        printf("\nError: Invalid account data.\n");
        pauseConsole();
        return;
    }

    system("cls");
    printf("\n╔════════════════════════════════════════════════════════════╗\n");
    printf("║                     ACCOUNT DETAILS                         ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    printf("Account Number : %d\n", acc->accountNumber);
    printf("Name          : %s, %s %s\n", acc->lastname, acc->firstname, acc->midname);
    printf("Address       : %s\n", acc->street);
    printf("              : %s, %s\n", acc->barangay, acc->city);
    printf("              : %s %s\n", acc->region, acc->postalCode);
    printf("Balance       : ₱%.2f\n", acc->balance);
    printf("\nPress ENTER to continue...");
    pauseConsole();
}

void transDisplay(const Transaction *trans) {
    LOGGER();
}