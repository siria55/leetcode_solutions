### Solution 1 binary search + simulate

- t-complexity: $O(n^2 * logn)$
- s-complexity: $O(n)$

Maintain a disjoint 2-d array. When add a new number, simulate according to description.

Use an `unordered_set` to remember a number has been added to stream. Duplicate nubmer won't change the outcome.

When add number val, there're four cases:

1. `val-1` and `val+1` is already in stream, then the intervals than ends with `val-1` and starts with `val+1` can be merged in to one.
2. `val-1` is in stream but not `val+1`, just add val to interval that ends with `val-1`.
3. `val+1` is in stream but not `val-1`, this case is symmetry to case 2.
4. Both `val-1` and `val+1` are not in stream, val will form a new interval.

