### Solutuion 1 递归

注意`*`一定是match preceding char，`*`不会出现在第一个位置

### Solutuion 2 DP


```
dp[i][j]: if s[0..i-1] matches p[0..j-1]

if p[j-1] != '*':
    dp[i][j] = dp[i-1][j-1] && s[i-1] == p[j-1]

if p[j-1] == '*': (denote p[j-2] with x)
    dp[i][j] is true iff any of the following is true
    1) "x*" repeats 0 time and matches empty: dp[i][j-2]
    2) "x*" repeats >= 1 times and matches "x*x": s[i-1] == x && dp[i-1][j]
```

