### Solution 1 bit + greedy

if last bit is 0, then right shift, one step down
if not, count bit of n-1 and n+1, we want remove as much ones as possible

for -1, only left-most bit of 1 can be removed
for +1, all left-most consecutive ones will be removed

then n + 1 == n - 1, do ++n is better, except 3

special cases:
- a special case is when n = 3, n + 1 == n - 1, use n-1 will fast
- n = `INT_MAX`, n + 1 will overflow

