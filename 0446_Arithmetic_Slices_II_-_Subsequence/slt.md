### Solution1 dp

- 时间复杂度 $O(n^2)$
- 空间复杂度 $O(n)$

https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/deng-chai-shu-lie-hua-fen-ii-zi-xu-lie-b-77pl/

我们首先考虑至少有两个元素的等差子序列，下文将其称作「弱等差子序列」

尾项和公差可以确定一个等差数列。定义状态 f[i][d] 表示尾项为 nums[i]，公差为 d 的弱等差子序列的个数。

用双重循环遍历 nums， j < i，将 nums[i] 和 nums[j] 分别当做的尾项和倒数第二项，则有 d = nums[i] - nums[j]。我们可以将 nums[i] 加到以 nums[j] 为尾项，且公差为 d 的弱等差子序列的末尾。

于是有转义方程 f[i][d] += f[j][d] + 1， +1 因为 (nums[j], nums[i]) 本身也算一个弱等差子序列。（f[i][d](弱等差的数目) = f[j][d](真等差的数目) + 1(假等差的数目)）

由于题目中要求至少三个元素，当状态转义发生时，f[j][d] 已经是弱等差子序列，再加上 nums[i] 便有了三个元素。

于是将循环中的 f[j][d] 累加，就是结果
