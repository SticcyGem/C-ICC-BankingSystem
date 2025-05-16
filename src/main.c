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

void handleAuthMenu(int *isAuth) {
    guiAuthMenu();
    char choice = getch();

    switch (choice) {
        case MENU_AUTH_LOGIN:
            LOG("Selected: Log In");
            if (accLogin() == 1) {
                LOG("Log in Successful.");
                *isAuth = 1;
            } else {
                LOG("Log in Failed.");
            }
            break;
        case MENU_AUTH_SIGNUP:
            LOG("Selected: Sign Up");
            if (accSignup() == 1) {
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

void handleInquiryMenu() {
    int loop = 1;
    while (loop){
        guiAccInquiryMenu();
        char choice = getch();
        switch (choice) {
            case MENU_INQUIRY_BALANCE:
                LOG("Selected: Check Balance");
                break;
            case MENU_INQUIRY_STATEMENT:
                LOG("Selected: Account Statement");
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

void handleSettingsMenu() {
    int loop = 1;
    while (loop == 1) {
        guiAccSettingMenu();
        char choice = getch();
        switch (choice) {
            case '1':
                LOG("Selected: Display Account Details");
                guiAccDisplay();
                break;
            case '2':
                LOG("Selected: Edit Account Details");
                accEdit();
                break;
            case '3':
                LOG("Selected: Delete Account");
                guiAccDeleteMenu();
                char choiceAccDelMenu = getch();
                switch (choiceAccDelMenu) {
                    case MENU_DELETE_NO:
                        LOG("Selected: No - Delete Account");
                        break;
                    case MENU_DELETE_YES:
                        LOG("Selected: Yes - Delete Account");
                        accDelete();
                        break;
                    default:
                        LOG("Selected: Invalid Choice");
                        break;
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

void handleMainMenu(int *isAuth) {
    guiMainMenu();
    char choice = getch();
    switch (choice) {
        case MENU_MAIN_INQUIRY:
            LOG("Selected: Inquiry");
            handleInquiryMenu();
            break;
        case MENU_MAIN_DEPOSIT:
            LOG("Selected: Deposit");
            accDeposit();
            break;
        case MENU_MAIN_WITHDRAW:
            LOG("Selected: Withdraw");
            accWithdraw();
            break;
        case MENU_MAIN_SETTINGS:
            LOG("Selected: Account Setting");
            handleSettingsMenu();
            break;
        case MENU_MAIN_LOGOUT:
            LOG("Selected: Log Out");
            accLogout();
            *isAuth = 0;
            break;
        default:
            LOG("Selected: Invalid Choice");
            break;
    }
}

int main() {
    LOG("Starting Banking System..");
    system("chcp 65001 > nul");
    Account currentAcc;
    initializeAcc(&currentAcc);
    int isAuth = 0;

    while (1) {
        if (!isAuth) {
            handleAuthMenu(&isAuth);
        } else {
            handleMainMenu(&isAuth);
        }
    }

    return 0;
}
