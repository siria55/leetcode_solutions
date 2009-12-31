### Solution 1 dp

dp[i] represents length is i, min moves

if i % j == 0:
    dp[i] = dp[j] + dp[i/j]

如果n为一个质数，那么结果就是n,因为只能一个个粘贴
如果n为一个合数，那么他的结果就是分解因式的结果之和

