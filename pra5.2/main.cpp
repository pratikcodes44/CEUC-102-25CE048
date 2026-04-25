#include <iostream>
#include <string>
#include "FileCounter.h"

using namespace std;

int main() {
    string filename;
    FileCounter counter;

    cout << "Enter the name of the text file to read (e.g., test.txt): ";
    getline(cin, filename);

    if (counter.processFile(filename)) {
        counter.displayStats();
    } else {
        cout << "Error: Could not open the file '" << filename << "'. Please check if it exists.\n";
    }

    return 0;
}
