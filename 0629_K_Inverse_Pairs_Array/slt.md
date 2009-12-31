### Solution 1 DP + presum

- t-complexity: $O(NK)$
- s-complexity: $O(K)$

if we have some permutation of 1...4

- 5 x x x x creates 4 new inverse pairs
- x 5 x x x creates 3 new inverse pairs
  ...
- x x x x 5 creates 0 new inverse pairs

If we have numbers [1...n], and we  put 1 in the first position, it will create no inversions with the rest of the array. If we choose 2 for the first position, it will create one inversion. If we choose n for the first position, it will create n-1 inversion with the rest of the array

`dp[n][k]` denotes the number of arrays that have k inverse pairs for array composed of 1 to n

if we put n as the last number then all the k inverse pair should come from the first n-1 numbers
if we put n as the second last number then there's 1 inverse pair involves n so the rest k-1 comes from the first n-1 numbers
...
if we put n as the first number then there's n-1 inverse pairs involve n so the rest k-(n-1) comes from the first n-1 numbers

`dp[n][k] = dp[n-1][k] + dp[n-1][k-1] + ... + dp[n-1][k-n+1]`


