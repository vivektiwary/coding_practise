/**
 *  Rohit dreams he is in a shop with an infinite amount of marbles. He is allowed to select n marbles. 
 *  There are marbles of k different colors. From each color there are also infinitely many marbles. 
 *  Rohit wants to have at least one marble of each color, but still there are a lot of possibilities for 
 *  his selection. In his effort to make a decision he wakes up. Now he asks you how many possibilities 
 *  for his selection he would have had. Assume that marbles of equal color can't be distinguished, and the 
 *  order of the marbles is irrelevant.
 *
 * 
 * Input:
 * 
 * The first line of input contains a number T <= 100 that indicates the number of test cases to follow. 
 * Each test case consists of one line containing n and k, where n is the number of marbles Rohit selects 
 * and k is the number of different colors of the marbles. You can assume that 1<=k<=n<=100 00 00.
 *
 * 
 * Output:
 * 
 * For each test case print the number of possibilities that Rohit would have had. You can assume that 
 * this number fits into a signed 64 bit integer.
 * 
 * Example
 * 
 * Input:
 * 2
 * 10 10
 * 30 7
 * 
 * Output:
 * 1
 * 475020
 *
 *
 * Concepts: 
 * 
 * We need to select n marbles out of k types with the condition that atleast one from each type is selected.
 * For selecting n objects out of r types we have the formular  (n + r - 1)C(n)
 * But as we have a condition that atleast one should be selected, we have choose k objects 1 from each then
 * we need to choose (n - k) objects from k types. So the formular would be:
 * 		n = n - k
 *   	r = k
 * so,
 * 		(n - k + k - 1)C(n - k)
 *
 *
 * Algo for computing nC(r):
 *
 * Recursive algo:
 * 		n C 0 = 1
 * 		n C k = (n C k-1)* ((n - k + 1)/ k)
 *
 * 		Pseudo code:
 * 			binom n 0 = 1
 * 			binom n k = binom n (k - 1) * (n - k + 1) / k
 *
 * Another algo (Prime factorisation of n C k)
 *
 *
 * Another algo (Stirling's approximation)
 */


#include <iostream>
using namespace std;

long long getNumberOfWays(int objects, int types) {
	int r = objects - types;
	int n = r + types - 1;
	if (r > n/2) {
		r = n - r;
	}
	long long result = 1;
	for (int i = 0; i < r; ++i) {
		result *= n;
		result /= (i + 1);
		n--;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	int testCases;
	cin >> testCases;
	while (testCases--) {
		int n, k;
		cin >> n >> k;
		long long result = getNumberOfWays(n, k);
		cout << result << endl;
	}
	return 0;
}

