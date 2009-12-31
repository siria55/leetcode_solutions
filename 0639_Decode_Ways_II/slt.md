### Solution1 dp + by cases

- t-complexity: $O(n * C)$
    C = 26
- s-complexity: $O(1)%

f[i] ::= answer with s[i] ended string, `f[0] = s[0] == '*' ? 9 : (s[0] == 0 ? 0 : 1)`

- s[i] == `*`
    - s[i] as a single item: `f[i] = f[i-1] * 9`
    - s[i] paired with last char as an item:
        - s[i-1] = 1: item can be from 11 to 19, `f[i] = f[i-2] * 9`
        - s[i-1] = 2: item can be from 21 to 26, `f[i] = f[i-2] * 6`
        - s[i-1] = `*`: item can be from 11-19 and from 21 to 26, `f[i] = f[i-2] * 15`
- s[i] is number:
    - s[i-1] is `*`:
        - s[i] == 0, s[i] must pair with s[i-1] as group, which may be 10 or 20, `f[i] = f[i-2]*2`
        - s[i] in [1,9]
            - s[i] as a single item, `f[i] = f[i-1]`
            - s[i] paried with last char
                - s[i] in [1,6]: s[i-1] can be 1 or 2, `f[i] = f[i-2] * 2`
                - s[i] in [7,9]: s[i] can be 1, `f[i] = f[i-2] * 1`
    - s[i-1] is number:
        - s[i] is 0, s[i-1] must be 1 xor 2, and must be paired, `f[i] = f[i-2]`
        - s[i] in [1,9]
            - s[i] as a single item, `f[i] = f[i-1]`
            - s[i] paired with s[i-1]:
                - s[i-1] is 1, `f[i] = f[i-2]`
                - s[i-1] is 2, and s[i] in [1,6], `f[i] = f[i-2]`

and the get sum of all the cases



