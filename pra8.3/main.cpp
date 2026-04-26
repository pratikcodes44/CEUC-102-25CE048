#include <iostream>
#include <string>
#include <sstream>
#include "BankAccount.h"

using namespace std;

int main() {
    string inputStr;
    double initialBalance = 0.0;

    cout << "Enter initial balance for the account: ";
    getline(cin, inputStr);
    if (inputStr.length() > 0) {
        initialBalance = stod(inputStr);
    }

    BankAccount account(initialBalance);

    ostringstream oss;
    oss << "System Start. Initial balance: " << initialBalance;
    account.addLog(oss.str());

    int choice = 0;

    do {
        cout << "\n=== Banking Menu ===\n";
        cout << "Current Balance: " << account.getBalance() << "\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. View Transaction Logs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        getline(cin, inputStr);
        if (inputStr.length() > 0) {
            choice = stoi(inputStr);
        } else {
            choice = 0;
        }

        try {
            if (choice == 1) {
                cout << "Enter amount to deposit: ";
                getline(cin, inputStr);
                double amount = stod(inputStr);
                account.deposit(amount);
                cout << "Deposit successful!\n";
            }
            else if (choice == 2) {
                cout << "Enter amount to withdraw: ";
                getline(cin, inputStr);
                double amount = stod(inputStr);
                account.withdraw(amount);
                cout << "Withdrawal successful!\n";
            }
            else if (choice == 3) {
                account.printLogs();
            }
            else if (choice == 4) {
                cout << "Exiting system. Final logs printing...\n";
                account.printLogs();
            }
            else {
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
            }
        }
        catch (const InsufficientFundsException& e) {
            cout << "\n[TRANSACTION FAILED] " << e.message << "\n";
            account.addLog("Exception Caught: " + e.message);
        }
        catch (const InvalidAmountException& e) {
            cout << "\n[TRANSACTION FAILED] " << e.message << "\n";
            account.addLog("Exception Caught: " + e.message);
        }

    } while (choice != 4);

    return 0;
}
