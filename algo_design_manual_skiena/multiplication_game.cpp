/**
 * 2-2. “A Multiplication Game” – Programming Challenges 110505, UVA Judge 847. (algorithm design by skiena)
 *
 * Stan and Ollie play the game of multiplication by multiplying an integer p by
 * one of the numbers 2 to 9. Stan always starts with p = 1, does his multiplication,
 * then Ollie multiplies the number, then Stan, and so on. Before a game starts,
 * they draw an integer 1 < n < 4, 294, 967, 295 and the winner is whoever reaches p >= n first.
 *
 * Input
 * Each input line contains a single integer n.
 *
 * Output
 * For each line of input, output one line - either
 *
 * Stan wins.
 * or
 * Ollie wins.
 *
 * assuming that both of them play perfectly.
 *
 * Sample Input
 * 162
 * 17
 * 34012226
 *
 * Sample Output
 * Stan wins.
 * Ollie wins.
 * Stan wins.
 *
 *
 *
 * Thinking:
 * If we observe the patterns we will get to know that
 * In Stan 1st chance Stan can have max number as  9
 * In Ollie 1st chance she can have max number as 2*9 (as stan can choose 2 while multiplying)
 *
 * In Stan 2nd chance he can have max number as 9*2*9 (as Ollie can choose 2 while multiplying)
 * In Ollie 2nd chance she can have max number as 2 * 9 * 2 * 9 (as stan can choose 2 while multiplying)
 *
 * If we follow this pattern we will get to know the following:
 *   1 < n < 9          : stan wins
 *   10 < n < 18        : Ollie wins
 *   19 < n < 162       : stan wins
 *   162 < n < 324      : Ollie wins
 *   .
 *   .
 *   .
 * One more pattern is the range , for stan it increases by 9 times while for Ollie it only increases by 2 times
 * 18 = 9 * 2 and 162 = 18 * 9
 * So suppose n = 206, if Ollie has to win, then stan has to multiply the number by 9 while Ollie has to multiply
 * the number by 2.
 *
 *
 */

#include <iostream>

using namespace std;

int main() {
    long long n;
    while(scanf("%lld", &n) != EOF) {
        bool stan = true;
        long long p = 1;
        while(p < n) {
            if (stan) p *= 9;
            if (!stan) p *= 2;
            stan = !stan;
        }
        if (!stan) cout << "Stan wins." << endl;
        if (stan) cout << "Ollie wins." << endl;
    }
    return 0;
}

/*

 This solution does not work correctly after 324, see below for a better algo.

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n;
    while (scanf("%lld", &n)!=EOF) {
        int chance = 0; // 0 for stan and 1 for Ollie
        long long p = 1;
        while (p < n) {
            long long x = floor(n / (9 * p));
            if (x <= 1) {
                x = 9;
            } else if (x > 9) {
                x = 9;
            } else if (x <= 2) {
                x = 2;
            } else {
                x -= 1;
            }
            p *= x;
            chance ^= 1;
        }
        chance ^= 1;
        if (chance == 0) {
            cout << "Stan wins." << endl;
        } else {
            cout << "Ollie wins." << endl;
        }
    }
}*/
