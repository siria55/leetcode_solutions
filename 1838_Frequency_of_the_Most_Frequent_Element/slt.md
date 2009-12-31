### Solution1 前缀和 + 二分

- 时间复杂度 O(n * logn)
- 空间复杂度 (n + 排序用的空间)
    n 是 pre_sum 用的空间

参考：https://leetcode-cn.com/problems/frequency-of-the-most-frequent-element/solution/1838-zui-gao-pin-yuan-su-de-pin-shu-shua-ub57/

先把 nums 排序

然后遍历 i for i in range(len(nums))

对于每个 i，取 l = 0, r = i

然后统计 mid 到 i 右边的顶上的面积

// 长方形面积 - sum(nums[mid], nums[mid+1], ..., nums[i-1], nums[i])
// 后面一个用前缀和实现
area = nums[i] * (i - mid + 1) - (sum[i] - sum[mid-1])

如果:

- area > k，说明这个面积太大，k不满足，l = mid + 1
- area <= k，说明这个面积偏小，但可以满足，r = mid - 1

用这个二分法，找到 r 中最大的 mid
