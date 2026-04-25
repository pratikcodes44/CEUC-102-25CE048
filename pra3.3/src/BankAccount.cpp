#include "BankAccount.h"
#include <iostream>
#include<string>

using namespace std;

int BankAccount::totalAccounts = 0;

BankAccount::BankAccount(int accNum, std::string accName, double initialBalance)
{
    accountNumber = accNum;
    accountHolderName = accName;
    balance = (initialBalance >= 0) ? initialBalance : 0.0;
    totalAccounts++;
}

BankAccount::~BankAccount()
{
    totalAccounts--;
}

int BankAccount::getAccountNumber()
{
    return accountNumber;
}

string BankAccount::getAccountHolderName()
{
    return accountHolderName;
}

double BankAccount::getBalance()
{
    return balance;
}

int BankAccount::getTotalAccounts()
{
    return totalAccounts;
}

void BankAccount::deposit(double amount)
{
    if (amount > 0)
    {
        balance += amount;
    }
    else
    {
        cout << "Error: Invalid deposit amount.\n";
    }
}

bool BankAccount::withdraw(double amount)
{
    if (amount > 0 && balance >= amount)
    {
        balance -= amount;
        return true;
    }

    cout << "Error: Invalid amount or insufficient funds.\n";
    return false;
}

bool BankAccount::transferTo(BankAccount& recipient, double amount)
{
    if (amount > 0 && balance >= amount)
    {
        this->withdraw(amount);
        recipient.deposit(amount);
        return true;
    }
    cout << "Transfer failed: Check balance and amount.\n";
    return false;
}

void BankAccount::displayAccountSummary()
{
    cout << "Account Number: " << accountNumber << "\n"<< "Account Holder: " << accountHolderName << "\n"<< "Current Balance: $" << balance << "\n";
}
