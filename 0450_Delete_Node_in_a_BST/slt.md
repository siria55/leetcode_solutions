### Solution 1 dfs delete

- t-complexity: O(h)
    h is the height of the tree
- s-complexity: O(h)

if node is target node:

- if do not have left child, replace it with right child
- if do not have right child, replace it with left child
- if have both children, put left child to right child's left most leaf, and delete it

