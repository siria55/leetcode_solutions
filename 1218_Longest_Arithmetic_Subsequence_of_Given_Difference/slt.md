### Solution 1 DP

- t-complexity: $O(n)$
- s-complexity: $O(C)$
    C = 40001

n is in range [-10000, 10000], n-diff is in range [-20000, 20000]. and move to positive as index

- state definition: dp[n] is longest subsequence ended with n
- state transfer: dp[n] = dp[n-diff] + 1
- init value: None
- return value: max(dp[arr[i]])

