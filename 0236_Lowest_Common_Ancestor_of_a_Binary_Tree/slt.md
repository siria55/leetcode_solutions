### Solution 1 DFS

- t-complexity: O(N)
    N is number of nodes
- s-complexity: O(N)
    in worst case, recursion depth is N

three cases for root is p and q's lowest common ancester:

1. p and q are in root's sub-trees, and is not in same side
2. p == root, q is in root's left or right sub-tree
3. q == root, p is in root's left or right sub-tree

