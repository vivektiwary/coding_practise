# Basic concepts related to programming

## <a name='table_of_contents'></a>Table of contents:
1. [Sorting and Searching](#sorting_and_searching)
    1. [Application of Sorting](#application_of_sorting)
2. [Algorithm Analysis](#algorithm_analysis)
3. [Common Algorithms](#common_algorithms)
4. [Data Structures and Concepts](#important_data_structures_and_concepts)
5. [Mathematical formulas and their Proofs](#math_formulas_and_proofs)
6. [Mathematical concepts and Algorithms](#mathematical_concepts_and_algorithm)
7. [Puzzles](#puzzles)


## <a name='sorting_and_searching'></a> Sorting and Searching

### <a name='application_of_sorting'></a> Application of `sorting`:

1. **Searching**: Binary search tests whether an item is in a dictionary in `O(log n)` time, provided the keys are all sorted. `Search preprocessing` is perhaps the single most important application of `sorting`.

2. **Closest pair**: Given a set of n numbers, how do you find the pair of numbers that have the `smallest difference` between them? Once the numbers are `sorted`, the closest pair of numbers must lie next to each other somewhere in sorted order. Thus, a `linear-time` scan through them completes the job, for a total of `O(n log n)` time including the sorting.

3. **Element Uniqueness**: Are there any `duplicates` in a given set of n items? This is a `special case` of the `closest-pair` problem above, where we ask if there is a pair separated by a gap of zero. The `most efficient` algorithm `sorts the numbers` and then does a `linear scan` though checking all adjacent pairs.

4. **Frequency Distribution**: Given a set of n items, which element occurs the `largest number` of times in the set? If the items are sorted, we can `sweep` from `left to right` and count them, since all identical items will be lumped together during sorting. 
To find out how often an arbitrary element k occurs, look up k using binary search in a sorted array of keys. By walking to the left of this point until the first the element is not k and then doing the same to the right, we can find this count in `O(log n + c)` time, where `c` is the number of `occurrences of k`.
Even better, the number of instances of `k` can be found in `O(log n)` time by using `binary search` to look for the positions of both `k − e` and `k + e` (where
`e` is arbitrarily small) and then taking the difference of these positions.

5. **Selection**: What is the `k`<sup>th</sup> largest item in an array? If the keys are placed in sorted order, the `k`<sup>th</sup> largest can be found in `constant time` by simply looking at the `k`<sup>th</sup> position of the array. In particular, the median element (see Section 14.3 (page 445)) appears in the `(n/2)`<sup>nd</sup> position in sorted order.

6. **Convex hulls**: What is the polygon of `smallest area` that contains a given set of `n` points in two dimensions? The `convex hull` is like a `rubber band` `stretched over the points in the plane and then released`. It compresses to just cover the points, as shown in Figure 4.1(l). The `convex hull` gives a nice representation of the shape of the points and is an important building block for more sophisticated geometric algorithms, as discussed in the catalog in Section 17.2 (page 568).  
But how can we use sorting to construct the convex hull? Once you have the points sorted by `x-coordinate`, the points can be inserted from left to right into the hull. Since the `right-most point` is always on the `boundary`, we know that it will appear in the `hull`. Adding this new `right-most` point may cause others to be deleted, but we can quickly identify these points because they lie inside the polygon formed by adding the new point. See the example in Figure 4.1(r). These points will be neighbors of the previous point we inserted, so they will be easy to find and delete. The total time is linear after the sorting has been done.