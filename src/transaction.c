/**
 * @file transaction.c
 * @brief Manages financial operations: deposit, withdraw, and inquiry.
 * 
 * This module performs transactional logic involving account balance updates,
 * inquiry of current balance, and viewing the statement of account.
 * It accesses and updates Account.txt and StatementOfAccount.txt.
 * 
 * @author 
 * ESPEJO, John Gabriel R.
 * 
 * @date 
 * May 2025
 */

#include "lib/bankinglib.h"

void transDeposit(Account *acc, Account *accb, Transaction *trans, int *isAuth) {
    LOGGER();
    guiAccDeposit();
    if (!guiStringInput(acc, accb, GUI_INPUT_DEPOSITBALANCE, isAuth)) {
        LOG("Operation canceled by user. [Account Deposit Balance\n");
        return;
    }
    pauseConsole();
}

void transWithdraw(Account *acc, Account *accb, Transaction *trans, int *isAuth) {
    LOGGER();
    guiAccWithdraw();
    if (!guiStringInput(acc, accb, GUI_INPUT_WITHDRAWBALANCE, isAuth)) {
        LOG("Operation canceled by user. [Account Withdraw Balance\n");
        return;
    }
    pauseConsole();
}

void transBalance(const Account *acc, Account *accb) {
    LOGGER();
    guiAccBalance(acc);
}

void transStatement(const Account *acc, Account *accb, const Transaction *trans) {
    LOGGER();
    guiAccStatement(acc, trans);
}