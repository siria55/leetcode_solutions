### Solution1 DP

- 时间复杂度 $O((m+n)k)$
    m 是 flights 长度
- 空间复杂度 $O(n * k)$
    即 dp 占用的空间

f[t][i] 表示恰好 t 次航班，从 src 到 i 的最下花费。

状态转移方程

f[t][i] = min(f[t-1][j] + cost(j,i)) for every flights 中从 j 到 i 的航班

最多能达的航班数是 k + 1，最后答案为 min(f[1][dst], f[2][dst], ..., f[k+1][dst])

当 t=0 时，f[0][i] 表示不搭航班到 i 的最小花费，有：

- f[0][i] = 0, i == src
- f[0][i] = inf, i != src



