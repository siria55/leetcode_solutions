### Solution 1 DP

- t-complexity: $ O(n^2) $
- s-complexity: $ O(n) $

根据数对的第一个数排序所有的数对，dp[i] 存储以 pairs[i] 结尾的最长链的长度。当 i < j 且 pairs[i][1] < pairs[j][0] 时，扩展数对链，更新 dp[j] = max(dp[j], dp[i] + 1)。

