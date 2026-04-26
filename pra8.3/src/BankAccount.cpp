#include "BankAccount.h"
#include <iostream>
#include <sstream>

using namespace std;

BankAccount::BankAccount(double initialBalance) {
    balance = initialBalance;
    logCount = 0;
}

void BankAccount::addLog(const string& message) {
    if (logCount < 100) {
        logs[logCount] = message;
        logCount++;
    }
}

void BankAccount::deposit(double amount) {
    CallTracker tracker(this, "deposit");

    if (amount <= 0) {
        throw InvalidAmountException("Invalid deposit amount.");
    }

    balance += amount;

    ostringstream oss;
    oss << "Deposit successful. New balance: " << balance;
    addLog(oss.str());
}

void BankAccount::withdraw(double amount) {
    CallTracker tracker(this, "withdraw");

    if (amount <= 0) {
        throw InvalidAmountException("Invalid withdrawal amount.");
    }
    if (amount > balance) {
        throw InsufficientFundsException("Insufficient balance for withdrawal.");
    }

    balance -= amount;

    ostringstream oss;
    oss << "Withdrawal successful. New balance: " << balance;
    addLog(oss.str());
}

void BankAccount::processTransaction(double amount) {
    CallTracker tracker(this, "processTransaction");

    if (amount == 0) {
        throw InvalidAmountException("Transaction amount cannot be zero.");
    }
    else if (amount > 0) {
        deposit(amount);
    }
    else {
        withdraw(-amount);
    }
}

void BankAccount::printLogs() const {
    cout << "\n--- Transaction and Execution Logs ---\n";
    for (int i = 0; i < logCount; i++) {
        cout << logs[i] << "\n";
    }
}

double BankAccount::getBalance() const {
    return balance;
}

CallTracker::CallTracker(BankAccount* account, const string& name) {
    acc = account;
    funcName = name;
    acc->addLog("Entering function: " + funcName);
}

CallTracker::~CallTracker() {
    acc->addLog("Exiting function: " + funcName + " (Stack Unwinding)");
}

InsufficientFundsException::InsufficientFundsException(const string& msg) {
    message = msg;
}

InvalidAmountException::InvalidAmountException(const string& msg) {
    message = msg;
}
