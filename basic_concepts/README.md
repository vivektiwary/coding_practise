# Basic concepts related to programming

## <a name='table_of_contents'></a>Table of contents:
1. [Common Data-structures](#common_data_structures)
    1. [Arrays](#arrays)
    2. [Recursive Objects](#recursive_objects)
    3. [Dictionaries](#dictionaries)
        1. [Comparing Dictionary Implementations](#comparing_dictionary_implementation)
    4. [Binary Search Trees](#binary_search_tree)
    5. [Priority Queue](#priority_queue)
        1. [Basic Priority Queue Implementation](#basic_priority_queue_implementation)
    6. [Hashing and String](#hashing_and_string)
        1. [Collision Resolution](#collision_resolution)
    7. [Specialised Data Structures](#specialised_data_structures)
2. [Sorting and Searching](#sorting_and_searching)
    1. [Application of Sorting](#application_of_sorting)
    2. [Order of Sorting](#order_of_sorting)
    3. [Heap-sort: Fast Sorting via Data Structures](#heap_sort)
        1. [Heaps](#heaps)
        2. [Constructing Heaps](#constructing_heaps)
        3. [Extracting the Minimum](#extracting_minimum)
        4. [Faster Heap Construction](#faster_heap_construction)
    4. [Sorting by Incremental Insertion](#sorting_by_incremental_insertion)
    5. [MergeSort: Sorting by Divide-and-Conquer](#merge_sort)
    6. [QuickSort: Sorting by Randomization](#quick_sort)
        1. [Intuition: The Expected Case for QuickSort](#expected_case_for_quick_sort)
        2. [Randomised Algorithms](#randomized_algorithm)
    7. [Distribution Sort: Sorting via Bucketing](#distribution_sort)
    8. [Binary Search and Related Algorithms](#binary_search_and_related_algorithms)
        1. [Counting Occurrences](#counting_occurrences)
        2. [One-Sided Binary Search](#one_sided_binary_search)
        3. [Square and Other Roots](#square_and_other_roots)
    9. [Divide-and-Conquer](#divide_and_conquer)
        1. [Recurrence Relations](#recurrence_relations)
        2. [Divide-and-Conquer Recurrences](#divide_and_conquer_recurrences)
        3. [Solving Divide-and-Conquer Recurrences](#solving_divide_and_conquer_recurrences)
3. [Graph Traversal](#graph_traversal)
    1. [Flavors of Graphs](#flavors_of_graph)
    2. [Friendship Graph](#friendship_graph)
    3. [Data Structures for Graphs](#data_structures_for_graphs)
    4. [Traversing a Graph](#traversing_a_graph)
    5. [Breadth-First Search](#breadth_first_search)
        1. [Exploiting Traversal](#exploiting_traversal)
        2. [Finding Paths](#finding_paths)
    6. [Application of Breadth First Search](#application_of_breadth_first_search)
        1. [Connected Components](#connected_components)
        2. [Two Coloring Graphs](#two_coloring_graphs)
    7. [Depth-First Search](#depth_first_search)
    8. [Application of Depth-First Search](#application_of_depth_first_search)
        1. [Finding Cycles](#finding_cycles)
3. [Important Questions](#important_questions)
4. [Problems Wiki](#problem_wiki)
4. [Data Structures and Concepts](#important_data_structures_and_concepts)
5. [Mathematical formulas and their Proofs](#math_formulas_and_proofs)
6. [Mathematical concepts and Algorithms](#mathematical_concepts_and_algorithm)
7. [Puzzles](#puzzles)


## <a name='common_data_structures'></a> Common Data Structures

- Contiguous vs. Linked Data Structures:
  - Data structures can be neatly classified as either contiguous or linked, depending
upon whether they are based on arrays or pointers:
    - `Contiguously-allocated` structures are composed of single slabs of 
    memory, and include arrays, matrices, heaps, and hash tables.
    
    - `Linked data structures` are composed of distinct chunks of memory 
    bound together by `pointers`, and include lists, trees, and 
    graph adjacency lists.


### <a name='arrays'></a> Arrays:

Advantages of contiguously-allocated arrays include:
- `Constant-time access given the index` – Because the index of each element
maps directly to a particular memory address, we can access arbitrary data
items instantly provided we know the index.

- `Space efficiency` – Arrays consist purely of data, so no space is wasted with
links or other formatting information. Further, `end-of-record` information is
not needed because arrays are built from `fixed-size` records.

- `Memory locality` – A common programming idiom involves iterating through
all the elements of a data structure. Arrays are good for this because they
exhibit excellent `memory locality`. `Physical continuity` between `successive data`
accesses helps exploit the `high-speed cache memory` on modern computer
architectures.

- Downside: As size is fixed, it can't be adjusted in the middle of
the program.

  - Actually, we can efficiently enlarge arrays as we need them, through the miracle
  of `dynamic arrays`. Suppose we start with an array of size 1, and double its size from
  `m` to `2m` each time we run out of space. This doubling process involves allocating a
  new contiguous array of size `2m`, copying the contents of the old array to the lower
  half of the new one, and returning the space used by the old array to the storage
  allocation system.

  - The apparent waste in this procedure involves the `recopying of the old contents`
  on each expansion. How many times might an element have to be recopied after a
  total of `n` insertions?

  - Well, the first inserted element will have been recopied when
  the array expands after the first, second, fourth, eighth, . . . insertions. It will take
  log<sub>2</sub> n doublings until the array gets to have `n` positions.

  - However, most elements do not suffer much upheaval. Indeed, the `(n/2 + 1)st` 
  through `nth` elements will move at most once and might never 
  have to move at all.

  - If `half the elements` move `once`, a `quarter of the elements` `twice`, and so on, the
  total number of movements `M` is given by
  ![dynamic array equation](../images/dynamic_array_equation.png)
  
  - Thus, each of the `n` elements move only `two times` on average, and the total work
  of managing the `dynamic array` is the same `O(n)` as it would have been if a single
  array of sufficient size had been allocated in advance!
  
  - The primary thing lost using dynamic arrays is the `guarantee` that `each array
  access` takes `constant time` in the `worst case`. Now all the queries will be fast, 
  except for those relatively few queries `triggering array doubling`. What we get 
  instead is a `promise` that the `nth` array access will be completed quickly enough 
  that the `total effort` expended so far will still be `O(n)`. Such `amortized guarantees` 
  arise frequently in the analysis of data structures.


[Table of contents](#table_of_contents)

### <a name='recursive_objects'></a> Recursive objects
- `Lists` – Chopping the first element off a linked list leaves a `smaller linked list`.
This same argument works for `strings`, since removing characters from string
leaves a string. Lists are `recursive objects`.

- `Arrays` – Splitting the first `k` elements off of an `n` element array gives two
smaller arrays, of size `k` and `n − k`, respectively. Arrays are `recursive objects`.


### <a name='dictionaries'></a> Dictionaries

The `dictionary` data type permits access to data items by content. 
You stick an item into a dictionary so you can find it when you 
need it.

The primary operations of dictionary support are:
- `Search(D,k)` – Given a search key `k`, return a pointer to the element in 
dictionary `D` whose key value is `k`, if one exists.

- `Insert(D,x)` – Given a data item `x`, add it to the set in the dictionary `D`.

- `Delete(D,x)` – Given a pointer to a given data item `x` in the dictionary `D`,
  remove it from `D`.

Certain dictionary data structures also efficiently support other useful 
operations:

- `Max(D)` or `Min(D)` – Retrieve the item with the `largest` (or `smallest`) key 
from `D`. This enables the dictionary to serve as a `priority queue`.

- `Predecessor(D,k)` or `Successor(D,k)` – Retrieve the item from `D` whose key is
immediately before (or after) `k` in sorted order. These enable us to iterate
through the elements of the data structure.

>Many common data processing tasks can be handled using these dictionary
operations. For example, suppose we want to remove all duplicate names from a
mailing list, and print the results in sorted order.
>
>Initialize an empty dictionary D, whose search key will be the record name. 
Now read through the mailing list, and for each record search to see if the 
name is already in D. If not, insert it into D.
>
>Once finished, we must extract the remaining names out of the dictionary.
By starting from the first item Min(D) and repeatedly calling Successor until we
obtain Max(D), we traverse all elements in sorted order.


[Table of contents](#table_of_contents)


### <a name='comparing_dictionary_implementation'></a>Comparing Dictionary Implementation
**Problem**:
>What are the asymptotic worst-case running times for each of the seven
fundamental dictionary operations (search, insert, delete, successor, predecessor,
minimum, and maximum) when the data structure is implemented as:
> - An unsorted array
> - A sorted array

**Solution**:

This problem reveal some of the inherent trade-offs 
of data structure design. A given data representation may permit efficient 
implementation of certain operations at the cost that other operations 
are expensive.

In addition to the array in question, we will assume access to a 
few extra variables such as `n`—the number of elements currently in 
the array. Note that we must maintain the value of these variables 
in the operations where they change (e.g., `insert` and `delete`), 
and `charge these operations` the cost of this `maintenance`.

The basic dictionary operations can be implemented with the following costs
on unsorted and sorted arrays, respectively:

| Dictionary Operation | Unsorted Array | Sorted Array  |
| :------------------: | :------------: | :-----------: |
| Search(L, k)         | O(n)           | O(log n)      |
| Insert(L, x)         | O(1)           | O(n)          |
| Delete(L, x)         | O(1)*          | O(n)          |
| Successor(L, x)      | O(n)           | O(1)          |
| Predecessor(L, x)    | O(n)           | O(1)          |
| Minimum(L)           | O(n)           | O(1)          |
| Maximum(L)           | O(n)           | O(1)          |


`Deletion` is somewhat trickier, hence the superscript( ∗ ) in the table. 
The definition states that we are given a pointer `x` to the element to 
delete, so we need not spend any time searching for the element. But 
removing the `xth` element from the array `A` leaves `a hole` that must 
be filled. We could fill the `hole` by moving each of the elements 
`A[x + 1]` to `A[n]` up `one position`, but this requires `Θ(n)` time 
when the first element is deleted. The following idea is better: 
just write over `A[x]` with `A[n]`, and decrement `n`. This only takes
`constant time`.

Implementing a dictionary using a `sorted array` completely `reverses` 
our notions of what is `easy` and what is `hard`. Searches can now be 
done in `O(log n)` time, using `binary search`, because we know the 
`median element` sits in `A[n/2]`. Since the upper and lower portions of 
the array are also `sorted`, the `search` can continue recursively on the 
appropriate portion. The number of `halvings of n` until we get to a 
single element is `Math.ceil(lg n)`.

>Data structure design must balance all the different operations it 
supports. The fastest data structure to support both operations `A` and `B` 
may well `not` be the `fastest structure` to support either `operation A` or
`B`.

**Note**: We can charge a operation some extra money (which will be asymptotically 
same), to make some other critical operation faster.
For example, If an operation is taking `O(n)` and another one is also
taking `O(n)` but if we do some processing(may be another loop, so the 
effective complexity would remain O(n)) in the first operation then
the next operation would be `O(1)`.


[Table of contents](#table_of_contents)


### <a name='binary_search_tree'></a> Binary Search Trees

We have seen data structures that allow `fast search` or `flexible update`, 
but not `fast search` and `flexible update`.  
`Unsorted`, `doubly-linked` lists supported `insertion` and
`deletion` in `O(1)` time but `search` took `linear time` in the worse case.
`Sorted arrays` support `binary search` and `logarithmic query times`, but 
at the cost of `linear-time update`.

Binary search requires that we have fast access to two elements—specifically
the median elements above and below the given node.  To combine these ideas, 
we need a `linked list` with `two pointers per node`. This is the basic 
idea behind `binary search trees`.

A `rooted binary tree` is recursively defined as either being 
- empty, or 
- consisting of a node called the `root`, together with two rooted binary 
trees called the left and right subtrees, respectively.

A `binary search tree` labels each node in a `binary tree` with a `single 
key` such that for any `node labeled x`, `all nodes` in the `left subtree` 
of `x` have `keys < x` while all nodes in the `right subtree` of `x` have 
`keys > x`. This `search tree labeling` scheme is `very special`. For any 
`binary tree` on `n` nodes, and any set of `n` keys, there is `exactly one` 
labeling that makes it a `binary search tree`.


**Finding minimum and maximum element in a tree**:

>Implementing the `find-minimum` operation requires knowing where the 
minimum element is in the tree. By definition, the `smallest key` must 
reside in the `left subtree` of the `root`, since all keys in the 
`left subtree` have values less than that of the `root`. The minimum 
element must be the `leftmost` descendent of the root. Similarly, the 
maximum element must be the rightmost descendent of the root.

```c
tree *find_minimum(tree *t)
{
    tree *min;                  /* pointer to minimum */
    if (t == NULL) return(NULL);
    min = t;
    while (min->left != NULL)
        min = min->left;
    return(min);
}
```

**Insertion in a tree**:
> There is only one place to insert an item `x` into a `binary search tree` 
`T` where we know we can find it again. We must replace the `NULL` pointer 
found in `T` after an `unsuccessful query` for the `key k`.
>
>This implementation uses `recursion` to combine the `search` and `node 
insertion` stages of `key insertion`. The three arguments to insert tree 
are
> - a pointer `l` to the `pointer linking` the `search subtree` to the 
`rest of the tree`,
> - the key `x` to be inserted, and 
> - a `parent pointer` to the `parent node` containing `l`.

```c
insert_tree(tree **l, item_type x, tree *parent)
{
    tree *p;                /* temporary pointer */
    if (*l == NULL) {
        p = malloc(sizeof(tree)); /* allocate new node */
        p->item = x;
        p->left = p->right = NULL;
        p->parent = parent;
        *l = p;                 /* link into parent’s record */
        return;
    }
    if (x < (*l)->item)
        insert_tree(&((*l)->left), x, *l);
    else
        insert_tree(&((*l)->right), x, *l);
}
```

Allocating the node and `linking` it in to the tree is a `constant-time` 
operation after the `search` has been `performed` in `O(h)` time.


**Deletion from a Tree**:
>Deletion is somewhat trickier than insertion, because removing a node 
means appropriately linking its two descendant subtrees back into the 
tree somewhere else. There are three cases:
> - `Leaf nodes` have `no children`, and so may be `deleted` by simply 
`clearing` the pointer to the `given node`.
> - The case of the `doomed node` having `one child` is also straightforward. 
There is `one parent` and `one grandchild`, and we can `link the grandchild` 
directly to the `parent` without `violating` the `in-order` labeling property 
of the tree.
> - But what of a to-be-deleted node with `two children`? Our solution is 
to `relabel` this node with the `key` of its `immediate successor` in 
`sorted order`. This `successor` must be the `smallest value` in the 
`right subtree`, specifically the `leftmost descendant` in the `right 
subtree (p)`. Moving this to the `point of deletion` results in a 
properly-labeled `binary search tree`, and reduces our `deletion problem` 
to physically removing a node with at most `one child`—a case that has 
been resolved above.


> A binary tree can have `heights` ranging from `lg n` to `n`. But how 
`tall are they on average`? The `average case` analysis of algorithms can 
be `tricky` because we must `carefully` specify what `we mean by average`. 
The question is well defined if `we consider each of the n!` possible insertion 
orderings `equally likely` and average over those. If so, we are in luck, 
because with `high probability` the resulting `tree` will have `O(log n)` 
height.
>
> This argument is an important example of the power of `randomization`. 
We can often develop simple algorithms that offer good performance with 
`high probability`. We will see that a similar idea underlies the fastest 
known sorting algorithm, `quicksort`.



[Table of contents](#table_of_contents)


### <a name='priority_queue'></a> Priority Queues

`Priority queues` are data structures that provide more flexibility than 
`simple sorting`, because they allow `new elements` to enter a system at 
arbitrary intervals. It is much more `cost-effective` to insert a new job 
into a `priority queue` than to `re-sort` everything on each such arrival.

The basic priority queue supports three primary operations:
- `Insert(Q,x)`– Given an item `x` with key `k`, insert it into the 
`priority queue Q`.
- `Find-Minimum(Q)` or `Find-Maximum(Q)`– Return a pointer to the item 
whose `key` value is `smaller` (`larger`) than any other key in the 
`priority queue Q`.
- `Delete-Minimum(Q)` or `Delete-Maximum(Q)`– Remove the item from the 
`priority queue Q` whose `key` is minimum (maximum).


[Table of contents](#table_of_contents)

### <a name='basic_priority_queue_implementation'></a> Basic Priority Queue Implementation

**Problem**:
> What is the worst-case time complexity of the three basic priority queue
operations (`insert`, `find-minimum`, and `delete-minimum`) when the basic 
data structure is
> - An unsorted array
> - A sorted array
> - A balanced binary search tree

**Solution**:
>There is surprising subtlety in implementing these three operations, even
 when using a data structure as simple as an unsorted array. The unsorted array
 dictionary implemented `insertion` and `deletion` in `constant time`, and 
 `search` and minimum in `linear time`.  
 A `linear time` implementation of `delete-minimum` can be composed from 
 `find-minimum`, followed by `search`, followed by `delete`.
>
>For sorted arrays, we can implement `insert` and `delete` in `linear time`,
 and `minimum` in `constant time`. However, all `priority queue` `deletions` 
 involve only the `minimum element`. By `storing` the `sorted array` in `reverse` 
 order (largest value on top), the `minimum element` will be the `last one` 
 in the array. `Deleting` the `tail element` requires `no movement` of any 
 items, just decrementing the number of remaining items n, and so 
 `delete-minimum` can be implemented in `constant time`.
>
> All this is fine, yet the following table claims we can implement `find-minimum`
  in `constant time` for each data structure:
  
|                   | Unsorted Array | Sorted Array | Balanced Tree |
|:------------:     | :-----------:  | :----------: | :-----------: |
| Insert(Q, x)      | O(1)           | O(n)         | O(log n)      |
| Find-Minimum(Q)   | O(1)           | O(1)         | O(1)          |
| Delete-Minimum(Q) | O(n)           | O(1)         | O(log n)      |

> The trick is using an `extra variable` to store a `pointer/index` to the `minimum`
  entry in each of these structures, so we can simply return this value whenever we
  are asked to `find-minimum`.
>
> Updating this pointer on each insertion is easy—we update it if and only 
  if the newly inserted value is `less than the current minimum`.
>
> But what happens on a `delete-minimum`? We can `delete` the `minimum entry` 
  `have`, then do an `honest find-minimum` to restore our `canned value`. 
  The `honest find-minimum` takes `linear time` on an `unsorted array` and 
  `logarithmic time` on a `tree`, and hence can be `folded` into the `cost` 
  of each `deletion`.

[Table of contents](#table_of_contents)

### <a name='hashing_and_string'></a> Hashing and String

`Hash tables` are a very practical way to maintain a `dictionary`. They 
exploit the fact that `looking an item` up in an `array` takes `constant 
time` once you have its index. A `hash function` is a `mathematical function`
that maps `keys to integers`. We will use the `value of our hash function` 
as an `index` into an `array`, and `store` our item at that `position`.

The first step of the hash function is usually to map each key to a 
big integer. Let `α` be the size of the alphabet on which a given 
string `S` is written. Let `char(c)` be a function that maps each 
symbol of the `alphabet` to a `unique integer` from `0` to `α − 1`. 
The function  
![image for hash function](../images/hash_function.png)  
maps `each string` to a `unique` (but large) integer by treating the 
characters of the string as “digits” in a `base-α` number system.

The result is `unique identifier` numbers, but they are `so large` 
they will quickly `exceed` the number of `slots` in our `hash table`
(denoted by `m`). We must reduce this number to an integer between 
`0` and `m−1`, by taking the remainder of `H(S) mod m`.
This works on the same principle as a `roulette wheel`. The ball 
travels a `long distance` around and around the `circumference-m` 
wheel `Math.floor( H(S)/m )` times before settling down to a `random bin`. 
If the `table size` is selected with `enough finesse` 
(ideally `m` is a `large prime` not too close to 2<sup>i</sup> − 1), 
the resulting hash values should be `fairly uniformly distributed`.


### <a name='collision_resolution'></a> Collision Resolution

No matter how good our hash function is, we had better be prepared 
for collisions, because `two distinct keys` will occasionally 
`hash to the same value`.

- `Chaining` is the `easiest approach` to `collision resolution`. 
Represent the `hash table` as an `array of m linked lists`.
The `ith` list will contain all the items that hash to the value of `i`.
Thus `search`, `insertion`, and `deletion` reduce to the corresponding
problem in `linked lists`.

    - If the `n keys` are `distributed uniformly` in a table, each list
    will contain roughly `n/m` elements, making them a `constant size` when 
    `m ≈ n`.

    - `Chaining` is `very natural`, but devotes a considerable amount of memory 
    to `pointers`. This is space that could be used to make the table larger, 
    and hence the "lists" smaller.

- The alternative is something called `open addressing`.
    - The hash table is maintained as an `array of elements` (not buckets), 
      each initialized to `null`.
    - On an `insertion`, we check to see if the desired position is `empty`.
      If so, we `insert` it. If not, we must find some other place to insert
      it instead.
    - The simplest possibility (called `sequential probing`) inserts the item 
      in the `next open spot` in the table.
    - If the `table` is `not too full`, the contiguous runs of items should 
      be `fairly small`, hence this `location` should be only a few slots 
      from its `intended position`.
    - `Searching` for a given key now involves going to the appropriate hash 
      value and checking to see if the item there is the one we want. If so,
      return it. Otherwise we must keep checking through the length of
      the run.
    - `Deletion` in an `open addressing scheme` can get `ugly`, since removing
       one element might `break a chain of insertions`, making some elements
       inaccessible. We have `no alternative` but to `reinsert` all the items 
       in the run following the `new hole`.

[Table of contents](#table_of_contents)

### <a name='specialised_data_structures'></a> Specialised Data Structures
- `String data structures` – Character strings are typically represented by 
   arrays of characters, perhaps with a special character to mark the end of 
   the string. `Suffix trees/arrays` are special data structures that preprocess 
   strings to make `pattern matching` operations `faster`.
   
- `Geometric data structures` – Geometric data typically consists of collections 
   of `data points and regions`. `Regions` in the `plane` can be described by 
   `polygons`, where the `boundary of the polygon` is given by a `chain of line 
   segments`. `Polygons` can be represented using an `array of points` 
   (v<sub>1</sub> , . . . , v<sub>n</sub> , v<sub>1</sub> ), such that (v<sub>i</sub> , v<sub>i+1</sub> ) 
   is a `segment` of the `boundary`. `Spatial data structures` such as
   `kd-trees` organize `points and regions` by `geometric location` to 
   support `fast search`.

- `Graph data structures` – Graphs are typically represented using either 
   `adjacency matrices` or `adjacency lists`. The choice of representation 
   can have a substantial impact on the design of the resulting `graph 
   algorithms`.

- `Set data structures` – `Subsets of items` are typically represented using 
   a dictionary to support `fast membership queries`. Alternately, `bit vectors` 
   are `boolean arrays` such that the i<sup>th</sup> bit represents `true` 
   if `i` is in the `subset`.

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


[Table of contents](#table_of_contents)

### <a name='order_of_sorting'></a> Order of Sorting:

1. **increasing or decreasing order?**: A set of keys S are sorted in `ascending` order when S<sub>i</sub> ≤ S<sub>i+1</sub> for all 1 ≤ i < n. They are in `descending` order when S<sub>i</sub> ≥ S<sub>i+1</sub> for all 1 ≤ i < n. Different applications call for different orders.

2. **sorting just the key or an entire record?**: Sorting a data set involves `maintaining the integrity` of `complex data` records. A mailing list of names, addresses, and phone numbers may be sorted by names as the `key field`, but it had better `retain the linkage` between `names` and `addresses`. Thus, we need to `specify` which `field is the key field` in any complex record, and understand the full extent of each record.

3. **what should we do with equal key?**: Elements with `equal` key values will all bunch together in any total order, but sometimes the relative order among these keys matters. Suppose an encyclopedia contains both `Michael Jordan(the basketball player)` and `Michael Jordan (the statistician)`. Which entry should appear first? You may need to `resort to secondary keys`, such as article size, to resolve ties in a meaningful way.  
Sometimes it is required to leave the items in the `same relative order` as in the `original permutation`. Sorting algorithms that automatically enforce this requirement are called `stable`. Unfortunately `few fast algorithms` are `stable`. `Stability` can be achieved for any sorting algorithm by `adding the initial position` as a `secondary key`.  
Of course we could make no decision about equal key order and let the ties fall where they may. But beware, certain efficient sort algorithms (such as `quick-sort`) can run into `quadratic performance trouble` unless `explicitly engineered` to deal with `large numbers of ties`.

4. **what about non-numerical data?**: Alphabetizing is the sorting of text strings. Libraries have very complete and complicated rules concerning the `relative collating sequence` of characters and punctuation. Is `Skiena` the same key as `skiena`? Is `Brown-Williams` before or after `Brown America`, and before or after `Brown, John`?  

    The right way to specify such matters to your sorting algorithm is with an application-specific pairwise-element `comparison function`. Such a `comparison function` takes pointers to record items a and b and returns “<” if a < b, “>” if a > b, or “=” if a = b.
    
    
[Table of contents](#table_of_contents)


### <a name='heap_sort'></a> HeapSort: Fast Sorting via Data Structures

We start with `data structure` design, because one of the most `dramatic algorithmic improvements` via `appropriate data structures` occurs in `sorting`. `Selection sort` is a simple-to-code algorithm that repeatedly extracts the smallest remaining element from the unsorted part of the set:

```c
    SelectionSort(A):
        For i = 1 to n do
            Sort[i] = Find-Minimum from A
            Delete-Minimum from A
        Return(Sort)
```

A `C` language implementation of `selection sort` appeared back in Section 2.5.1(page 41). There we `partitioned` the input array into `sorted` and `unsorted` regions. To find the `smallest item`, we performed a `linear sweep` through the `unsorted portion` of the array.

The `smallest item` is then `swapped` with the `i`<sup>th</sup> item in the array before moving on to the next iteration. `Selection sort` performs `n` iterations, where the average iteration takes `n/2` steps, for a total of O(n<sup>2</sup>) time.  
But what if we improve the `data structure`? It takes `O(1)` time to remove a particular item from an `unsorted array` once it has been located, but `O(n)` time to find the `smallest item`. These are exactly the operations supported by `priority queues`.  
So what happens if we `replace` the `data structure` with a `better priority queue` implementation, either a `heap` or a `balanced binary tree`? Operations within the loop now take `O(log n)` time each, instead of `O(n)`. Using such a `priority queue implementation` speeds up `selection sort` from O(n<sup>2</sup>) to O(n log n).  
The name typically given to this algorithm, `heapsort`, `obscures` the relationship between them, but `heapsort` is nothing but an `implementation of selection sort` using the `right data structure`.

[Table of contents](#table_of_contents)

#### <a name='heaps'></a> Heaps:

Heaps are a simple and elegant data structure for efficiently supporting the `priority queue` operations `insert` and `extract-min`. They work by maintaining a `partial order` on the set of elements which is `weaker` than the `sorted order` (so it can be efficient to maintain) yet `stronger` than `random order` (so the minimum element can be quickly identified).  

Power in any hierarchically-structured organization is reflected by a `tree`, where each `node` in the tree represents a `person`, and `edge (x, y)` implies that `x` directly `supervises` (or dominates) `y`. The fellow at the root sits at the “top of the heap.”

In this spirit, a `heap-labeled tree` is defined to be a `binary tree` such that the `key labeling` of each `node` `dominates` the `key labeling` of each of its `children`. In a `min-heap`, a node `dominates` its `children` by containing a `smaller key` than they do, while in a `max-heap` `parent nodes` dominate by being `bigger`.

![image_for_min_heap](../images/binary-heap.png)

The above figure presents a min-heap ordered tree of red-letter years in American history (kudos to you if you can recall what happened each year).

The most natural implementation of this binary tree would store each key in a `node with pointers` to its two children. As with binary search trees, the `memory used by the pointers` can easily `outweigh` the `size of` keys, which is the data we are really interested in.

The heap is a slick data structure that enables us to represent binary trees `without` using `any pointers`. We will store data as `an array of keys`, and `use the position` of the keys to `implicitly satisfy` the role of the pointers.

We will store the `root of the tree` in the `first position` of the array, and its `left and right` children in the `second` and `third` positions, respectively. In general, we will store the 2<sup>l</sup> keys of the `l`<sup>th</sup> level of a complete binary tree from left-to-right in positions 2<sup>l−1</sup> to 2<sup>l</sup> − 1, as shown in Figure 4.2(r). We assume that the array `starts` with `index 1` to simplify matters.

```c
typedef struct {
    item_type q[PQ_SIZE+1];  /* body of queue */
    int n;  /* number of queue elements */
} priority_queue;
```

What is especially nice about this representation is that the positions of the parent and children of the key at position `k` are readily determined. The `left child` of `k` sits in position `2k` and the `right child` in `2k + 1`, while the parent of `k` holds court in position 	`floor(n/2)`. Thus we can move around the tree without any pointers.

```c
pq_parent(int n)
{
    if (n == 1) return(-1);  
    else return((int) n/2);  /* implicitly take floor(n/2) */
}

pq_young_child(int n)
{
    return(2 * n);
}

```

So, we can store any binary tree in an array without pointers. What is the catch? Suppose our height `h` tree was `sparse`, meaning that the number of nodes n < 2<sup>h</sup> . All missing internal nodes still take up space in our structure, since we must represent a full binary tree to maintain the positional mapping between parents and children.

Space efficiency thus demands that we not allow holes in our tree—i.e., that each level be packed as much as it can be. If so, only the last level may be incomplete. By packing the elements of the last level as far to the left as possible, we can represent an `n-key` tree using exactly `n` elements of the array. If we did not enforce these structural constraints, we might need an array of size 2<sup>n</sup> to store the same elements. Since all but the last level is always filled, the height `h` of an `n` element heap is logarithmic because:

![image_for_heap_height_summation](../images/heap_height_summation.png)

so `h = floor(lg n)`.  
This implicit representation of binary trees saves memory, but is less flexible than using pointers. We cannot store arbitrary tree topologies without wasting large amounts of space. We cannot move subtrees around by just changing a single pointer, only by explicitly moving each of the elements in the subtree. This loss of flexibility explains why we cannot use this idea to represent `binary search trees`, but it works just fine for `heaps`.

**Problem**: How can we efficiently search for a particular key in a heap?
**Solution**: We can’t. Binary search does not work because a `heap` is `not` a `binary search tree`. We know almost nothing about the relative order of the `n/2` leaf elements in a `heap`—certainly nothing that lets us avoid doing linear search through them.

#### <a name='constructing_heaps'></a> Constructing Heaps:

Heaps can be constructed incrementally, by inserting each new element into the `left-most` open spot in the array, namely the (n + 1)<sup>st</sup> position of a previously `n-element` heap. This ensures the desired balanced shape of the `heap-labeled` tree, but does not necessarily maintain the dominance ordering of the keys. The new key might be less than its parent in a `min-heap`, or greater than its parent in a `max-heap`.

The solution is to `swap` any such `dissatisfied` element with its `parent`. The old parent is now happy, because it is properly dominated. The other child of the old parent is still happy, because it is now dominated by an element even more extreme than its previous parent. The new element is now happier, but may still dominate its new parent. We now recur at a higher level, `bubbling up` the new key to its proper position in the hierarchy. Since we replace the root of a subtree by a larger one at each step, we preserve the heap order elsewhere.

```c
pq_insert(priority_queue *q, item_type x)
{
    if (q->n >= PQ_SIZE)
        printf("Warning: priority queue overflow insert x=%d\n",x);
    else {
        q->n = (q->n) + 1;
        q->q[ q->n ] = x;
        bubble_up(q, q->n);
    }
}

bubble_up(priority_queue *q, int p)
{
    if (pq_parent(p) == -1) return; /* at root of heap, no parent */
    if (q->q[pq_parent(p)] > q->q[p]) {
        pq_swap(q,p,pq_parent(p));
        bubble_up(q, pq_parent(p));
    }
}

```

This `swap` process takes `constant time` at each level. Since the height of an `n-element` heap is `lg n`, each insertion takes at most `O(log n)` time. Thus an initial heap of `n` elements can be constructed in `O(n log n)` time through `n` such insertions:

```c
pq_init(priority_queue *q)
{
    q->n = 0;
}

make_heap(priority_queue *q, item_type s[], int n)
{
    int i;     /* counter */
    pq_init(q);
    for (i=0; i<n; i++)
        pq_insert(q, s[i]);
}

```

#### <a name='extracting_minimum'></a> Extracting the Minimum:

The remaining priority queue operations are identifying and deleting the dominant element. Identification is easy, since the top of the heap sits in the first position of the array.  

Removing the top element leaves a hole in the array. This can be filled by moving the element from the `right-most` leaf (sitting in the `n`<sup>th</sup> position of the array) into the first position.

The shape of the tree has been restored but (as after insertion) the labeling of the root may no longer satisfy the heap property. Indeed, this new root may be dominated by both of its children. The root of this `min-heap` should be the `smallest` of three elements, namely the `current root` and its `two children`. If the `current root` is dominant, the heap order has been restored. If not, the dominant child should be swapped with the root and the problem pushed down to the next level.

This dissatisfied element `bubbles down` the heap until it dominates all its children, perhaps by becoming a leaf node and ceasing to have any. This `percolate-down` operation is also called **`heapify`**, because it merges two heaps (the subtrees below the original root) with a new key.

```c
item_type extract_min(priority_queue *q)
{
    int min = -1;   /* minimum value */
    if (q->n <= 0) printf("Warning: empty priority queue.\n");
    else {
        min = q->q[1];
        q->q[1] = q->q[ q->n ];
        q->n = q->n - 1;
        bubble_down(q,1);
    }
    return(min);
}

bubble_down(priority_queue *q, int p)
{
    int c;  /* child index */
    int i;  /* counter */
    int min_index;  /* index of lightest child */
    
    c = pq_young_child(p);
    min_index = p;
    
    for (i=0; i<=1; i++)
        if ((c+i) <= q->n) {
            if (q->q[min_index] > q->q[c+i]) min_index = c+i;
        }
        
    if (min_index != p) {
        pq_swap(q,p,min_index);
        bubble_down(q, min_index);
    }
}

```

We will reach a leaf after `floor(lg n)` bubble down steps, each constant time. Thus root deletion is completed in `O(log n)` time.

Exchanging the maximum element with the last element and calling `heapify` repeatedly gives an `O(n log n)` sorting algorithm, named `Heapsort`.

```c
heapsort(item_type s[], int n)
{
    int i;  /* counters */
    priority_queue q;   /* heap for heapsort */

    make_heap(&q,s,n);
    
    for (i=0; i<n; i++)
        s[i] = extract_min(&q);
}
```

`Heapsort` is a great sorting algorithm. It is simple to program; indeed, the complete implementation has been presented above. It runs in worst-case `O(n log n)` time, which is the best that can be expected from any sorting algorithm. It is an `in-place` sort, meaning it uses `no extra memory` over the array containing the elements to be sorted. Although other algorithms prove slightly faster in practice, you won’t go wrong using `heapsort` for sorting data that sits in the computer’s main memory.


#### <a name='faster_heap_construction'></a> Faster Heap Construction:

As we have seen, a heap can be constructed on `n` elements by incremental insertion in `O(n log n)` time. Surprisingly, heaps can be constructed even faster by using our `bubble down` procedure and some clever analysis.

Suppose we pack the `n` keys destined for our `heap` into the first `n` elements of our `priority-queue` array. The shape of our heap will be right, but the dominance order will be all messed up. How can we restore it?

Consider the array in `reverse order`, starting from the last (n<sup>th</sup>) position. It represents a leaf of the tree and so dominates its nonexistent children. The same is the case for the last `n/2` positions in the array, because all are leaves. If we continue to walk backwards through the array we will finally encounter an internal node with children. This element may not dominate its children, but its children represent well-formed (if small) heaps.

This is exactly the situation the `bubble down` procedure was designed to handle, restoring the heap order of arbitrary root element sitting on top of two `sub-heaps`. Thus we can create a heap by performing `n/2` non-trivial calls to the `bubble down` procedure:

Multiplying the number of calls to `bubble down` `(n)` times an upper bound on the cost of each operation `(O(log n))` gives us a running time analysis of `O(n log n)`. This would make it no faster than the `incremental insertion` algorithm described above.

But note that it is indeed an `upper bound`, because only the last insertion will actually take 	`lg n` steps. Recall that `bubble down` takes time proportional to the `height of the heaps` it is merging. Most of these heaps are extremely small. In a full binary tree on n nodes, there are n/2 nodes that are leaves (i.e. , height 0), n/4 nodes that are height 1, n/8 nodes that are height 2, and so on. In general, there are at most `ceil`(n/2<sup>h+1</sup>) nodes of height `h`, so the cost of building a heap is:

![heap_building_cost](../images/heap_building_cost.png)

Since this sum is not quite a `geometric series`, we can’t apply the usual identity to get the sum, but rest assured that the puny contribution of the numerator (h) is crushed by the denominator (2<sup>h</sup>). The series quickly `converges` to `linear`.

Does it matter that we can construct heaps in `linear time` instead of `O(n log n)`? Usually not. The construction time did not dominate the complexity of `heapsort`, so improving the construction time does not improve its worst-case performance. Still, it is an impressive display of the power of careful analysis, and the free lunch that `geometric series` convergence can sometimes provide.

[Table of contents](#table_of_contents)

### <a name='sorting_by_incremental_insertion'></a> Sorting by Incremental Insertion

Insertion sort:

```c
InsertionSort(A)
    A[0] = −∞
    for i = 2 to n do
        j = i
        while (A[j] < A[j − 1]) do
            swap(A[j], A[j − 1])
            j = j − 1
```

Although `insertion sort` takes O(n<sup>2</sup>) in the worst case, it 
performs considerably better if the data is `almost sorted`, since `few 
iterations` of the `inner loop` suffice to sift it into the proper 
position.

`Insertion sort` is perhaps the simplest example of the `incremental insertion` 
technique, where we build up a `complicated structure` on `n items` by 
first building it on `n−1 items` and then making the necessary changes to 
add the `last item`. `Incremental insertion` proves a particularly useful 
technique in `geometric algorithms`.


### <a name='merge_sort'></a> MergeSort: Sorting by Divide-and-Conquer

`Recursive algorithms` reduce `large problems` into `smaller ones`. A 
`recursive approach` to `sorting` involves `partitioning` the elements 
into `two groups`, `sorting` each of the `smaller problems` `recursively`, 
and then `interleaving` the `two sorted lists` to totally `order` the 
elements. This algorithm is called `mergesort`, recognizing the importance
of the `interleaving operation`:

```c
Mergesort(A[1, n])
    Merge( MergeSort(A[1, n/2]), MergeSort(A[n/2 + 1, n]) )
```

The `basis case` of the `recursion` occurs when the sub-array to be sorted 
consists of a `single element`, so `no rearrangement` is possible.

The efficiency of `mergesort` depends upon how efficiently we combine the 
`two sorted halves` into a `single sorted list`. We could concatenate them 
into `one list` and call `heapsort` or some other `sorting algorithm` to do 
it, but that would just `destroy` all the work spent `sorting` our component
lists.

What is the total running time of `mergesort`? It helps to think about how 
much work is done at each level of the execution tree. If we assume for 
simplicity that `n` is a `power of two`, the `kth level` consists of all 
the 2<sup>k</sup> calls to `mergesort` processing sub-ranges of n/2<sup>k</sup> 
elements.

The work done on the `(k = 0)th` level involves merging `two sorted lists`, 
each of size `n/2`, for a total of at most `n − 1` comparisons. The work 
done on the `(k = 1)th` level involves `merging` `two pairs of sorted lists`, 
each of size `n/4`, for a total of at most `n−2` comparisons. In general, 
the work done on the `kth` level involves merging 2<sup>k</sup> pairs 
`sorted list`, each of size n/2<sup>k+1</sup> , for a total of at 
most n − 2<sup>k</sup> comparisons.

`Linear work` is done merging all the elements on each level. Each of 
the `n` elements appears in exactly one sub-problem on each level. 
The most expensive case (in terms of comparsions) is actually the 
top level.

The number of elements in a sub-problem gets `halved` at `each level`. 
Thus the number of times we can `halve` `n` until we get to `1` is 
**Math.ceil(lg<sub>2</sub> n)**.

Because the recursion goes `lg n` levels deep, and a `linear amount` of 
work is done per level, `mergesort` takes `O(n log n)` time in the 
worst case.
- `Mergesort` is a great algorithm for `sorting linked lists`, because 
  it does not rely on `random access` to elements as does `heapsort` or 
  `quicksort`.
  
- Its primary disadvantage is the need for an `auxilliary buffer` when 
  sorting arrays. It is easy to merge `two sorted linked lists` without 
  using any `extra space`, by just `rearranging the pointers`.
  
```c
mergesort(item_type s[], int low, int high)
{
    int i;                  /* counter */
    int middle;             /* index of middle element */
    if (low < high) {
        middle = (low+high)/2;
        mergesort(s,low,middle);
        mergesort(s,middle+1,high);
        merge(s, low, middle, high);
    }
}
```

```c
merge(item_type s[], int low, int middle, int high)
{
    int i;              /* counter */
    queue buffer1, buffer2; /* buffers to hold elements for merging */
    init_queue(&buffer1);
    init_queue(&buffer2);
    for (i=low; i<=middle; i++) enqueue(&buffer1,s[i]);
    for (i=middle+1; i<=high; i++) enqueue(&buffer2,s[i]);
    i = low;
    while (!(empty_queue(&buffer1) || empty_queue(&buffer2))) {
        if (headq(&buffer1) <= headq(&buffer2))
            s[i++] = dequeue(&buffer1);
        else
            s[i++] = dequeue(&buffer2);
    }
    while (!empty_queue(&buffer1)) s[i++] = dequeue(&buffer1);
    while (!empty_queue(&buffer2)) s[i++] = dequeue(&buffer2);
}
```

[Table of contents](#table_of_contents)


### <a name='quick_sort'></a> QuickSort: Sorting by Randomization

Suppose we select a `random item` `p` from the `n items` we seek to sort. 
`Quicksort` separates the `n − 1` other items into `two piles`: 
- a `low pile` containing all the elements that appear `before p` in sorted 
  order and 
- a `high pile` containing all the elements that appear `after p` in sorted 
  order. 

`Low` and `high` denote the `array positions` we place the respective piles, 
leaving a `single slot` between them for `p`.

Such `partitioning` buys us `two things`. 
- First, the `pivot element p` ends up in the `exact array position` it will 
  reside in the the `final sorted order`. 
- Second, `after partitioning` no element `flops` to the `other side` in the 
  `final sorted order`. 

Thus `we can now sort the elements to the left and the right of the pivot 
independently`! This gives us a `recursive sorting algorithm`, since we can 
use the `partitioning approach` to `sort` each `sub-problem`. The algorithm 
must be correct since each element ultimately ends up in the `proper 
position`:

```c
quicksort(item_type s[], int l, int h)
{
    int p;              /* index of partition */
    if ((h-l)>0) {
        p = partition(s,l,h);
        quicksort(s,l,p-1);
        quicksort(s,p+1,h);
    }
}
```
```c
int partition(item_type s[], int l, int h)
{
    int i;              /* counter */
    int p;              /* pivot element index */
    int firsthigh;      /* divider position for pivot element */
    
    p = h;
    firsthigh = l;
    for (i=l; i<h; i++)
        if (s[i] < s[p]) {
            swap(&s[i],&s[firsthigh]);
            firsthigh ++;
        }
    
    swap(&s[p],&s[firsthigh]);
    
    return(firsthigh);
}
```

Since the `partitioning step` consists of at most `n swaps`, it takes 
`linear time` in the `number of keys`. But how long does the entire 
`quicksort` take? As with `mergesort`, `quicksort` builds a `recursion 
tree` of `nested sub-ranges` of the `n-element array`. As with `mergesort`, 
`quicksort` spends `linear time` processing (now `partitioning` instead of
`mergeing`) the elements in each sub-array on each level. As with 
`mergesort`, `quicksort` runs in `O(n · h)` time, where `h` is the height 
of the `recursion tree`.

The difficulty is that the `height of the tree` depends upon where the 
`pivot element` ends up in `each partition`. If we get very lucky and 
happen to repeatedly pick the `median element` as our `pivot`, the 
`sub-problems` are always `half the size` of the `previous level`. The 
`height` represents the `number of times` we can `halve` `n` until we 
get down to `1`, or at most **Math.ceil(lg<sub>2</sub> n)**.

Now suppose we consistently get `unlucky`, and our `pivot element` always 
`splits` the `array` as `unequally` as possible. This implies that the 
`pivot element` is always the `biggest` or `smallest` element in the 
`sub-array`. After this `pivot` settles into its `position`, we are left 
with one `sub-problem of size n − 1`. We spent `linear work` and reduced 
the size of our problem by `one measly element`. It takes a tree of height 
`n − 1` to chop our array down to `one element per level`, for a worst 
case time of Θ(n<sup>2</sup>).

Thus, the worst case for `quicksort` is `worse` than `heapsort` or `mergesort`. 
To justify its name, `quicksort` had better be good in the `average case`. 
Understanding why requires some intuition about `random sampling`.

[Table of contents](#table_of_contents)

#### <a name='expected_case_for_quick_sort'></a> Intuition: The Expected Case for QuickSort

The `expected performance` of `quicksort` depends upon the `height of the 
partition tree` constructed by `random pivot elements` at each step. 
`Mergesort` ran in `O(n log n)` time because we split the keys into two 
equal halves, sorted them recursively, and then merged the halves in 
`linear time`. Thus, whenever our `pivot element` is `near` the `center` 
of the `sorted array` (i.e. , the `pivot` is close to the `median element`), 
we get a `good split` and `realize the same performance as mergesort`.

I will give an intuitive explanation of why `quicksort` is `O(n log n)` in 
the `average case`. How likely is it that a `randomly selected pivot` is a 
good one? The best possible selection for the `pivot` would be the `median 
key`, because `exactly half of elements` would end up `left`, and `half 
the elements` right, of the `pivot`. Unfortunately, we only have a 
`probability` of `1/n` of `randomly selecting the median as pivot`, which 
is quite small.

Suppose a `key` is a `good enough pivot` if it lies is in the `center half` 
of the `sorted space` of keys—i.e. , those ranked from `n/4` to `3n/4` in 
the `space of all keys` to be sorted. Such good enough `pivot elements` are 
quite plentiful, since `half the elements` lie closer to the `middle` 
than one of the two ends. Thus, on `each selection` we will pick a 
`good enough pivot` with `probability of 1/2`.

Can you `flip a coin` so it comes up `tails each time`? `Not without cheating`. 
If you flip a `fair coin` `n times`, it will come out `heads` about `half 
the time`. Let `heads denote` the chance of `picking a good enough pivot`.

The `worst possible good enough pivot` leaves the `bigger half` of the 
`space partition` with `3n/4 items`. What is the height h<sub>g</sub> of a 
`quicksort partition tree` constructed repeatedly from the `worst-possible` 
`good enough pivot`? The deepest path through this tree passes through 
partitions of size n, (3/4)n, (3/4)<sup>2</sup> n, . . ., down to 1. How
many times can we multiply `n` by `3/4` until it gets down to `1`?

(3/4)<sup>h<sub>g</sub></sup> n = 1 ⇒ n = (4/3)<sup>h<sub>g</sub></sup>

so h<sub>g</sub> = log<sub>4/3</sub> n.

But only `half of all randomly selected pivots` will be `good enough`. The 
rest we classify as `bad`.

The worst of these `bad pivots` will do essentially `nothing` to `reduce
the partition size` along the `deepest path`. The `deepest path` from the 
`root` through a typical `randomly-constructed` `quicksort partition tree` 
will pass through roughly `equal numbers` of `good-enough` and `bad pivots`. 
Since the expected number of `good splits` and `bad splits` is the `same`, 
the `bad splits` can only `double the height of the tree`, so 
h ≈ 2h<sub>g</sub> = 2 log<sub>4/3</sub> n, which is clearly `Θ(log n)`.

On average, `random quicksort partition trees` (and by analogy, `binary search
trees` under `random insertion`) are `very good`. More careful analysis shows 
the `average height` after `n insertions` is approximately `2 ln n`. Since 

>2 ln n ≈ 1.386 lg<sub>2</sub> n

this is only `39%` taller than a `perfectly balanced binary tree`. Since 
`quicksort` does `O(n)` work `partitioning on each level`, the average 
time is `O(n log n)`. If we are `extremely unlucky` and our randomly 
selected elements always are among the `largest` or `smallest` element 
in the array, `quicksort` turns into `selection sort` and runs in 
O(n<sup>2</sup> ). However, the odds against this are `vanishingly small`.

[Table of contents](#table_of_contents)

#### <a name='randomized_algorithm'></a> Randomized Algorithms

There is an important subtlety about the expected case `O(n log n)` running 
time for `quicksort`. Our `quicksort` implementation above selected the 
`last element` in each sub-array as `the pivot`. Suppose this program were 
given a `sorted array` as input. If so, at each step it would pick the 
`worst possible pivot` and run in `quadratic time`.

For any `deterministic method` of `pivot selection`, there exists a 
`worst-case` input instance which will `doom` us to `quadratic time`. 
The analysis presented above made no claim stronger than:
> “QuickSort runs in Θ(n log n) time, with high probability, if you give
  me randomly ordered data to sort.”
  
But now suppose we add an `initial step` to our algorithm where we 
`randomly permute` the order of the `n elements` before we try to 
`sort them`. Such a `permutation` can be constructed in `O(n)` time. 
This might `seem like wasted effort`, but it provides the `guarantee` 
that `we can expect Θ(n log n) running time` whatever the initial input 
was. The `worst case` performance `still can happen`, but it depends only 
upon how `unlucky we are`. There is no longer a `well-defined` 
“worst case” input. We now can say
> “Randomized quicksort runs in Θ(n log n) time on any input, with high
  probability.”

Alternately, we could get the `same guarantee` by `selecting a random 
element` to be the `pivot at each step`.

`Randomization` is a powerful tool to `improve algorithms` with `bad 
worst-case` but `good average-case` complexity. It can be used to make 
`algorithms` more `robust to boundary cases` and `more efficient` on 
highly structured input instances that confound `heuristic decisions` 
(such as `sorted input to quicksort`). It often lends itself to simple 
algorithms that provide `randomized performance guarantees` which
are otherwise obtainable only using `complicated deterministic algorithms`.

Some of the approaches to designing efficient randomized algorithms 
are readily explainable:

- `Random sampling` – Want to get an idea of the `median value` of `n things` 
   but don’t have either the `time or space` to look at them all? Select a 
   `small random sample` of the `input` and `study those`, for the results 
   should be representative.
   - This is the idea behind `opinion polling`. Biases creep in unless you 
   take a truly `random sample`, as `opposed` to the `first x` people you 
   happen to see. To `avoid bias`, actual `polling agencies` typically dial 
   `random phone numbers` and hope `someone answers`.

- `Randomized hashing` – We have claimed that `hashing` can be used to 
   implement dictionary operations in `O(1)` “expected-time.” However, 
   for any `hash function` there is a `given worst-case set of keys` 
   that `all get hashed to the same bucket`. But now suppose we `randomly 
   select our hash function` from a large family of `good ones` as the 
   `first step` of our algorithm. We get the same type of `improved 
   guarantee` that we did with `randomized quicksort`.
   
- `Randomized search` – Randomization can also be used to drive `search 
   techniques` such as `simulated annealing`

**Note**:
> QuickSort is 2-3 times faster than merge sort or heap sort if the
QuickSort is implemented well.

[Table of contents](#table_of_contents)

### <a name='distribution_sort'></a> Distribution Sort: Sorting via Bucketing

We could sort sorting names for the telephone book by partitioning them 
according to the `first letter` of the `last name`. This will create `26 
different piles`, or `buckets`, of names. Observe that any name in the `J` 
pile `must occur` after `every name in the I pile`, but before any name 
in the `K pile`. Therefore, we can proceed to sort each pile individually 
and just `concatenate the bunch of sorted piles` together at the end.

If the `names are distributed evenly` among the `buckets`, the resulting 
`26 sorting problems` should each be `substantially smaller` than the 
`original problem`. Further, by now `partitioning each pile` based on the 
`second letter` of `each name`, we generate smaller and smaller piles. 
The `names will be sorted` as soon as `each bucket contains` only a `single 
name`. The resulting algorithm is commonly called `bucketsort` or
`distribution sort`.

`Bucketing` is a very effective idea whenever we are confident that the 
`distribution of data` will be `roughly uniform`. It is the idea that 
underlies `hash tables`, `kd-trees`, and a variety of other `practical 
data` structures. The `downside` of such techniques is that the `performance` 
can be `terrible` when the `data distribution` is not `what we expected`. 
Although data structures such as `balanced binary trees` offer `guaranteed`
`worst-case behavior` for `any input distribution`, `no such promise` 
exists for `heuristic data structures` on `unexpected input distributions`.

`Nonuniform distributions` do occur in `real life`. Consider Americans with 
the uncommon last name of `Shifflett`. When last I looked, the Manhattan 
telephone directory (with over one million names) contained exactly `five 
Shiffletts`. So how many `Shiffletts` should there be in a small city of 
50,000 people? The `Shifflett` clan is a fixture of the region, but it 
would `play havoc` with any `distribution sort program`, as refining 
buckets from `S to Sh to Shi to Shif to . . . to Shifflett` results in 
`no significant partitioning`.

[Table of contents](#table_of_contents)


### <a name='binary_search_and_related_algorithms'></a> Binary Search and Related Algorithms

`Binary search` is a `fast algorithm` for `searching in a sorted array` of 
keys `S`. To search for `key q`, we compare `q` to the middle key `S[n/2]`. 
If `q` appears before `S[n/2]`, it must reside in the `top half of S`; if 
not, it must `reside in the bottom half of S`. By repeating this process 
recursively on the correct half, we locate the key in a total of 
`Math.ceil(lg n)` comparisons—a big win over the `n/2` comparisons 
expect using `sequential search`:

```c
int binary_search(item_type s[], item_type key, int low, int high)
{
    int middle;                     /* index of middle element */
    if (low > high) return (-1);
    middle = (low+high)/2;
    if (s[middle] == key) return(middle);
    if (s[middle] > key)
        return( binary_search(s,key,low,middle-1) );
    else
        return(binary_search(s,key,middle+1,high) );
}
```

This much we probably know. What is important is to have a sense of just
how fast binary search is. `Twenty questions` is a popular children’s 
game where `one player selects a word` and the other repeatedly asks 
`true/false` questions in an attempt to guess it. If the word remains 
unidentified after `20 questions`, the `first party wins`; otherwise, 
the `second player takes the honors`. In fact, the `second player always 
has a winning strategy`, based on `binary search`. Given a printed 
dictionary, the player opens it in the middle, selects a word (say “move”),
and asks whether the unknown word is before “move” in alphabetical order. 
Since standard dictionaries contain 50,000 to 200,000 words, we can be 
certain that the process will terminate `within twenty questions`.

[Table of contents](#table_of_contents)

### <a name='counting_occurrences'></a> Counting Occurrences

Several `interesting algorithms` follow from `simple variants` of 
`binary search`. Suppose that `we want to count` the `number of times` 
a given `key k` (say "John") occurs in a given `sorted array`. 
Because `sorting` groups `all the copies of k` into a `contiguous
block`, the problem reduces to finding the `right block` and then 
measures `its size`.

The `binary search` routine presented above enables us to find the index 
of `an element` of the `correct block` (x) in `O(lg n)` time. The natural 
way to identify the boundaries of the block is to `sequentially test` 
elements to the `left of x` until we find the first one that differs from 
the search key, and then repeat this search to the `right of x`. 
The difference between the indices of the left and right boundaries
(plus one) gives the count of the number of occurrences of `k`.

This algorithm runs in `O(lg n + s)`, where `s` is the `number of 
occurrences` of the `key`. This can be `as bad as linear` if the `entire 
array` consists of `identical keys`. A `faster algorithm` results by 
`modifying binary search` to `search for the boundary` of the block 
`containing k`, instead of `k itself`. Suppose we delete the equality 
test
> if (s[middle] == key) return(middle);

from the implementation above and return the `index low` instead of `−1` 
on each `unsuccessful search`.
`All searches` will now be `unsuccessful`, since there is `no equality
test`. The `search` will `proceed to the right half` whenever the key is 
compared to `an identical array element`, eventually terminating at the 
`right boundary`.
`Repeating the search` after `reversing the direction` of the `binary 
comparison` will lead us to the `left boundary`.
Each search takes `O(lg n)` time, so we can `count the occurrences` in
`logarithmic time` `regardless of the size` of the block.

**Note**: This method is tested but why this is working is not logical
enough.


[Table of contents](#table_of_contents)

### <a name='one_sided_binary_search'></a> One-Sided Binary Search

Now suppose we have an `array A` consisting of a `run of 0’s`, followed 
by `an unbounded run of 1’s`, and would like to `identify the exact point` 
of `transition` between them. `Binary search` on the array would provide 
the `transition point` in `Math.ceil(lg n)` tests, if we had a `bound n` 
on the `number of elements` in the array. In the `absence` of such a bound, 
we can `test repeatedly` at `larger intervals` `(A[1], A[2], A[4], A[8], 
A[16],. . .)` until we find a `first nonzero value`. Now we have a `window 
containing the target` and can `proceed with binary search`. This 
`one-sided binary search` finds the `transition point p` using at most 
`2 Math.ceil(lg p)` comparisons, `regardless` of `how large` the array 
actually is. `One-sided binary search` is most useful whenever we are 
looking for `a key that lies close to our current position`.

### <a name='square_and_other_roots'></a> Square and Other Roots

The `square root` of `n` is the number `r` such that r<sup>2</sup> = n. 
`Square root` computations are performed inside every pocket calculator, 
but it is instructive to develop an efficient algorithm to compute them.

First, observe that the `square root of n ≥ 1` must be `at least 1` and 
`at most n`. Let `l = 1` and `r = n`. Consider the `midpoint` of this 
interval, `m = (l + r)/2`. How does **m<sup>2</sup>** compare to `n`? 
If **n ≥ m<sup>2</sup>** , then the `square root` must be `greater than m`, 
so the algorithm repeats with `l = m`. If **n < m<sup>2</sup>** , then the 
`square root must be less than m`, so the algorithm repeats with `r = m`. 
Either way, we have halved the interval using only one comparison. 
Therefore, after `lg n` rounds we will have identified the square root 
to `within ±1`.

This `bisection method`, as it is called in `numerical analysis`, can also 
be applied to the `more general` problem of `finding the roots of an 
equation`. We say that `x` is a `root of the function f` if `f (x) = 0`. 
Suppose that we start with values `l and r` such that `f (l) > 0` and 
`f (r) < 0`. If `f` is a `continuous function`, there `must exist` a `root`
`between l and r`. Depending upon the `sign of f (m)`, where 
`m = (l + r)/2`, we can cut this window containing the root in `half` 
with each test and stop soon as our estimate becomes 
`sufficiently accurate`.

`Root-finding` algorithms that `converge faster` than `binary search` are 
`known for both of these problems`. Instead of always testing the midpoint 
of the interval, these `algorithms interpolate to find a test point` 
closer to the `actual root`. Still, `binary search` is `simple`, `robust`, 
and works as well as possible without additional information on the 
nature of the function to be computed.

[Table of contents](#table_of_contents)

### <a name='divide_and_conquer'></a> Divide-and-Conquer

One of the `most powerful techniques` for solving problems is to `break 
them down into smaller`, more `easily solved pieces`. `Smaller problems` 
are `less overwhelming`, and they `permit us to focus on details` that are 
lost when we are studying the `entire problem`. A `recursive algorithm` 
starts to `become apparent` when we can `break the problem` into 
`smaller instances` of the `same type of problem`. Effective `parallel
processing` requires decomposing jobs into at least as many tasks as 
processors, and is becoming more important with the advent of 
cluster computing and multi-core processors.

Two `important algorithm design paradigms` are based on `breaking problems
down into smaller problems`. We will see `dynamic programming`,
which typically 
- removes one element from the problem, 
- solves the smaller problem, 
- and then uses the solution to this smaller problem to add back the 
  element in the proper way. 

`Divide-and-conquer` instead 
- splits the problem in `(say) halves`, 
- solves each half, 
- then stitches the pieces back together to form a full solution.

To use `divide-and-conquer` as an algorithm design technique, we must 
- divide the problem into two smaller sub-problems, 
- solve each of them recursively, 
- and then meld the two partial solutions into one solution to the full problem. 

`Whenever the merging takes less time than solving the two sub-problems`, 
we get an `efficient algorithm`. `MergeSort`, is the classic example of
a `divide-and-conquer` algorithm. It takes only `linear time` to `merge 
two sorted lists of n/2 elements`, each of which was obtained in 
`O(n lg n)` time.

`Divide-and-conquer` is a design technique with many `important algorithms` 
to its credit, including `mergesort`, `the fast Fourier transform`, 
and `Strassen’s matrix multiplication` algorithm. Beyond `binary search` 
and `its many variants`, however, We may find it to be a `difficult design 
technique to apply in practice`. Our `ability to analyze` 
`divide-and-conquer` algorithms `rests on our strength` to `solve the 
asymptotics of recurrence relations` `governing the cost of such` 
`recursive algorithms`.

[Table of contents](#table_of_contents)


### <a name='recurrence_relations'></a> Recurrence Relations

Many `divide-and-conquer` algorithms have time complexities that are 
naturally modeled by `recurrence relations`. Evaluating such recurrences 
is important to understanding when `divide-and-conquer` `algorithms` 
`perform well`, and provide an `important tool` for `analysis in general`. 
The reader who balks at the very idea of analysis is free to skip this 
section, but there are `important insights` into `design` that come from 
an `understanding of the behavior` of `recurrence relations`.

What is a `recurrence relation`? It is an `equation that is defined in 
terms of itself`. `The Fibonacci numbers` are described by the recurrence 
relation F<sub>n</sub> = F<sub>n−1</sub> + F<sub>n−2</sub>. Many other 
natural functions are `easily expressed as recurrences`. `Any polynomial` 
can be `represented by a recurrence`, such as the `linear function`:

> a<sub>n</sub> = a<sub>n−1</sub> + 1, a<sub>1</sub> = 1 => a<sub>n</sub> = n

Any exponential can be represented by a recurrence:
> a<sub>n</sub> = 2a<sub>n−1</sub> , a<sub>1</sub> = 1 => a<sub>n</sub> = 2<sup>n−1</sup>

Finally, lots of `weird functions` that `cannot be described easily` 
with `conventional notation` can be represented by a `recurrence`:

> a<sub>n</sub> = na<sub>n−1</sub> , a<sub>1</sub> = 1 => a<sub>n</sub> = n!

This means that `recurrence relations` are a `very versatile` way to 
`represent functions`.

The `self-reference` property of `recurrence relations` is shared with 
`recursive programs` or `algorithms`, as the `shared roots of both 
terms reflect`. Essentially, `recurrence relations` provide a way to 
analyze `recursive structures`, such as `algorithms`.


[Table of contents](#table_of_contents)

### <a name='divide_and_conquer_recurrences'></a> Divide-and-Conquer Recurrences

`Divide-and-conquer` algorithms tend to `break a given problem` into 
`some number of smaller pieces (say a)`, each of which is of `size n/b`. 
Further, they spend `f(n) time` to combine these sub-problem solutions 
into a `complete result`. Let `T(n)` denote the worst-case time the 
algorithm takes to solve a problem of `size n`. Then `T(n)` is given by 
the following `recurrence relation`:
> T(n) = a T(n/b) + f(n)

Consider the following examples:
- `Sorting` – The running time behavior of `mergesort` is governed by the 
  recurrence `T(n) = 2T(n/2) + O(n)`, since the algorithm divides the data 
  into `equal-sized` halves and then spends `linear time` `merging the 
  halves` after they are `sorted`. In fact, this `recurrence` evaluates 
  to `T(n) = O(n lg n)`, just as we got by our previous analysis.

- `Binary Search` – The running time behavior of `binary search` is 
  governed by the recurrence `T(n) = T(n/2) + O(1)`, since at each step 
  we spend `constant time` to reduce the problem to an instance half its 
  size. In fact, this recurrence evaluates to `T(n) = O(lg n)`, just as 
  we got by our previous analysis.
  
- `Fast Heap Construction` – The `bubble down` method of `heap construction`
  built an `n-element` heap by constructing two `n/2 element` heaps and 
  then `merging` them with the `root` in `logarithmic time`. This argument 
  reduces to the `recurrence relation` `T(n) = 2T(n/2) + O(lg n)`. In
  fact, this recurrence evaluates to `T(n) = O(n)`, just as we got by our 
  previous analysis.
  
- `Matrix Multiplication` – The standard `matrix multiplication` algorithm 
  for two `n × n` matrices takes **O(n<sup>3</sup>)**, because we
  compute the `dot product of n` terms for each of the **n<sup>2</sup>** 
  elements in the product matrix.  
  However, `Strassen` discovered a `divide-and-conquer` algorithm that
  manipulates the products of `seven n/2 × n/2` matrix products to yield 
  the product of `two n × n matrices`. This yields a time-complexity 
  recurrence **T(n) = 7T(n/2) + O(n<sup>2</sup>)**. In fact, this 
  recurrence evaluates to **T(n) = O(n<sup>2.81</sup>)**, which seems 
  impossible to predict without solving the recurrence.
  
[Table of contents](#table_of_contents)

### <a name='solving_divide_and_conquer_recurrences'></a> Solving Divide-and-Conquer Recurrences

In fact, `divide-and-conquer` recurrences of the form `T(n) = aT(n/b) + f(n)` 
are generally `easy to solve`, because the solutions typically fall into 
one of `three distinct cases`:

1. If f(n) = O(n<sup>log<sub>b</sub> a−e</sup> ) for some constant e > 0, then **T(n) = Θ(n<sup>log<sub>b</sub> a</sup>)**.
2. If f(n) = Θ(n<sup>log<sub>b</sub> a</sup> ), then **T(n) = Θ(n<sup>log<sub>b</sub> a</sup> lg n)**.
3. If f(n) = Ω(n<sup>log<sub>b</sub> a+e</sup> ) for some constant e > 0, and if 
   `af(n/b) ≤ cf(n)` for some c < 1, then `T(n) = Θ(f(n))`.
   
Although this looks somewhat frightening, it really isn’t difficult to 
apply. The issue is `identifying` which case of the so-called `master 
theorem` holds for your given recurrence.

- `Case 1` holds for `heap construction` and `matrix multiplication`, while
- `Case 2` holds `mergesort` and `binary search`. 
- `Case 3` generally arises for clumsier algorithms, where the cost of 
  combining the sub-problems dominates everything.
  
The `master theorem` can be thought of as a `black-box` piece of machinery, 
invoked as needed and left with its mystery intact. However, with a little 
study, the reason why the master theorem works can become apparent.

Below Figure shows the recursion tree associated with a typical 
`T(n) = aT(n/b) + f(n)` `divide-and-conquer` algorithm. `Each problem` of 
`size n` is `decomposed` into a `problems of size n/b`. `Each sub-problem` 
of `size k` takes `O(f(k))` time to deal with `internally`, `between 
partitioning` and `merging`. The total time for the algorithm is the `sum` 
of `these internal costs`, `plus the overhead of building the recursion 
tree`. The `height of this tree` is **h = log<sub>b</sub>n** and the 
number of leaf nodes **a<sup>h</sup> = a<sup>log<sub>b</sub>n</sup>** ,
which happens to simplify to **n<sup>log<sub>b</sub>a</sup>** with some 
algebraic manipulation.

The `three cases` of the `master theorem` correspond to `three different 
costs` which might be `dominant` as a function of `a, b, and f(n)`:
- `Case 1`: `Too many leaves` – If the number of `leaf nodes` outweighs 
  the `sum of the internal evaluation cost`, the total running time is 
  **O(n<sup>log<sub>b</sub>a</sup>)**.  
  **Note**: It means no of children will be more than the size in which
  they got divided. (ex: 4 children of size = n/2)

- `Case 2: Equal work per level` – As we `move down the tree`, each problem
  gets `smaller` but there are `more of them to solve`. If the `sum of the 
  internal evaluation costs` at `each level` are `equal`, the `total 
  running time` is the `cost per level` **(n<sup>log<sub>b</sub> a</sup>)** 
  times the number of levels **(log<sub>b</sub> n)**, for a total 
  running time of **O(n<sup>log<sub>b</sub>a</sup> lg n)**.
  **Note**: When the number of children and their size are equal. 
  (ex: children = 2 and size = n/2, binary-search)
  
- `Case 3: Too expensive a root` – If the `internal evaluation costs` grow 
  `rapidly enough with n`, then the `cost of the root evaluation` may 
   `dominate`. If so, the the `total running time` is `O(f(n))`.

![master_theorem](../images/master_theorem.jpg)


[Table of contents](#table_of_contents)

### <a name='graph_traversal'></a> Graph Traversal

Graphs are one of the unifying themes of computer science—an `abstract 
representation` that describes `the organization of transportation systems`, 
`human interactions`, and `telecommunication networks`. That so many 
different structures can be modeled using a single formalism is a source 
of great power to the educated programmer.

More precisely, a graph `G = (V, E)` consists of `a set of vertices V` 
together with `a set E of vertex pairs or edges`. Graphs are important 
because they can be used to represent essentially any relationship. 
For example, graphs can model `a network of roads`, with `cities as 
vertices` and `roads between cities as edges`. `Electronic circuits` can 
also be `modeled as graphs`, with `junctions as vertices` and `components 
as edges`.

The key to solving many algorithmic problems is to think of them in terms
of `graphs`. `Graph theory` provides a `language` for talking about the 
properties of relationships, and it is amazing how often `messy applied 
problems` have a `simple description` and `solution` in terms of 
classical `graph properties`.

`Designing truly novel graph algorithms is a very difficult task`. The key 
to using `graph algorithms effectively` in applications lies in `correctly 
modeling` your `problem` so you can take `advantage of existing algorithms`. 
Becoming familiar with many different algorithmic graph problems is `more 
important` than understanding the details of particular `graph algorithms`.

[Table of contents](#table_of_contents)

### <a name='flavors_of_graph'></a> Flavors of Graphs

A graph `G = (V, E)` is defined on `a set of vertices V` , and contains 
`a set of edges E` of `ordered or unordered pairs` of vertices from `V` . 
In modeling a `road network`, the `vertices` may `represent the cities 
or junctions`, certain pairs of which are `connected by roads/edges`. 
In analyzing the `source code` of a `computer program`, the `vertices`
may `represent lines of code`, with an `edge connecting lines x and y` 
if `y is the next statement executed after x`. In analyzing human 
interactions, the `vertices` typically represent `people`, with 
`edges connecting pairs of related souls`.

`Several fundamental properties of graphs` `impact the choice` of the 
data structures used to `represent them` and `algorithms available` to 
analyze them. The `first step` in any `graph problem` is determining 
the `flavors of graphs` you are dealing with:
- `Undirected` vs. `Directed` – A graph `G = (V, E)` is `undirected` 
  `if edge (x, y) ∈ E` `implies that (y, x)` is also in `E`. If not, we say that the graph is directed. Road
  networks between cities are typically undirected, since any large road has
  lanes going in both directions. Street networks within cities are almost always
  directed, because there are at least a few one-way streets lurking somewhere.
  Program-flow graphs are typically directed, because the execution flows from
  one line into the next and changes direction only at branches. Most graphs
  of `graph-theoretic` interest are `undirected`.

- `Weighted` vs. `Unweighted` – Each `edge` (or `vertex`) in a `weighted 
  graph` `G` is assigned a `numerical value`, or `weight`. The edges of a 
  road network graph might be weighted with their `length, drive-time, or 
  speed limit`, depending upon the application. 
  In `unweighted graphs`, there is `no cost distinction` between various
  `edges` and `vertices`.
  The difference between `weighted and unweighted` graphs becomes 
  particularly apparent in finding the `shortest path` between two 
  vertices. For `unweighted graphs`, the shortest path must have the 
  `fewest number of edges`, and can be found using a `breadth-first 
  search` as discussed in this chapter. `Shortest paths` in `weighted 
  graphs` requires more `sophisticated algorithms`.
  
- `Simple` vs. `Non-simple` – Certain types of `edges` `complicate` 
  the `task of working with graphs`. A `self-loop` is an `edge (x, x)` 
  involving only `one vertex`. An `edge(x, y)` is a `multi-edge` if it 
  occurs `more than once` in the graph.
  `Both of these structures` require `special care` in `implementing 
  graph algorithms`. Hence `any graph` that avoids them is called 
  `simple`.
  
- `Sparse` vs. `Dense`: Graphs are `sparse` when only a `small fraction` 
  of the `possible vertex pairs` ( <sub>n</sub>C<sub>2</sub> for a simple, 
  `undirected graph` on `n vertices`) actually have `edges` defined 
  between them. Graphs where a `large fraction` of the `vertex pairs`
  define `edges` are called `dense`. There is no official boundary between 
  what is called `sparse` and what is called `dense`, but typically 
  `dense graphs` have a `quadratic number of edges`, while sparse graphs 
  are `linear in size`.
  
  `Sparse graphs` are usually `sparse` for `application-specific` reasons. 
  Road networks must be `sparse graphs` because of `road junctions`. The 
  most ghastly intersection I’ve ever heard of was the endpoint of only 
  `seven different roads`. Junctions of `electrical components` are 
  similarly limited to the number of wires that can meet at a point, 
  perhaps except for power and ground.

- `Cyclic` vs. `Acyclic` – An `acyclic graph` does not contain any `cycles`. 
  Trees are `connected`, `acyclic undirected graphs`. Trees are the simplest 
  interesting graphs, and are inherently `recursive structures` because 
  `cutting any edge` leaves two smaller trees.
  
  `Directed acyclic graphs` are called `DAGs`. They arise `naturally` in 
  `scheduling problems`, where a `directed edge (x, y)` indicates that 
  `activity x` must occur `before y`. An operation called `topological 
  sorting` orders the `vertices` of a `DAG` to respect these `precedence 
  constraints`. `Topological sorting` is `typically` the `first step` 
  of `any algorithm` on a `DAG`.
  
- `Embedded` vs. `Topological` – A graph is `embedded` if the `vertices 
  and edges` are `assigned geometric positions`. Thus, any `drawing` of a 
  graph is an `embedding`, which may or may not have `algorithmic 
  significance`.
  
  Occasionally, the `structure` of a graph is completely defined by the 
  `geometry of its embedding`. For example, if we are given a collection 
  of points in the plane, and seek the `minimum cost tour` visiting all 
  of them (i.e., the `traveling salesman problem`), the underlying 
  `topology` is the `complete graph` connecting each pair of vertices. 
  The `weights` are typically defined by the `Euclidean distance` between 
  each pair of points.
  
  `Grids of points` are another example of `topology from geometry`. 
  Many problems on an `n × m grid` involve walking between neighboring 
  points, so the edges are implicitly defined from the geometry.
  
- `Implicit` vs. `Explicit` – Certain graphs are not `explicitly constructed` 
  and then `traversed`, but `built as we use them`. A good example is in 
  `backtrack search`. The `vertices` of this `implicit search graph` are 
  the `states` of the `search vector`, while `edges` `link pairs of states` 
  that can be directly generated from each other. Because you do not have 
  to `store the entire graph`, it is often `easier to work` with an 
  `implicit graph` than `explicitly construct it` prior to `analysis`.
  
- `Labeled` vs. `Unlabeled` – Each `vertex` is assigned a `unique name` 
  or `identifier` in a `labeled graph` to distinguish it from all other 
  vertices. In `unlabeled graphs`, no such distinctions have been made.
  
  `Graphs` arising in applications are often `naturally and meaningfully` 
  `labeled`, such as `city names` in a `transportation network`. A common 
  problem is that of `isomorphism testing`—determining whether the 
  `topological structure` of `two graphs` are `identical` if we `ignore` 
  any `labels`. Such problems are typically solved using `backtracking`, 
  by trying to `assign` each vertex in each graph a label such that the 
  `structures are identical`.
  
[Table of contents](#table_of_contents)

### <a name='friendship_graph'></a> Friendship Graph

To demonstrate the importance of `proper modeling`, let us consider a 
graph where the `vertices are people`, and there is an `edge` between 
two people `if and only if` they are `friends`. Such graphs are called 
`social networks` and are well defined on any set of people—be they the 
people in your neighborhood, at your school/business, or even spanning 
the entire world. An entire science analyzing `social networks` has
sprung up in recent years, because many interesting aspects of people 
and their behavior are best understood as properties of this `friendship 
graph`.

[Table of contents](#table_of_contents)

### <a name='data_structures_for_graphs'></a> Data Structures for Graphs

Selecting the right graph data structure can have an `enormous impact` 
on `performance`. Your two basic choices are `adjacency matrices` and 
`adjacency lists`. We assume the graph `G = (V, E)` contains `n` vertices 
and `m` edges.

- `Adjacency Matrix`: We can represent `G` using an `n × n` matrix `M` , 
where element `M [i, j] = 1` `if (i, j) is an edge of G`, and `0` if it 
isn’t. This allows `fast answers` to the question `is (i, j) in G?`, and 
`rapid updates` for `edge insertion` and `deletion`. It may use 
`excessive space` for `graphs` with `many vertices` and relatively 
`few edges`, however.

| Comparision                             |   Winner                            |
|:----------------------------------------|------------------------------------:|
|Faster to test if (x, y) is in graph?    |adjacency matrices                   |
|Faster to find the degree of a vertex?   |adjacency lists                      |
|Less memory on small graphs?             |adjacency lists (m + n) vs. (n<sup>2</sup>)|
|Less memory on big graphs?               |adjacency matrices (a small win)     |
|Edge insertion or deletion?              |adjacency matrices O(1) vs. O(d)     |
|Faster to traverse the graph?            |adjacency lists Θ(m + n) vs. Θ(n<sup>2</sup>) |
|Better for most problems?                |adjacency lists                      |


Consider a graph that represents the `street map of Manhattan` in New York
City. Every junction of `two streets` will be a `vertex` of the graph. 
Neighboring `junctions` are connected by `edges`. How big is this graph? 
Manhattan is basically a grid of `15 avenues` each crossing roughly `200 
streets`. This gives us about `3,000 vertices` and `6,000 edges`, 
since `each vertex` `neighbors` `four other
vertices` and `each edge` is shared between `two vertices`. This modest 
amount of data should easily and efficiently be stored, yet an 
adjacency matrix would have `3,000 × 3,000 = 9,000,000` cells, almost 
all of them `empty`!

There is some potential to `save space` by `packing multiple bits` per `word`
or `simulating` a `triangular matrix` on `undirected graphs`. But these 
methods lose the `simplicity` that makes `adjacency matrices` so 
`appealing` and, more critically, remain inherently `quadratic on sparse 
graphs`.

- `Adjacency Lists`: We can more efficiently represent `sparse graphs` by 
  using `linked lists` to `store` the `neighbors` adjacent to each `vertex`. 
  `Adjacency lists` require `pointers` but are `not frightening` once you 
  have experience with `linked structures`.
  
  `Adjacency lists` make it `harder to verify` whether a given `edge (i, j)` 
  is in `G`, since we must `search through` the `appropriate list` to find 
  the `edge`. However, it is `surprisingly easy` to `design graph algorithms` 
  that `avoid` any need for `such queries`. Typically, we `sweep through` 
  all the `edges` of the graph in `one pass` via a `breadth-first` or 
  `depth-first` traversal, and `update the implications` of the `current 
  edge` as we visit it.
  
**Note**: `Adjacency lists` are the `right data structure` for most
          applications of graphs.


We will use `adjacency list` as the data structure for graph. We represent
a graph using the following data type. For each graph, we keep a `count` of 
the `number of vertices`, and assign `each vertex` a `unique identification`
number from `1` to `nvertices`.

```c
#define MAXV            1000 /* maximum number of vertices */

typedef struct {
    int y;                      /* adjacency info */
    int weight;                 /* edge weight, if any */
    struct edgenode *next;      /* next edge in list */
} edgenode;


typedef struct {
    edgenode *edges[MAXV+1];     /* adjacency info */
    int degree[MAXV+1];          /* outdegree of each vertex */
    int nvertices;               /* number of vertices in graph */
    int nedges;                  /* number of edges in graph */
    bool directed;               /* is the graph directed? */
} graph;
```
We represent `directed edge (x, y)` by an `edgenode y` in `x’s` 
`adjacency list`. The `degree field` of the `graph` `counts` the 
`number` of `meaningful entries` for the given `vertex`. An `undirected 
edge (x, y)` appears `twice` in any `adjacency-based graph structure`,
once as `y in x’s list`, and once as `x in y’s list`. The `boolean flag` 
`directed` identifies whether the given `graph` is to be `interpreted` 
as `directed` or `undirected`.

To demonstrate the use of this data structure, we show how to `read` a 
`graph from a file`. A typical graph format consists of an initial line 
featuring the number of `vertices and edges` in the graph, followed by a 
listing of the `edges at one vertex` per line.
```c
initialize_graph(graph *g, bool directed)
{
    int i;                              /* counter */
    
    g -> nvertices = 0;
    g -> nedges = 0;
    g -> directed = directed;
    
    for (i=1; i<=MAXV; i++) g->degree[i] = 0;
    for (i=1; i<=MAXV; i++) g->edges[i] = NULL;
}
```

Actually reading the graph requires `inserting` each 
`edge` into this structure:

```c
read_graph(graph *g, bool directed)
{
    int i;                      /* counter */
    int m;                      /* number of edges */
    int x, y;                   /* vertices in edge (x,y) */
    
    initialize_graph(g, directed);
    
    scanf("%d %d",&(g->nvertices),&m);
    
    for (i=1; i<=m; i++) {
        scanf("%d %d",&x,&y);
        insert_edge(g,x,y,directed);
    }
}
```

The critical routine is `insert edge`.
The new `edgenode` is inserted at the beginning of the appropriate 
`adjacency list`, since `order doesn’t matter`. We `parameterize`
our `insertion` with the `directed Boolean flag`, to `identify` whether 
we need to `insert two copies` of each `edge` or only `one`. Note the 
use of `recursion` to solve this problem:
```c
insert_edge(graph *g, int x, int y, bool directed)
{
    edgenode *p;                    /* temporary pointer */
    
    p = malloc(sizeof(edgenode));   /* allocate edgenode storage */
    
    p->weight = NULL;
    p->y = y;
    p->next = g->edges[x];
    
    g->edges[x] = p;                /* insert at head of list */
    
    g->degree[x] ++;

    if (directed == FALSE)
        insert_edge(g,y,x,TRUE);
    else
        g->nedges ++;
}
```

`Printing` the `associated graph` is just a matter of `two nested loops`, 
one through `vertices`, the other through `adjacent edges`:

```c
print_graph(graph *g)
{
    int i;                      /* counter */
    edgenode *p;                /* temporary pointer */

    for (i=1; i<=g->nvertices; i++) {
        printf("%d: ",i);
        p = g->edges[i];
        while (p != NULL) {
            printf(" %d",p->y);
            p = p->next;
        }
        printf("\n");
    }
}
```

It is a good idea to use a well-designed graph data type as a model for building
your own, or even better as the foundation for your application.
We recommend `LEDA` or `Boost` as the `best-designed` `general-purpose` 
`graph data structures` currently available. They may be `more powerful` 
(and hence somewhat `slower/larger`) than you need, but they do `so many 
things right` that you are likely to `lose` `most of the potential 
do-it-yourself benefits` through `clumsiness`.

[Table of contents](#table_of_contents)

### <a name='traversing_a_graph'></a> Traversing a Graph

Perhaps the most fundamental `graph problem` is to `visit every edge
and vertex` in a `graph` in a `systematic way`. Indeed, all the basic 
bookkeeping operations on graphs (such `printing` or `copying graphs`, 
and `converting between alternate representations`) are applications of 
`graph traversal`.

`Mazes` are naturally represented by `graphs`, where each `graph vertex` 
`denotes` a `junction of the maze`, and each `graph edge` denotes a 
`hallway in the maze`. Thus, any `graph traversal` algorithm must be 
powerful enough to get us `out of an arbitrary maze`. For `efficiency`, 
we must make sure `we don’t get trapped` in the maze and visit the `same 
place` repeatedly. For `correctness`, we must do the `traversal` in a 
`systematic way` to guarantee that we get `out of the maze`. 
Our `search` must take us through every `edge and vertex` in the graph.

The key idea behind `graph traversal` is to `mark each vertex` when we 
`first visit` it and `keep track` of what we have not yet `completely 
explored`. Although bread crumbs or unraveled threads have been used to 
mark visited places in fairy-tale mazes, we will rely on `Boolean flags` 
or `enumerated types`.

Each vertex will exist in one of three states:
- `undiscovered` – the vertex is in its initial, virgin state.

- `discovered` – the vertex has been `found`, but we have `not` yet 
  `checked` out all its `incident edges`.
  
- `processed` – the `vertex` after we have visited all its `incident edges`.

Obviously, a vertex cannot be processed until after we discover it, so the 
state of each `vertex` progresses over the course of the traversal from 
`undiscovered` to `discovered` to `processed`.

We must also `maintain` a `structure` containing the `vertices` that we 
have `discovered but not yet completely processed`. Initially, only the 
`single start vertex` is considered to be `discovered`. To completely 
`explore a vertex v`, we must evaluate `each edge` leaving `v`. If an 
`edge` goes to an `undiscovered vertex x`, we mark `x` `discovered` and 
`add` it to the `list of work to do`. We `ignore` an `edge` that goes to a
`processed vertex`, because further contemplation will tell us nothing 
new about the graph. We can also `ignore` any edge going to a `discovered 
but not processed vertex`, because the `destination` `already resides` 
on the `list of vertices to process`.

Each `undirected edge` will be considered `exactly twice`, once when 
each of its `endpoints is explored`. `Directed edges` will be considered 
`only once`, when exploring the `source vertex`.

Every `edge` and `vertex` in the `connected component` must eventually 
be `visited`. Why? Suppose that there exists a vertex `u` that remains 
`unvisited`, whose `neighbor` `v` was `visited`. This neighbor `v` will 
eventually be explored, after which we will `certainly` visit `u`. 
Thus, we must find everything that is there to be found.

[Table of contents](#table_of_contents)

### <a name='breadth_first_search'></a> Breadth-First Search


The basic `breadth-first search` algorithm is given below. At some point 
during the course of a traversal, `every node` in the `graph` changes 
state from `undiscovered` to `discovered`. In a `breadth-first search` of 
an `undirected graph`, we `assign a direction` to `each edge`, from the 
`discoverer u` to the `discovered v`. We thus denote `u` to be the
`parent of v`. Since each node has `exactly one parent`, `except` for the 
`root`, this defines a `tree` on the `vertices` of the `graph`. This tree, 
illustrated below, defines a `shortest path` from the `root` to every 
`other node` in the `tree`. This property makes `breadth-first search` 
very useful in `shortest path problems`.

![Breadth_first_search](../images/breadth_first_search.png)


```c
BFS(G, s)
    for each vertex u ∈ V [G] − {s} do
        state[u] = “undiscovered”
        p[u] = nil, i.e. no parent is in the BFS tree
    state[s] = “discovered”
    p[s] = nil
    Q = {s}
    while Q != empty do
        u = dequeue[Q]
        process vertex u as desired
        for each v ∈ Adj[u] do
            process edge (u, v) as desired
            if state[v] = “undiscovered” then
                state[v] = “discovered”
                p[v] = u
                enqueue[Q, v]
        state[u] = “processed”
```

The `graph edges` that do `not appear` in the `breadth-first search tree` 
also have `special properties`. For `undirected graphs`, `non-tree edges` 
can `point only to vertices` on the `same level as the parent vertex`, 
or to vertices on the `level directly below the parent`. These properties 
follow easily from the fact that `each path in the tree` must be the 
`shortest path in the graph`. For a `directed graph`, a `back-pointing edge`
`(u, v)` can exist whenever `v` lies closer to the `root` than `u` does.

**Implementation**:

Our `breadth-first search` implementation `bfs` uses `two Boolean arrays` 
to maintain our `knowledge` about `each vertex in the graph`. A vertex is 
`discovered` the `first time we visit it`. A `vertex` is considered 
`processed` after we have `traversed` all `outgoing edges` from it. 
Thus, each vertex passes from `undiscovered` to `discovered` to `processed`
over the course of the search. This information could have been maintained 
using one `enumerated type` variable, but we used `two Boolean variables` 
instead.

```c
bool processed[MAXV+1];             /* which vertices have been processed */
bool discovered[MAXV+1];            /* which vertices have been found */
int parent[MAXV+1];                 /* discovery relation */
```
Each vertex is initialized as `undiscovered`:

```c
initialize_search(graph *g)
{
    int i;                              /* counter */
    for (i=1; i<=g->nvertices; i++) {
        processed[i] = discovered[i] = FALSE;
        parent[i] = -1;
    }
}
```

Once a `vertex is discovered`, it is `placed on a queue`. Since we process 
these vertices in `first-in, first-out` order, the `oldest vertices` are 
`expanded first`, which are exactly those `closest to the root`:

```c
bfs(graph *g, int start)
{
    queue q;                        /* queue of vertices to visit */
    int v;                          /* current vertex */
    int y;                          /* successor vertex */
    edgenode *p;                    /* temporary pointer */
    
    init_queue(&q);
    enqueue(&q,start);
    discovered[start] = TRUE;
    
    while (empty_queue(&q) == FALSE) {
        v = dequeue(&q);
        process_vertex_early(v);
        processed[v] = TRUE;
        p = g->edges[v];
        while (p != NULL) {
            y = p->y;
            if ((processed[y] == FALSE) || g->directed)
                process_edge(v,y);
            if (discovered[y] == FALSE) {
                enqueue(&q,y);
                discovered[y] = TRUE;
                parent[y] = v;
            }
            p = p->next;
        }
        process_vertex_late(v);
    }
}
```
[Table of contents](#table_of_contents)

### <a name='exploiting_traversal'></a> Exploiting Traversal

The exact behavior of `bfs` depends upon the functions `process_vertex_early()`, 
`process_vertex_late()`, and `process_edge()`. Through these functions, we 
can `customize` what the `traversal does` as it makes its official visit to 
each edge and each vertex. Initially, we will do all of `vertex processing` 
on `entry`, so `process_vertex_late()` returns without action:

```c
process_vertex_late(int v)
{
}
```

By setting the active functions to

```c
process_vertex_early(int v)
{
    printf("processed vertex %d\n",v);
}
```

```c
process_edge(int x, int y)
{
    printf("processed edge (%d,%d)\n",x,y);
}
```

we print each `vertex and edge` `exactly once`. If we instead set 
`process_edge` to
```c
process_edge(int x, int y)
{
    nedges = nedges + 1;
}
```

we get an `accurate count` of the `number of edges`. Different algorithms 
perform different actions on vertices or edges as they are encountered. 
These functions give us the freedom to easily customize our response.

[Table of contents](#table_of_contents)

### <a name='finding_paths'></a> Finding Paths

The `parent` array set within `bfs()` is very useful for finding interesting 
paths through a graph. The `vertex` that `discovered vertex i` is defined 
as `parent[i]`. `Every vertex` is `discovered` during the course of 
traversal, so except for the root `every node has a parent`. The parent 
relation defines a tree of discovery with the initial search node as the 
root of the tree.

Because `vertices` are `discovered in order of increasing distance` from the 
`root`, this `tree` has a very `important property`. The `unique tree path` 
from the `root to each node` `x ∈ V` uses the `smallest number of edges` 
(or equivalently, intermediate nodes) possible on any `root-to-x` path in 
the graph.

We can `reconstruct this path` by following the `chain of ancestors` from 
`x` to the `root`. Note that we have to `work backward`. We `cannot find` 
the `path` from the `root` to `x`, since `that does not follow` the 
direction of the `parent pointers`. Instead, we must find the path 
from `x` to the `root`. Since this is the `reverse` of how we normally
want the path, we can either 
- store it and then explicitly reverse it using a `stack`, or
- let `recursion reverse` it for us, as follows:

```c
find_path(int start, int end, int parents[])
{
    if ((start == end) || (end == -1))
        printf("\n%d",start);
    else {
        find_path(start,parents[end],parents);
        printf(" %d",end);
    }
}
```
On our breadth-first search graph example (Figure 5.9) our algorithm generated
the following parent relation:

|vertex|   1 | 2   |  3  | 4   |  5  |  6  |
|:---: |:---:|:---:|:---:|:---:|:---:|:---:|
|parent|-1   |  1  | 2   | 5   | 1   |  1  |


![breadth_first_search](../images/breadth_first_search.png)

For the shortest path from 1 to 4, upper-right corner, this parent relation yields
the path {1, 5, 4}.

There are `two points` to remember when using `breadth-first search` to 
find a `shortest path` from `x to y`: 
- First, the `shortest path tree` is only useful if `BFS` was `performed` 
  with `x` as the `root of the search`. 
- Second, `BFS` gives the `shortest path` only if the `graph is unweighted`.


[Table of contents](#table_of_contents)

### <a name='application_of_breadth_first_search'></a> Application of Breadth-First Search

Most elementary graph algorithms make `one or two traversals` of the graph 
while we update our knowledge of the graph. Properly implemented using 
`adjacency lists`, any such algorithm is destined to be `linear`, since 
`BFS` runs in `O(n + m)` time on both `directed` and `undirected` graphs. 
This is `optimal`, since it is `as fast as` one can hope to read any 
`n-vertex`, `m-edge` graph.

### <a name='connected_components'></a> Connected Components
The `six degrees of separation` theory argues that there is always a short 
path linking every `two people` in the world. We say that a graph is 
`connected` if there is a `path` between any `two vertices`. If the 
theory is true, it means the `friendship graph` must be `connected`.

A `connected component` of an `undirected graph` is a `maximal set of 
vertices` such that `there is a path between every pair of vertices`. The 
`components` are `separate “pieces”` of the graph such that there is `no 
connection` between the `pieces`. If we envision `tribes` in `remote parts` 
of the world that have `yet not been encountered`, each such `tribe` would 
`form a separate connected component` in the `friendship graph`.
A `remote hermit`, or `extremely unpleasant` fellow, would represent a 
connected component of one vertex.

An amazing number of seemingly complicated problems reduce to `finding or
counting connected components`. For example, testing whether a puzzle such 
as Rubik’s cube or the 15-puzzle can be solved from any position is really 
asking whether the graph of legal configurations is connected.

`Connected components` can be found using `breadth-first search`, since the 
`vertex order` does not matter. We start from the `first vertex`. Anything 
we discover during this search must be part of the same `connected 
component`. We then repeat the search from any `undiscovered vertex` 
(if one exists) to define the `next component`, and so on until all 
vertices have been found:

```c
connected_components(graph *g)
{
    int c;                      /* component number */
    int i;                      /* counter */
    
    initialize_search(g);
    
    c = 0;
    for (i=1; i<=g->nvertices; i++)
        if (discovered[i] == FALSE) {
            c = c+1;
            printf("Component %d:",c);
            bfs(g,i);
            printf("\n");
    }
}



process_vertex_early(int v)
{
    printf(" %d",v);
}

process_edge(int x, int y)
{
}
```

Observe how we increment a counter `c` denoting the `current component number`
with each call to `bfs`. We could have explicitly bound each vertex to its 
component number (instead of printing the vertices in each component) by 
changing the action of `process_vertex`.

There are `two distinct notions` of connectivity for `directed graphs`, 
leading to algorithms for finding both `weakly connected` and 
`strongly connected` components. Both of these can be found in `O(n + m)` 
time.

[Table of contents](#table_of_contents)

### <a name='two_coloring_graphs'></a> Two-Coloring Graphs

The `vertex-coloring` problem seeks to assign a `label` (or color) to 
each `vertex` of a `graph` such that `no edge links` any `two vertices` of 
the `same color`. We can easily avoid all conflicts by assigning each 
vertex a `unique color`. However, the goal is to `use as few colors as 
possible`. `Vertex coloring` problems often arise in `scheduling 
applications`, such as `register allocation in compilers`.

A graph is `bipartite` if it can be `colored` without `conflicts` while 
using only `two colors`. `Bipartite` graphs are important because they 
arise `naturally` in many applications. Consider the `had-sex-with` graph 
in a `heterosexual world`. Men have sex only with women, and vice versa. 
Thus, gender defines a legal `two-coloring`, in this simple model.

But how can we find an appropriate `two-coloring` of a graph, thus 
separating the men from the women? Suppose we assume that the starting 
vertex is male. All vertices adjacent to this man must be female, 
assuming the graph is indeed `bipartite`.

We can augment `breadth-first search` so that whenever we discover a new 
vertex, we `color it` the `opposite of its parent`. We check whether any 
`non-discovery edge` links two vertices of the `same color`. Such a 
`conflict` means that the graph cannot be `two-colored`. Otherwise, we 
will have constructed a proper `two-coloring` whenever we terminate without 
conflict.

```c
twocolor(graph *g)
{
    int i;                          /* counter */
    
    for (i=1; i<=(g->nvertices); i++)
        color[i] = UNCOLORED;
    
    bipartite = TRUE;
    
    initialize_search(&g);
    
    for (i=1; i<=(g->nvertices); i++)
        if (discovered[i] == FALSE) {
            color[i] = WHITE;
            bfs(g,i);
        }
}


process_edge(int x, int y)
{
    if (color[x] == color[y]) {
        bipartite = FALSE;
        printf("Warning: not bipartite due to (%d,%d)\n",x,y);
    }
    color[y] = complement(color[x]);
}

complement(int color)
{
    if (color == WHITE) return(BLACK);
    if (color == BLACK) return(WHITE);
    
    return(UNCOLORED);
}

```

We can assign the first vertex in any `connected component` to be whatever
`color/sex` we wish. `BFS` can separate the men from the women, but we 
can’t tell them apart just by using the graph structure.

[Table of contents](#table_of_contents)

### <a name='depth_first_search'></a> Depth-First Search
There are two primary graph traversal algorithms: `breadth-first search 
(BFS)` and `depth-first search (DFS)`. For certain problems, it makes 
absolutely `no difference` which you use, but in others the distinction 
is crucial.

The difference between `BFS` and `DFS` results is in the `order` in which 
they `explore vertices`. This `order` depends completely upon the 
`container data structure` used to store the `discovered` but `not 
processed` vertices.

- `Queue` – By `storing` the vertices in a `first-in, first-out (FIFO)` 
  `queue`, we explore the `oldest unexplored vertices first`. Thus our 
  `explorations` `radiate out slowly` from the `starting vertex`, 
  defining a `breadth-first search`.
  
- `Stack` – By `storing` the vertices in a `last-in, first-out (LIFO)`
  `stack`, we `explore` the `vertices by lurching(uncontrolled-movement) 
  along a path`, `visiting` a `new neighbor` if one is `available`, and 
  `backing up` only when we are `surrounded` by `previously discovered
  vertices`. Thus, our explorations `quickly wander away` from our `starting 
  point`, defining a `depth-first search`.

Our implementation of `dfs` maintains a notion of `traversal time` for 
each vertex. Our `time clock ticks` each time we `enter or exit` any 
vertex. We keep track of the `entry and exit` times for each vertex.

`Depth-first search` has a `neat` `recursive implementation`, which 
eliminates the need to explicitly use a `stack`:

```c
DFS(G, u)
    state[u] = “discovered”
    process vertex u if desired
    entry[u] = time
    time = time + 1
    for each v ∈ Adj[u] do
        process edge (u, v) if desired
        if state[v] = “undiscovered” then
            p[v] = u
            DFS(G, v)
    
    state[u] = “processed”
    exit[u] = time
    time = time + 1
```

The `time intervals` have interesting and useful properties with respect 
to `depth-first search`:

- `Who is an ancestor?` – Suppose that `x` is an `ancestor` of `y` in the 
  `DFS` tree. This implies that we `must enter` `x before y`, since there 
  is no way we can be born before our own father or grandfather! We also 
  must `exit` `y` before we `exit` `x`, because the mechanics of `DFS` 
  ensure we `cannot exit` `x` until after we have `backed up` from the 
  `search` of `all its descendants`. Thus the time interval of `y` must 
  be properly nested within ancestor `x`.
  
- `How many descendants?` – The difference between the `exit` and `entry` 
  times for `v` tells us `how many` `descendents` `v` has in the `DFS tree`. 
  The `clock` gets `incremented` on `each vertex entry` and `vertex exit`, 
  so `half the time difference` denotes the `number of descendents of v`.
  
We will use these `entry` and `exit` times in several applications of 
`depth-first search`, particularly `topological sorting` and 
`biconnected/strongly-connected` components. We need to be able to take 
separate actions on each `entry` and `exit`, thus motivating distinct 
`process_vertex_early` and `process_vertex_late` routines called from 
`dfs`.

The other important property of a `depth-first search` is that it 
`partitions` the `edges` of an `undirected graph` into `exactly two 
classes`: `tree edges` and `back edges`. The `tree edges` discover `new 
vertices`, and are those `encoded in the parent relation`. `Back edges` 
are those whose `other endpoint` is an `ancestor of the vertex` being 
`expanded`, so they `point back` into the `tree`.

An amazing property of `depth-first search` is that all edges fall into 
these `two classes`. Why can’t an edge go to a `brother` or `cousin node` 
instead of an `ancestor`? `All nodes` reachable from a given `vertex v` 
are `expanded` `before we finish` with the `traversal from v`, so such 
topologies are `impossible for undirected graphs`. This `edge 
classification` proves fundamental to the `correctness` of 
`DFS-based algorithms`.

**Implementation**:

A `depth-first search` can be thought of as a `breadth-first search` 
with a `stack` instead of a `queue`. The beauty of implementing `dfs` 
`recursively` is that `recursion eliminates` the need to keep an 
`explicit stack`:

```c
dfs(graph *g, int v)
{
    edgenode *p;                /* temporary pointer */
    int y;                      /* successor vertex */
    
    if (finished) return;       /* allow for search termination */
    
    discovered[v] = TRUE;
    time = time + 1;
    entry_time[v] = time;
    
    process_vertex_early(v);
    
    p = g->edges[v];
    while (p != NULL) {
        y = p->y;
        if (discovered[y] == FALSE) {
            parent[y] = v;
            process_edge(v,y);
            dfs(g,y);
        }
        else if ((!processed[y]) || (g->directed))
            process_edge(v,y);
            
        if (finished) return;
            
        p = p->next;
    }
        
    process_vertex_late(v);
    
    time = time + 1;
    exit_time[v] = time;
    
    processed[v] = TRUE;
}
```

`Depth-first search` use essentially the same idea as `backtracking`.
Both involve `exhaustively searching` `all possibilities` by advancing 
if `it is possible`, and `backing up` `as soon as` there is `no unexplored 
possibility` for `further advancement`. Both are most easily understood 
as `recursive algorithms`.

**NOTE**: `DFS` organizes vertices by `entry/exit` times, and edges into 
`tree and back edges`. This organization is what gives `DFS` its `real 
power`.


[Table of contents](#table_of_contents)

### <a name='application_of_depth_first_search'></a> Application of Depth-First Search
As algorithm design paradigms go, a `depth-first search` isn’t particularly 
intimidating. It is surprisingly `subtle`, however meaning that its 
correctness requires getting details right.

The `correctness` of a `DFS-based` algorithm depends upon specifics of 
exactly `when we process` the `edges` and `vertices`. We can process 
`vertex v` either `before` we have traversed any of the `outgoing edges` 
from `v` (`process_vertex_early()`) or `after` we have finished 
processing all of them (`process_vertex_late()`). Sometimes we
will take special actions at both times, say `process_vertex_early()` 
to initialize a vertex-specific `data structure`, which will be 
`modified` on `edge-processing` operations and then 
analyzed afterwards using `process_vertex_late()`.

In `undirected graphs`, each `edge (x, y)` sits in the `adjacency lists` 
of vertex `x and y`. Thus there are `two potential times` to process each 
`edge (x, y)`, namely when `exploring x` and when `exploring y`. 
The `labeling of edges` as `tree edges or back edges` occurs during the 
`first time` the edge is `explored`. This first time we see an edge is
usually a logical time to do `edge-specific processing`. Sometimes, 
we may want to take different action the second time we see an edge.

But when we encounter `edge (x, y)` from `x`, how can we tell if we 
have `previously traversed` the edge from `y`? The issue is easy if 
vertex `y` is `undiscovered`: `(x, y)` becomes a `tree edge` so this 
`must be` the `first time`. The issue is also easy if `y` has not been 
`completely processed`; since we `explored the edge` when we explored `y`
this must be the `second time`. But what if `y` is an `ancestor of x`, 
and thus in a `discovered state`? Careful reflection will convince you 
that this must be our `first traversal` unless `y` is the 
`immediate ancestor` of `x`—i.e. , `(y, x) is a tree edge`. This
can be established by testing if `y == parent[x]`.

I find that the subtlety of `depth-first search`-based algorithms kicks 
me in the head whenever I try to implement one. I encourage you to 
analyze these implementations carefully to see where the problematic 
cases arise and why.


[Table of contents](#table_of_contents)

### <a name='finding_cycles'></a> Finding Cycles
`Back edges` are the key to finding a `cycle` in an `undirected graph`. 
If there is no `back edge`, all `edges` are `tree edges`, and `no cycle` 
exists in a tree. But any `back edge` going from `x` to an ancestor `y` 
creates a `cycle` with the `tree path` from `y to x`. Such a cycle is 
easy to find using `dfs`:

```c
process_edge(int x, int y)
{
    if (parent[x] != y) {                   /* found back edge! */
        printf("Cycle from %d to %d:",y,x);
        find_path(y,x,parent);
        printf("\n\n");
        finished = TRUE;
    }
}
```

The `correctness` of this `cycle detection algorithm` depends upon 
`processing` `each undirected edge` `exactly once`. Otherwise, a spurious 
`two-vertex cycle (x, y, x)` could be composed from the two traversals of 
any `single undirected edge`. We use the `finished` flag to terminate 
after finding the `first cycle`.

[Table of contents](#table_of_contents)





### <a name='important_questions'></a> Important Questions
- How many binary tree can be formed using `n` nodes?


### <a name='problem_wiki'></a> Problems Wiki
- `Nuts and Bolts Problem`
  > The nuts and bolts problem is defined as follows. You are given a 
    collection of `n` bolts of `different widths`, and `n` corresponding 
    nuts. You `can test` whether a given `nut and bolt fit together`, 
    from which you learn whether the `nut is too large`, `too small`, or 
    an `exact match` for the `bolt`. The differences in `size` between 
    pairs of `nuts or bolts` are `too small` to see by `eye`, so you 
    `cannot compare the sizes` of two nuts or two bolts directly. 
    You are to match each bolt to each nut.  
    Give an O(n<sup>2</sup>) algorithm to solve the nuts and bolts problem. 
    Then give a `randomized` O(n log n) expected time algorithm for the 
    same problem.
    
  **Solution**:
  > The brute force algorithm for matching nuts and bolts starts with the
    `first bolt` and `compares it to each nut` until we find a match. In 
    the worst case, this will require `n comparisons`. Repeating this for 
    each successive bolt on all remaining nuts yields a 
    `quadratic-comparison` algorithm.
  >  - What if we pick a `random bolt` and try it? On average, we would 
     expect to get about halfway through the `set of nuts` before we 
     found the match, so this `randomized algorithm` would do `half the 
     work` as the `worst case`. That counts as some kind of improvement, 
     although `not an asymptotic one`.
  >  - `Randomized quicksort` achieves the desired expected-case running 
     time, so a natural idea is to `emulate` it on the nuts and bolts 
     problem. Indeed, `sorting both the nuts and bolts` by `size` would 
     yield a `matching`, since the `ith` largest nut must match the `ith` 
     largest bolt.
  > - The fundamental step in `quicksort` is partitioning elements around 
     a `pivot`. Can we `partition nuts and bolts` around a `randomly 
     selected` `bolt b`? Certainly we partition the nuts into those of 
     size `less than b` and `greater than b`. But decomposing the problem 
     into `two halves` requires `partitioning the bolts` as well, and we 
     `cannot compare bolt against bolt`. But once we find the `matching nut` 
     to `b` we can use it to `partition the bolts` accordingly. 
     In `2n − 2` comparisons, we partition the nuts and bolts, and the 
     remaining analysis follows directly from `randomized quicksort`.
  > - What is interesting about this problem is that `no simple 
     deterministic` algorithm for `nut and bolt sorting` is `known`. 
     It illustrates how `randomization` makes the `bad case` go away, 
     leaving behind a `simple and beautiful algorithm`.

[Table of contents](#table_of_contents)