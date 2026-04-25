#include "FileCounter.h"
#include <iostream>
#include <fstream>

using namespace std;

FileCounter::FileCounter() {
    charCount = 0;
    wordCount = 0;
    lineCount = 0;
}

bool FileCounter::processFile(const string& filename) {
    ifstream file(filename);

    if (!file) {
        return false;
    }

    string line;
    while (getline(file, line)) {
        lineCount++;
        charCount += line.length() + 1;

        bool inWord = false;
        for (int i = 0; i < line.length(); i++) {
            char ch = line[i];

            if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
                inWord = false;
            } else {
                if (!inWord) {
                    wordCount++;
                    inWord = true;
                }
            }
        }
    }

    file.close();
    return true;
}

void FileCounter::displayStats() const {
    cout << "\n--- File Statistics ---\n";
    cout << "Total Lines      : " << lineCount << "\n";
    cout << "Total Words      : " << wordCount << "\n";
    cout << "Total Characters : " << charCount << "\n";
}
