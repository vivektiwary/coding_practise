# Practise code from various websites including codechef, hackerearth, hackerrank



## Important concepts:
* Segment Trees:
> Segment trees are data structures which are particularly helpful in range query and 
> range update.
> The time complexity of building the tree is O(n). As we need to update the value of 
> each node and their are (2*n -1) nodes in the tree.
> The point which should be noted is that the time complexity of query and update is
> only O(lg n).


* Lazy Propagation:
> Lazy propagation refers to a mechanism where we do not update all the nodes in a 
> given range. Rather than that, we lazily update the parent node of a range and mark
> its children for `lazy update`.

> For example: (Please refer to the image given below to understand better.)
> Suppose you have to update all the nodes in range [0:2], (this symbol means, both are included)
> We don't have to update all the nodes in that given range if we use lazy propagation. We only
> have to update node representing (0:2) and mark it immediate children lazy.
> 	* We need an auxilary space for storing the nodes which have been marked lazy.
>   * We need to update the node values only when searching.

![Image for segment tree]
(/images/segment_tree.jpg)

* Code for building a `segment tree`:
```c++
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
```

* Code for `range update`:
```c++
	void updateRange(int node, int start, int end, int l, int r, int val, int count[], int lazy[]) {
		// In this code we are using lazy propagation. For more details about lazy propagation read above.
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
```
