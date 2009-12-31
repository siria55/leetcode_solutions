### Solution1 双指针

- 时间复杂度 O(n^2)
- 空间复杂度 O(1)

先排序。用 i 遍历最长边, l = 0, r = i - 1

- nums[l] + nums[r] > nums[i]，则[l, r-1] 和 r 和 i 都成组成三角形，r--
- nums[l] + nums[r] <= nums[i]，则 l++
