/**
 * 2-1. “Primary Arithmetic” – Programming Challenges 110501, UVA Judge 10035. (algorithm design by skiena 2nd edition)
 *
 *
 * We have to find the number of carry which will arise while adding two UNSIGNED numbers
 * The numbers will be less than 10 digit long
 */


#include <iostream>

using namespace std;

int main() {
    long long num1, num2;
    cin >> num1 >> num2;
    while(num1 || num2) {
        int carry = 0;
        int carryCount = 0;
        int num1Array[10];
        int num2Array[10];
        int size1 = 0, size2 = 0;
        while (num1) {
            num1Array[size1++] = num1 % 10;
            num1 /= 10;
        }
        while (num2) {
            num2Array[size2++] = num2 % 10;
            num2 /= 10;
        }
        int size = size1 >= size2 ? size1 : size2;
        for (int i = 0; i < size; ++i) {
            if (i < size2 && i < size1) {
                if (num1Array[i] + num2Array[i] + carry >= 10) {
                    carry = 1;
                    carryCount++;
                }
                else {
                    carry = 0;
                }
            }
            else if (i >= size2 && i < size1) {
                if (num1Array[i] + carry >= 10) {
                    carry = 1;
                    carryCount++;
                }
                else {
                    carry = 0;
                }
            }
            else if (i >= size1 && i < size2) {
                if (num2Array[i] + carry >= 10) {
                    carry = 1;
                    carryCount++;
                }
                else {
                    carry = 0;
                }
            }
        }
        if (!carryCount) {
            cout << "No carry operation." << endl;
        }
        else if(carryCount == 1) {
            cout << "1 carry operation." << endl;
        }
        else {
            cout << carryCount << " carry operations." << endl;
        }
        cin >> num1 >> num2;
    }
    return 0;
}