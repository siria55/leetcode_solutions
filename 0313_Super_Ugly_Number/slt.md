###  思路1 DP

同264，只是235换成了一个未定的list

dp[i] 表示第 i 个超级丑数。最小的超级丑数是1，有 dp[1] = 1

创建与数组 primes 长度相同的数组 pointers, 每个元素初始化为 1

当 2 <= i <= n 时，dp[i] = min(dp[pointers[j]] * primes[j]) (for j in range(len(primes)))

然后再把用到的那个指针 += 1