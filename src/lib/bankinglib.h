#ifndef BANKINGLIB_H
#define BANKINGLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <math.h>
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

#define MAX_TRANSACTIONS 100

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
    char date[50];
    float amount;
} Transaction;

// main.c
void handleAuthMenu(Account *acc, Account *accb, int *isAuth);
void handleMainMenu(Account *acc, Account *accb, Transaction *trans, int *isAuth);
void handleInquiryMenu(const Account *acc);
void handleSettingsMenu(Account *acc, Account *accb, int *isAuth);
void handleEditMenu(Account *acc, Account *accb, int *isAuth);
void handleDeleteMenu(Account *acc, Account *accb, int *isAuth);

// account.c
void initializeAcc(Account *acc, Account *accb);
void initializeAccBackupFromAccount(const Account *acc, Account *accb);
void initializeTrans(Transaction* tran);
int getNextAccountNumber(const char *filename);
int accLogin(Account *acc, Account *accb, int *isAuth);
int accSignup(Account *acc, Account *accb, int *isAuth);
void accLogout(Account *acc, Account *accb);
void accDelete(Account *acc, Account *accb);
int accEditName(Account *acc, Account *accb, int *isAuth);
int accEditAddress(Account *acc, Account *accb, int *isAuth);
int accEditPassword(Account *acc, Account *accb, int *isAuth);
void accDisplay(const Account *acc);

// common.c
void pauseConsole(void);
char menuInput(void);
int userInput(const char *fmt, void *var);
const char* getCurrentTimestamp();
const char* getCurrentDate();
void setCurrentDate(char *buffer, size_t size);
int createFolderIfNeeded(const char *path);
int fileExists(const char *filename);

// datahandling.c
long getline(char **lineptr, size_t *n, FILE *stream);
int loadAccountByNumber(Account *acc, Account *accb, int accountNumber, const char *filename);
int saveOrUpdateAccount(Account *acc, const char *filename);
int getTransactionsByAcc(Transaction *list, int accountNumber, const char *filename);
int logTransaction(Transaction *trans, int accountNumber, const char *filename);
int deleteTransactionsByAccount(int accountNumber, const char *filename);

// menu.c
void guiCredit(void);
void guiAuthMenu(void);
void guiMainMenu(const Account *acc);
void guiAccSettingMenu(void);
void guiAccEditingMenu(void);
void guiAccDeleteMenu(void);
void guiAccInquiryMenu(void);
void guiDEBUG(void);
void guiAccDisplay(const Account *acc);
void guiAccBalance(const Account *acc);
void guiAccStatement(const Account *acc, const Transaction *transList, int count);
void guiAccSignup(void);
void guiAccLogin(void);
void guiAccLoginFailed(void);
void guiAccNoStatement(void);

void guiAccID(void);
void guiAccPass(void);
void guiAccCPass(void);
void guiAccFirstName(void);
void guiAccLastName(void);
void guiAccMidName(void);
void guiAccStreet(void);
void guiAccBarangay(void);
void guiAccCity(void);
void guiAccRegion(void);
void guiAccPostalCode(void);

void guiInputInvalidMessage(void);
void guiInputExitMessage(void);
int guiAuthenticatedInput(const char *label, char *oldValue, char *newValue);
int guiSignUpInput(const char *label, char *oldValue, char *newValue);
int guiStringInput(Account *acc, Account *accb, int choice, int *isAuth, float *amount);

void guiAccDeposit(void);
void guiAccWithdraw(void);
void guiAccEditName(void);
void guiAccEditAddress(void);
void guiAccEditPassword(void);

// transaction.c
void transDeposit(Account *acc, Account *accb, Transaction *trans, int *isAuth);
void transWithdraw(Account *acc, Account *accb, Transaction *trans, int *isAuth);
void transBalance(const Account *acc);
void transStatement(const Account *acc);

#endif // BANKINGLIB_H
