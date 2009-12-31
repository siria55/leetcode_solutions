### Solution 1 bisearch

- t-complexity $O(logn)$
- s-complexity $O(1)$

O(logN)一般考虑二分搜索。有如下规律：

规律一：如果nums[i+1] < nums[i]，则在i之前一定存在峰值元素（包括i）

规律二：如果nums[i] < nums[i+1]，则在i+1之后一定存在峰值元素（包括i+1）如果i+1是最后一个元素，则i+1就是峰值
