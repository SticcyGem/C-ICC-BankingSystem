/**
 * @file bankinglib.h
 * @brief Header file containing global constants, structures, and function prototypes for the Banking System.
 * 
 * This header defines constants, data structures for representing accounts and transactions,
 * and function prototypes for the banking system operations, such as creating, updating, 
 * deleting accounts, performing transactions, and handling statements.
 * 
 * @note The function implementations are located in respective source files:
 *       - Account-related functions are defined in `account.c`.
 *       - Transaction-related functions are defined in `transaction.c`.
 *       - Data handling functions are in `datahandling.c`.
 *       - Common utility functions are in `common.c`.
 * 
 * @author
 * PEREZ, Emmanuel A.
 * 
 * @date
 * May 2025
 */

#ifndef BANKINGLIB_H
#define BANKINGLIB_H
 
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "debug.h"
 
/// @brief File paths for storing account and transaction data.
#define ACC_FILE   "Account.txt"
#define TRANS_FILE "StatementOfAccount.txt"
#define TEMP_FILE  "data/temp.txt"
#define EXAMPLE_ACC_FILE "data/example_account.txt"

// -------------------- START UP MENU CHOICES --------------------
#define MENU_STARTUP_NORMAL   '1' /**< Startup menu option: Normal Mode */
#define MENU_STARTUP_DEBUG    '2' /**< Auth menu option: Debug Mode */
 
// -------------------- AUTH MENU CHOICES --------------------
 
#define MENU_AUTH_LOGIN    '1' /**< Auth menu option: Log In */
#define MENU_AUTH_SIGNUP   '2' /**< Auth menu option: Sign Up */
#define MENU_AUTH_CREDITS  '3' /**< Auth menu option: View Credits */
#define MENU_AUTH_EXIT     '4' /**< Auth menu option: Exit the program */

// -------------------- MAIN MENU CHOICES --------------------
 
#define MENU_MAIN_INQUIRY    '1' /**< Main menu option: Account Inquiry */
#define MENU_MAIN_DEPOSIT    '2' /**< Main menu option: Deposit money */
#define MENU_MAIN_WITHDRAW   '3' /**< Main menu option: Withdraw money */
#define MENU_MAIN_SETTINGS   '4' /**< Main menu option: Account Settings */
#define MENU_MAIN_LOGOUT     '5' /**< Main menu option: Log out */
 
// -------------------- INQUIRY MENU CHOICES --------------------
 
#define MENU_INQUIRY_BALANCE   '1' /**< Inquiry menu option: Check Balance */
#define MENU_INQUIRY_STATEMENT '2' /**< Inquiry menu option: View Statement of Account */
#define MENU_INQUIRY_BACK      '3' /**< Inquiry menu option: Return to Main Menu */
 
// -------------------- DELETE ACCOUNT MENU --------------------
 
#define MENU_DELETE_NO   '1' /**< Delete confirmation: No */
#define MENU_DELETE_YES  '2' /**< Delete confirmation: Yes */

// -------------------- STRUCTURE --------------------

/** 
 * @struct Account
 * @brief Represents a bank account with personal and authentication details.
 * 
 * Stores the account holder's personal information, address, balance,
 * and authentication data, along with a flag for account deletion status.
 */
typedef struct {
    int accountNumber;     /**< Unique identifier for the account. */
    char password[100];    /**< Password for account authentication. */
    char firstname[50];    /**< First name of the account holder. */
    char lastname[50];     /**< Last name of the account holder. */
    char midname[50];      /**< Middle name of the account holder. */
    char street[50];       /**< Street address of the account holder. */
    char barangay[50];     /**< Barangay (local community) of the account holder. */
    char city[50];         /**< City of the account holder. */
    char region[50];       /**< Region of the account holder. */
    char postalCode[5];    /**< Postal code of the account holder. */
    float balance;         /**< Current balance of the account. */
    int toDelete;          /**< Flag: 0 = active, non-zero = marked for deletion. */
} Account;

/**
 * @struct AccountBackup
 * @brief A backup copy of an account's personal and financial information.
 *
 * This struct stores dynamically allocated strings for personal details 
 * and fixed-size arrays for postal code and balance. It is used to 
 * keep a copy of an Account's important data for comparison or restoration.
 * 
 * Mostly for Logging Purposes
 */
typedef struct {
    char firstname[50];
    char lastname[50];
    char midname[50];
    char street[50];
    char barangay[50];
    char city[50];
    char region[50];
    char postalCode[5];
    float balance;
} AccountBackup;

/**
 * @struct Transaction
 * @brief Represents a financial transaction.
 * 
 * Stores details about transactions such as deposits and withdrawals.
 */
typedef struct {
    int accountNumber;        /**< The account number associated with the transaction. */
    int transactionType;      /**< Type of the transaction (0 = deposit, 1 = withdrawal). */
    char date[20];            /**< Date the transaction took place. */
    float amount;             /**< Amount of money involved in the transaction. */
} Transaction;

// -------------------- FUNCTION PROTOTYPES --------------------

/***
 *    ____ _  _ _  _ ____ ___ _ ____ _  _     _  _ ____ _ _  _    ___  ____ ____ ____ ____ ____ _  _ 
 *    |___ |  | |\ | |     |  | |  | |\ | .   |\/| |__| | |\ |    |__] |__/ |  | | __ |__/ |__| |\/| 
 *    |    |__| | \| |___  |  | |__| | \| .   |  | |  | | | \|    |    |  \ |__| |__] |  \ |  | |  |                                                                                                 
 */


void handleAuthMenu(int *isAuth, Account *acc);

void handleMainMenu(int *isAuth, Account *acc, AccountBackup *accb, Transaction *trans);

void handleInquiryMenu(const Account *acc, const Transaction *trans);

void handleSettingsMenu(Account *acc);

void handleEditMenu(Account *acc);

void handleDeleteMenu(Account *acc);

/***
 *    ____ _  _ _  _ ____ ___ _ ____ _  _     ____ ____ _  _ ____ ____ ____ _    
 *    |___ |  | |\ | |     |  | |  | |\ | .   | __ |___ |\ | |___ |__/ |__| |    
 *    |    |__| | \| |___  |  | |__| | \| .   |__] |___ | \| |___ |  \ |  | |___ 
 *                                                                               
 */
void example1(Account *acc, AccountBackup *accb);

void example2(int accountNumber, Account *acc, const char *filename);

void example3(Account *acc, const char *filename);

/**
 * @brief Pauses the program until the user presses ENTER.
 * 
 * This function waits for the user to hit ENTER before continuing.
 */
void pauseConsole();

/**
 * @brief Clears the console screen.
 * 
 * This function clears the console output, providing a clean slate for new output.
 */
char menuInput();

/**
 * @brief Reads user input from the console.
 * 
 * This function takes a format string and a variable to store the input.
 * It uses `scanf` to read the input based on the provided format.
 * 
 * @param fmt Format string for input (e.g., "%d", "%s").
 * @param var Pointer to the variable where the input will be stored.
 * @return 1 if successful, 0 otherwise.
 */
int userInput(const char *fmt, void *var);



/***
 *    ____ _  _ _  _ ____ ___ _ ____ _  _     ____ _  _ _ 
 *    |___ |  | |\ | |     |  | |  | |\ | .   | __ |  | | 
 *    |    |__| | \| |___  |  | |__| | \| .   |__] |__| | 
 *                                                        
 */

/**
 * @brief Displays the credit screen of the banking system.
 * 
 * This function clears the console and shows the ASCII art credit screen,
 * including contributors, project roles, and GitHub links. 
 * It waits for the user to press ENTER before returning to the previous menu.
 */
void guiCredit();

/**
 * @brief Displays the authentication menu for the banking system.
 * 
 * This function clears the console screen and shows the ASCII art logo followed by
 * a menu with options for logging in, signing up, viewing credits, or exiting the program.
 * The menu allows the user to select an action based on their input.
 * 
 * The menu consists of the following options:
 * - [1.] Log In
 * - [2.] Sign Up
 * - [3.] Credits
 * - [4.] Exit Program
 * 
 * @see accLogin(), accSignup(), guiCredits()
 */
void guiAuthMenu();

/**
 * @brief Displays the main menu for the banking system.
 * 
 * This function prints an ASCII art-styled header and displays the main user options
 * available in the banking system. It is typically shown after successful login or
 * user authentication.
 * 
 * The menu consists of the following options:
 * - [1.] Inquiry
 * - [2.] Deposit
 * - [3.] Withdraw
 * - [4.] Account Setting
 * - [5.] Log Out
 * 
 * The function does not take user input; it only displays the menu.
 * User input should be handled in the main application loop.
 * 
 * @see accInquiry(), accDeposit(), accWithdraw(), accSetting(), guiAuthMenu()
 */
void guiMainMenu(const Account *acc);

/**
 * @brief Displays the inquiry menu for account-related inquiries.
 * 
 * This function prints an ASCII art-styled header and displays the options
 * available for account inquiries. It is typically shown after the user selects
 * the inquiry option from the main menu.
 * 
 * The menu consists of the following options:
 * - [1.] Check Balance
 * - [2.] View Statement of Account
 * - [3.] Back to Main Menu
 * 
 * The function does not take user input; it only displays the menu.
 * User input should be handled in the main application loop.
 */
void guiAccSettingMenu();

/**
 * @brief Displays the account settings menu for editing or deleting account details.
 * 
 * This function prints an ASCII art-styled header and displays the options
 * available for account settings. It is typically shown after the user selects
 * the account setting option from the main menu.
 * 
 * The menu consists of the following options:
 * - [1.] Display Account Details
 * - [2.] Edit Account Details
 * - [3.] Delete Account
 * - [4.] Back to Main Menu
 * 
 * The function does not take user input; it only displays the menu.
 * User input should be handled in the main application loop.
 */
void guiAccEditingMenu();

/**
 * @brief Displays the account deletion confirmation menu.
 * 
 * This function prints an ASCII art-styled header and displays the options
 * available for confirming account deletion. It is typically shown after the user
 * selects the delete option from the account settings menu.
 * 
 * The menu consists of the following options:
 * - [1.] No (Cancel Deletion)
 * - [2.] Yes (Confirm Deletion)
 * 
 * The function does not take user input; it only displays the menu.
 * User input should be handled in the main application loop.
 */
void guiAccDeleteMenu();

/**
 * @brief Displays the account inquiry menu for checking balance and statement.
 * 
 * This function prints an ASCII art-styled header and displays the options
 * available for account inquiries. It is typically shown after the user selects
 * the inquiry option from the main menu.
 * 
 * The menu consists of the following options:
 * - [1.] Check Balance
 * - [2.] View Statement of Account
 * - [3.] Back to Main Menu
 * 
 * The function does not take user input; it only displays the menu.
 * User input should be handled in the main application loop.
 */
void guiAccInquiryMenu();

void guiAccDisplay(const Account *acc);

/***
 *    ____ ____ ____ ____ _  _ _  _ ___     ____ ____ ____ ____ ___ _ ____ _  _ 
 *    |__| |    |    |  | |  | |\ |  |  .   |    |__/ |___ |__|  |  | |  | |\ | 
 *    |  | |___ |___ |__| |__| | \|  |  .   |___ |  \ |___ |  |  |  | |__| | \| 
 *                                                                              
 */

/**
 * @brief Initializes the fields of an Account structure to default values.
 * 
 * This function sets numeric fields to 0 or 0.0, and string fields to empty strings.
 * Useful for clearing or resetting an Account before use.
 * 
 * @param acc Pointer to the Account structure to initialize.
 */
void initializeAcc(Account* acc);

/**
 * @brief Initializes the fields of an AccountBackup structure to default values.
 * 
 * This function sets numeric fields to 0 or 0.0, and string fields to empty strings.
 * Useful for clearing or resetting an AccountBackup before use.
 * 
 * @param backup Pointer to the AccountBackup structure to initialize.
 */
void initializeAccBackupFromAccount(AccountBackup *backup, const Account *acc);

/**
 * @brief Initializes the fields of a Transaction structure to default values.
 * 
 * Sets the account number and transaction type to 0, amount to 0.0, 
 * and clears the date string. This is useful to reset or prepare a 
 * Transaction structure before usage.
 * 
 * @param tran Pointer to the Transaction structure to initialize.
 */
void initializeTrans(Transaction *trans);

int accLogin();

int accSignup();

void accLogout(Account *acc);

/***
 *    ____ ____ ____ ____ _  _ _  _ ___     ___ ____ ____ _  _ ____ ____ ____ ___ _ ____ _  _ 
 *    |__| |    |    |  | |  | |\ |  |  .    |  |__/ |__| |\ | [__  |__| |     |  | |  | |\ | 
 *    |  | |___ |___ |__| |__| | \|  |  .    |  |  \ |  | | \| ___] |  | |___  |  | |__| | \| 
 *                                                                                            
 */

void transDeposit(Account *acc, Transaction *trans);

void transWithdraw(Account *acc, Transaction *trans);

void transBalance(const Account *acc);

void transStatement(const Account *acc, const Transaction *trans);

/***
 *    ____ ____ ____ ____ _  _ _  _ ___     _  _ ____ _  _ _ ___  _  _ _    ____ ___ _ ____ _  _ 
 *    |__| |    |    |  | |  | |\ |  |  .   |\/| |__| |\ | | |__] |  | |    |__|  |  | |  | |\ | 
 *    |  | |___ |___ |__| |__| | \|  |  .   |  | |  | | \| | |    |__| |___ |  |  |  | |__| | \| 
 *                                                                                               
 */

void accEditName(Account *acc);

void accEditAddress(Account *acc);

void accEditPassword(Account *acc);
 
void accDelete(Account *acc);

/***
 *    ___  ____ ___ ____ ___  ____ ____ ____     _  _ ____ _  _ _ ___  _  _ _    ____ ___ _ ____ _  _ 
 *    |  \ |__|  |  |__| |__] |__| [__  |___ .   |\/| |__| |\ | | |__] |  | |    |__|  |  | |  | |\ | 
 *    |__/ |  |  |  |  | |__] |  | ___] |___ .   |  | |  | | \| | |    |__| |___ |  |  |  | |__| | \| 
 *                                                                                                    
 */
#endif  // BANKINGLIB_H
