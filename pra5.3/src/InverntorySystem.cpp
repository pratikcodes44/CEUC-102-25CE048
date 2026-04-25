#include "InverntorySystem.h"
#include <iostream>
#include <fstream>

using namespace std;

InventorySystem::InventorySystem(string file) {
    filename = file;
}

void InventorySystem::parseLine(const string& line, string& name, string& qty, string& price) const {
    int commaCount = 0;
    name = "";
    qty = "";
    price = "";

    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ',') {
            commaCount++;
        } else {
            if (commaCount == 0) {
                name += line[i];
            } else if (commaCount == 1) {
                qty += line[i];
            } else if (commaCount == 2) {
                price += line[i];
            }
        }
    }
}

void InventorySystem::addItem(const string& name, const string& qty, const string& price) {
    ofstream file(filename, ios::app);
    if (file) {
        file << name << "," << qty << "," << price << "\n";
    }
    file.close();
}

void InventorySystem::viewAll() const {
    ifstream file(filename);
    if (!file) {
        cout << "Inventory is empty or file not found.\n";
        return;
    }

    string line;
    cout << "\n--- All Inventory Items ---\n";
    while (getline(file, line)) {
        if (line.length() == 0) continue;

        string name, qty, price;
        parseLine(line, name, qty, price);

        cout << "Name: " << name << " | Quantity: " << qty << " | Price: " << price << "\n";
    }
    file.close();
}

void InventorySystem::searchItem(const string& searchName) const {
    ifstream file(filename);
    if (!file) {
        cout << "Inventory is empty or file not found.\n";
        return;
    }

    string line;
    bool found = false;

    cout << "\n--- Search Results ---\n";
    while (getline(file, line)) {
        if (line.length() == 0) continue;

        string name, qty, price;
        parseLine(line, name, qty, price);

        if (name == searchName) {
            cout << "Item Found -> Name: " << name << " | Quantity: " << qty << " | Price: " << price << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Item '" << searchName << "' not found in the inventory.\n";
    }

    file.close();
}
