### Solution 1 贪心

- t-complexity: $O(n)$
- s-complexity: $O(1)$

用 diff 记录 L 和 R 出现的次数之差，等于 0 时说明平衡，则结果 + 1
