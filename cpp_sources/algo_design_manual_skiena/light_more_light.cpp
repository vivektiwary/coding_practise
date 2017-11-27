/*
 * There is man named Mabu who switches on-off the lights along a corridor at our university.
 * Every bulb has its own toggle switch that changes the state of the light.
 * If the light is off, pressing the switch turns it on. Pressing it again will turn it off.
 * Initially each bulb is off.
 *
 * He does a peculiar thing. If there are n bulbs in a corridor, he walks along the corridor
 * back and forth n times. On the ith walk, he toggles only the switches whose position is divisible
 * by i. He does not press any switch when coming back to his initial position. The ith walk is
 * defined as going down the corridor (doing his peculiar thing) and coming back again.
 * Determine the final state of the last bulb. Is it on or off?
 *
 * Input
 * The input will be an integer indicating the nth bulb in a corridor, which is less than or
 * equal to 2^32 - 1. A zero indicates the end of input and should not be processed.
 *
 * Output
 * Output ``yes'' or ``no'' to indicate if the light is on, with each case appearing on its own line.
 *
 * Sample Input
 * 3
 * 6241
 * 8191
 * 0
 *
 * Sample Output
 * no
 * yes
 * no
 *
 *
 * Thinking:
 * As on i th walk he toggles the bulbs whose places are divisible by i, so we can find out
 * the number of factors of that number, it the number of factors will be even then the last
 * light will be "off" otherwise "on". "This algorithm is giving time limit exceeded".
 *
 * Better Algorithm:
 * If we see carefully, we will find that only a 'perfect square' will have odd number of
 * factors rest all will be even. So if we find whether the number is perfect square or not
 * we will get the answer.
 *
 *
 * See below for another solution
 *
 */

/*
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

void findFactors(int num, map<int, int> &numFactors) {
    while (num % 2 == 0) {
        num = num / 2;
        if (numFactors[2]) {
            numFactors[2] += 1;
        }
        else {
            numFactors[2] = 1;
        }
    }
    for (int i = 3; i <= floor(sqrt(num)); i = i + 2) {
        while (num % i == 0) {
            num /= i;
            if (numFactors[i]) {
                numFactors[i] += 1;
            }
            else {
                numFactors[i] = 1;
            }
        }
    }
    if (num > 1) {
        if (numFactors[num]) {
            numFactors[num] += 1;
        } else {
            numFactors[num] = 1;
        }
    }
}

int main() {
    int n;
    cin >> n;
    while (n) {
        map<int, int> numFactors;
        findFactors(n, numFactors);
        int sum = 0;
        for (auto f = numFactors.cbegin(); f != numFactors.cend(); ++f) {
            sum += f -> second;
        }
        if (sum % 2 == 0) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
        cin >> n;
    }
    return 0;
}*/


#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n;
    cin >> n;
    while(n) {
        long long sqrtNum = sqrt(n);
        if (n == sqrtNum * sqrtNum) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
        cin >> n;
    }
}