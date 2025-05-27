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
    float depositedAmount = 0.0f;
    if (!guiHandleDepositBal(acc, accb, isAuth, &depositedAmount)) {
        LOG("Operation canceled by user. [Account Deposit Balance]\n");
        return;
    }

    setCurrentDate(trans->date, sizeof(trans->date));
    trans->transactionType = 1;
    trans->amount = depositedAmount;

    logTransaction(trans, acc->accountNumber, "data/StatementOfAccount.txt");
    saveOrUpdateAccount(acc, "data/Account.txt");
    pauseConsole();
}

void transWithdraw(Account *acc, Account *accb, Transaction *trans, int *isAuth) {
    LOGGER();
    guiAccWithdraw();
    float withdrawnAmount = 0.0f;
    if (!guiHandleWithdrawBal(acc, accb, isAuth, &withdrawnAmount)) {
        LOG("Operation canceled by user. [Account Withdraw Balance]\n");
        return;
    }

    setCurrentDate(trans->date, sizeof(trans->date));
    trans->transactionType = 2;
    trans->amount = withdrawnAmount;

    logTransaction(trans, acc->accountNumber, "data/StatementOfAccount.txt");
    saveOrUpdateAccount(acc, "data/Account.txt");
    pauseConsole();
}

void transStatement(const Account *acc) {
    LOGGER();
    Transaction transList[100] = {0};
    int count = getTransactionsByAcc(transList, acc->accountNumber, "data/StatementOfAccount.txt");
    if (count == 0) {
        guiAccNoStatement();
        return;
    }
    guiAccStatement(acc, transList, count);
    pauseConsole();
}

void transBalance(const Account *acc) {
    LOGGER();
    guiAccBalance(acc);
    pauseConsole();
}
