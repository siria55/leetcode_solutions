### Solution 1 DP + state machine

由题目可知，股票买卖有3个状态，
定义 dp[i][0],表示第i天持有股票
定义 dp[i][1],表示第i天处于冷冻期，且不持有股票 (刚卖)
定义 dp[i][2]，表示第i天不处于冷冻期，且不持有股票

状态机见：

https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/czhuang-tai-ji-dong-tai-gui-hua-by-zhang-fcid/


```
dp[i][0] = max(dp[i-1][0], dp[i-1][2] - prices[i])
dp[i][1] = dp[i-1][0] + prices[i]
dp[i][2] = max(dp[i-1][1], dp[i-1][2])
```

