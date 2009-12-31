### Solution 1 simulation

- t-complexity: $O(logn)$
    n is num's value, i /= 1000, so it's log
- s-complexity: $O(logn)$

In English three words a group, for num <= 2^ 31 - 1, possible range is

- Billion
- Million
- Thousand

And leading these words with [0, 999]

Use a function `num2str` to convert nubmer bellow 999

- x >= 100: Need `??? Hundred`
- x >= 20: Need `??? XXX-ty`
- x < 20: Show simple words

