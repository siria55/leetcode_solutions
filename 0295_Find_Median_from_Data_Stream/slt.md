### Solution1 优先队列

- 时间复杂度
    - addNum: $O(logn)$
    - findMedian: $O(1)$
- 空间复杂度 $O(n)$

用两个优先队列 que_max, que_min, 分别存放大于中位数和小于中位数的数。

- 当数量为奇数数时，让 que_min 中的数比 que_max 中多一个。此时中位数就是 que_min 的队头。
- 当数量为偶数时，中位数就是他们两个队头的平均值

当添加数的时候

- num <= max(que_min) 则把 num 添加到 que_min 中。并把可能多的元素移动到 que_max 中
- num > max(que_min) 则把 num 添加到 que_max 中。并把可能多的元素移动到 que_min 中
- 当数量为 0 时，直接加到 que_min 中
