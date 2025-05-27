#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For system("cls") and atoi/atof if needed from original
#include <math.h>   // For roundf

// Assuming bankinglib.h contains Account struct definition and GUI_INPUT_... constants
#include "lib/bankinglib.h" 

// Forward declarations or assume these are in bankinglib.h or another included .c file
// These are functions CALLED BY the helper functions.
// It's assumed these are defined elsewhere, possibly in the same src/menu.c file but outside this block, or in another linked .c file.
extern int userInput(const char *format, ...);
extern void guiInputInvalidMessage();
extern void guiInputExitMessage();
extern void guiAccID();
extern void guiAccPass();
extern void guiAccCPass();
extern void guiAccFirstName();
extern void guiAccLastName();
extern void guiAccMidName();
extern void guiAccStreet();
extern void guiAccBarangay();
extern void guiAccCity();
extern void guiAccRegion();
extern void guiAccPostalCode();
extern void guiAccWithdrawBalance();
extern void guiAccDepositBalance();
extern int guiAuthenticatedInput(const char *fieldName, char *dest, const char *currentVal);
extern int guiSignUpInput(const char *fieldName, char *dest, const char *currentVal); 
extern void guiAccSignup(); 
extern int getNextAccountNumber(); 

// Logging macros (definitions are assumed to be elsewhere, e.g., bankinglib.h or pre-defined in menu.c)
#ifndef LOG
#define LOG(message) printf("LOG: %s\n", message)
#endif
#ifndef LOG_STRUCT_CHANGE_VAL
// Simulating a more specific macro for float, as the original might be int-only.
// If a proper float version exists, it should be used.
#define LOG_STRUCT_CHANGE_FLOAT(var, val) printf("LOG_STRUCT_CHANGE_VAL: %s changed to %.2f\n", #var, val)
#endif
#ifndef LOG_STRUCT_CHANGE_STR
#define LOG_STRUCT_CHANGE_STR(var, val) printf("LOG_STRUCT_CHANGE_STR: %s changed to %s\n", #var, val)
#endif
#ifndef LOGGER
#define LOGGER() printf("LOGGER: Entered %s\n", __func__)
#endif

// Helper function 1: handleAccountNumberSignup
int handleAccountNumberSignup(Account *acc, Account *accb) {
    LOGGER();
    // accb is not used in this specific function based on the case logic, but kept for signature consistency if needed elsewhere.
    (void)accb; // Mark accb as unused to prevent compiler warnings.
    
    char inputAccID[20]; // Used for string input then converted to int for validation
    int generatedAccNum = getNextAccountNumber(); 

    LOG("Using Account Number Signup GUI");
    guiAccID(); 
    
    printf("Your new Account ID will be: %d\n", generatedAccNum);
    printf("Please enter this Account ID to confirm: ");
    fflush(stdout);

    if (userInput("%19s", inputAccID) == 0) { 
        guiInputExitMessage();
        return 0;
    }

    if (atoi(inputAccID) != generatedAccNum) {
        guiInputInvalidMessage();
        return 0; 
    }

    acc->accountNumber = generatedAccNum; // Assign the integer directly
    LOG("Account Number assigned: %d", acc->accountNumber); // Log the assigned integer
    return 1;
}

// Helper function 2: handleAccountNumberLogin
int handleAccountNumberLogin(Account *accb) {
    LOGGER();
    LOG("Using Account Number Login GUI");
    int tempAccNumInt; // Declare temporary integer for input
    guiAccID(); 
    fflush(stdout);
    // Read input as an integer
    if (userInput("%d", &tempAccNumInt) == 0) { 
        guiInputExitMessage();
        return 0;
    }
    accb->accountNumber = tempAccNumInt; // Assign to the int field
    LOG("Account number %d entered for login.", accb->accountNumber); // Log the entered integer

    guiAccPass(); 
    fflush(stdout);
    if (userInput("%255s", accb->password) == 0) { 
        guiInputExitMessage();
        return 0;
    }
    LOG("Password input received for login."); 
    return 1;
}

// Helper function 3: handlePasswordSignup
int handlePasswordSignup(Account *acc, Account *accb) {
    LOGGER();
    (void)accb; 

    char passConfirm[256]; 
    int loop = 1;

    LOG("Using Password Signup GUI");
    do {
        guiAccPass(); 
        fflush(stdout);
        if (userInput("%255s", acc->password) == 0) { 
            guiInputExitMessage();
            return 0;
        }

        guiAccCPass(); 
        fflush(stdout);
        if (userInput("%255s", passConfirm) == 0) { 
            guiInputExitMessage();
            return 0;
        }

        if (strcmp(acc->password, passConfirm) != 0) {
            guiInputInvalidMessage();
        } else if (strlen(acc->password) < 8) { 
            guiInputInvalidMessage();
            printf("Password must be at least 8 characters long. Please try again.\n");
            fflush(stdout);
        } else {
            loop = 0; 
        }
    } while (loop);

    LOG_STRUCT_CHANGE_STR(acc->password, "********"); 
    return 1;
}

// Helper function 4: handleGenericFieldInput
int handleGenericFieldInput(Account *acc, Account *accb, int choice, int *isAuth) {
    LOGGER();
    int inputResult = 1; 
    char tempFieldName[64]; 

    switch (choice) {
        case GUI_INPUT_FIRSTNAME:
            strcpy(tempFieldName, "First Name");
            LOG("Using First Name Input GUI");
            if (!(*isAuth)) { 
                system("cls");
                guiAccSignup(); 
            }
            guiAccFirstName(); 
            fflush(stdout);
            if (*isAuth) {
                inputResult = guiAuthenticatedInput(tempFieldName, accb->firstname, acc->firstname);
            } else {
                inputResult = guiSignUpInput(tempFieldName, accb->firstname, ""); 
            }
            if (inputResult == 1) {
                 strcpy(acc->firstname, accb->firstname);
                 LOG_STRUCT_CHANGE_STR(acc->firstname, acc->firstname);
            }
            break;

        case GUI_INPUT_LASTNAME:
            strcpy(tempFieldName, "Last Name");
            LOG("Using Last Name Input GUI");
            guiAccLastName();
            fflush(stdout);
            if (*isAuth) {
                inputResult = guiAuthenticatedInput(tempFieldName, accb->lastname, acc->lastname);
            } else {
                inputResult = guiSignUpInput(tempFieldName, accb->lastname, "");
            }
            if (inputResult == 1) {
                strcpy(acc->lastname, accb->lastname);
                LOG_STRUCT_CHANGE_STR(acc->lastname, acc->lastname);
            }
            break;

        case GUI_INPUT_MIDNAME:
            strcpy(tempFieldName, "Middle Name");
            LOG("Using Middle Name Input GUI");
            guiAccMidName();
            fflush(stdout);
            if (*isAuth) {
                inputResult = guiAuthenticatedInput(tempFieldName, accb->midname, acc->midname);
            } else {
                inputResult = guiSignUpInput(tempFieldName, accb->midname, "");
            }
            if (inputResult == 1) {
                strcpy(acc->midname, accb->midname);
                LOG_STRUCT_CHANGE_STR(acc->midname, acc->midname);
            }
            break;

        case GUI_INPUT_STREET:
            strcpy(tempFieldName, "Street");
            LOG("Using Street Input GUI");
            if (!(*isAuth)) { 
                system("cls");
                guiAccSignup(); 
            }
            guiAccStreet();
            fflush(stdout);
            if (*isAuth) {
                inputResult = guiAuthenticatedInput(tempFieldName, accb->street, acc->street);
            } else {
                inputResult = guiSignUpInput(tempFieldName, accb->street, "");
            }
            if (inputResult == 1) {
                strcpy(acc->street, accb->street);
                LOG_STRUCT_CHANGE_STR(acc->street, acc->street);
            }
            break;

        case GUI_INPUT_BARANGAY:
            strcpy(tempFieldName, "Barangay");
            LOG("Using Barangay Input GUI");
            guiAccBarangay();
            fflush(stdout);
            if (*isAuth) {
                inputResult = guiAuthenticatedInput(tempFieldName, accb->barangay, acc->barangay);
            } else {
                inputResult = guiSignUpInput(tempFieldName, accb->barangay, "");
            }
            if (inputResult == 1) {
                strcpy(acc->barangay, accb->barangay);
                LOG_STRUCT_CHANGE_STR(acc->barangay, acc->barangay);
            }
            break;

        case GUI_INPUT_CITY:
            strcpy(tempFieldName, "City");
            LOG("Using City Input GUI");
            guiAccCity();
            fflush(stdout);
            if (*isAuth) {
                inputResult = guiAuthenticatedInput(tempFieldName, accb->city, acc->city);
            } else {
                inputResult = guiSignUpInput(tempFieldName, accb->city, "");
            }
            if (inputResult == 1) {
                strcpy(acc->city, accb->city);
                LOG_STRUCT_CHANGE_STR(acc->city, acc->city);
            }
            break;

        case GUI_INPUT_REGION:
            strcpy(tempFieldName, "Region");
            LOG("Using Region Input GUI");
            guiAccRegion();
            fflush(stdout);
            if (*isAuth) {
                inputResult = guiAuthenticatedInput(tempFieldName, accb->region, acc->region);
            } else {
                inputResult = guiSignUpInput(tempFieldName, accb->region, "");
            }
            if (inputResult == 1) {
                strcpy(acc->region, accb->region);
                LOG_STRUCT_CHANGE_STR(acc->region, acc->region);
            }
            break;

        case GUI_INPUT_POSTALCODE:
            strcpy(tempFieldName, "Postal Code");
            LOG("Using Postal Code Input GUI");
            guiAccPostalCode();
            fflush(stdout);
            if (*isAuth) {
                inputResult = guiAuthenticatedInput(tempFieldName, accb->postalCode, acc->postalCode);
            } else {
                inputResult = guiSignUpInput(tempFieldName, accb->postalCode, "");
            }
            if (inputResult == 1) {
                strcpy(acc->postalCode, accb->postalCode);
                LOG_STRUCT_CHANGE_STR(acc->postalCode, acc->postalCode);
            }
            break;
        
        default:
            LOG("Error: Invalid choice in handleGenericFieldInput");
            return 0; 
    }

    if (inputResult == 0) { 
        guiInputExitMessage(); 
        return 0;
    }
    
    return 1; 
}

// Helper function 5: handleWithdrawBalance
int handleWithdrawBalance(Account *acc, Account *accb, float *amount) {
    LOGGER();
    (void)accb; 

    char inputAmount[50];
    float withdrawAmount;
    int loop = 1;

    LOG("Using Withdraw Balance GUI");
    guiAccWithdrawBalance(); 
    
    do {
        printf("Enter amount to withdraw: "); 
        fflush(stdout);
        if (userInput("%49s", inputAmount) == 0) { 
            guiInputExitMessage();
            return 0;
        }
        char *endptr;
        withdrawAmount = strtof(inputAmount, &endptr);
        if (inputAmount == endptr || *endptr != '\0') { 
             guiInputInvalidMessage();
             printf("Invalid number format. Please enter a valid amount.\n");
             fflush(stdout);
             continue; 
        }
        withdrawAmount = roundf(withdrawAmount * 100) / 100; 

        if (withdrawAmount <= 0) {
            guiInputInvalidMessage();
            printf("Withdrawal amount must be positive.\n"); 
            fflush(stdout);
        } else if (withdrawAmount > acc->balance) {
            guiInputInvalidMessage();
            printf("Insufficient balance. Current balance: %.2f\n", acc->balance);
            fflush(stdout);
        } else {
            loop = 0; 
        }
    } while (loop);

    acc->balance -= withdrawAmount;
    acc->balance = roundf(acc->balance * 100) / 100; 
    *amount = withdrawAmount; 

    LOG_STRUCT_CHANGE_FLOAT(acc->balance, acc->balance);

    return 1;
}

// Helper function 6: handleDepositBalance
int handleDepositBalance(Account *acc, Account *accb, float *amount) {
    LOGGER();
    (void)accb; 
    
    char inputAmount[50];
    float depositAmount;
    int loop = 1;

    LOG("Using Deposit Balance GUI");
    guiAccDepositBalance(); 

    do {
        printf("Enter amount to deposit: "); 
        fflush(stdout);
        if (userInput("%49s", inputAmount) == 0) { 
            guiInputExitMessage();
            return 0;
        }
        char *endptr;
        depositAmount = strtof(inputAmount, &endptr);
        if (inputAmount == endptr || *endptr != '\0') { 
             guiInputInvalidMessage();
             printf("Invalid number format. Please enter a valid amount.\n");
             fflush(stdout);
             continue;
        }
        depositAmount = roundf(depositAmount * 100) / 100; 

        if (depositAmount <= 0) {
            guiInputInvalidMessage();
            printf("Deposit amount must be positive.\n");
            fflush(stdout);
        } else {
            loop = 0; 
        }
    } while (loop);

    acc->balance += depositAmount;
    acc->balance = roundf(acc->balance * 100) / 100; 
    *amount = depositAmount; 

    LOG_STRUCT_CHANGE_FLOAT(acc->balance, acc->balance);

    return 1;
}

// Main guiStringInput function refactored to use helper functions
int guiStringInput(Account *acc, Account *accb, int choice, int *isAuth, float *amount) {
    LOGGER();
    int success = 1; // Assume success initially, helpers return 0 on failure

    switch (choice) {
        case GUI_INPUT_ACCOUNTNUMBER_SIGNUP:
            success = handleAccountNumberSignup(acc, accb);
            break;
        case GUI_INPUT_ACCOUNTNUMBER_LOGIN:
            success = handleAccountNumberLogin(accb);
            break;
        case GUI_INPUT_PASSWORD_SIGNUP:
            success = handlePasswordSignup(acc, accb);
            break;
        case GUI_INPUT_FIRSTNAME:
        case GUI_INPUT_LASTNAME:
        case GUI_INPUT_MIDNAME:
        case GUI_INPUT_STREET:
        case GUI_INPUT_BARANGAY:
        case GUI_INPUT_CITY:
        case GUI_INPUT_REGION:
        case GUI_INPUT_POSTALCODE:
            success = handleGenericFieldInput(acc, accb, choice, isAuth);
            break;
        case GUI_INPUT_WITHDRAWBALANCE:
            success = handleWithdrawBalance(acc, accb, amount);
            break;
        case GUI_INPUT_DEPOSITBALANCE:
            success = handleDepositBalance(acc, accb, amount);
            break;
        default:
            LOG("Input GUI not Declared Properly, Skipping...");
            // The 'success' variable remains 1 by default for unhandled cases,
            // as per the instruction to "Keep the existing default..." and not explicitly set failure.
            break;
    }

    printf("[0m\n"); // Clear attributes and newline
    return success;
}
