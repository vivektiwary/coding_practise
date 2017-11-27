/*
 * 3-11. [5] Suppose that we are given a sequence of n values x 1 , x 2 , ..., x n and seek to
 * quickly answer repeated queries of the form: given i and j, find the smallest value
 * in x i , . . . , x j .
 *      (a) Design a data structure that uses O(n 2 ) space and answers queries in O(1)
 *          time.
 *      (b) Design a data structure that uses O(n) space and answers queries in O(log n)
 *          time. For partial credit, your data structure can use O(n log n) space and have
 *          O(log n) query time.
 *
 * Solution for (a) section.
 *
 */


#include <iostream>

using namespace std;

int main() {
    int size;
    cout << "Enter the count of the element" << endl;
    cin >> size;
    int num[size][size];
    for (int i = 0; i < size; ++i) {
        cout << "Enter the " << i+1 << "th element" << endl;
        cin >> num[i][0];
        for (int j = 0; j < i; ++j) {
            num[j][i] = min(num[j][i-1], num[i][0]);
        }
        num[i][i] = num[i][0];
    }
    cout << "Enter your query range" << endl;
    int start, end;
    cin >> start >> end;
    while (start != 0 && end != 0) {
        if (start <= end) {
            cout << "The min element is: " << num[start - 1][end - 1] << endl;
        }
        else {
            cout << "The min element is: " << num[end - 1][start - 1] << endl;
        }
        cout << "Enter your query range" << endl;
        cin >> start >> end;
    }
}