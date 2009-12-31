### Solution 1 DP

- t-comlpexity: O(n^2)
- s-comlpexity: O(n)

dp[i] represents LIS ending with i.

```
max_len = 1
for i in range(n):
    for j in range(i):
        if nums[j] < nums[i]:
            dp[i] = max(dp[i], dp[j]+1)
    max_len = max(max_len, dp[i])
```

