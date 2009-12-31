### Solution 1 贪心，排序 + 大顶堆

- 时间复杂度 $O(max(n * logn, k * logn))$
    构建 projects 并排序：n * logn
    执行 k 步项目：k * logn
- 空间复杂度 $O(n)$

贪心：`在需要的本金小于等于我们当前资本的项目中，利益最大的是哪个`

将 profit 和 capital 关联起来，并按照 capital 排序

所有小于等于当前本金的都可以加入到大顶堆中
