### Solution 1 dp

if sum is odd, then return false

state definition:

dp[i][j] means select numbers from index of [0, i], and very numbers can only bu used once, let sum of these numbers to be j.

if j < nums[i], 则要和为 j 的情况下，不能选 nums[i]，则 dp[i][j] = dp[i-1][j]

if j >= nums[j], 则可以选也可以不选

dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]

