直接暴力会超时

### Solution 1 enumerate + hash table

- t-complexity $O(n^2)$
- s-complexity $O(n)$

题目所描述的回旋镖可以视作一个 V 型的折线。我们可以枚举每个 points[i]，将其当作 V 型的拐点

设 points 中有 m 个点到 points[i] 的距离均相等，我们需要从这 m 点中选出 2 个点当作回旋镖的 2 个端点，由于题目要求考虑元组的顺序，因此方案数即为在 m 个元素中选出 2 个不同元素的排列数

$A_{m}^{2} = m \cdot (m-1)$

所以我们只需要遍历两次，内层循环统计每个距离上，有多少个 m，用 hash table 记录从 距离到 m 的映射
