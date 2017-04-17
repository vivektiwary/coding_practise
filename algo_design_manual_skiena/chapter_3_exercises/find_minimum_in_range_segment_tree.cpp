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
 * Solution for (b) section.
 *
 */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class SegTree {
    int query(int nodeNum, int left, int right, int startIndex, int endIndex);
    void makeTree(int nodeNum, int leftRange, int rightRange);
    void printTree(int nodeNum, int leftRange, int rightRange);
public:
    vector<int> sequence;
    int size;
    vector<int> segTree;
    SegTree(int size): size{size}{};
    void query();
    void makeTree();
    void printTree();
};

int SegTree::query(int nodeNum, int left, int right, int startIndex, int endIndex) {
    if (startIndex > right || endIndex < left) {
        return 999999999; // Return something bigger than your expected element value
    }
    else if (startIndex <= left && endIndex >= right) {
        return segTree[nodeNum];
    }
    int mid = floor((left + right)/2);
    int min1 = query((2*nodeNum+1), left, mid, startIndex, endIndex);
    int min2 = query((2*nodeNum+2), mid+1, right, startIndex, endIndex);
    return min1 < min2 ? min1 : min2;
}

void SegTree::query() {
    int startIndex, endIndex;
    cout << "Enter start index and end index separated by space" << endl;
    cin >> startIndex >> endIndex;
    while (startIndex > 0 && endIndex < size + 1) {
        cout << "the minimum is: " << query(0, 0, size-1, startIndex-1, endIndex-1) << endl;
        cout << "Enter start index and end index separated by space" << endl;
        cin >> startIndex >> endIndex;
    }
}

void SegTree::makeTree(int nodeNum, int leftRange, int rightRange) {
    if (leftRange == rightRange) {
        segTree.at(nodeNum) = sequence[rightRange];
        return;
    }
    int mid = floor((rightRange + leftRange)/2);
    makeTree((2*nodeNum + 1), leftRange, mid);
    makeTree((2*nodeNum + 2), mid+1, rightRange);
    int minimum = min(segTree[2*nodeNum + 1], segTree[2*nodeNum + 2]);
    segTree.at(nodeNum) = minimum;
}

void SegTree::makeTree() {
    for (int i = 0; i < size; ++i) {
        int data;
        cin >> data;
        sequence.insert(sequence.cbegin() + i, data);
    }
    for (int i = 0; i < 4*size; ++i) {
        segTree.push_back(0);
    }
    makeTree(0, 0, size - 1);
}

void SegTree::printTree(int nodeNum, int leftRange, int rightRange) {
    if (nodeNum == rightRange) {
        cout << segTree[nodeNum];
        return;
    }
    cout << segTree[nodeNum];
    int mid = floor((leftRange + rightRange)/2);
    printTree((2*nodeNum+1), leftRange, mid);
    printTree((2*nodeNum+2), mid+1, rightRange);
}

void SegTree::printTree() {
    printTree(0, 0, size-1);
}

int main() {
    int seqSize;
    cout << "Enter the size of input" << endl;
    cin >> seqSize;
    SegTree st{seqSize};
    st.makeTree();
    st.query();
}
