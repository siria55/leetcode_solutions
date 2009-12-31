### Solution1 快慢双指针

- 时间复杂度 $O(n)$
- 空间复杂度 $O(1)$

fast 指针每次走两步，slow 指针每次走一步

把链表分成两部分，设环前的长度为 a，环中的长度为 b。

- 第一次相遇：
    - case1 fast 遇到 NULL，说明是无环链表，直接返回 nullptr
    - case2 fast == slow，设 fast 走了 f 步，slow 走了 s 步。有
        - f = 2s
        - f = s + nb 快指针比慢指针多走 n 圈
        可以解得：s = nb, f = 2nb。即慢指针走了 n 圈，快指针走了 2n 圈
- 第二次相遇：
    如果一个指针走 a + nb 步的话，则必然会走到还的入口。这时慢指针走了 nb，我们希望慢指针再走 a 步。
    这时 slow 不变，将 fast 指向 head。slow 和 fast 每次都走一步。
    当 fast == slow 时，f = a, s = a + nb。这时就找到入口了
