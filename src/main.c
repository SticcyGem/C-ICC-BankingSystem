/**
 * @file main.c
 * @brief Entry point of the Banking System application (C Version).
 * 
 * This file contains the main function which serves as the menu controller
 * for the banking system. It routes the user to operations like account
 * creation, inquiry, deposit, withdrawal, and account updates.
 * 
 * @author
 * PEREZ, Emmanuel A.
 * 
 * @date 
 * May 2025
 * 
 * For more information about the flow of the program, refer to the flowchart:
 * https://www.canva.com/design/DAGl7LPdl8k/zaiFHfmo4EYKvyTH0h5Vtw/edit?utm_content=DAGl7LPdl8k&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton
 */

#include "lib/bankinglib.h"

int main() {
    logReset();
    openLogViewer();
    LOG("Starting Banking System..");
    system("chcp 65001 > nul");

    Account currentAcc;
    Account backupAcc;
    Transaction currentTrans;
    initializeAcc(&currentAcc);
    initializeAccBackupFromAccount(&currentAcc, &backupAcc);
    initializeTrans(&currentTrans);
    int isAuth = 0;
    while (DEBUG) {
        guiDEBUG();
        LOG_WARN("Debug Mode: ON");
        LOG_WARN("To turn off DEBUG MODE, go to debug.h and set DEBUG to 0");
        char choice = menuInput();
        switch (choice) {
            case MENU_STARTUP_NORMAL:
                LOG("Selected: Normal Mode");
                while (1) {
                    if (!isAuth) {
                        handleAuthMenu(&currentAcc, &backupAcc, &isAuth);
                    } else {
                        handleMainMenu(&currentAcc, &backupAcc, &currentTrans, &isAuth);
                    }
                }
                break;
            case MENU_STARTUP_DEBUG:
                LOG("Selected: Debug Mode");
                example1(&currentAcc, &backupAcc);
                break;
            default:
                LOG("Selected: Invalid Choice");
                break;
        }
    }
    while (1) {
        if (!isAuth) {
            handleAuthMenu(&currentAcc, &backupAcc, &isAuth);
        } else {
            handleMainMenu(&currentAcc, &backupAcc, &currentTrans, &isAuth);
        }
    }
    return 0;
}
// -------------------- AUTHENTICATION FUNCTIONS --------------------
void handleAuthMenu(Account *acc, Account *accb, int *isAuth) {
    guiAuthMenu();
    char choice = menuInput();
    switch (choice) {
        case MENU_AUTH_LOGIN:
            LOG("Selected: Log In");
            if (accLogin(acc, accb) == 1) {
                LOG("Log in Successful.");
                *isAuth = 1;
            } else {
                LOG("Log in Failed.");
            }
            break;
        case MENU_AUTH_SIGNUP:
            LOG("Selected: Sign Up");
            if (accSignup(acc, accb) == 1) {
                LOG("Sign Up Successful.");
                *isAuth = 1;
            } else {
                LOG("Sign Up Failed.");
            }
            break;
        case MENU_AUTH_CREDITS:
            LOG("Selected: Credits");
            guiCredit();
            break;
        case MENU_AUTH_EXIT:
            LOG("Selected: Exit Program");
            exit(0);
        default:
            LOG("Selected: Invalid Choice");
            break;
    }
}

// -------------------- MAIN MENU FUNCTIONS --------------------
void handleMainMenu(Account *acc, Account *accb, Transaction *trans, int *isAuth) {
    int loop = 1;
    while (loop){
        guiMainMenu(acc);
        char choice = menuInput();
        switch (choice) {
            case MENU_MAIN_INQUIRY:
                LOG("Selected: Inquiry");
                handleInquiryMenu(acc, accb, trans);
                break;
            case MENU_MAIN_DEPOSIT:
                LOG("Selected: Deposit");
                transDeposit(acc, accb, trans);
                break;
            case MENU_MAIN_WITHDRAW:
                LOG("Selected: Withdraw");
                transWithdraw(acc, accb, trans);
                break;
            case MENU_MAIN_SETTINGS:
                LOG("Selected: Account Setting");
                handleSettingsMenu(acc, accb, isAuth);
                if (*isAuth == 0) {
                    loop = 0;
                }
                break;
            case MENU_MAIN_LOGOUT:
                LOG("Selected: Log Out");
                *isAuth = 0;
                loop = 0;
                break;
            default:
                LOG("Selected: Invalid Choice");
                break;
        }
    }
}

// -------------------- INQUIRY MENU FUNCTIONS --------------------
void handleInquiryMenu(const Account *acc, Account *accb, const Transaction *trans) {
    int loop = 1;
    while (loop){
        guiAccInquiryMenu();
        char choice = menuInput();
        switch (choice) {
            case MENU_INQUIRY_BALANCE:
                LOG("Selected: Check Balance");
                transBalance(acc, accb);
                break;
            case MENU_INQUIRY_STATEMENT:
                LOG("Selected: Account Statement");
                transStatement(acc, accb, trans);
                break;
            case MENU_INQUIRY_BACK:
                LOG("Selected: Back");
                loop = 0;
                break;
            default:
                LOG("Selected: Invalid Choice");
                break;
        }
    }
}

// -------------------- SETTINGS MENU FUNCTIONS --------------------
void handleSettingsMenu(Account *acc, Account *accb, int *isAuth) {
    int loop = 1;
    while (loop) {
        guiAccSettingMenu();
        char choice = menuInput();
        switch (choice) {
            case '1':
                LOG("Selected: Display Account Details");
                guiAccDisplay(acc);
                break;
            case '2':
                LOG("Selected: Edit Account Details");
                handleEditMenu(acc, accb);
                break;
            case '3':
                LOG("Selected: Delete Account");
                handleDeleteMenu(acc, accb, isAuth);
                if (*isAuth == 0) {
                    loop = 0;
                }
                break;
            case '4':
                LOG("Selected: Back");
                loop = 0;
                break;
            default:
                LOG("Selected: Invalid Choice");
                break;
        }
    }
}

// -------------------- EDIT MENU FUNCTIONS --------------------
void handleEditMenu(Account *acc, Account *accb) {
    int loop = 1;
    while (loop) {
        guiAccEditingMenu();
        char choice = menuInput();
        switch (choice) {
            case '1':
                LOG("Selected: Edit Name");
                accEditName(acc, accb);
                break;
            case '2':
                LOG("Selected: Edit Address");
                accEditAddress(acc, accb);
                break;
            case '3':
                LOG("Selected: Edit Password");
                accEditPassword(acc, accb);
                break;
            case '4':
                LOG("Selected: Back");
                loop = 0;
                break;
            default:
                LOG("Selected: Invalid Choice");
                break;
        }
    }
}

// -------------------- DELETE MENU FUNCTIONS --------------------
void handleDeleteMenu(Account *acc, Account *accb, int *isAuth) {
    int loop = 1;
    while (loop) {
        guiAccDeleteMenu();
        char choice = menuInput();
        switch (choice) {
            case MENU_DELETE_NO:
                LOG("Selected: No - Delete Account");
                loop = 0;
                break;
            case MENU_DELETE_YES:
                LOG("Selected: Yes - Delete Account");
                accDelete(acc, accb);
                loop = 0;
                *isAuth = 0;
                break;
            default:
                LOG("Selected: Invalid Choice");
                break;
        }
    }
}