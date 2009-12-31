### Solution 1 贪心模拟

steps:

1. if k > 0, go to 2, else 4
2. find min of nums, negate it
3. k--, goto 1
4. get sum of nums

关键是如何取得 nums 的最小值， nums 元素值不大，可以用 hash 数组实现

