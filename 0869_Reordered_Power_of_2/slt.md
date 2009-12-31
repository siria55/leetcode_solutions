### Solution 1 hash

- t-complexity: $O(C * log n)$
    count every digit in n use log n, C is contant approximate to 30
- s-complexity: $O(C)$

we can rearrange n in any order, so what only matter is count of every digits in n.

2^29 < 10^9 < 2^39, so there are 30 2's power in range of [1,10^9], as 2^0, 2^1, ..., 2^29

we pre-compute every possible digits count of these 2's powers, and rearrange n to see if its in these pre-computed possible digits.

