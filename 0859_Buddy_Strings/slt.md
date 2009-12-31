### Solution 1 simulation

- t-complexity: $O(n + C)$
    C is size of charset
- s-complexity: $O(C)$

直接暴力会超时

- s 和 goal 长度或者词频不同，则不为 buddy string
- s 与 goal 不同的字符数量为 2 （能相互交换）
- s and goal diff char number is 0, and s has char which appear more than twice

