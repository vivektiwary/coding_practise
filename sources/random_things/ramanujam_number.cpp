//
// Created by infibam on 12/1/17.
//
/**
 * A ramanujam number is a special number x, such that take any other a, b, c, d
 * a^3 + b^3 = c^3 + d^3 = x. Meaning it's a number which is the sum of two cube pairs.
 * So we have to find the ramanujam numbers such that a, b, c, d < n
 *
 * Strategy:
 * We will find the cubes of all number from 0 - n including and store that in an array.
 * Then we loop over all the pairs of this number and have an dictionary with key = sum of
 * cubes of pairs.
 * We then sum the pairs and check whether that is already there in our dictionary or not.
 * If it is there we have found our Ramanujam number, else we will add the sum in our
 * dictionary. We are using a different auxilary dictionary for storing all the Ramanujam
 * number.
 *
 * Solution taken from : http://rosslebeau.com/2016/algorithm-design-manual-ramanujan-numbers
 */

#include <iostream>
#include <map>
#include <set>
#include <utility>

using namespace std;

int main() {
    int n = 1000; // ramanujam number
    int cubes[n + 1];
    for (int i = 0; i <= n; i++) {
        cubes[i] = i * i * i;
    }
    map<int, pair<int, int>> cubeSum;
    map<int, set<int>> ramanujamNo;
    for (int i = 1; i < n -1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int a3 = cubes[i];
            int b3 = cubes[j];
            int sum = a3 + b3;
            pair<int, int> pair2;
            set<int> mySet;
            if ((pair2 = cubeSum[sum]).first) {
                mySet.insert(i);
                mySet.insert(j);
                mySet.insert(pair2.first);
                mySet.insert(pair2.second);
                ramanujamNo[sum] = mySet;
            }
            else {
                cubeSum[sum] = make_pair(i, j);
            }
        }
    }
    for (auto rnum = ramanujamNo.cbegin(); rnum != ramanujamNo.cend(); ++rnum) {
        cout << rnum -> first << endl;
    }
    return 0;
}
