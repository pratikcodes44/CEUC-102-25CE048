#include "WordCounter.h"
#include <iostream>

using namespace std;

WordCounter::WordCounter() {
    uniqueCount = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        counts[i] = 0;
    }
}

void WordCounter::toLowerCase(string &str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

void WordCounter::processParagraph(const string& paragraph) {
    string currentWord = "";

    for (int i = 0; i <= paragraph.length(); i++) {
        char ch = (i < paragraph.length()) ? paragraph[i] : ' ';

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            currentWord += ch;
        } else {
            if (currentWord.length() > 0) {
                toLowerCase(currentWord);

                bool found = false;
                for (int j = 0; j < uniqueCount; j++) {
                    if (uniqueWords[j] == currentWord) {
                        counts[j]++;
                        found = true;
                        break;
                    }
                }

                if (!found && uniqueCount < MAX_WORDS) {
                    uniqueWords[uniqueCount] = currentWord;
                    counts[uniqueCount] = 1;
                    uniqueCount++;
                }

                currentWord = "";
            }
        }
    }
}

void WordCounter::displayFrequencies() const {
    cout << "\n--- Word Frequencies ---\n";
    if (uniqueCount == 0) {
        cout << "No words found." << endl;
        return;
    }

    for (int i = 0; i < uniqueCount; i++) {
        cout << uniqueWords[i] << " : " << counts[i] << endl;
    }
}
