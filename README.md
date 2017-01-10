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
> have to update node representing (0:2) (which is node = 1 in below image) and mark it immediate children lazy.
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
* Code for `range query`:
```c++
	int searchRange(int node, int start, int end, int l, int r, int count[], int lazy[]) {
		// Check if this node is marked for lazy updation and if yes, udpate it.
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
```

## Useful algorithms
* Algorithm for calculating polynomial equations:
> ![image for equation 1](/images/pol_equation.png)
> 
> We need to calculate p(x)
 
 One naive algorithm or brute force algorithm would be:
 
 ```c++
     int p = a[0] ;
     int xpower = 1;
     for (int i = 1; i <= n; ++i) {
        xpower = x ∗ xpower;
        p = p + a i ∗ xpower;
     }
 ```
 > In this algorithm we have to perform 2*n multiplications and n additions. Which is not that good.
 
 > One better algorithm is `Horner's Method`:
 
 ```c++
    int res = 0;
    for (int i = n; i <= 0; --i) {
        res = (res * x) + a[i];
    }
    return res;
 ```
 > This algorithm assumes the fact that,
 > ![image for equation1](/images/pol_equation.png) can be written as
 > ![image for equation2](/images/pol_equation_1.png)
 > If we go on like that we will have `a[n]` and next one will be
 > `a[n-1]*x`.
 
## Mathematical formulas and proofs
* Sum of 1 to n  
![image_for_arithmetic](/images/arithmatic_sequence.png)
  
Proof:
> Suppose S(n) = 1 + 2 + . . . + n     &nbsp; &nbsp; &nbsp; &nbsp; (eq 1)  
> We can also say that, S(n) = n + n-1 + n-2 + . . . + 1 &nbsp; &nbsp; &nbsp; &nbsp; (eq 2)   
> Adding eq 1 and eq 2, we have,
> 2 S(n) = (n + 1) + (n + 1) + . . . (n + 1)  
> We should note that each number is (n + 1) and there are n elements. So the sum would be: n * (n + 1).
> So ![image for arithmetic2](/images/arithmetic_seq_1.png)
  
* Sum of square of a sequence  
![image for arithmetic2](/images/arithmetic_seq_square.png)
 
Proof:  
> We know that  &nbsp; &nbsp; ![image_for_lemma](/images/arithmetic_lemma.png) &nbsp; &nbsp; (can be proved using mathematical induction). So  &nbsp; &nbsp; ![image for first step](/images/arithmetic_sqr_proof_step_1.png) &nbsp; &nbsp; which can be written as &nbsp; &nbsp; ![image for step2](/images/arithmetic_sqr_proof_step_2.png). &nbsp; &nbsp;  
> By reducing the above equation we will get &nbsp; &nbsp; ![image for arithmetic2](/images/arithmetic_seq_1.png)
 
* Sum of cubes of a sequence  
![image for arithmetic3](/images/arithmetic_seq_cubes.png)
 
Proof:
> We can prove this by induction. There is another way of proving this by using.
>![link](https://proofwiki.org/wiki/Sum_of_Sequence_of_Cubes)