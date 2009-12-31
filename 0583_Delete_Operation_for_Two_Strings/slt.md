### Solution1 DP

dp[i][j] 表示以 i-1 结尾的 word1 和以 j-1 结尾的 word2 想要相等，所需要删除的最少字数

状态转移方程：

```
if word1[i-1] == word2[j-1]:
    dp[i][j] = dp[i-1][j-1]
else:
    dp[i][j] = min(dp[i-1][j-1] + 2, dp[i-1][j] + 1, dp[i][j-1] + 1)    // 表示两个串都删 | 删 word1 | 删 word2
```

