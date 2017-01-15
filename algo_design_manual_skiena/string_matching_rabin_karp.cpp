/*
 * String matching using Rabin-Karp algorithm
 * We are using "Rabin fingerprint" rolling function.
 */

#include <iostream>
#include <cmath>


using namespace std;

int rabinFingerprintHash(string s, int previousHash, char previousChar) {
    int primeBase = 101;
    int size = s.length();
    if (previousHash) {
        return primeBase * (previousHash - ((int) previousChar * (int) pow(primeBase, size - 1))) + (int) s[size - 1];
    }
    else {
        int hashResult = 0;
        for (int i = 0; i < size; ++i) {
            hashResult += (int) s[i] * (int) pow(primeBase, (size - 1 - i));
        }
        return hashResult;
    }
}

int match(string s, string pattern) {
    int stringSize = s.length();
    int patternSize = pattern.length();
    int pHash = rabinFingerprintHash(pattern, 0, '\0');

    for (int i = 0; i < (stringSize - patternSize + 1); ++i) {
        string subString = s.substr(i, (patternSize));
        int sHash;
        if (i == 0) {
            sHash = rabinFingerprintHash(subString, 0, '\0');
        }
        else {
            sHash = rabinFingerprintHash(subString, sHash, s[i - 1]);
        }
        if (sHash == pHash) {
            if (pattern.compare(subString) == 0) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    string s, pattern;
    cout << "Enter the string" << endl;
    cin >> s;
    cout << "Enter the pattern" << endl;
    cin >> pattern;
    int res = match(s, pattern);
    if (res != -1) {
        cout << "The match has been found at " << res << endl;
    }
    else {
        cout << "No match has been found" << endl;
    }
    return 0;
}