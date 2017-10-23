/**
 * Problem statement:
 * Given an unsorted array and a sum, you have to find out the index of
 * two elements whose sum will be equal to the sum given.
 *
 * Solution: Using auxilary space.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(i) where i is the largest value of the element in that array
 */

#include <iostream>
#include <map>

using namespace std;

int main() {
    int sum;
    cout << "Enter the sum value" << endl;
    cin >> sum;
    int size;
    cout << "Enter the size of the array!" << endl;
    cin >> size;
    int arr[size];
    cout << "Enter the elements" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    // Here we are making a Hash which will store the index of a given element
    // This will help us while deciding the second element.
    map<int, int> hash;
    for (int i = 0; i < size; ++i) {
        hash[arr[i]] = i;
    }
    int firstIndex = 0;
    int secondIndex = 0;
    for (int i = 0; i < size; ++i) {
        if (hash[sum - arr[i]] && (hash[sum - arr[i]] != i)) {
            firstIndex = i;
            secondIndex = hash[sum - arr[i]];
        } 
    }
    cout << "the first element is " << arr[firstIndex] << " with index " << firstIndex << endl;
    cout << "the second element is " << arr[secondIndex] << " with index " << secondIndex << endl;
    return 0;
}
