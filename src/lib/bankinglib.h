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
 
/// @def DEBUG
/// @brief Set to 1 to enable debug logging with 1-second delay.
#define DEBUG 0

/// @def LOG(fmt, ...)
/// @brief Outputs debug log if DEBUG is enabled.
#if DEBUG
    #define LOG(fmt, ...) do { printf("[DEBUG] " fmt "\n", ##__VA_ARGS__); Sleep(1000); } while (0)
#else
    #define LOG(fmt, ...)
#endif
 
/// @brief File paths for storing account and transaction data.
#define ACC_FILE   "Account.txt"
#define TRANS_FILE "StatementOfAccount.txt"
 
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

/***
 * ███████ ████████ ██████  ██    ██  ██████ ████████ ██    ██ ██████  ███████ 
 * ██         ██    ██   ██ ██    ██ ██         ██    ██    ██ ██   ██ ██      
 * ███████    ██    ██████  ██    ██ ██         ██    ██    ██ ██████  █████   
 *      ██    ██    ██   ██ ██    ██ ██         ██    ██    ██ ██   ██ ██      
 * ███████    ██    ██   ██  ██████   ██████    ██     ██████  ██   ██ ███████                        
 */

/** 
 * @struct Account
 * @brief Represents a bank account.
 * 
 * Holds the personal and account information of a user.
 */
typedef struct {
    int accountNumber;  /**< The unique identifier for the account. */
    char name[50];      /**< The full name of the account holder. */
    char street[50];    /**< The street address of the account holder. */
    char barangay[50];  /**< The barangay (local community) of the account holder. */
    char city[50];      /**< The city of the account holder. */
    char region[50];    /**< The region of the account holder. */
    char postalCode[4]; /**< The postal code of the account holder's address. */
    float balance;      /**< The current balance of the account. */
    char password[20];  /**< The password for account authentication. */
    int toDelete;       /**< Flag indicating if the account is marked for deletion. */
} Account;

/**
 * @struct Transaction
 * @brief Represents a financial transaction.
 * 
 * Stores details about transactions such as deposits and withdrawals.
 */
typedef struct {
    int accountNumber;        /**< The account number associated with the transaction. */
    int transactionType;      /**< Type of the transaction (1 = deposit, 0 = withdrawal). */
    char date[20];            /**< Date the transaction took place. */
    float amount;             /**< Amount of money involved in the transaction. */
} Transaction;

/**
 * ███████ ██    ██ ███    ██  ██████        ██████  ███████  ██████ ██       █████  ██████   █████  ████████ ██  ██████  ███    ██ 
 * ██      ██    ██ ████   ██ ██      ██     ██   ██ ██      ██      ██      ██   ██ ██   ██ ██   ██    ██    ██ ██    ██ ████   ██ 
 * █████   ██    ██ ██ ██  ██ ██             ██   ██ █████   ██      ██      ███████ ██████  ███████    ██    ██ ██    ██ ██ ██  ██ 
 * ██      ██    ██ ██  ██ ██ ██      ██     ██   ██ ██      ██      ██      ██   ██ ██   ██ ██   ██    ██    ██ ██    ██ ██  ██ ██ 
 * ██       ██████  ██   ████  ██████        ██████  ███████  ██████ ███████ ██   ██ ██   ██ ██   ██    ██    ██  ██████  ██   ████                                                                                                                                    
 */

/**
 * ░█▀▀░█░█░█▀█░█▀▀░▀█▀░▀█▀░█▀█░█▀█░░░░░░░█▀▀░█▀▀░█▀█░█▀▀░█▀▄░█▀█░█░░░░░█░█░█▀▀░█▀▀
 * ░█▀▀░█░█░█░█░█░░░░█░░░█░░█░█░█░█░░▀░░░░█░█░█▀▀░█░█░█▀▀░█▀▄░█▀█░█░░░░░█░█░▀▀█░█▀▀
 * ░▀░░░▀▀▀░▀░▀░▀▀▀░░▀░░▀▀▀░▀▀▀░▀░▀░░▀░░░░▀▀▀░▀▀▀░▀░▀░▀▀▀░▀░▀░▀░▀░▀▀▀░░░▀▀▀░▀▀▀░▀▀▀
 */

/**
 * @brief Pauses the program until the user presses ENTER.
 * 
 * This function waits for the user to hit ENTER before continuing.
 */
void pauseConsole();

/**
 * ░█▀▀░█▀▄░█▀█░█▀█░█░█░▀█▀░█▀▀░░░█░█░█▀▀░█▀▀░█▀▄░░░▀█▀░█▀█░▀█▀░█▀▀░█▀▄░█▀▀░█▀█░█▀▀░█▀▀
 * ░█░█░█▀▄░█▀█░█▀▀░█▀█░░█░░█░░░░░█░█░▀▀█░█▀▀░█▀▄░░░░█░░█░█░░█░░█▀▀░█▀▄░█▀▀░█▀█░█░░░█▀▀
 * ░▀▀▀░▀░▀░▀░▀░▀░░░▀░▀░▀▀▀░▀▀▀░░░▀▀▀░▀▀▀░▀▀▀░▀░▀░░░▀▀▀░▀░▀░░▀░░▀▀▀░▀░▀░▀░░░▀░▀░▀▀▀░▀▀▀
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
void guiMainMenu();

void guiAccSettingMenu();

void guiAccEditingMenu();

void guiAccDeleteMenu();

void guiAccInquiryMenu();

void guiAccDisplay();

/**
 * ░█▀█░█▀▀░█▀▀░█▀█░█░█░█▀█░▀█▀░░░░░░░█▀▀░█▀▄░█▀▀░█▀█░▀█▀░▀█▀░█▀█░█▀█░░░█▀▀░█░█░█▀▀░▀█▀░█▀▀░█▄█
 * ░█▀█░█░░░█░░░█░█░█░█░█░█░░█░░░▀░░░░█░░░█▀▄░█▀▀░█▀█░░█░░░█░░█░█░█░█░░░▀▀█░░█░░▀▀█░░█░░█▀▀░█░█
 * ░▀░▀░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀░▀░░▀░░░▀░░░░▀▀▀░▀░▀░▀▀▀░▀░▀░░▀░░▀▀▀░▀▀▀░▀░▀░░░▀▀▀░░▀░░▀▀▀░░▀░░▀▀▀░▀░▀
 */

int accLogin();

int accSignup();

void accDeposit();

void accWithdraw();

void accEdit();

void accDelete();

void accLogout();

/**
 * @brief Initializes an Account structure with default values.
 * 
 * This function sets all fields of the given Account pointer to safe default values.
 * Useful before login, signup, or resetting account data to avoid garbage values.
 * 
 * @param acc Pointer to the Account structure to be initialized.
 * 
 * @note Defined in `account.c`.
 */
void initializeAcc(Account* acc);

#endif  // BANKINGLIB_H
