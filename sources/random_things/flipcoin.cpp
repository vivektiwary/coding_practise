/**
 * There are N coins kept on the table, numbered from 0 to N - 1. Initially, each coin is kept tails up.
 * You have to perform two types of operations :
 *
 * 1) Flip all coins numbered between A and B inclusive. This is represented by the command "0 A B"
 * 2) Answer how many coins numbered between A and B inclusive are heads up. This is represented by the command "1 A B".
 *
 * Input :
 *
 * The first line contains two integers, N and Q. Each of the next Q lines are either of
 * the form "0 A B" or "1 A B" as mentioned above.
 *
 * Output :
 *
 * Output 1 line for each of the queries of the form "1 A B" containing the required answer for the corresponding query.
 *
 * Sample Input :
 *
 * 4 7
 * 1 0 3
 * 0 1 2
 * 1 0 1
 * 1 0 0
 * 0 0 3
 * 1 0 3
 * 1 3 3
 *
 * Saple Output :
 * 0
 * 1
 * 0
 * 2
 * 1
 *
 *
 * Algo: The naive algo is giving 'time limit exceeded error' so doing it with segment tree.
 *
 */


#include <iostream>
#include <cstring>

using namespace std;


void build(int node, int start, int end, int count[], int coin[]) {
	if (start == end) {
		count[node] = coin[start];
		return;
	}
	int mid = (start + end) / 2;
	build((node * 2 + 1), start, mid, count, coin);
	build((node * 2 + 2), mid + 1, end, count, coin);
	count[node] = count[node * 2 + 1] + count[node * 2 + 2];
}

void updateRange(int node, int start, int end, int l, int r, int val, int count[], int lazy[]) {
	if (lazy[node] != 0) {
		if (start == end) {
			count[node] ^= 1;
		}
		else {
			if (count[node] > 0) {
				count[node] = ((end - start + 1) * lazy[node] - count[node]);
			}
			else {
				count[node] += (end - start + 1) * lazy[node];
			}
			lazy[node * 2 + 1] ^= lazy[node];
			lazy[node * 2 + 2] ^= lazy[node];
		}
		lazy[node] = 0;
	}
	if (start > end || start > r || end < l) return;

	if (start >= l && end <= r) {
		if (start == end) {
			count[node] ^= 1;
		}
		else {
			if (count[node] > 0) {
				count[node] = ((end - start + 1) * val - count[node]);
			}
			else {
				count[node] += (end - start + 1) * val;
			}
			lazy[node * 2 + 1] ^= val;
			lazy[node * 2 + 2] ^= val;
		}
    return;
	}
	int mid = (start + end) / 2;
  int left = (node * 2) + 1;
  int right = (node * 2) + 2;
	updateRange(left, start, mid, l, r, val, count, lazy);
	updateRange(right, mid + 1, end, l, r, val, count, lazy);
	count[node] = count[node * 2 + 1] + count[node * 2 + 2];
}

int searchRange(int node, int start, int end, int l, int r, int count[], int lazy[]) {
	if (lazy[node] != 0) {
		if (start == end) {
			count[node] ^= 1;
		}
		else {
			if (count[node] > 0) {
					count[node] = ((end - start + 1) * lazy[node] - count[node]);
			}
			else {
					count[node] += (end - start + 1) * lazy[node];
			}
			lazy[node*2 + 1] ^= lazy[node];
			lazy[node*2 + 2] ^= lazy[node];
		}
		lazy[node] = 0;
	}
	if (start > end || start > r || end < l) return 0;
	if (start >= l && end <= r)  return count[node];
	int mid = (start + end) / 2 ;
	int p1 = searchRange((node * 2) + 1, start, mid, l, r, count, lazy);
	int p2 = searchRange((node * 2) + 2, mid + 1, end, l, r, count, lazy);
	return p1 + p2;
}


int main(int argc, char const *argv[])
{
	int n, q;
	cin >> n >> q;
	int coin[n];
	memset(coin, 0, sizeof(coin));
	int count[4*n];
	int lazy[4*n];
	memset(lazy, 0, sizeof(lazy));
	build(0, 0, n-1, count, coin);
	while (q--) {
		int ops, i, j;
		cin >> ops >> i >> j;
		if (ops == 1) {
			cout << searchRange(0, 0, n-1, i, j, count, lazy) << endl;
		}
		else if (ops == 0) {
			updateRange(0, 0, n-1, i, j, 1, count, lazy);
		}
	}
	return 0;
}
