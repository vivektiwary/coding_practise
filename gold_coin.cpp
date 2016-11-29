//
// Created by vivek on 26/11/16.
//
/*
 * In Byteland they have a very strange monetary system.
 * Each Bytelandian gold coin has an integer number written on it.
 * A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4.
 * But these numbers are all rounded down (the banks have to make a profit).
 * You can also sell Bytelandian coins for American dollars. The exchange rate is 1:1.
 * But you can not buy Bytelandian coins.You have one gold coin.
 * What is the maximum amount of American dollars you can get for it?
 *
 *
 * Note: Here at first i did not notice that this problem consists of sub problems
 * so i naively tried to solve it for (n/2 + n/3 + n/4) but on second look, i found
 * that this problem consists some sub-problems. So at first I tried to solve it
 * using recursion, but the time limit got exceeded. Then later on I used 'memoization'.
 * Also i found out that (10^9 >>>> 2^16 but less than 2^32.
 *
 * */
#include <iostream>
#include <map>

using namespace std;

map<int, long long> dp;

long long find_dollar(long long num) {
    if (num == 0) {
        return 0;
    }
    if (dp[num] != 0) return dp[num];
    long long tempValue = find_dollar(num/2) + find_dollar(num/3) + find_dollar(num/4);
    if (tempValue > num) {
        dp[num] = tempValue;
    }
    else {
        dp[num] = num;
    }
    return dp[num];
}

int main() {
    long long num;
    while(cin >> num) {
        long long res = find_dollar(num);
        cout << res << endl;
    }
}
