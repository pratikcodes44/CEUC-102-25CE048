#include <iostream>
#include <string>
#include "InverntorySystem.h"

using namespace std;

int main() {
    InventorySystem inv("inventory_data.txt");
    string choiceStr;
    int choice = 0;

    do {
        cout << "\n=== Inventory Management System ===\n";
        cout << "1. Add Item\n";
        cout << "2. View All Items\n";
        cout << "3. Search Item by Name\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        getline(cin, choiceStr);
        if (choiceStr.length() > 0) {
            choice = choiceStr[0] - '0';
        }

        if (choice == 1) {
            string name, qty, price;
            cout << "Enter Item Name: ";
            getline(cin, name);
            cout << "Enter Quantity: ";
            getline(cin, qty);
            cout << "Enter Price: ";
            getline(cin, price);

            inv.addItem(name, qty, price);
            cout << "Item successfully added to inventory.\n";
        }
        else if (choice == 2) {
            inv.viewAll();
        }
        else if (choice == 3) {
            string searchName;
            cout << "Enter exact Item Name to search: ";
            getline(cin, searchName);
            inv.searchItem(searchName);
        }

    } while (choice != 4);

    return 0;
}
