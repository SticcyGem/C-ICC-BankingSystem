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

#define GUI_INPUT_ACCOUNTNUMBER_SIGNUP   1
#define GUI_INPUT_ACCOUNTNUMBER_LOGIN    2
#define GUI_INPUT_PASSWORD_SIGNUP        3
#define GUI_INPUT_PASSWORD_LOGIN         4
#define GUI_INPUT_FIRSTNAME              5
#define GUI_INPUT_LASTNAME               6
#define GUI_INPUT_MIDNAME                7
#define GUI_INPUT_STREET                 8
#define GUI_INPUT_BARANGAY               9
#define GUI_INPUT_CITY                   10
#define GUI_INPUT_REGION                 11
#define GUI_INPUT_POSTALCODE             12
#define GUI_INPUT_WITHDRAWBALANCE        13
#define GUI_INPUT_DEPOSITBALANCE         14

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
    int transactionType;
    char date[20];
    float amount;
} Transaction;

// main.c
void handleAuthMenu(Account *acc, Account *accb, int *isAuth);
void handleMainMenu(Account *acc, Account *accb, Transaction *trans, int *isAuth);
void handleInquiryMenu(const Account *acc, Account *accb, const Transaction *trans);
void handleSettingsMenu(Account *acc, Account *accb, int *isAuth);
void handleEditMenu(Account *acc, Account *accb);
void handleDeleteMenu(Account *acc, Account *accb, int *isAuth);

// account.c
void initializeAcc(Account *acc);
void initializeAccBackupFromAccount(const Account *acc, Account *accb);
void initializeTrans(Transaction* tran);
int getNextAccountNumber(const char *filename);
int accLogin(Account *acc, Account *accb);
int accSignup(Account *acc, Account *accb);
void accLogout(Account *acc, Account *accb);
void accDelete(Account *acc, Account *accb);
void accEditName(Account *acc, Account *accb);
void accEditAddress(Account *acc, Account *accb);
void accEditPassword(Account *acc, Account *accb);
void accDisplay(const Account *acc);
void transDisplay(const Transaction *trans);

// common.c
char menuInput();
int userInput(const char *fmt, void *var);
void pauseConsole();
void logReset();
void openLogViewer();
int fileExists(const char *filename);
void example1(Account *acc, Account *accb);
void example2(int accountNumber, Account *acc, const char *filename);
void example3(Account *acc, const char *filename);

// datahandling.c
long getline(char **lineptr, size_t *n, FILE *stream);
int loadAccountByNumber(Account *acc, Account *accb, int accountNumber, const char *filename);
int saveOrUpdateAccount(Account *acc, Account *accb, const char *filename);
int getTransactionsByAcc(Transaction *list, int accountNumber, const char *filename);
int logTransaction(Transaction *trans, int accountNumber, const char *filename);

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
void guiAccDeposit();
void guiAccSignup();
void guiAccWithdraw();
int guiStringInput(Account *acc, Account *accb, int choice);
void guiAccEditName();
void guiAccEditAddress();
void guiAccEditPassword();
void guiAccStatement(const Account *acc, const Transaction *trans);
void guiDEBUG();

// transaction.c
void transDeposit(Account *acc, Account *accb, Transaction *trans);
void transWithdraw(Account *acc, Account *accb, Transaction *trans);
void transBalance(const Account *acc, Account *accb);
void transStatement(const Account *acc, Account *accb, const Transaction *trans);

#endif // BANKINGLIB_H
