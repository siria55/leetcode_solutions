### Solution 1 Shuffle Simulation

- t-complexity: $O(n)$
- s-complexity: $O(n)$

共有 n 个不同的数，根据每个位置能够选择什么数，共有 n! 种组合。

题目要求每次调用 shuffle 时等概率返回某个方案，或者说每个元素都够等概率出现在每个位置中。

我们可以使用 Knuth 洗牌算法（Fisher-Yates 洗牌算法），在 O(n) 复杂度内等概率返回某个方案。

具体的，我们从前往后尝试填充 `[0, n - 1]` 该填入什么数时，通过随机当前下标与（剩余的）哪个下标进行值交换来实现。
