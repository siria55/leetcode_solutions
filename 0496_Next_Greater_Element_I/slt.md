### Solution 1 Monotone Stack

- t-complexity: $O(len1 + len2)$
    every element can in or out of stack in len2, and len1 for construct answer
- s-complexity: $O(len2)$

traverse nums2, at the same time, maintain a monotone stack.

for element as nums2[i], compare stack top element with it.

1. stack is empty, push nums2[i] into stack
2. stack is not empty:
    1. top < nums2[i], means nums[2] is the first element greater than top, record this in hash table
    2. top >= nums2[i], add nums2[i] to stack

