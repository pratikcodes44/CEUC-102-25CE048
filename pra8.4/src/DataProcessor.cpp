#include "DataProcessor.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

DataProcessor::DataProcessor() {
    totalSum = 0.0;
    validCount = 0;
    invalidCount = 0;
}

void DataProcessor::reset() {
    totalSum = 0.0;
    validCount = 0;
    invalidCount = 0;
}

void DataProcessor::processFile(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        throw runtime_error("File not found or cannot be opened.");
    }

    string line;
    int lineNumber = 0;

    while (getline(file, line)) {
        lineNumber++;

        if (line.empty()) {
            continue;
        }

        try {
            double value = stod(line);
            totalSum += value;
            validCount++;
        }
        catch (const invalid_argument& e) {
            cout << "Skipped Line " << lineNumber << " (Corrupted Data): '" << line << "'\n";
            invalidCount++;
        }
        catch (const out_of_range& e) {
            cout << "Skipped Line " << lineNumber << " (Value Out of Range): '" << line << "'\n";
            invalidCount++;
        }
    }

    file.close();
}

void DataProcessor::displayResults() const {
    cout << "\n--- File Processing Summary ---\n";
    cout << "Valid numeric records processed : " << validCount << "\n";
    cout << "Corrupted records skipped       : " << invalidCount << "\n";

    if (validCount > 0) {
        cout << "Total Sum : " << totalSum << "\n";
        cout << "Average   : " << (totalSum / validCount) << "\n";
    } else {
        cout << "No valid numeric data found to calculate sum or average.\n";
    }
}
