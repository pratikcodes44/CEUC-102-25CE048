#include <iostream>
#include <string>
#include <stdexcept>
#include "DataProcessor.h"

using namespace std;

int main() {
    DataProcessor processor;
    string filename;
    bool success = false;

    cout << "=== Data File Processor ===\n";

    while (!success) {
        cout << "\nEnter the file path to process (or type 'exit' to quit): ";
        getline(cin, filename);

        if (filename == "exit") {
            cout << "Exiting program.\n";
            break;
        }

        try {
            processor.reset();
            processor.processFile(filename);
            success = true;
            processor.displayResults();
        }
        catch (const runtime_error& e) {
            cout << "\n[ERROR] " << e.what() << "\n";
            cout << "Please check the filename and try again.\n";
        }
    }

    return 0;
}
