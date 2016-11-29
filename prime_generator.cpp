//
// Created by vivek on 26/11/16.
//
/*
 * Shridhar wants to generate some prime numbers for his cryptosystem. Help him!
 * Your task is to generate all prime numbers between two given numbers.
 *
 * Input:
 *
 * The first line contains t, the number of test cases (less then or equal to 10).
 * Followed by t lines which contain two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.
 *
 * Output
 *
 * For every test case print all prime numbers p such that m <= p <= n, one number per line.
 * Separate the answers for each test case by an empty line.
 *
 * */


#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

map<long, bool>sieve;

void regularSieve(int num, vector<int> &prime, long lowerLimit, long higherLimit) {
	bool mark[num + 1];
	memset(mark, true, sizeof(mark));
	for (int i = 2; i*i <= num; ++i) {
		if (mark[i]) {
			for (int j = 2*i; j <= num; j += i) {
				mark[j] = false;
			}
		}
	}

	for (int i = 2; i <= num; ++i) {
		if (mark[i]) {
			prime.push_back(i);
			if (i >= lowerLimit && i <= higherLimit) {
				cout << i << endl;
			}
		}
	}
}

void segmentedSieve(long m, long n) {
	int limit = (int) floor(sqrt(1000000000)) + 1;
	vector<int> prime;
	regularSieve(limit, prime, m, n);
	bool mark[(n - m) + 1];
	memset(mark, true, sizeof(mark));
	for (int i = 0; i < prime.size(); ++i) {
		int lowPrime = floor(m / prime[i]) * prime[i];
		if (lowPrime < m) {
			lowPrime += prime[i];
		}
		for (int j = lowPrime; j <= n; j += prime[i]) {
			mark[j - m] = false;
		}
	}
	for (int i = m; i <= n; ++i) {
		if (mark[i - m] && i >= m && i > 1 && i > 0) {
			cout << i << endl;
		}
	}
	prime.clear();
}


int main() {
	int t;
	cin >> t;
	while(t--) {
		long m, n;
		cin >> m >> n;
		segmentedSieve(m, n);
	}
	return 0;
}
