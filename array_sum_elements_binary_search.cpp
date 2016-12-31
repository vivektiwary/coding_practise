/**
 * Problem statement:
 * Given an unsorted array and a sum, you have to find out the index of
 * two elements whose sum will be equal to the sum given.
 *
 * Solution: Using binary search after sorting
 * 
 * Complexity:
 * Time: O(n lg n)
 * Space: O(1)
 */

#include <iostream>
#include <algorithm>

using namespace std;

void findNumbersForSum(int arr[], int sum, int *firstIndex, int *secondIndex, int size) {
    for (int i = 0; i < size; ++i) {
        
    }
}

int main() {
    cout << "Enter the sum number" << endl;
    int sum;
    cin >> sum;
    cout << "Enter the length of the array" << endl;
    int length;
    cin >> length;
    int arr[length];
    cout << "Enter the elements" << endl;
    for (int i = 0; i < length; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + length);
    int firstIndex;
    int secondIndex;
    findNumbersForSum(arr, sum, &firstIndex, &secondIndex, length);
    return 0;
}
