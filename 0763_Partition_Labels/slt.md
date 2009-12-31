### Solution1 greedy

- 时间复杂度 $O(n)$
- 空间复杂度 $O(\vert \sum \vert)$
    其中 $\vert \sum \vert$ 是字符集的大小，这里是 26

遍历两次，第一次记录每个字符出现的最后位置。第二次，为了能尽可能多的划分

- 从左到右遍历，维护当前 partition 的 start 和 end
- 对于每个 ch，end = max(end, last[ch])
- 下标 i == end 时，说明这个 partition 找完了。开始下一轮
