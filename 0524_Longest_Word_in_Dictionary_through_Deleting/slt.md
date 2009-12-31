### Solution 1 双指针检查 subsequence

- 时间复杂度 $O(n \cdot x)$
    n 是 dictionary 的长度。x 是字符串的平均长度
- 空间复杂度 $O(x)$

for t in dictionary:
    if t is sub-sequence of s:
       再判断长度和字典序
