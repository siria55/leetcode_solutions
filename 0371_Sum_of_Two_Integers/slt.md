### Solution1 bit operation

- t-complexity $O(C)$
    C is const with value 32
- s-complexity $O(1)$

iterate from low to high decimal

three cases of current bits:

- both bits are 1, current value depends on carry, and next carry = 1
- only one of the bits is 1
    - if carry is 1, then current value is 0, and next carry keeps 1
    - if carry is 0, then current value is 1, and next carry keeps 0
    these two cases can be summarized as res |= ((carry ^ 1) << i), and carry remain
- none of these bits are 0, current value is carry, next carry is 0

