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
 * ESPEJO, John Gabriel R.
 * 
 * @date 
 * May 2025
 */

#include "lib/bankinglib.h"

// Resets all fields of the Account structure to default values.
void initializeAcc(Account* acc) {
    LOG("Running: Account Initialization.");
    acc->accountNumber = 0;
    strcpy(acc->name, "");
    strcpy(acc->street, "");
    strcpy(acc->barangay, "");
    strcpy(acc->city, "");
    strcpy(acc->region, "");
    strcpy(acc->postalCode, "");
    acc->balance = 0.0f;
    strcpy(acc->password, "");
    acc->toDelete = 0;
}

int accLogin(){
    LOG("Running: Account Log in.");
    return 1;
}

int accSignup(){
    LOG("Running: Account Sign up.");
    return 1;
}