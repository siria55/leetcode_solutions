### Solution 1 hash map + map

Assuming n is the number of set operations, and m is the number os get operations

- Time Comlpexity:
    - Set: O(1) single operation, and total O(n)
      Note: assuming timestamps are only increasing, If not, it's O(n log n)
    - Get: O(log n) for a single operation, and total O(m log n)
- Space Comlpexity: O(n)

由于添加的 timestamp 是递增的，内层也可以用数组 + 二分查找

