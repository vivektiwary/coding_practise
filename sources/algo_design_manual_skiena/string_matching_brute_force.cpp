/*
 * Brute force string matching algo
 */

#include <iostream>

using namespace std;

bool match(string s, string pattern) {
    int stringSize = s.length();
    int patternSize = pattern.length();
    for (int i = 0; i <= (stringSize - patternSize); ++i) {
        int count = 0;
        for (int j = 0; j < patternSize; ++j) {
            if (s[i + j] == pattern[j]) {
                count++;
            }
            else {
                break;
            }
        }
        if (count == patternSize) {
            return true;
        }
    }
    return false;
}

int main() {
    string s, pattern;
    cout << "Enter the string" << endl;
    cin >> s;
    cout << "Enter the pattern" << endl;
    cin >> pattern;
    bool res = match(s, pattern);
    if (res) {
        cout << "Its a match" << endl;
    }
    else {
        cout << "Its not a match" << endl;
    }
    return 0;
}