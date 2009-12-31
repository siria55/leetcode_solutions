### Solution1 DP

- 时间复杂度 $O(n)$
- 空间复杂度 $O(n)$

`dp[i][j][k]` 表示前 i 天、在 A 为 j 次、末尾连续的 L 为 k 次的方案数

状态转移方程：

- 当前为 P：此时连续 L 为 0
    dp[i][j][0] += dp[i-1][j][k] for j in range(2) for k in range(3)
- 当前为 L：连续的 L + 1
    dp[i][j][k] += dp[i-1][j][k-1] for j in range(2) for k in range(1, 3)
- 当前为 A：则缺席天数加 1
    dp[i][1][k] += dp[i-1][0][k] for k in range(3)

初始状态：

天数为 0，A 和 L 的次数为 0，则只有一种情况，即 "P"

dp[0][0][0] = 1

最后再把最后一天的所有情况加起来即可
