/**
 * @file common.c
 * @brief Contains utility functions for the Banking System.
 * 
 * This file contains common helper functions that can be used across
 * the banking system application. These functions perform tasks such
 * as handling user input or managing common banking operations.
 * 
 * @author
 * GARGANTA, Arexzus B.
 * 
 * @date 
 * May 2025
 */

#include "lib/bankinglib.h"

char menuInput() {
    LOGGER();
    while (_kbhit()) getch();
    char ch = getch();
    LOG_KEY_INPUT(ch);
    return ch;
}

int userInput(const char *fmt, void *var) {
    LOGGER();
    char buffer[256];

    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';

        if (buffer[0] == '\0') {
            if (INPUT_DEBUG) {
                LOG("No input provided.");
            }
            return 0;  // Indicate no input
        }

        if (strcmp(fmt, "%d") == 0) {
            *(int *)var = atoi(buffer);
        } else if (strcmp(fmt, "%f") == 0) {
            *(float *)var = atof(buffer);
        } else if (strcmp(fmt, "%s") == 0) {
            strncpy((char *)var, buffer, 49);
            ((char *)var)[49] = '\0';
        } else {
            LOG("Unsupported format: '%s'", fmt);
            return 0;
        }

        if (INPUT_DEBUG) {
            LOG("Scanned input: format='%s', value='%s'", fmt, buffer);
        }

        return 1;
    } else {
        LOG("Error reading input");
        return 0;
    }
}

void pauseConsole() {
    LOGGER();
    printf("\nPress ENTER to continue...");
    while (_kbhit()) getch();
    char ch = getch();
    LOG_KEY_INPUT(ch);
}

void logReset() {
    LOGGER();
    FILE *logFile = fopen(DEBUG_LOG_FILE, "w");
    if (logFile) {
        fclose(logFile);
    } else {
        LOG("Error resetting log file");
    }
}

void openLogViewer() {
    LOGGER();
    #if DEBUG
        system("start \"LogViewerWindow\" powershell -NoExit -Command \"$host.UI.RawUI.WindowTitle = 'LogViewerWindow'; Get-Content log.txt -Wait\"");
    #endif
}

int fileExists(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

void example1(Account *acc, AccountBackup *accb) {
    LOGGER();

    char choice;

    do {
        system("cls");

        char mode;
        int accountNumber = 0;
        int loginSuccess = 0;

        while (1) {
            printf("[1.] Login\n");
            printf("[2.] Signup\n");
            mode = menuInput();
            system("cls");

            if (mode == '1') {
                if (!fileExists(EXAMPLE_ACC_FILE)) {
                    printf("No accounts exist yet. Please sign up first.\n");
                    pauseConsole();
                    system("cls");
                    continue;
                }
            
                printf("Enter account number to login: ");
                if (!userInput("%d", &accountNumber)) {
                    printf("No input received. Login canceled.\n");
                    pauseConsole();
                    system("cls");
                    continue;
                }
            
                example2(accountNumber, acc, EXAMPLE_ACC_FILE);
            
                if (acc->accountNumber != accountNumber) {
                    printf("Login failed. Try again.\n");
                    pauseConsole();
                    system("cls");
                    continue;
                }
            
                loginSuccess = 1;
                break;
            } else if (mode == '2') {
                initializeAccBackupFromAccount(accb, acc);

                acc->accountNumber = getNextAccountNumber(EXAMPLE_ACC_FILE);
                printf("Hardcoded Initialization for Sign Up (Check Logs)\n\n");
                LOG("Assigned new account number: %d", acc->accountNumber);

                strcpy(acc->firstname, "Emmanuel");
                LOG_STRUCT_CHANGE_STR("First Name", accb->firstname, acc->firstname);

                strcpy(acc->lastname, "Perez");
                LOG_STRUCT_CHANGE_STR("Last Name", accb->lastname, acc->lastname);

                strcpy(acc->midname, "Arriola");
                LOG_STRUCT_CHANGE_STR("Middle Name", accb->midname, acc->midname);

                acc->balance = 1000.50f;
                LOG_STRUCT_CHANGE_VAL("Balance", accb->balance, acc->balance);

                initializeAccBackupFromAccount(accb, acc);
                example3(acc, EXAMPLE_ACC_FILE);

                loginSuccess = 1;
                break;
            } else {
                printf("Invalid option selected.\n");
                pauseConsole();
            }
        }

        // Account Editing
        printf("Editing First Name (press Enter to skip): ");
        userInput("%s", acc->firstname);
        LOG_STRUCT_CHANGE_STR("First Name", accb->firstname, acc->firstname);

        printf("Editing Last Name (press Enter to skip): ");
        userInput("%s", acc->lastname);
        LOG_STRUCT_CHANGE_STR("Last Name", accb->lastname, acc->lastname);

        printf("Editing Middle Name (press Enter to skip): ");
        userInput("%s", acc->midname);
        LOG_STRUCT_CHANGE_STR("Middle Name", accb->midname, acc->midname);

        initializeAccBackupFromAccount(accb, acc);

        // Simulate user deposit
        float deposit = 0.0f;
        while (1) {
            printf("Deposit Amount (press Enter to skip): ");
            userInput("%f", &deposit);
            if (deposit == 0) {
                printf("No deposit made.\n");
                break;
            } else if (deposit < 0) {
                printf("Deposit must be greater than zero (0), please enter again.\n");
            } else {
                acc->balance += deposit;
                LOG_STRUCT_CHANGE_VAL("Balance", accb->balance, acc->balance);
                LOG("Deposited: %.2f", deposit);
                break;
            }
        }        

        // Save updated account
        example3(acc, EXAMPLE_ACC_FILE);
        pauseConsole();
        system("cls");

        // Simulate logout (clear struct)
        printf("Logging out...\n");
        initializeAcc(acc);
        pauseConsole();

        printf("Do you want to repeat? (y/n): ");
        choice = menuInput();
        system("cls");

    } while (choice == 'y' || choice == 'Y');
    LOG_ERROR("Exiting Program... (Reason: Debug Example was executed.)");
    exit(0);
}

void example2(int accountNumber, Account *acc, const char *filename) {
    LOGGER();
    printf("Check Logs! \n\n");
    Account oldAcc = *acc;

    FILE *file = fopen(filename, "rb");
    if (!file) {
        LOG_ERROR("Failed to open file to load: %s", filename);
        return;
    }

    Account temp;
    int found = 0;
    while (fread(&temp, sizeof(Account), 1, file) == 1) {
        if (temp.accountNumber == accountNumber) {

            // Log changes field by field before overwriting *acc
            if (oldAcc.accountNumber != temp.accountNumber) {
                LOG_FILE_RETRIEVED_VAL("accountNumber", oldAcc.accountNumber, temp.accountNumber);
            }
            if (strcmp(oldAcc.firstname, temp.firstname) != 0) {
                LOG_FILE_RETRIEVED_STR("firstname", oldAcc.firstname, temp.firstname);
            }
            if (strcmp(oldAcc.lastname, temp.lastname) != 0) {
                LOG_FILE_RETRIEVED_STR("lastname", oldAcc.lastname, temp.lastname);
            }
            if (strcmp(oldAcc.midname, temp.midname) != 0) {
                LOG_FILE_RETRIEVED_STR("midname", oldAcc.midname, temp.midname);
            }
            if (oldAcc.balance != temp.balance) {
                LOG_FILE_RETRIEVED_VAL("balance", oldAcc.balance, temp.balance);
            }
            // Add more fields as needed (For now, only 5 fields are logged in this demo) 

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
    }
}

void example3(Account *acc, const char *filename) {
    LOGGER();
    FILE *file = fopen(filename, "rb");
    if (!file) {
        LOG_WARN("Account file not found, creating new one: %s", filename);
        file = fopen(filename, "wb"); // Create an empty file
        if (!file) {
            LOG_ERROR("Failed to create file: %s", filename);
            return;
        }
        fclose(file);
        file = fopen(filename, "rb"); // Reopen in read mode
    }

    FILE *temp = fopen("../data/temp.dat", "wb");
    if (!temp) {
        fclose(file);
        LOG_ERROR("Failed to open temp file for update.");
        return;
    }

    Account tempAcc;
    int found = 0;
    while (fread(&tempAcc, sizeof(Account), 1, file) == 1) {
        if (tempAcc.accountNumber == acc->accountNumber && !found) {
            // Log field-by-field changes before writing updated data
            LOG_FILE_CHANGE_VAL("accountNumber", tempAcc.accountNumber, acc->accountNumber);
            LOG_FILE_CHANGE_STR("firstname", tempAcc.firstname, acc->firstname);
            LOG_FILE_CHANGE_STR("lastname", tempAcc.lastname, acc->lastname);
            LOG_FILE_CHANGE_STR("midname", tempAcc.midname, acc->midname);
            LOG_FILE_CHANGE_VAL("balance", tempAcc.balance, acc->balance);
            // Add more fields as needed (For now, only 5 fields are logged in this demo) 

            size_t written = fwrite(acc, sizeof(Account), 1, temp);
            if (written != 1) {
                LOG_ERROR("Failed to write updated account %d to temp file.", acc->accountNumber);
            } else {
                LOG("Updated account %d in temp file.", acc->accountNumber);
            }
            found = 1;  // Mark as found to prevent re-logging
        } else {
            fwrite(&tempAcc, sizeof(Account), 1, temp);
        }
    }

    fclose(file);
    fclose(temp);

    if (!found) {
        temp = fopen("../data/temp.dat", "ab");
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
    }

    if (remove(filename) != 0) {
        LOG_ERROR("Failed to remove old file: %s", filename);
    } else {
        LOG("Removed old file: %s", filename);
    }

    if (rename("../data/temp.dat", filename) != 0) {
        LOG_ERROR("Failed to rename temp file to: %s", filename);
    } else {
        LOG("Renamed temp file to: %s", filename);
    }
}