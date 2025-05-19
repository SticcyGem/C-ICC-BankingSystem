#ifndef BANKINGLIB_H
#define BANKINGLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "debug.h"

#define ACC_FILE   "Account.txt"
#define TRANS_FILE "StatementOfAccount.txt"
#define TEMP_FILE  "data/temp.txt"
#define EXAMPLE_ACC_FILE "data/example_account.txt"

#define MENU_STARTUP_NORMAL   '1'
#define MENU_STARTUP_DEBUG    '2'

#define MENU_AUTH_LOGIN    '1'
#define MENU_AUTH_SIGNUP   '2'
#define MENU_AUTH_CREDITS  '3'
#define MENU_AUTH_EXIT     '4'

#define MENU_MAIN_INQUIRY    '1'
#define MENU_MAIN_DEPOSIT    '2'
#define MENU_MAIN_WITHDRAW   '3'
#define MENU_MAIN_SETTINGS   '4'
#define MENU_MAIN_LOGOUT     '5'

#define MENU_INQUIRY_BALANCE   '1'
#define MENU_INQUIRY_STATEMENT '2'
#define MENU_INQUIRY_BACK      '3'

#define MENU_DELETE_NO   '1'
#define MENU_DELETE_YES  '2'

typedef struct {
    int accountNumber;
    char password[100];
    char firstname[50];
    char lastname[50];
    char midname[50];
    char street[50];
    char barangay[50];
    char city[50];
    char region[50];
    char postalCode[5];
    float balance;
    int toDelete;
} Account;

typedef struct {
    int accountNumber;
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

typedef struct {
    int accountNumber;
    int transactionType;
    char date[20];
    float amount;
} Transaction;

// main.c
void handleAuthMenu(int *isAuth, Account *acc, AccountBackup *accb);
void handleMainMenu(int *isAuth, Account *acc, AccountBackup *accb, Transaction *trans);
void handleInquiryMenu(const Account *acc, AccountBackup *accb, const Transaction *trans);
void handleSettingsMenu(Account *acc);
void handleEditMenu(Account *acc);
void handleDeleteMenu(Account *acc);

// account.c
void initializeAcc(Account *acc);
void initializeAccBackupFromAccount(AccountBackup *backup, const Account *acc);
void initializeTrans(Transaction* tran);
int getNextAccountNumber(const char *filename);
int accLogin(Account *acc, AccountBackup*accb);
int accSignup(Account *acc, AccountBackup*accb);
void accLogout(Account *acc, AccountBackup*accb);
void accDelete(Account *acc);
void accEditName(Account *acc);
void accEditAddress(Account *acc);
void accEditPassword(Account *acc);
void accDisplay(const Account *acc);
void transDisplay(const Transaction *trans);

// common.c
char menuInput();
int userInput(const char *fmt, void *var);
void pauseConsole();
void logReset();
void openLogViewer();
int fileExists(const char *filename);
void example1(Account *acc, AccountBackup *accb);
void example2(int accountNumber, Account *acc, const char *filename);
void example3(Account *acc, const char *filename);

// datahandling.c
long getline(char **lineptr, size_t *n, FILE *stream);
int loadAccountByNumber(int accountNumber, Account *acc, const char *filename);
int saveOrUpdateAccount(Account *acc, const char *filename);
int getTransactionsByAcc(int accountNumber, Transaction *list, const char *filename);
int logTransaction(int accountNumber, Transaction *trans, const char *filename);

// menu.c
void guiCredit();
void guiAuthMenu();
void guiMainMenu(const Account *acc);
void guiAccSettingMenu();
void guiAccEditingMenu();
void guiAccDeleteMenu();
void guiAccInquiryMenu();
void guiAccDisplay(const Account *acc);
void guiAccBalance(const Account *acc);
void guiAccDeposit(const Account *acc, float amount);
void guiAccWithdraw(const Account *acc, float amount);
void guiAccEditName(const Account *acc);
void guiAccEditAddress(const Account *acc);
void guiAccEditPassword(const Account *acc);
void guiAccStatement(const Account *acc, const Transaction *trans);
void guiDEBUG();

// transaction.c
void transDeposit(Account *acc, AccountBackup *accb, Transaction *trans);
void transWithdraw(Account *acc, AccountBackup *accb, Transaction *trans);
void transBalance(const Account *acc, AccountBackup *accb);
void transStatement(const Account *acc, AccountBackup *accb, const Transaction *trans);

#endif // BANKINGLIB_H
